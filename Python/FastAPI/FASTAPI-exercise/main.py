from fastapi import FastAPI
from pydantic import BaseModel
from typing import List, Dict
from typing import Union


class Body(BaseModel):
    password: str
    rules: List[Dict[str,Union[str, int]]]


""" Metodo 1 """
class ValidatePassword:
    
    noMatch: list[str]
    
    def IsValide(self,password: str, rules:List[Dict[str,Union[str, int]]]) -> tuple[bool,list[str]]:
        self.noMatch = []
        self.password = password
        
        rulesDict : Dict[str,int]  =  dict((regra["rule"],int(regra["value"])) for regra in rules )

        if self.minSize(rulesDict.get("minSize",0)):
            self.noMatch.append("minSize")
        
        if self.minUppercase(rulesDict.get("minUppercase",0)):
            self.noMatch.append("minUppercase")
        
        if self.minLowercase(rulesDict.get("minLowercase",0)):
            self.noMatch.append("minLowercase")
            
        if self.minDigit(rulesDict.get("minDigit",0)):
            self.noMatch.append("minDigit")
            
        if self.minSpecialChars(rulesDict.get("minSpecialChars",0)):
            self.noMatch.append("minSpecialChars") 
    
        if "noRepeted" in rulesDict.keys():    
            if self.noRepeted():
                self.noMatch.append("noRepeted")
            
        return (len(self.noMatch) == 0, self.noMatch)
            
    
    def minSize(self,value: int) -> bool:
        return len(self.password) < value
    
    def minUppercase(self,value: int) -> bool:
        return sum(1 for c in self.password if c.isupper()) < value
    
    def minLowercase(self,value: int)-> bool:
        return sum(1 for c in self.password if c.islower()) < value
    
    def minDigit(self,value: int) -> bool:
        return sum(1 for c in self.password if c.isdigit()) < value
        
    def minSpecialChars(self,value: int) -> bool:
        SpecialChar  = "!@#$%^&*()-+\/{}[]"
        return sum(1 for c in self.password if c in SpecialChar) < value
    
    def noRepeted(self) -> bool:
        return  any(self.password[n] for n in range(0,len(self.password)-1) if self.password[n]  == self.password[n+1])


""" Metodo 2 """
def Validate(password:str,rules:List[Dict[str,Union[str, int]]]):
   
    noMatch: list[str] = []
    SpecialChar: str = "!@#$%^&*()-+\/{}[]"

    valitation = {
        "minSize":  lambda x:  None if bool(len(password) >= x) else noMatch.append("minSize"),
        "minUppercase": lambda x: None if sum(1 for c in password if c.isupper()) >= x else noMatch.append("minUppercase"),
        "minLowercase": lambda x: None if sum(1 for c in password if c.islower()) >= x else noMatch.append("minLowercase"),
        "minDigit": lambda x: None if sum(1 for c in password if c.isdigit()) >= x else noMatch.append("minDigit"),
        "minSpecialChars" : lambda x: None if sum(1 for c in password if c in SpecialChar) >= x else noMatch.append("minSpecialChars"),
        "noRepeted": lambda x: None if any(password[n] for n in range(0,len(password)-1) if password[n]  == password[n+1] ) else noMatch.append("noRepeted")
    }

    for rule in rules:  
        
        if list(rule.values())[0] in list(valitation.keys()):
            
            valitation.get(rule["rule"],None)(int(rule["value"]))
            
    return (len(noMatch) == 0, noMatch)
            
app = FastAPI()


@app.post("/verify")
def read_root(Body: Body ):

    verify, noMatch = ValidatePassword().IsValide(Body.password,Body.rules)
    # verify, noMatch = Validate(Body.password,Body.rules)
    return {"verify": verify, "noMatch": noMatch}
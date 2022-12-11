from fastapi import FastAPI
from pydantic import BaseModel
from typing import List, Dict
from typing import Union
from typing import Callable

"""
    Esplicando o Codigo
"""


""" 
    Definindo o Body
    password : uma string
    rules : lista de dict com as regras

"""
class Body(BaseModel):
    password: str
    rules: List[Dict[str,Union[str, int]]]


""" 
        Metodo 1 
    Facil de leer e escalável
    
"""
class ValidatePassword:
    
    # Definindo tipos de variaveis globais 
    ## noMatch como uma lista de str
    ## password um string
    noMatch: list[str]
    password: str
    
    """ Criando a funçao para validar a senha"""
    #                                                     especicando tipo de retorno da funçao: tupla de (True/False,Lista)
    def IsValide(self,password: str, rules:List[Dict[str,Union[str, int]]]) -> tuple[bool,list[str]]:
        
        self.noMatch = []
        self.password = password
        
        """ trasformando a lista de dict 
        de rules = [{ "rule": "minSize","value": 3 }, { "minUppercase": 2 } ]
        em { "minSize" : 3, "minUppercase" : 2 }
        
        fiz a lista de dicionarios em um unico dicionario para ser mais facil 
        ps: explicação em baixo 
        """
        rulesDict : Dict[str,int]  =  dict((regra["rule"],int(regra["value"])) for regra in rules )


        # Em todas as verificaçoes/rule colocando o valor/value de cada e se nao exister o valor sera 0 (sempre valido)
        
        # rulesDict.get("minSize",0) retorna o valor de { "rule" : "minSize", "value": 2} ou 0
        
        if self.minSize(rulesDict.get("minSize",0)):
            # se a senha nao cumplir com o minSize, adiciono na lista "noMatch"
            self.noMatch.append("minSize")
        
        if self.minSpecialChars(rulesDict.get("minSpecialChars",0)):
            self.noMatch.append("minSpecialChars") 
        
        if self.minDigit(rulesDict.get("minDigit",0)):
            self.noMatch.append("minDigit")
        
        if self.minLowercase(rulesDict.get("minLowercase",0)):
            self.noMatch.append("minLowercase")
            
        if self.minUppercase(rulesDict.get("minUppercase",0)):
            self.noMatch.append("minUppercase")
    
        # Ja que noRepeted nao tem value so precisa verificar se esta ou nao no "rules"
        if "noRepeted" in rulesDict.keys():    
            if self.noRepeted():
                self.noMatch.append("noRepeted")
        
        return (len(self.noMatch) == 0, self.noMatch)
            
    """ Separei as Verificaçoes da senha para ficar mais facil se precisar adicionar mais no futuro """
    def minSize(self,value: int) -> bool:
        return len(self.password) < value
    
    def minUppercase(self,value: int) -> bool:
        return sum(1 for c in self.password if c.isupper()) < value
    
    def minLowercase(self,value: int)-> bool:
        return sum(1 for c in self.password if c.islower()) < value
    
    def minDigit(self,value: int) -> bool:
        return sum(1 for c in self.password if c.isdigit()) < value
        
    def minSpecialChars(self,value: int) -> bool:
        SpecialChar  = r"!@#$%^&*()-+\/{}[]"
        return sum(1 for c in self.password if c in SpecialChar) < value
    
    def noRepeted(self) -> bool:
        return  any(self.password[n] for n in range(0,len(self.password)-1) if self.password[n]  == self.password[n+1])


""" 
        Metodo 2
    mais rapido e com menor codigo
"""
def Validate(password:str,rules:List[Dict[str,Union[str, int]]]):
   
    noMatch: list[str] = []
    SpecialChar: str = r"!@#$%^&*()-+\/{}[]"

    """
    validation 
    
    um dicionario com chave os posiveis "rules"
    e o valor uma funçao lambda x: que faz a verificaçao e adiciona se noMach se nao for valido 
    
    
    """
    validation: dict[str,Callable[[int],None]] = {
        "minSize":  lambda x:  noMatch.append("minSize")  if  len(password) < x else None,
        "minUppercase": lambda x: noMatch.append("minUppercase") if  sum(1 for c in password if c.isupper()) < x else None,
        "minLowercase": lambda x: noMatch.append("minLowercase") if  sum(1 for c in password if c.islower()) < x else None,
        "minDigit": lambda x:  noMatch.append("minDigit") if sum(1 for c in password if c.isdigit()) < x else None,
        "minSpecialChars" : lambda x: noMatch.append("minSpecialChars") if  sum(1 for c in password if c in SpecialChar) < x else None,
        "noRepeted": lambda x: noMatch.append("noRepeted") if any(password[n] for n in range(0,len(password)-1) if password[n]  == password[n+1] ) else None
    }
    
    for rule in rules: 
        # Para cada rule no rules ele ativa o lambda para adicionar na lista noMatch
        """ 
        Exemplo
        
        digamos que rule = { "rule": "minSize","value": 3 }
        
        ele buscara o lambda no validation["minSize"](3) e ativara a validaçao
        """ 
        validation.get(rule["rule"],lambda: None)(int(rule["value"]))
            
    return (len(noMatch) == 0, noMatch)
            
"""
NOTA: Porque Fiz 2 metodos?

quando vi o problema que tinha que fazer, pensei rapidamente 2 metodos para fazer

o 1 primerio usando uma classe que pode se entender mais facilmente e se pode adicionar mais validaçoes facilmente
o 2 Muito rapido escrevendo o codigo (nao demorei nem 5 minutos para fazer) e o codigo se roda mais facil (nao faz verificaoes desnecesarias)

nao sabia qual seria o melhor para fazer entao decidi fazer os 2

atualmente a api esta usando o metodo 1 mas se quizer mudar so retirar os "###" na linha 164
"""

""" API """ 
          
app = FastAPI()

# Definindo a rota
@app.post("/verify")
def read_root(Body: Body ):
    
    # verify sendo um bool (True o False) e no Match sendo o a lista
    
    verify, noMatch = ValidatePassword().IsValide(Body.password,Body.rules)
    ### tambem funciona: verify, noMatch = Validate(Body.password,Body.rules)
    
    return {"verify": verify, "noMatch": noMatch}
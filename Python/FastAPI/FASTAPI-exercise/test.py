from fastapi.testclient import TestClient

from main import app

client = TestClient(app)



""" TEST 1 Senha Valida """
def test_validePassword():
    body = {"password":"1hi3Jo2ha/n2/",
            "rules": [
                {"rule": "minSize","value": 8},
                {"rule": "minSpecialChars","value": 2},
                {"rule": "minDigit","value": 4},
                {"rule": "minLowercase", "value": 4},
                {"rule": "minUppercase", "value": 1},
                {"rule": "noRepeted","value":0},
                ]
            }
    response = client.post("/verify",json=body)

    assert response.json() == {
        "verify": True,
        "noMatch": []
        }

""" Test 2 senha invalida """    
def test_invalidePassword():
    body = {"password":"aa",
            "rules": [
                {"rule": "minSize","value": 8},
                {"rule": "minSpecialChars","value": 2},
                {"rule": "minDigit","value": 4},
                {"rule": "minLowercase", "value": 4},
                {"rule": "minUppercase", "value": 1},
                {"rule": "noRepeted","value":0},
                ]
            }
    response = client.post("/verify",json=body)

    assert response.json() == {
        "verify": False,
        "noMatch": [
            "minSize",
            "minSpecialChars",
            "minDigit",
            "minLowercase", 
            "minUppercase",
            "noRepeted",
            ]
        }
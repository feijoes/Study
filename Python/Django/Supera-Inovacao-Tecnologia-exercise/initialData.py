from requests import post,Response
import json

with open("products.json") as f:
    data: list[dict[str,any]] = json.load(f)


for i in data:
    r : Response = post(url = "http://127.0.0.1:8000/produtos/",data=i)
 

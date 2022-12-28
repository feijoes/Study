# Desafio tecnico

## Setup projeto

Primeramente faça git clone do repo 

```
git clone https://github.com/feijoes/desafio.git
```

### Setup backend
abra um cmd (se estiver usando windows) 
e instale requiriments.txt

```pip
pip install -r ./backend/requirements.txt
```

Va para pasta backend\backend e crie um arquivo .env com algumas configuraçoes:

```
PASSWORD=<Senha do usuario>
USER=<Usuario>
SECRET_KEY=django-insecure-z=wd1wi1oyxpdobae(gm15weo2skwyqtwl$i%de*r(op6jpx=o 
NAMEDB=<Nome da database>
```
e com isso so precisa fazer o migrations com manage.py 
```cmd
python manage.py makemigrations
python manage.py migrate
```
agora so precisa rodar o servidor
```
python manage.py runserver
```
para adicionar o produtos iniciais va para a pasta inicial e execute o `initialData.py` (enquanto o servidor estiver rodando) para adicionar os produtos iniciais

### Setup frontend

abra otro cmd entre na pasta frontend , instale as dependecias  e execute 

```cmd
cd ./frontend/
npm i
npm run dev
```

### Explicação API

A principal url é em `http://127.0.0.1:8000/`
e as rotas são:
* `/register/`
Onde se fará o registro do usuario, se devera especificar o username,email e password
> Json Esperado em metodo POST
```json
{
  "username": "Pedro",
  "password": "senha123",
  "email" : "pcaladomoura@gmail.com"
}
```
> Json de retorno
```json
{
    "user": {
        "username": "Pedro",
        "email": "pcaladomoura@gmail.com"
    },
    "token": "82ea2298a5b076581744e5d7a7e4b590d61cd2137bc28eabb9c3dd3109552e13"
}
```
* `/login/`
Onde se fará o login do usuario, se devera especificar o username e password

> Json Esperado em metodo POST
```json
{
  "username": "Pedro",
  "password": "senha123",
}
```
> Json de retorno
```json
{
  "expiry": "2022-12-19T12:01:44.086582Z",
  "token": "5c1a1ac5dbc17c9b9c0748ca7fab8adb9377269ca2eba29185ccb5c38ccc6958"
}
```
* `/produtos/`
Onde se motrara os produtos

> Json Retorno em metodo GET
```json
[
    {
        "name": "Super Mario Odyssey",
        "price": 197.88,
        "score": 100,
        "image": "super-mario-odyssey.png"
    },
    {
        "name": "Call Of Duty Infinite Warfare",
        "price": 49.99,
        "score": 80,
        "image": "call-of-duty-infinite-warfare.png"
    }
]
```
pode passar o parametro `/produto/?sort=` que retornara os produtos ordenados por *price* ,*name* ou *score*


E Com metodo POST ira criar um produto
> Json esperado em metodo POST
```json
{
    "name": "Mortal Kombat XL",
    "price": 69.99,
    "score": 150,
    "image": "mortal-kombat-xl.png"
}
```
* `/static/`
aqui onde  servira os assets, como por exemplo `/static/fifa-18.png` tera a imagen do jogo fifa-18

#### A partir de aqui ira precisar adicionar no `headers` do request `"Authorization" : "Token 82ea2298a5b0..."`
* `/carrinho/`
aqui onde podera ver o seu atual carrinho de compras

No carrinho podera ver no json `"produtos"` onde seria uma lista de dict onde especificara o `produto` no carrinho e a `quantidade` do produto no carrinho
junto com o ``frete`` e ``subtotal``
> Json de retorno no metodo GET
```json
{
    "produtos": [
        {
            "produto": {
                "name": "Terra Média: Sombras de Mordor",
                "price": 79.99,
                "score": 50,
                "image": "terra-media-sombras-de-mordor.png"
            },
            "quantidade": 1
        },
    ],
    "frete": 10,
    "subtotal": 79.99
}
```
***quando o subtotal é >= 250 o frete retornado é 0***


Para adicionar produtos mande um json com a chave `"nomesProdutos"` 

com o valor um dict com `nome do produto : quantidade comprada`
> Json esperado para adicionar um produto no carrinho no metodo POST
```json
{
   "nomesProdutos":{
       "Call Of Duty Infinite Warfare": 2,
       "Terra Média: Sombras de Mordor": 1
    }
}
```
**Para remover um produto do carrinho**

mande um um request exatamente igual (metodo POST) so que coloco a quantidade comprada em numeros negativos

* `/logout/`

mande request com metodo POST e isso desativara o Token JWT usado.





Type 
  TAlfabeto = array [1..26] Of Char;

Const 
  MAX = 3 {valor entero mayor estricto que 0};

Type 
  TEspecie = (manzano, peral, naranjo);
  TArbol = Record

    identificador: Integer;
    especie: TEspecie;
    Case plaga: Boolean Of 
      true : (fumigado: Boolean);
      false: ()
  End;
  TCultivo = Record

    arboles: array [1..MAX] Of TArbol;
    tope: 0..MAX;
  End;
  TIDArbol = Record

    ids: array [1..MAX] Of Integer;
    tope: 0..MAX;
  End;

Type 
  ListaBin = ^NodoBin;
  NodoBin = Record
    bin: 0..1;
    sig: ListaBin;
  End;

procedure agregarNodo(var lista: ListaBin; bit: integer);
var
  nuevo: ListaBin;
begin
  New(nuevo);
  nuevo^.bin := bit;
  nuevo^.sig := lista;
  lista := nuevo;
end;

procedure liberarLista(var lista: ListaBin);
var
  actual: ListaBin;
begin
  while lista <> nil do
  begin
    actual := lista;
    lista := lista^.sig;
    Dispose(actual);
  end;
end;
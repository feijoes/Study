
Type 
  TipoLista = ^TipoCelda;
  TipoCelda = Record
    elemento: integer;
    siguiente: TipoLista;
  End;

Const N = 3;
(* entero mayor o igual que 3 *)

Type ArregloNum = array [1..N] Of Integer;

Const 
  MAX = 3 ; { entero mayor que 0 }

Type 
  tipo_estado = (libre, ocupada);
  tipo_rango = 1 .. 10;
  tipo_sala = Record

    capacidad : Integer;
    Case estado: tipo_estado Of 
      ocupada : (cantHoras: tipo_rango);
      libre : ()
  End;
  tipo_salas = Record

    salas : ARRAY[1..MAX] Of tipo_sala;
    cantidad : 0..MAX
  End;

Procedure InsertarInicio(Var lista: TipoLista; elem: Integer);

Var 
  nuevo: TipoLista;
Begin
  New(nuevo);
  nuevo^.elemento := elem;
  nuevo^.siguiente := lista;
  lista := nuevo;
End;

Procedure ImprimirLista(lista: TipoLista);
Begin
  While lista <> Nil Do
    Begin
      Write(lista^.elemento, ' ');
      lista := lista^.siguiente;
    End;
  WriteLn;
End;

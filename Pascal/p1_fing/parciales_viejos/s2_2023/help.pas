
Const MAXPREGUNTA = 3; { valor mayor que 0 }

Type 
  TOpcion = 'A' .. 'E';
  TRespuesta = Record
    Case responde : boolean Of 
      true : (opcion : TOpcion);
      false: ()
  End;
  RangoPregunta = 1 .. MAXPREGUNTA;
  TRespuestas = array [RangoPregunta] Of TRespuesta;
  TCorrectas = array [RangoPregunta] Of TOpcion;

Type 
  Lista = ^TipoCelda;
  TipoCelda = Record
    dato: real;
    sig: Lista
  End;
Procedure ImprimirLista(lis: Lista);
Begin
  While lis <> nil Do
    Begin
      writeln(lis^.dato:0:2);
      lis := lis^.sig;
    End;
End;
procedure agregarNodo(var lista: Lista; n: real);
var
  nuevo: Lista;
begin
  New(nuevo);
  nuevo^.dato := n;
  nuevo^.sig := lista;
  lista := nuevo;
end;

const MAX = 3 ; { valor mayor que 1 }
type
TEntero = record
digs : array [1..MAX] of '0'..'9';
tope : 0..MAX
end

Program act_9;

Const 
  M = 10; {valor entero mayor estricto a 0}
N = 1000; {valor entero mayor estricto a 0}
Type Factor = Record
  primo : 1..N;
  Case multiple : boolean Of 
    true: (exponente : 1..N);
    false : ();
End;

Type Descomp = Record
  factores : array [1..M] Of Factor;
  tope : 0..M;
End;

Var a: Factor;
var b: Descomp;

Procedure factorizacion (num : Integer; var listaFac : Descomp);
var value:integer;
var top,divisor :integer;

begin
    value:=num;
    top:=1;

    divisor:=2;

    while value >1  Do
    begin

    while (value mod divisor) = 0 Do
    begin
    
    value := value div divisor;
    listaFac.factores[top].primo := divisor;
    listaFac.factores[top].exponente:=listaFac.factores[top].exponente+1
    end;
    top:=top+1;
    divisor:=divisor +1;    
    end;

    listaFac.tope:=top;
end;

Begin


factorizacion(4,b);
writeln(b.tope)

End.


Program act_3;

Const 
  N = 5; {valor mayor estricto a 1}

Type 
  CadenaN = array [1..N] Of integer;

Var test, test2 : CadenaN;

Function cantMayores(cadn:CadenaN; num:integer) : integer;

Var i, cant: integer;
Begin
  cant := 0;
  For i:= 1 To N Do
    Begin
      If cadn[i] > num Then cant + = 1;
    End;
  cantMayores := cant;
End;
Function ordenado(cadn:CadenaN) : boolean;

Var i : integer;
Begin
  i := 1;
  While (i < N) And (cadn[i] <= cadn[i+1]) Do
    i := i + 1;
  ordenado := i = N
End;
Begin

  test[1] := 1;
  test[2] := 2;
  test[3] := 3;
  test[4] := 4;
  test[5] := 5;

  test2[1] := 1;
  test2[2] := 2;
  test2[3] := 5;
  test2[4] := 3;
  test2[5] := 4;

  writeln(cantMayores(test, 3));
  // Should be 2

  writeln(ordenado(test2));
  // Should be True

End.

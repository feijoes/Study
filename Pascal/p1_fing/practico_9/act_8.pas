
Program act_8;

Const 
  N = 5; {valor mayor estricto a 1}

Type 
  Digito = '0'..'9';
  Digitos = array [1..N] Of Digito;

Var test: Digitos;
Procedure leerArreglo(Var a:Digitos);

Var i: integer;
Begin
  writeln('Escribir digitos');
  For i:=1 To N Do
    read(a[i]);

End;
Function conversion(a:Digitos) : integer;

Var i,times, digit: integer;
Begin
  digit := 0;
  times := 1;
  For i:= N Downto 1 Do
    Begin
      digit := digit + (ord(a[i])-48) * times;
      times := times * 10;
    End;

  conversion := digit;
End;
Begin
  leerArreglo(test);
  writeln('digitos de test es ', conversion(test))
End.


Program test;

Type 
  PunteroInt = ^integer;
  PunteroChar = ^char;

Var 
  apun1, apun2: ^integer;
  apun3, apun4: PunteroChar;
  a: integer;
Begin
  a := 1;  { Assign a value to 'a' }

  { Assign the address of 'a' to the pointers }
  apun1^ := a;

  a := 3;
  writeln(apun1^);
End.

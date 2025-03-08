
Program act_11;

Type 
  Complejo = Record
    re, im : integer;
  End;
var test1,test2,test3 : Complejo;
procedure sumaComplejos (c1, c2 : Complejo; VAR c3 : Complejo);
Begin
    c3.re := c1.re + c2.re;
    c3.im := c1.im + c2.im;
End;
procedure multComplejos (c1, c2 : Complejo; VAR c3 : Complejo);
Begin
    c3.re := c1.re * c2.re - c1.im * c2.im;;
    c3.im := c1.im * c2.re - c2.im * c1.re;;
End;
begin
test1.re := 1;
test2.re := 2;
test2.im := 1;
test1.im := 1;

sumaComplejos(test1,test2, test3);

writeln('complejo re = ', test3.re, ' im = ', test3.im)
end.
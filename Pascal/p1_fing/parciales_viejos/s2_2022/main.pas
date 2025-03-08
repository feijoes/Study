
Program Parcial;
{$INCLUDE help.pas}
Function desplazamiento(alf: TAlfabeto): Integer;

Var location,diff,i,k: integer;
Begin
  i := 1;
  location := 0;
  While (i<= 26) And (location = 0) Do
    Begin
      If alf[i] = 'A'  Then location := i;
      i := i+1;
    End;
  If location > 13 Then
    diff := 26 - location+1
  Else If location < 13 Then
         diff := location-1
  Else
    diff := 13;
  i := 1;
  k := 0;
  While (i<= 26) And (diff <> -1) Do
    Begin
      If (i = location) Then
        Begin
          k := -diff;
        End;
      If Ord(alf[i]) <> Ord('A') + k + (diff) Then diff := -1;
      i := i+1;
      k := k+1;
    End;
  desplazamiento := diff;
End;

Procedure arbolesAFumigar(cultivo: TCultivo; esp: TEspecie; Var af: TIDArbol);

Var i: integer;
Begin
  af.tope := 0;
  For i:=1 To cultivo.tope Do
    Begin
      If (cultivo.arboles[i].especie = esp) And (cultivo.arboles[i].plaga) And (
         Not cultivo.arboles[i].fumigado) Then
        Begin
          af.tope := af.tope +1;
          af.ids[af.tope] := cultivo.arboles[i].identificador;
        End;
    End;
End;
Procedure actualizarCultivo(curados: TIDArbol; Var cultivo: TCultivo);

Var i,j: integer;
  modificado : Boolean;
Begin
  For i:= 1 To curados.tope Do
    Begin
      j := 1;
      modificado := false;
      While (j <= cultivo.tope) And (Not modificado)  Do
        Begin
          If (cultivo.arboles[j].identificador = curados.ids[i]) Then
            Begin
              modificado := true;
              cultivo.arboles[j].plaga := false;
            End;
          j := j+1;
        End;
    End;
End;
Function calcularNum(lista: ListaBin): Integer;
Var 
  contador, elevado: Integer;
Begin
  contador := 0;
  elevado := 1;
  While lista <> Nil Do
    Begin
      contador := contador + lista^.bin * elevado;
      elevado := elevado * 2;
      lista := lista^.sig
    End;
  calcularNum := contador
End;

Var 
  alfabeto: TAlfabeto;
  shift, i, case_despla,resultado: Integer;
  cultivo: TCultivo;
  afumigar: TIDArbol;
  lista: ListaBin;
Begin
  WriteLn('Ejemplo de uso de desplazamiento', sLineBreak);

  { Caso 1: Sin desplazamiento }
  For i := 1 To 26 Do
    alfabeto[i] := Chr(Ord('A') + i - 1);
  shift := desplazamiento(alfabeto);
  WriteLn('Caso 1: El desplazamiento es: ', shift);

  { Caso 2: Con desplazamiento }
  case_despla := 3;
  For i := 1 To 26 Do
    alfabeto[i] := Chr(Ord('A') + ((i + case_despla - 1) Mod 26));

  shift := desplazamiento(alfabeto);
  WriteLn('Caso 2: El desplazamiento es: ', shift);

  { Caso 3: Con desplazamiento mal }
  case_despla := 0;
  For i := 1 To 26 Do
    alfabeto[i] := Chr(Ord('A') + ((i + case_despla - 1) Mod 26));
  alfabeto[12] := 'B';
  shift := desplazamiento(alfabeto);
  WriteLn('Caso 3: El desplazamiento es: ', shift);
  WriteLn(sLineBreak);


  WriteLn('Ejemplo de uso de arbolesAFumigar', sLineBreak);
  { Ejemplo de inicialización de cultivo }
  cultivo.tope := 3;
  cultivo.arboles[1].identificador := 1;
  cultivo.arboles[1].especie := manzano;
  cultivo.arboles[1].plaga := true;
  cultivo.arboles[1].fumigado := false;

  cultivo.arboles[2].identificador := 2;
  cultivo.arboles[2].especie := peral;
  cultivo.arboles[2].plaga := true;
  cultivo.arboles[2].fumigado := false;

  cultivo.arboles[3].identificador := 3;
  cultivo.arboles[3].especie := naranjo;
  cultivo.arboles[3].plaga := false; { No tiene plaga }
  cultivo.arboles[3].fumigado := false;

  { Llamar a la función para identificar árboles a fumigar }
  arbolesAFumigar(cultivo, manzano, afumigar);

  { Mostrar resultados }
  Write('Identificadores de árboles de especie manzano a fumigar : ');
  For i := 1 To afumigar.tope Do
    Write(afumigar.ids[i]);
  WriteLn(sLineBreak);

  WriteLn('Ejemplo de uso de actualizarCultivo', sLineBreak);
  actualizarCultivo(afumigar, cultivo);
  arbolesAFumigar(cultivo, manzano, afumigar);

  { Mostrar resultados }
  Write('Identificadores de árboles de especie manzano a fumigar : ');
  For i := 1 To afumigar.tope Do
    Write(afumigar.ids[i]);
  WriteLn(sLineBreak);
  WriteLn(sLineBreak);
  WriteLn(sLineBreak);
  WriteLn(sLineBreak);
  WriteLn(sLineBreak);
  WriteLn(sLineBreak);
  WriteLn(sLineBreak);

  WriteLn('Ejemplo de uso de calcularNum', sLineBreak);
  lista := Nil;

  { Ejemplo para el número binario 11010 [0, 1, 0, 1, 1]}
  agregarNodo(lista, 1);
  agregarNodo(lista, 1);
  agregarNodo(lista, 0);
  agregarNodo(lista, 1);
  agregarNodo(lista, 0);
  write(lista^.bin);

  resultado := calcularNum(lista);
  WriteLn('El número decimal es: ', resultado); { Debe imprimir 26 }

  liberarLista(lista);
  WriteLn(sLineBreak);
End.

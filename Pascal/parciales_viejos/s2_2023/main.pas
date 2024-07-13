
Program Parcial;
{$INCLUDE help.pas}
Function puntaje(respuestas : TRespuestas; correctas : TCorrectas) : real;

Var cont :  real;
  i: integer;
Begin
  cont := 0;
  For i:=1 To MAXPREGUNTA Do
    Begin
      If (respuestas[i].responde) Then
        Begin
          If (respuestas[i].opcion = correctas[i]) Then
            cont := cont+2
          Else
            cont := cont-0.5;
        End;
    End;
  puntaje := cont;
End;
Function AlMenosN (n : Integer; opcion : TOpcion; respuestas : TRespuestas) :





                                                                         boolean
;

Var i, cont : integer;
Begin
  i := 1;
  cont := 0;
  While (i<= MAXPREGUNTA) And (cont < n) Do
    Begin
      If (respuestas[i].responde) Then
        Begin
          If (respuestas[i].opcion = opcion) Then
            cont := cont+1;
        End;
      i := i+1;
    End;
  AlMenosN := cont = n;
End;
Procedure NumeroAlCuadrado(Var lis : Lista; r : real);

Var temp_lis, nuevo : Lista;
  encontrado : Boolean;
Begin
  encontrado := false;
  temp_lis := lis;
  While (temp_lis^.sig <> Nil) And (Not encontrado) Do
    Begin
      If (temp_lis^.dato = r) Then
        Begin
          temp_lis^.dato := r*r;
          encontrado := true;
        End;
      temp_lis := temp_lis^.sig;
    End;
  If (Not encontrado) Then
    Begin
      new(nuevo);
      nuevo^.dato := r;
      nuevo^.sig := Nil;
      temp_lis^.sig := nuevo;
    End;
End;
Function iguales (n, m: TEntero): boolean;
i: integer;
diferente : Boolean;
Begin
  If n.tope = m.tope Then
    Begin
      diferente := false;
      i := 1;
      While (i<= n.tope) And Not diferente Do
        Begin
          If n.digs[i] <> m.digs[i] Then diferente := true;
          i := i+1;
        End;
    End
  Else
    diferente := false;
  iguales := diferente;
End;

Var 
  respuestas: TRespuestas;
  correctas: TCorrectas;
  i: integer;
  resultado,valor: real;
  ista: Lista;
Begin
  { Inicializar respuestas y correctas con algunos valores de ejemplo }
  respuestas[1].responde := true;
  respuestas[1].opcion := 'A';
  respuestas[2].responde := true;
  respuestas[2].opcion := 'B';
  respuestas[3].responde := false;

  correctas[1] := 'A';
  correctas[2] := 'C';
  correctas[3] := 'E';

  resultado := puntaje(respuestas, correctas);
  writeln('El puntaje total es: ', resultado:0:2);

  If AlMenosN(2, 'A', respuestas) Then
    writeln('Hay al menos 2 respuestas con la opción A')
  Else
    writeln('No hay al menos 2 respuestas con la opción A');

  ista := Nil;
  For i := 1 To 3 Do
    Begin
      agregarNodo(ista, i);
    End;

  writeln('Lista original:');
  ImprimirLista(ista);

  { Aplicar NumeroAlCuadrado y agregar un nuevo número }
  NumeroAlCuadrado(ista, 2);  { 2 ya está en la lista, se convertirá en 4 }
  NumeroAlCuadrado(ista, 5);  { 5 no está en la lista, se agregará }

  writeln('Lista modificada:');
  ImprimirLista(ista);
End.


Program Parcial;
{$INCLUDE help.pas}
Function docIguales (doc1, doc2: Documento): boolean;

Var i: integer;
  iguales: boolean;
Begin
  iguales := true;
  i := 1;
  While (i<=MaxDigito) And iguales Do
    Begin
      If doc1[i] <> doc2[i] Then iguales := false;
      i := i +1;
    End;
  docIguales := iguales;
End;
Function fechasIguales (fec1, fec2: Fecha): boolean;
Begin
  fechasIguales := (fec1.dia = fec2.dia) And (fec1.mes = fec2.mes) And (fec1.
                   anio = fec2.anio)
End;
Function estadoUsuario (doc: Documento; age: Agenda): Estado;

Var i: integer;
Begin
  i := 1;
  While (i <= age.tope) And Not (docIguales(age.usuarios[i].documento, doc)) Do
    i := i + 1;
  If (i <= age.tope) Then
    estadoUsuario := age.usuarios[i].est
  Else
    estadoUsuario := Ausente
End;
Procedure usuariosFecha (fec: Fecha; age: Agenda; Var atendidos: Agenda);

Var i: integer;
Begin
  atendidos.tope := 0;
  For i:=1 To age.tope Do
    Begin
      If (age.usuarios[i].est = Atendido) And fechasIguales(fec, age.usuarios[i]
         .fechaAtendido) Then
        Begin
          atendidos.tope := atendidos.tope +1;
          atendidos.usuarios[atendidos.tope] := age.usuarios[i];
        End;
    End;
End;

Procedure agregaPrincipio (elem: char; Var list: Lista);

Var nuevo : Lista;
Begin
  New(nuevo);
  nuevo.elem := elem;
  nuevo.sig := list;
  list := nuevo;
End;
Procedure soloAlfaNumericos (list: Lista; Var resultado: Lista);

Var p : Lista;
Begin
  resultado := Nil;
  p := list;
  While p <> Nil Do
    Begin
      If (esAlfaNumerico (p^.elem)) Then
        agregaPrincipio (p^.elem, resultado);
      p := p^.sig
    End
End;

Var 
  i : integer;
  documento1, documento2, doc: Documento;
  sonIguales: boolean;
  fecha1, fecha2: Fecha;
  agend,atendidos: Agenda;
  estad: Estado;
Begin
  WriteLn('Ejemplo de uso docIguales' + sLineBreak);


  For i:= 1 To MaxDigito Do
    Begin
      documento1[i] := i;
      documento2[i] := i;
    End;

  // Caso que son iguales
  sonIguales := docIguales(documento1, documento2);

  If sonIguales Then
    writeln('Caso 1: Los documentos son iguales.')
  Else
    writeln('Caso 1: Los documentos son diferentes.');


  // Caso que no son iguales
  documento2[MaxDigito] := 0;
  sonIguales := docIguales(documento1, documento2);

  If sonIguales Then
    writeln('Caso 2: Los documentos son iguales.')
  Else
    writeln('Caso 2: Los documentos son diferentes.');

  WriteLn(sLineBreak+ 'Ejemplo de uso fechasIguales' +  sLineBreak);
  // Caso 1: Las fechas son iguales
  fecha1.dia := 15;
  fecha1.mes := 7;
  fecha1.anio := 2024;

  fecha2.dia := 15;
  fecha2.mes := 7;
  fecha2.anio := 2024;

  sonIguales := fechasIguales(fecha1, fecha2);

  If sonIguales Then
    writeln('Caso 1: Las fechas son iguales.')
  Else
    writeln('Caso 1: Las fechas son diferentes.');

  // Caso 2: Las fechas son diferentes
  fecha1.dia := 15;
  fecha1.mes := 7;
  fecha1.anio := 2024;

  fecha2.dia := 16;
  fecha2.mes := 7;
  fecha2.anio := 2024;

  sonIguales := fechasIguales(fecha1, fecha2);


  If sonIguales Then
    writeln('Caso 2: Las fechas son iguales.')
  Else
    writeln('Caso 2: Las fechas son diferentes.');

  WriteLn(sLineBreak+ 'Ejemplo de uso estadoUsuario' +  sLineBreak);
  agend.tope := 2;

  // Usuario 1
  agend.usuarios[1].documento[1] := 1;
  agend.usuarios[1].documento[2] := 2;
  agend.usuarios[1].documento[3] := 3;
  agend.usuarios[1].documento[4] := 4;
  agend.usuarios[1].est := Agendado;
  agend.usuarios[1].fechaAsignada.dia := 15;
  agend.usuarios[1].fechaAsignada.mes := 7;
  agend.usuarios[1].fechaAsignada.anio := 2024;

  // Usuario 2
  agend.usuarios[2].documento[1] := 5;
  agend.usuarios[2].documento[2] := 6;
  agend.usuarios[2].documento[3] := 7;
  agend.usuarios[2].documento[4] := 8;
  agend.usuarios[2].est := Atendido;
  agend.usuarios[2].fechaAtendido.dia := 10;
  agend.usuarios[2].fechaAtendido.mes := 6;
  agend.usuarios[2].fechaAtendido.anio := 2024;

  // Caso 1: Documento existente
  doc[1] := 1;
  doc[2] := 2;
  doc[3] := 3;
  doc[4] := 4;
  estad := estadoUsuario(doc, agend);
  writeln('Caso 1: El estado del usuario es: ', Ord(estad));
  // Imprimirá 0 (Agendado)

  // Caso 2: Documento no existente
  doc[1] := 9;
  doc[2] := 9;
  doc[3] := 9;
  doc[4] := 9;
  estad := estadoUsuario(doc, agend);
  writeln('Caso 2: El estado del usuario es: ', Ord(estad));
  // Imprimirá 2 (Ausente)

  WriteLn(sLineBreak+ 'Ejemplo de uso usuariosFecha' +  sLineBreak);

  agend.tope := 3;

  // Usuario 1
  agend.usuarios[1].documento[1] := 1;
  agend.usuarios[1].documento[2] := 2;
  agend.usuarios[1].documento[3] := 3;
  agend.usuarios[1].documento[4] := 4;
  agend.usuarios[1].est := Agendado;
  agend.usuarios[1].fechaAsignada.dia := 15;
  agend.usuarios[1].fechaAsignada.mes := 7;
  agend.usuarios[1].fechaAsignada.anio := 2024;

  // Usuario 2
  agend.usuarios[2].documento[1] := 5;
  agend.usuarios[2].documento[2] := 6;
  agend.usuarios[2].documento[3] := 7;
  agend.usuarios[2].documento[4] := 8;
  agend.usuarios[2].est := Atendido;
  agend.usuarios[2].fechaAtendido.dia := 10;
  agend.usuarios[2].fechaAtendido.mes := 7;
  agend.usuarios[2].fechaAtendido.anio := 2024;

  // Usuario 3
  agend.usuarios[3].documento[1] := 9;
  agend.usuarios[3].documento[2] := 0;
  agend.usuarios[3].documento[3] := 1;
  agend.usuarios[3].documento[4] := 2;
  agend.usuarios[3].est := Atendido;
  agend.usuarios[3].fechaAtendido.dia := 10;
  agend.usuarios[3].fechaAtendido.mes := 7;
  agend.usuarios[3].fechaAtendido.anio := 2024;

  fecha1.dia := 10;
  fecha1.mes := 7;
  fecha1.anio := 2024;

  atendidos.tope := 0;

  usuariosFecha(fecha1, agend, atendidos);

  // Mostramos los usuarios atendidos
  writeln('Usuarios atendidos el ', fecha1.dia, '/', fecha1.mes, '/', fecha1.
          anio,
          ':');
  For i := 1 To atendidos.tope Do
    Begin
      writeln('Usuario ', i, ': Documento ', atendidos.usuarios[i].documento[1],
              atendidos.usuarios[i].documento[2], atendidos.usuarios[i].
              documento[3],
              atendidos.usuarios[i].documento[4]);
    End;
End.

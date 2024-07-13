
Program Parcial;
{$INCLUDE help.pas}



Function AnteriorMasPosterior(a: ArregloNum): Integer;

Var i,location: Integer;
Begin
  i := 2;
  location := 0;
  While (i<=N-1) And (location = 0) Do
    Begin
      If a[i] = a[i-1] + a[i+1] Then location := i;
      i := i+1;
    End;
  AnteriorMasPosterior := location;
End;

Procedure ElimElemPos (Var lista: TipoLista; pos: Integer);

Var temp_lista1, temp_lista2 : TipoLista;
  i: integer;
Begin
  i := 1;
  temp_lista1 := lista;
  While (temp_lista1 <> Nil) And (i < pos-1) Do
    Begin
      temp_lista1 := temp_lista1^.siguiente;
      i := i+1;
    End;
  If (temp_lista1 <> Nil) And (temp_lista1^.siguiente <> Nil) Then
    Begin
      temp_lista2 := temp_lista1^.siguiente;
      temp_lista1^.siguiente := temp_lista2^.siguiente;
      Dispose(temp_lista2);
    End;
End;

Function salasLibres (salones: tipo_salas; total: Integer): Integer;

Var i, salas_disponibles : integer;
Begin
  salas_disponibles := 0;
  For i:= 1 To salones.cantidad Do
    Begin
      If (salones.salas[i].capacidad = total) And (salones.salas[i].estado =
         libre) Then salas_disponibles := salas_disponibles+1;
    End;
  salasLibres := salas_disponibles;
End;
Procedure elimSala (Var salones : tipo_salas; horas : tipo_rango);
Var i, location: integer;
Begin
  i := 1;
  location := 0;
  While (i<= salones.cantidad) And (location = 0) Do
    Begin
      If (salones.salas[i].estado = ocupada) And (salones.salas[i].cantHoras = horas) Then location := i;
    End;
  If location <> 0 Then
    Begin
      For i:= location To salones.cantidad -1  Do salones.salas[i] := salones.salas[i + 1];
      salones.cantidad := salones.cantidad -1;
    End;
End;

Var 
  arr,arr2: ArregloNum;
  pos,i : Integer;
  lista: TipoLista;
  misSalas: tipo_salas;
  totalSalasLibres: Integer;
Begin
  (* Ejemplo de uso AnteriorMasPosterior *)
  WriteLn('Ejemplo de uso AnteriorMasPosterior');
  arr[1] := 3;
  arr[2] := 8;
  arr[3] := 5;

  pos := AnteriorMasPosterior(arr);

  If pos <> 0 Then
    WriteLn('Caso 1: Elemento en la posición ', pos, ' cumple la condición.' +
            sLineBreak)
  Else
    WriteLn('Caso 1: Ningún elemento cumple la condición.' + sLineBreak);

  (* Ejemplo de uso AnteriorMasPosterior: que no cumple la condición *)
  arr2[1] := 1;
  arr2[2] := 3;
  arr2[3] := 1;

  pos := AnteriorMasPosterior(arr2);

  If pos <> 0 Then
    WriteLn('Caso 2: Elemento en la posición ', pos, ' cumple la condición.' +
            sLineBreak)
  Else
    WriteLn('Caso 2: Ningún elemento cumple la condición.'+ sLineBreak);

 (* Ejemplo de uso ElimElemPos *)
  WriteLn('Ejemplo de uso ElimElemPos' +  sLineBreak);
  lista := Nil;

  (* Insertar elementos en la lista *)
  InsertarInicio(lista, 3);
  InsertarInicio(lista, 2);
  InsertarInicio(lista, 1);

  WriteLn('Caso 1: Lista antes de eliminar:');
  ImprimirLista(lista);

  (* Eliminar el elemento en la posición 2 *)
  ElimElemPos(lista, 2);

  WriteLn('Caso 1: Lista después de eliminar el elemento en la posición 2:');
  ImprimirLista(lista);
  write(sLineBreak);
  lista := Nil;

  (* Insertar elementos en la lista *)
  InsertarInicio(lista, 4);
  InsertarInicio(lista, 3);
  InsertarInicio(lista, 2);
  InsertarInicio(lista, 1);

  WriteLn('Caso 2 Lista antes de eliminar:');
  ImprimirLista(lista);

  (* Eliminar el elemento en la posición 4 *)

  ElimElemPos(lista, 4);

  WriteLn('Caso 2: Lista después de eliminar el elemento en la posición 4:');
  ImprimirLista(lista);

  WriteLn(sLineBreak);
  WriteLn('Ejemplo de uso salasLibres' +  sLineBreak);
  { Inicializamos las salas }
  misSalas.cantidad := 3;
  misSalas.salas[1].capacidad := 50;
  misSalas.salas[1].estado := libre;
  misSalas.salas[2].capacidad := 100;
  misSalas.salas[2].estado := ocupada;
  misSalas.salas[2].cantHoras := 5;
  misSalas.salas[3].capacidad := 50;
  misSalas.salas[3].estado := libre;

  { Llamamos a la función salasLibres }
  totalSalasLibres := salasLibres(misSalas, 50);

  { Mostramos el resultado }
  WriteLn('Total de salas libres con capacidad de 50: ', totalSalasLibres);
  WriteLn('Ejemplo de uso salasLibres' +  sLineBreak);
  { Inicializamos las salas }
  misSalas.cantidad := 3;
  misSalas.salas[1].capacidad := 50;
  misSalas.salas[1].estado := ocupada;
  misSalas.salas[1].cantHoras := 5;
  misSalas.salas[2].capacidad := 100;
  misSalas.salas[2].estado := ocupada;
  misSalas.salas[2].cantHoras := 3;
  misSalas.salas[3].capacidad := 50;
  misSalas.salas[3].estado := libre;

  { Llamamos al procedimiento elimSala }
  elimSala(misSalas, 5);

  { Mostramos el estado de las salas después de la eliminación }
  WriteLn('Cantidad de salas después de eliminación: ', misSalas.cantidad);
  For i := 1 To misSalas.cantidad Do
    Begin
      Write('Sala ', i, ': Capacidad = ', misSalas.salas[i].capacidad,
            ', Estado = ');
      If misSalas.salas[i].estado = libre Then
        WriteLn('libre')
      Else
        WriteLn('ocupada, Horas = ', misSalas.salas[i].cantHoras);
    End;
End.

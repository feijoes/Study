Program act_2;

Const 
  MAXPERSONAS = 2; {valor entero mayor estricto a 0}
  MAXCAD = 9999; {valor entero mayor estricto a 0}

Type 
  Cadena = Record
    letras : array [1..MAXCAD] Of char;
    largo : 0..MAXCAD;
  End;
  Fecha = Record
    dia : 1..31;
    mes : 1..12;
    anio : 0..maxint;
  End;
  Persona = Record
    nombre : Cadena;
    fechNac : Fecha;
    indMadre, indPadre : 0..MAXPERSONAS;
  End;
  Familia = Record
    pers : array[1..MAXPERSONAS] Of Persona;
    tope : 0..MAXPERSONAS;
  End;
  
Function cadenasIguales(cad1, cad2: Cadena): Boolean;
Var
  isEqual: boolean;
  i: integer;
Begin
  isEqual := cad1.largo = cad2.largo;

  If Not isEqual Then
  Begin
    i := 1;
    While (i <= cad1.largo) And (isEqual) Do
    Begin
      isEqual := cad1.letras[i] = cad2.letras[i];
      i := i + 1;
    End;
  End;
  cadenasIguales := isEqual;
End;

Procedure desplegarCadena(cad: Cadena);
Var
  i: integer;
Begin
  
  writeln('El nombre de la cadena es: ', cad.letras);

End;

Procedure antepasados(usted: Cadena; historia: Familia);
Var
  i, padre, madre: integer;
  found: boolean;
Begin
  i := 1;
  found := False;
  While (i <= historia.tope) And (Not found) Do
  Begin
    If cadenasIguales(usted, historia.pers[i].nombre) Then
    Begin
        
      padre := historia.pers[i].indPadre;
      madre := historia.pers[i].indMadre;
      found := True;
    End;
    i := i + 1;
  End;
for i:= 1 to 10 Do
  begin
     writeln('cad largo: ',historia.pers[padre].nombre.letras[i]);
  end;
  if madre > 0 then desplegarCadena(historia.pers[madre].nombre);
  
  if padre > 0 then desplegarCadena(historia.pers[padre].nombre);
End;

Var
  fam: Familia;
  yo: Cadena;
begin
  fam.tope := 2; 

  { Inicialización de la primera persona }
  fam.pers[1].nombre.largo := 3;
  fam.pers[1].nombre.letras[1] := 'A';
  fam.pers[1].nombre.letras[2] := 'n';
  fam.pers[1].nombre.letras[3] := 'a';
  fam.pers[1].fechNac.dia := 12;
  fam.pers[1].fechNac.mes := 5;
  fam.pers[1].fechNac.anio := 1980;
  fam.pers[1].indMadre := 0; 
  fam.pers[1].indPadre := 2; 

  { Inicialización de la segunda persona }
  fam.pers[2].nombre.largo := 4;
  fam.pers[2].nombre.letras[1] := 'J';
  fam.pers[2].nombre.letras[2] := 'o';
  fam.pers[2].nombre.letras[3] := 's';
  fam.pers[2].nombre.letras[4] := 'e';
  fam.pers[2].nombre.letras[5] := 'r';
  fam.pers[2].fechNac.dia := 5;
  fam.pers[2].fechNac.mes := 10;
  fam.pers[2].fechNac.anio := 1975;
  fam.pers[2].indMadre := 0;
  fam.pers[2].indPadre := 0;

  { Inicialización de la persona "yo" }
  yo.largo := 3;
  yo.letras[1] := 'A';
  yo.letras[2] := 'n';
  yo.letras[3] := 'a';

  antepasados(yo, fam);
End.

Function todosTienenFormatoEnLinea ( tfmt : TipoFormato; ini, fin : RangoColumna
                                    ; ln : Linea ) : boolean;

{ Retorna true solo si todos los caracteres de `ln` entre las columnas `ini` y `fin`, 
  incluídos los extremos, tienen el formato `tfmt`. En otro caso retorna false. 

  Precondiciones: 1 <= ini <= ln.tope
                  1 <= fin <= ln.tope }

Var i: integer;
  tiene_formato: boolean;
Begin
  i := ini;
  tiene_formato := false;
  While (i <= fin) And Not tiene_formato Do
    Begin
      tiene_formato := ln.cars[i].fmt[tfmt] = false;
      i := i+1;
    End;
  todosTienenFormatoEnLinea := Not tiene_formato;

End;
Procedure aplicarFormatoEnLinea ( tfmt : TipoFormato; ini, fin :
                                 RangoColumna
                                 ; Var ln : Linea );

{ Aplica el formato `tfmt` a los caracteres de `ln` entre las columnas `ini` y `fin`, 
  incluídos los extremos. 
  Si todos los carácteres ya tienen el tipo de formato `tfmt`, en lugar de aplicarlo 
  lo quita.

  Precondiciones: 1 <= ini <= ln.tope
                  1 <= fin <= ln.tope }

Var i: integer;
  quitar: boolean;
Begin

  quitar := Not todosTienenFormatoEnLinea(tfmt, ini, fin, ln);
  For i := ini To fin Do
    Begin
      ln.cars[i].fmt[tfmt] :=  quitar;
    End;
End;



Function contarCaracteresEnTexto ( txt : Texto ) : integer;
{ Retorna la cantidad de caracteres que tiene el texto `txt` }

Var cantidad: integer;
  p: Texto;
Begin
  p := txt;
  cantidad := 0;
  While (p <> Nil) Do
    Begin
      cantidad := cantidad + p^.info.tope;
      p := p^.sig;
    End;
  contarCaracteresEnTexto := cantidad
End;


Procedure buscarCadenaEnLineaDesde(c: Cadena; ln: Linea; desde: RangoColumna; Var pc: PosibleColumna);
{ Busca la primera ocurrencia de la cadena `c` en la línea `ln` a partir de la 
  columna `desde`. Si la encuentra, retorna en `pc` la columna en la que inicia. 

  Precondiciones: 1 <= desde <= ln.tope }

Var
  i, k, location: integer;
  matchFound: boolean;
Begin
  i := desde;
  location := -1;
  
  While (i <= ln.tope) And (location < 0) Do
  Begin
    If c.cars[1] = ln.cars[i].car Then
    Begin
      matchFound := true;
      k := i;
      While (matchFound) And (k - i + 1 <= c.tope) And (k <= ln.tope) Do
      Begin
        If ln.cars[k].car <> c.cars[k - i + 1] Then
          matchFound := false;
        k := k + 1;
      End;
      If matchFound And (k - i = c.tope) Then
        location := i;
    End;
    i := i + 1;
  End;
  If location > 0 Then
  Begin
    pc.esColumna := true;
    pc.col := location;
  End
  Else pc.esColumna := false;
End;



Procedure buscarCadenaEnTextoDesde ( c : Cadena; txt : Texto; desde : Posicion
                                    ; Var pp : PosiblePosicion );

{ Busca la primera ocurrencia de la cadena `c` en el texto `txt` a partir de la 
  posición `desde`. Si la encuentra, retorna en `pp` la posición en la que incia. 
  La búsqueda no encuentra cadenas que ocupen más de una línea.

  Precondiciones: 1 <= desde.linea <= cantidad de líneas 
                  1 <= desde.columna <= tope de línea en desde.linea }

Var i, linea_contador: integer;
  temp_p: Posicion;
  pc: PosibleColumna;
  temp_txt: Texto;
  posicion_encontrada: boolean;
Begin
  linea_contador := desde.linea;
  temp_txt := ubicarLineaEnTexto(txt,desde.linea);
  posicion_encontrada:= false;
  While (temp_txt <> Nil) And not posicion_encontrada Do
    Begin
      buscarCadenaEnLineaDesde(c, temp_txt^.info, desde.columna, pc);
      If pc.esColumna Then
        Begin
          posicion_encontrada := true;
          pp.esPosicion := true;
          pp.p.linea := linea_contador;
          pp.p.columna := pc.col;
        End
      Else
        Begin
          linea_contador := linea_contador + 1;
          temp_txt := temp_txt^.sig;
          desde.columna := 1;
        End;
    End;
  If Not posicion_encontrada Then
    pp.esPosicion := false;
End;


Procedure insertarCadenaEnLinea ( c : Cadena; columna : RangoColumna
                                 ; Var ln : linea; Var pln : PosibleLinea );

{ Inserta la cadena `c` a partir de la `columna` de `ln`, y desplaza hacia la derecha 
  a los restantes caracteres de la línea. Los carácteres insertados toman el formato 
  del carácter que ocupaba la posición `columna` en la línea. Si la columna es 
  `ln.tope+1`, entonces queda sin formato.
  Si (c.tope + lin.tope) supera `MAXCOL`, los carácteres sobrantes se retornan (en
  orden) en la posible línea `pln`.
 
  Precondiciones:  1 <= columna <= ln.tope+1
                   columna <= MAXCOL
                   c.tope + columna <= MAXCOL  }

Var i: integer;
  nueva_linea : Linea;
  temp_caracter: Caracter;
Begin
  nueva_linea.tope := 0;
  If columna < ln.tope+1 Then temp_caracter.fmt := ln.cars[columna].fmt;
  For i:= ln.tope + c.tope Downto columna+c.tope Do
    Begin
      If i > MAXCOL Then
        Begin
          nueva_linea.tope := nueva_linea.tope +1;
          nueva_linea.cars[i - MAXCOL] := ln.cars[i - c.tope];
        End
      Else
        Begin
          ln.cars[i] := ln.cars[i - c.tope];
        End;
    End;
  For i:= 1 To c.tope Do
    Begin
      temp_caracter.car := c.cars[i];
      ln.cars[i + columna-1] := temp_caracter;
    End;
  ln.tope := ln.tope + c.tope - nueva_linea.tope;
  pln.esLinea := nueva_linea.tope > 0;
  pln.l := nueva_linea;
End;


Procedure insertarLineaEnTexto ( ln : Linea; nln : integer; Var txt : Texto );
{ Inserta la línea `ln` en la posición `nlin` del texto `txt`.

  Precondiciones: 1 < nln <= cantidad de líneas del texto + 1
}
Var temp_txt1, temp_txt2,temp_txt3 : Texto;
Begin
  New(temp_txt3);
  temp_txt1 := ubicarLineaEnTexto(txt, nln-1);
  temp_txt2 := ubicarLineaEnTexto(txt, nln);
  temp_txt3^.info := ln;
  temp_txt3^.sig := temp_txt2;
  temp_txt1^.sig := temp_txt3;
  
End;

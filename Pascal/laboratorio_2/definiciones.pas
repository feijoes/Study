
{$mode objfpc}{$H+}

uses
  SysUtils;

{ Constantes }
{ --------------------------------------------------- }
const

   MAXCOL = 80;       { cota de columnas de un archivo }
   MAXCAD = 60;       { cota de cadena de caracteres }



   { códigos de escape ANSI, usados internamente para el formato de impresión }
   ESC       = #27;
   Bold      = ESC + '[1m';
   Italics   = ESC + '[3m';
   Underline = ESC + '[4m';
   Res       = ESC + '[0m';

{ Tipos }
{ --------------------------------------------------- }

type
   
   { formato del texto }
   TipoFormato = ( Neg, Ita, Sub );
   Formato     = array [TipoFormato] of boolean;
   
   { un carácter en un texto incluye su formato }
   Caracter	= record
		     car : char;
		     fmt : Formato
		  end;



   { arreglo con tope que representa a una línea  }
   RangoColumna = 1..MAXCOL;
   Linea	= record  
		     cars : array [RangoColumna] of Caracter;
		     tope : 0..MAXCOL
		  end;	  

   PosibleLinea = record case esLinea :  boolean of
		      true  : (l: Linea);
		      false : ()
		  end;

   { lista de líneas, que representa a un texto }
   Texto	= ^NodoLinea; 
   NodoLinea	= record  
		     info : Linea;
		     sig  : Texto
		  end;

   { posición en el texto }
   Posicion	= record
		     linea    : 1 .. maxint;
		     columna  : RangoColumna
		  end;

   PosiblePosicion = record case esPosicion:  boolean of
		      true  : (p: Posicion);
		      false : ()
		     end;

   PosibleColumna = record case esColumna:  boolean of
		      true  : (col: 1 .. MAXCOL);
		      false : ()
		    end;

   { cadena de carácterers }
   Cadena	= record
		     cars : array [1..MAXCAD] of char;
		     tope : 0 .. MAXCAD
		  end;


{ Subprogramas }
{ --------------------------------------------------- }

function ubicarLineaEnTexto ( txt: Texto; nln: integer ) : Texto;
{ Devuelve un puntero al texto en la línea numero `nln`, comenzando en 1.
  Si el texto no tiene una línea en la posición `nln`, devuelve `NIL`. }
begin
   if nln <= 0 then ubicarLineaEnTexto := NIL
   else
   begin
      while (txt <> NIL) and (nln <> 1) do
      begin
	 txt := txt^.sig; nln := nln - 1
      end;
      ubicarLineaEnTexto := txt
   end
end;



{ Subprogramas  de escritura }
{ --------------------------------------------------- }

procedure mostrarCaracter (c : Caracter);
{ Muestra el caracter c formateado }
begin
   if c.fmt[Neg] then write(Bold);
   if c.fmt[Ita] then write(Italics);
   if c.fmt[Sub] then write(Underline);
   write(c.car);
   write(Res)
end;

procedure mostrarLinea (ln : Linea);
{ Muestra la línea ln formateada }
var i : integer;
begin
   for i := 1 to ln.tope do mostrarCaracter(ln.cars[i]);
   writeln
end;

procedure mostrarLineaCol (ln : Linea; n:integer);
{ Muestra la línea ln formateada e indica un número de columna }
var k : integer;
begin
   mostrarLinea (ln);
   for k := 1 to n-1 do write (' ');
   writeln ('^')
end;

procedure mostrarTexto (t : Texto);
{ Muestra el texto t }
var linea: integer;
begin
   linea := 1;
   while t <> NIL do
   begin
      write (linea:0, '. ');
      mostrarLinea (t^.info);
      t := t^.sig; linea := 1 + linea
   end
end;

procedure mostrarTipoFormato (tf : TipoFormato);
{ Muestra el tipo de formato tf }
begin
   case tf of
     Neg : write('negrita');
     Ita : write('itálica');
     Sub : write('subrayado');
   end  
end;

procedure mostrarFormato (f : Formato);
{ Muestra el formato f, donde:
  nis significa que tiene negrita, itálica y subrayado
  si en lugar de n muestra -, entonces no tiene negrita
  si en lugar de i muestra -, entonces no tiene itálica
  si en lugar de s muestra -, entonces no tiene subrayado }
begin
   if f[Neg] then write('n') else write('-');
   if f[Ita] then write('i') else write('-');
   if f[Sub] then write('s') else write('-')
end;

procedure mostrarFormatoTexto (t : Texto);
{ Muestra el formato del texto t }
var i : integer;
begin
   while t <> NIL do
   begin
      write('|');
      for i := 1 to t^.info.tope do
      begin
	 mostrarFormato(t^.info.cars[i].fmt);
	 write('|')
      end;
      writeln;
      t := t^.sig
   end
end;

procedure mostrarPosiblePosicion (p : Posibleposicion );
{ Muestra la posible posición p, si no es posición indica que no se encuentra }
begin
   with p do
      if esPosicion then writeln ('Línea:', p.linea:0, ' Columna:', p.columna:0)
      else writeln ('No se encuentra')
end;


procedure mostrarPosibleLinea (p : PosibleLinea);
{ Muestra la posible línea p, si no es línea indica que no se encuentra }
begin
   with p do
      if esLinea then mostrarLinea (p.l)
      else writeln ('No se encuentra')
end;


procedure mostrarPosibleColumna (p : PosibleColumna );
{ Muestra la posible columna p, si no es columna indica que no se encuentra }
begin
   with p do
      if esColumna then	writeln('Columna:', p.col)
      else writeln ('No se encuentra')
end;


{ Subprogramas  de lectura }
{ --------------------------------------------------- }

procedure leerCadena (var c : Cadena);
{ Lee cadena desde entrada estándar. 
  El salto de línea indica el fin de la cadena. }
begin
   with c do
   begin
      tope := 0;
      while not eoln do
      begin
	 tope := 1 + tope;
	 read (cars [tope])
      end;
      readln
   end
end;

procedure leerLinea (var l : Linea);
{ Lee cadena desde entrada estándar. 
  El salto de línea indica el fin de la cadena. }
begin
   with l do
   begin
      tope := 0;
      while not eoln do
      begin
	 tope := 1 + tope;
         read (cars[tope].car);
         cars[tope].fmt[Neg] := false;
         cars[tope].fmt[Ita] := false;
         cars[tope].fmt[Sub] := false;         
      end;
      readln
   end
end;

function leerTipoFormato () : TipoFormato;
{ Lee un tipo de formato como un número desde la entrada estándar.
  0 significa negrita, 1 itálica y 2 subrayado. }
var fmt	: integer;
begin
   readln (fmt);
   leerTipoFormato := TipoFormato(fmt)
end;



procedure leerTexto (var t : Texto);
{ Lee de la entrada el nombre de un archivo y luego lee un texto de ese archivo. }

type ListaFirstLast = record first, last : Texto end;

   procedure leeRenglon (var f :text; var lin : linea);
   begin
      with lin do
      begin
	 tope := 0;
	 while not eoln (f) and not eof (f) and (tope < MAXCOL) do
	 begin
	    inc(tope);
	    read(f, cars[tope].car);
	    cars[tope].fmt[Neg] := false;
	    cars[tope].fmt[Ita] := false;
	    cars[tope].fmt[Sub] := false
	 end;
	 readln (f)
      end
   end;			 

   procedure inicializar (var ls : ListaFirstLast);
   begin ls.first := nil; ls.last := nil end;

   procedure insertarEnListaVacia (var f :text; var ls : ListaFirstLast) ;
   var t				 : Texto;
   begin
      new (t); leeRenglon (f, t^.info);
      ls.first := t; ls.last := t
   end;

   procedure insertarEnListaNoVacia (var f :text; var ls : ListaFirstLast);
   var t: Texto;
   begin
      new (t); leeRenglon (f, t^.info);
      ls.last^.sig := t; ls.last := t
   end;

var f: text;
    nombre  : string;
    ls : ListaFirstLast;
begin

   readln(nombre);
   assign(f, nombre);
   reset(f); 

   inicializar (ls);

   if not eof (f) then
   begin
      insertarEnListaVacia (f, ls);
      while not eof(f) do insertarEnListaNoVacia (f, ls);
      ls.last^.sig := nil
   end;

   close (f);
   t := ls.first
   
end;


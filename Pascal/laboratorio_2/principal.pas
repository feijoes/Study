program principal;

{ Con esta directiva queda incluido el archivo definiciones.pas }
{$INCLUDE definiciones.pas}

{ Con esta directiva queda incluido el archivo tarea2.pas }
{$INCLUDE tarea2.pas}


function leerOpcion: integer;
var opcion : integer;
begin
   writeln('--------------------------------');
   writeln('Ingrese Opción');
   writeln('--------------------------------');
   writeln('0=fin');
   writeln('1=todosTienenFormatoEnLinea');
   writeln('2=aplicarFormatoEnLinea');
   writeln('3=contarCaracteresEnTexto');
   writeln('4=buscarCadenaEnLineaDesde');
   writeln('5=buscarCadenaEnTextoDesde');
   writeln('6=insertarCadenaEnLinea');
   writeln('7=insertarLineaEnTexto');
   writeln('100=mostrar texto');
   writeln('101=mostrar formatos');
   writeln('--------------------------------');
   readln(opcion);
   leerOpcion := opcion
end;

var
   opcion, ln : integer;
   txt, taux  : Texto;
   lin        : Linea;
   ini,fin    : integer;
   pos        : Posicion;
   c          : Cadena;
   tfmt       : TipoFormato;
   pc         : PosibleColumna;
   pp         : PosiblePosicion;
   pl         : PosibleLinea;

begin
   { inicializo el texto }
   write('Ingrese Nombre de Archivo: ');
   leerTexto(txt);

   repeat
      opcion := leerOpcion;
      case opcion of
        { mostrar }
        0 : writeln('Edición finalizada.');
        100 : mostrarTexto(txt);
        101 : mostrarFormatoTexto(txt);
        
        { todosTienenFormatoEnLinea }
        1   : begin
                write('Ingrese línea: ');
                readln(ln);
                write('Ingrese columna de inicio: ');
                readln(ini); 
                write('Ingrese columna de fin: ');
                readln(fin); 
                write('Ingrese Formato [0=negrita,1=italica,2=subrayado]: ');
                tfmt := leerTipoFormato();
                taux := ubicarLineaEnTexto (txt, ln);
                if todosTienenFormatoEnLinea(tfmt,ini, fin,taux^.info) then
                   write('Todos tienen formato ') 
                else
                   write('No todos tienen formato ');
                mostrarTipoFormato(tfmt);
                writeln 
            end;
        { aplicarFormatoLinea }
        2   : begin
                write('Ingrese línea: ');
                readln(ln);
                write('Ingrese columna de inicio: ');
                readln(ini); 
                write('Ingrese columna de fin: ');
                readln(fin); 
                write('Ingrese Formato [0=negrita,1=italica,2=subrayado]: ');
                tfmt := leerTipoFormato();
                taux := ubicarLineaEnTexto (txt, ln);
                aplicarFormatoEnLinea(tfmt,ini, fin,taux^.info)
            end;
        { contarCaracteresEnTexto }
        3   : 
             writeln ('El texto tiene ', contarCaracteresEnTexto(txt):0
                      , ' carácteres.');
        { buscarCadenaEnLineaDesde }
        4   :
             begin
                write ('Ingrese línea: ');
                readln (pos.linea);
                write ('Ingrese columna: ');
                readln (pos.columna);
                lin := ubicarLineaEnTexto (txt, pos.linea)^.info;
                write('Texto a buscar: ');
                leerCadena(c);
                buscarCadenaEnLineaDesde (c, lin, pos.columna, pc);
                writeln ('Resultado: ');
                mostrarPosibleColumna (pc);
                if pc.esColumna then mostrarLineaCol (lin, pc.col)
             end;
        { buscarCadenaEnTextoDesde }
        5   :
             begin
                write ('Ingrese línea: ');
                readln (pos.linea);
                write ('Ingrese columna: ');
                readln (pos.columna);
                writeln('Texto a buscar:');
                leerCadena(c);
                buscarCadenaEnTextoDesde (c, txt, pos, pp);
                writeln ('Resultado: ');
                mostrarPosiblePosicion (pp);
                if pp.esPosicion then
                begin
                   lin := ubicarLineaEnTexto (txt, pp.p.linea)^.info;
                   mostrarLineaCol (lin, pp.p.columna)
                end
             end;
        { insertarCadenaEnLinea }
        6   :
             begin
                write ('Ingrese línea: ');
                readln (pos.linea);
                write ('Ingrese columna: ');
                readln (pos.columna);
                write('Ingrese cadena: ');
                leerCadena(c);
                taux := ubicarLineaEnTexto (txt, pos.linea);
                insertarCadenaEnLinea(c,pos.columna,taux^.info,pl);
                write('Línea sobrante:');
                mostrarPosibleLinea(pl);
                if pl.esLinea then
                begin
                   write('Insertar línea sobrante como siguiente? [0=no,1=si]');
                   readln(opcion);
                   if opcion = 1 then insertarLineaEnTexto(pl.l,pos.linea+1,txt)
                end
             end;
        { insertarLineaEnTexto }
        7   :
            begin
               write ('Ingrese línea: ');
               readln (ln);
               write('Ingrese texto de línea: ');
               leerLinea(lin);
               insertarLineaEnTexto(lin,ln,txt);
             end;
        { testea ubicarLinea }
        10   :
            begin
               write ('Ingrese línea: ');
               readln (ln);
               mostrarLinea (ubicarLineaEnTexto (txt, ln)^.info)
            end;

        else writeln ('Opción inexistente')
       end
   until opcion = 0;
end.

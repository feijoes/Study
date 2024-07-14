
Const 
  MaxDigito = 9;
(* constantes de valores adecuados *)
  MaxUsuarios = 6;

Type 
  Documento = ARRAY [1..MaxDigito] Of 0..9;
  Estado = (Agendado, Atendido, Ausente);
  Fecha = Record
    dia : 1..31;
    mes : 1..12;
    anio : 1930..2030;
  End;
  Usuario = Record
    documento : Documento;
    Case est : Estado Of 
      Atendido : (fechaAtendido : Fecha);
      Agendado : (fechaAsignada : Fecha);
      Ausente : ();
  End;
  Agenda = Record
    usuarios : ARRAY [1..MaxUsuarios] Of Usuario;
    tope : 0..MaxUsuarios;
  End;

Type 
  Lista = ^Nodo;
  Nodo = Record
    elem : Char;
    sig : Lista;
  End;

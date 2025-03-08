#include <iostream>
#include <iomanip>
using namespace std;

typedef unsigned int nat;

class Fecha
{
public:
    nat dia;
    nat mes;
    nat anio;
    Fecha(nat dia, nat mes, nat anio) : anio(anio), dia(dia), mes(mes) {}
    bool isBisiesto(nat anio)
    {
        if (anio % 4 == 0)
        {
            return true;
        }
        return false;
    }
    nat diasMes()
    {
        if (this->mes == 2 && isBisiesto(this->anio))
        {
            return 29;
        }
        static const nat diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return diasMes[this->mes - 1];
    }

    Fecha avanzar(nat dias)
    {
        nat dia = (this->dia + dias) % diasMes();
        nat mes = (this->mes + ((this->dia + dias) / diasMes())) % 12;
        nat anio = this->anio + (this->mes + (this->dia + dias) / diasMes()) / 12;
        return Fecha(dia, mes, anio);
    }

    bool operator==(Fecha &otra) const
    {
        return this->anio == otra.dia && this->dia == otra.dia && this->mes == otra.mes;
    }

    bool operator!=(Fecha &otra) const
    {
        return !(*this == otra);
    }
    friend ostream &operator<<(ostream &os, const Fecha &fecha)
    {
        os << fecha.anio << "/"
           << std::setw(2) << std::setfill('0') << fecha.mes << "/"
           << std::setw(2) << std::setfill('0') << fecha.dia;
        return os;
    }
};

class Empleado
{
private:
    string nombre;

public:
    Empleado(string);
    string getNombre();
    virtual float darLiquidacion() = 0;
    // La operación es virtual para habilitar despacho
    // dinámico y es pura (=0) porque no tiene método
    // (no hay forma de calcular el sueldo si el
    // empleado no es común o jornalero)
};
Empleado::Empleado(string unNombre)
{
    nombre = unNombre;
}
string Empleado::getNombre()
{
    return nombre;
}
class Comun : public Empleado
{
private:
    float sueldoMensual;

public:
    Comun(string, float);
    float getSueldoMensual(); 
    virtual float darLiquidacion();

};
Comun::Comun(string unNombre, float unSueldoMensual) : Empleado(unNombre)
{
    sueldoMensual = unSueldoMensual;
}
float Comun::getSueldoMensual()
{
    return sueldoMensual;
}
float Comun::darLiquidacion()
{
    return sueldoMensual;
}
#include <iostream>

int main()
{
    std::cout << "Hello World";

    return 0;
}
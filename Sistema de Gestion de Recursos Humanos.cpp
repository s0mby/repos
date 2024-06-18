#include <iostream>
#include <string>
using namespace std;

class Empleado {
private:
    string nombre;
    float salario;
    int fechaContratacionAnio;
    int fechaContratacionMes;
    int fechaContratacionDia;
public:
    Empleado(string nombre, float salario, int anio, int mes, int dia) {
        this->nombre = nombre;
        this->salario = salario;
        this->fechaContratacionAnio = anio;
        this->fechaContratacionMes = mes;
        this->fechaContratacionDia = dia;
    }
    virtual float calcularSalario() = 0; // Método virtual puro
    string getNombre() const {
        return nombre;
    }
    void setNombre(const string& nombre) {
        this->nombre = nombre;
    }
    float getSalario() const {
        return salario;
    }
    void setSalario(float salario) {
        this->salario = salario;
    }
    int getFechaContratacionAnio() const {
        return fechaContratacionAnio;
    }
    int getFechaContratacionMes() const {
        return fechaContratacionMes;
    }
    int getFechaContratacionDia() const {
        return fechaContratacionDia;
    }
    void setFechaContratacion(int anio, int mes, int dia) {
        this->fechaContratacionAnio = anio;
        this->fechaContratacionMes = mes;
        this->fechaContratacionDia = dia;
    }
};

class Gerente : public Empleado {
private:
    float bono;
public:
    Gerente(string nombre, float salario, int anio, int mes, int dia, float bono)
    : Empleado(nombre, salario, anio, mes, dia) {
        this->bono = bono;
    }
    float calcularSalario() override {
        return getSalario() + bono;
    }
};
class Desarrollador : public Empleado {
private:
    int horasExtra;
    float pagoHoraExtra;
public:
    Desarrollador(string nombre, float salario, int anio, int mes, int dia, int horasExtra, float pagoHoraExtra)
    : Empleado(nombre, salario, anio, mes, dia) {
        this->horasExtra = horasExtra;
        this->pagoHoraExtra = pagoHoraExtra;
    }
    float calcularSalario() override {
        return getSalario() + (horasExtra * pagoHoraExtra);
    }
};

class Diseñador : public Empleado {
private:
    float comisionProyectos;
public:
    Diseñador(string nombre, float salario, int anio, int mes, int dia, float comisionProyectos)
    : Empleado(nombre, salario, anio, mes, dia) {
        this->comisionProyectos = comisionProyectos;
    }
    float calcularSalario() override {
        return getSalario() + comisionProyectos;
    }
};

int main() {
    // Creando empleados de diferentes tipos
    int cant = 3;
    Empleado* arreglo[cant];
    arreglo[0] = new Gerente("Pedro Paz", 2500, 2022, 3, 1, 400);
    arreglo[1] = new Desarrollador("Maria Velez", 2000, 2023, 5, 10, 10, 35);
    arreglo[2] = new Diseñador("Simeo Vill", 1800, 2024, 2, 15, 200);
   
    // Demostrando el polimorfismo para calcular salarios
    for(int i = 0; i < cant; i++){
        cout << "Nombre: " << arreglo[i]->getNombre() << endl;
        cout << "Salario: " << arreglo[i]->calcularSalario() << endl;
    }
   
    // Liberar memoria
    for(int i = 0; i < cant; i++){
        delete arreglo[i];
    }
   
    return 0;
}

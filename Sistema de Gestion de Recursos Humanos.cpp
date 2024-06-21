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
____________________________________________________________________________________________________________________________________________
#include <iostream>
#include <string>
#include <vector>
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
    virtual float calcularSalario() ; // Método virtual puro
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

template <typename T>
class Departamento {
private:
    T** empleados;
    int capacidad;
    int cantidad;
public:
    Departamento() {
        capacidad = 10;
        cantidad = 0;
        empleados = new T*[capacidad];
    }

    ~Departamento() {
        for (int i = 0; i < cantidad; ++i) {
            delete empleados[i];
        }
        delete[] empleados;
    }

    // Método para agregar un empleado al departamento
    void agregarEmpleado(T* empleado) {
        if (cantidad < capacidad) {
            empleados[cantidad++] = empleado;
        } else {
            cout << "No se puede agregar más empleados. Departamento lleno." << endl;
        }
    }

    // Método para eliminar un empleado del departamento
    void eliminarEmpleado(T* empleado) {
        for (int i = 0; i < cantidad; ++i) {
            if (empleados[i] == empleado) {
                delete empleados[i];
                for (int j = i; j < cantidad - 1; ++j) {
                    empleados[j] = empleados[j + 1];
                }
                cantidad--;
                return;
            }
        }
        cout << "Empleado no encontrado en el departamento." << endl;
    }

    // Método para buscar un empleado por nombre
    T* buscarEmpleado(const string& nombre) {
        for (int i = 0; i < cantidad; ++i) {
            if (empleados[i]->getNombre() == nombre) {
                return empleados[i];
            }
        }
        return nullptr;
    }

    // Método para listar todos los empleados del departamento
    void listarEmpleados() {
        for (int i = 0; i < cantidad; ++i) {
            cout << "Nombre: " << empleados[i]->getNombre() << endl;
            cout << "Salario: " << empleados[i]->calcularSalario() << endl;
            cout << "---------------------------" << endl;
        }
    }
};

int main() {
    // Creando empleados de diferentes tipos
    int cant = 3;
    Departamento<Empleado>* arreglo[cant];
    Departamento<Empleado>* departamentoGerentes =new Departamento<Gerente>;
    arreglo[0] = departamentoGerentes;
    departamentoGerentes->agregarEmpleado(new Gerente("Pedro Paz", 2500, 2022, 3, 1, 400));
    Departamento<Desarrollador> departamentoDesarrolladores;
    arreglo[1] = &departamentoDesarrolladores;
    departamentoDesarrolladores.agregarEmpleado(new Desarrollador("Maria Velez", 2000, 2023, 5, 10, 10, 35));
    arreglo[2] = Departamento<Disenador> departamentoDisenadores;
    departamentoDisenadores.agregarEmpleado(new Diseñador("Simeo Vill", 1800, 2024, 2, 15, 200));
   
    // Demostrando el polimorfismo para calcular salarios
    for(int i = 0; i < cant; i++){
        cout << "Nombre: " << arreglo[i]->getNombre() << endl;
        cout << "Salario: " << arreglo[i]->calcularSalario() << endl;
    }
    
    //listar empleados de cadad departamento
    cout << "Departamento de Gerentes:" << endl;
    departamentoGerentes.listarEmpleados();
    cout << "Departamento de Desarrolladores:" << endl;
    departamentoDesarrolladores.listarEmpleados();
    cout << "Departamento de Diseñadores:" << endl;
    departamentoDisenadores.listarEmpleados();

    // Liberar memoria
    for(int i = 0; i < cant; i++){
        delete arreglo[i];
    }
   
    return 0;
}

---------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
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
    virtual float calcularSalario() ; // Método virtual puro
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
template <typename T>
class arreglo{
private:
vector<T*>puntero;
public:
void agregar (T* ptr){
    puntero.push_back(ptr);
}
void mostrar()const{
    for (const auto& ptr : puntero){
        ptr -> mostrar();
    }
}

~Arreglo(){
    for (auto ptr : puntero){
        delete ptr;
        }
    }
};

int main(){
    Gerente obj();
    Desarrollador obj2();
    Diseñador obj3();
    Arreglo <Empleado> arreglo;

    arreglo.agregar(new Gerente(obj));
    arreglo.agregar(new Desarrollador(obj2));
    arreglo.agregar(new Diseñador(obj3));

    arreglo.mostrarTodos();
    return 0;
}

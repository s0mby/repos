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

using namespace std;

class Empleado {
private:
    string nombre;
    float salario;
    int fechaContratacionAnio;
    int fechaContratacionMes;
    int fechaContratacionDia;
    Empleado* siguiente; // Puntero al siguiente elemento de la lista

public:
    Empleado(string nombre, float salario, int anio, int mes, int dia)
        : nombre(nombre), salario(salario), fechaContratacionAnio(anio), fechaContratacionMes(mes), fechaContratacionDia(dia), siguiente(this) {}

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

    Empleado* getSiguiente() const { 
        return siguiente; 
        }
    void setSiguiente(Empleado* siguiente) { 
        this->siguiente = siguiente; 
        }

    virtual void imprimir() const = 0; // Método virtual puro para imprimir

    virtual ~Empleado() = default; // Destructor virtual por defecto
};

class Gerente : public Empleado {
private:
    float bono;

public:
    Gerente(string nombre, float salario, int anio, int mes, int dia, float bono)
        : Empleado(nombre, salario, anio, mes, dia), bono(bono) {}

    float calcularSalario() override {
        return getSalario() + bono;
    }

    void imprimir() const override {
        cout << "Gerente: " << getNombre() << ", Salario: " << calcularSalario() << endl;
    }
};

class Desarrollador : public Empleado {
private:
    int horasExtra;
    float pagoHoraExtra;

public:
    Desarrollador(string nombre, float salario, int anio, int mes, int dia, int horasExtra, float pagoHoraExtra)
        : Empleado(nombre, salario, anio, mes, dia), horasExtra(horasExtra), pagoHoraExtra(pagoHoraExtra) {}

    float calcularSalario() override {
        return getSalario() + (horasExtra * pagoHoraExtra);
    }

    void imprimir() const override {
        cout << "Desarrollador: " << getNombre() << ", Salario: " << calcularSalario() << endl;
    }
};

class Diseñador : public Empleado {
private:
    float comisionProyectos;

public:
    Diseñador(string nombre, float salario, int anio, int mes, int dia, float comisionProyectos)
        : Empleado(nombre, salario, anio, mes, dia), comisionProyectos(comisionProyectos) {}

    float calcularSalario() override {
        return getSalario() + comisionProyectos;
    }

    void imprimir() const override {
        cout << "Diseñador: " << getNombre() << ", Salario: " << calcularSalario() << endl;
    }
};

template <typename T>
class Inventario {
private:
    T* cabeza; // Puntero al primer elemento de la lista
    T* cola;   // Puntero al último elemento de la lista

public:
    Inventario() {
        cabeza = new T("", 0, 0, 0, 0); // Crear un nodo centinela
        cabeza->setSiguiente(cabeza);   // El nodo centinela apunta a sí mismo
        cola = cabeza;                  // Inicialmente, la cola es el nodo centinela
    }

    void agregarProducto(const T& producto) {
        T* nuevo = new T(producto);     // Crear un nuevo producto
        cola->setSiguiente(nuevo);      // Añadirlo al final de la lista
        nuevo->setSiguiente(cabeza);    // El nuevo producto apunta al centinela
        cola = nuevo;                   // Actualizar la cola
    }

    void eliminarProducto(const T& producto) {
        T* actual = cabeza;
        while (actual->getSiguiente() != cabeza && !(actual->getSiguiente()->getNombre() == producto.getNombre())) {
            actual = actual->getSiguiente();
        }

        if (actual->getSiguiente() != cabeza) { // Si se encontró el producto
            T* temp = actual->getSiguiente();
            actual->setSiguiente(temp->getSiguiente());
            if (temp == cola) {
                cola = actual; // Actualizar la cola si se eliminó el último producto
            }
            delete temp; // Liberar memoria del producto eliminado
        }
    }

    T* buscarProducto(const T& producto) {
        T* actual = cabeza->getSiguiente();
        while (actual != cabeza) {
            if (actual->getNombre() == producto.getNombre()) {
                return actual;
            }
            actual = actual->getSiguiente();
        }
        return nullptr; // No se encontró el producto
    }

    void listarProductos() const {
        T* actual = cabeza->getSiguiente();
        while (actual != cabeza) {
            actual->imprimir(); // Usar la función miembro imprimir
            actual = actual->getSiguiente();
        }
    }

    ~Inventario() {
        T* actual = cabeza->getSiguiente();
        while (actual != cabeza) {
            T* temp = actual;
            actual = actual->getSiguiente();
            delete temp;
        }
        delete cabeza; // Eliminar el nodo centinela
    }
};

int main() {
    Inventario<Gerente> inventarioGerentes;
    Inventario<Desarrollador> inventarioDesarrolladores;
    Inventario<Diseñador> inventarioDiseñadores;

    inventarioGerentes.agregarProducto(Gerente("Pedro Paz", 2500, 2022, 3, 1, 400));
    inventarioDesarrolladores.agregarProducto(Desarrollador("Maria Velez", 2000, 2023, 5, 10, 10, 35));
    inventarioDiseñadores.agregarProducto(Diseñador("Simeo Vill", 1800, 2024, 2, 15, 200));

    cout << "Gerentes:" << endl;
    inventarioGerentes.listarProductos();
    cout << endl;

    cout << "Desarrolladores:" << endl;
    inventarioDesarrolladores.listarProductos();
    cout << endl;

    cout << "Diseñadores:" << endl;
    inventarioDiseñadores.listarProductos();
    cout << endl;

    Gerente gerenteBuscar("Pedro Paz", 2500, 2022, 3, 1, 400);
    if (inventarioGerentes.buscarProducto(gerenteBuscar)) {
        cout << "Gerente encontrado: ";
        gerenteBuscar.imprimir();
        inventarioGerentes.eliminarProducto(gerenteBuscar);
    } else {
        cout << "Gerente no encontrado." << endl;
    }

    cout << "Gerentes después de eliminar:" << endl;
    inventarioGerentes.listarProductos();
    cout << endl;

    return 0;
}

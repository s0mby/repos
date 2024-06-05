#include <iostream>

// Clase base Empleado
class Empleado {
protected:
    string nombre;
    double salarioBase;
    int fechaContratacion;
public:
    // Constructor
    Empleado(double salario) : salarioBase(salario) {}
    // Método virtual para calcular el salario
    virtual double calcularSalario();
};
// Clase derivada Gerente
class Gerente : public Empleado {
public:
    // Constructor
    Gerente(double salario) : Empleado(salario) {}
    double calcularSalario() const override {
        return salarioBase;
    }
};
// Clase derivada Desarrollador
class Desarrollador : public Empleado {
public:
    // Constructor
    Desarrollador(double salario) : Empleado(salario) {}
    double calcularSalario() const override {
        return salarioBase / 2.0;
    }
};
int main() {
    
    return 0;
}

#include <iostream>

// Clase base Empleado
class Empleado {
protected:
    double salarioBase;
public:
    // Constructor
    Empleado(double salario) : salarioBase(salario) {}
    // Método virtual para calcular el salario
    virtual double calcularSalario() const = 0;
};
// Clase derivada EmpleadoTiempoCompleto
class EmpleadoTiempoCompleto : public Empleado {
public:
    // Constructor
    EmpleadoTiempoCompleto(double salario) : Empleado(salario) {}
    // Redefinición del método calcularSalario para empleados a tiempo completo
    double calcularSalario() const override {
        return salarioBase;
    }
};
// Clase derivada EmpleadoMedioTiempo
class EmpleadoMedioTiempo : public Empleado {
public:
    // Constructor
    EmpleadoMedioTiempo(double salario) : Empleado(salario) {}
    // Redefinición del método calcularSalario para empleados a medio tiempo
    double calcularSalario() const override {
        return salarioBase / 2.0;
    }
};
int main() {
    EmpleadoTiempoCompleto empleadoTC(3000.0);
    EmpleadoMedioTiempo empleadoMT(1500.0);
    std::cout << "Salario de Empleado a Tiempo Completo: $" << empleadoTC.calcularSalario() << std::endl;
    std::cout << "Salario de Empleado a Medio Tiempo: $" << empleadoMT.calcularSalario() << std::endl;
    return 0;
}

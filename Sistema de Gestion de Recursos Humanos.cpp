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
-------------------------------
#include <iostream>

using namespace std;

class Empleado {
private:
  string nombre;
  float salario;
  int fechaContratacion;

public:
  Empleado(string nombre, float salario, int fechaContratacion) {
    this->nombre = nombre;
    this->salario = salario;
    this->fechaContratacion = fechaContratacion;
  }

  virtual float calcularSalario(); // Método virtual

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

  fecha getFechaContratacion() const { 
      return fechaContratacion; 
  }
  void setFechaContratacion(const fecha& fechaContratacion) { 
      this->fechaContratacion = fechaContratacion; 
  }
};

class Gerente : public Empleado {
private:
  float bono;

public:
  Gerente(string nombre, float salario, fecha fechaContratacion, float bono) : Empleado(nombre, salario, fechaContratacion) {
    this->bono = bono;
  }

  float calcularSalario() { // Método virtual
    return salario + bono;
  }
};

class Desarrollador : public Empleado {
private:
  int horasExtra;
  float pagoHoraExtra;

public:
  Desarrollador(string nombre, float salario, fecha fechaContratacion, int horasExtra, float pagoHoraExtra) : Empleado(nombre, salario, fechaContratacion) {
    this->horasExtra = horasExtra;
    this->pagoHoraExtra = pagoHoraExtra;
  }

  float calcularSalario() { // Método virtual
    return salario + (horasExtra * pagoHoraExtra);
  }
};

class Diseñador : public Empleado {
private:
  float comisionProyectos;

public:
  Diseñador(string nombre, float salario, fecha fechaContratacion, float comisionProyectos) : Empleado(nombre, salario, fechaContratacion) {
    this->comisionProyectos = comisionProyectos;
  }

  float calcularSalario() { // Método virtual
    return salario + comisionProyectos;
  }
};

int main() {
  // Creando empleados de diferentes tipos
  Empleado PedroPaz("Pedro Paz", 2500, {2022, 3, 1});
  Gerente LiamSol("Liam Sol", 2800, {2021, 7, 15}, 400);
  Desarrollador MariaVelez("Maria Velez", 2000, {2023, 5, 10}, 10, 35);
  Diseñador SimeoVill("Simeo Vill", 1800, {2024, 2, 15}, 200);

  // Demostrando el polimorfismo para calcular salarios
  cout << "Nombre: " << PedroPaz.getNombre() << endl;
  cout << "Salario: " << PedroPaz.calcularSalario() << endl;

  cout << "Nombre: " << LiamSol.getNombre() << endl;
  cout << "Salario: " << LiamSol.calcularSalario() << endl;

  cout << "Nombre: " << MariaVelez.getNombre() << endl;
  cout << "Salario: " << MariaVelez.calcularSalario() << endl;

  cout << "Nombre: " << SimeoVill.getNombre() << endl;
  cout << "Salario: " << SimeoVill.calcularSalario() << endl;

  return 0;
}

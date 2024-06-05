#include <iostream>
using namespace std;
peneGAAAAAAAAAAAAAAAA

// Definición de la clase base Vehiculo
class Vehiculo {
public:
    virtual void conducir() = 0; // función virtual pura
};

// Definición de la primera subclase Auto, que refina la clase Vehiculo
class Auto : public Vehiculo {
public:
    void conducir() {
        cout << "Conduciendo un auto" << endl;
    }
};

// Definición de la segunda subclase Moto, que refina la clase Vehiculo
class Moto : public Vehiculo {
public:
    void conducir() {
        cout << "Conduciendo una moto" << endl;
    }
};

// Definición de la tercera subclase Camion, que refina la clase Vehiculo
class Camion : public Vehiculo {
public:
    void conducir() {
        cout << "Conduciendo un camión" << endl;
    }
};

int main() {
    // Crear objetos de las subclases y llamar a la función conducir
    Auto miAuto;
    /*Moto miMoto;
    Camion miCamion;
*/
    miAuto.conducir();
    /*miMoto.conducir();
    miCamion.conducir();
*/
    return 0;
}


class Mundo;

// Clase que tiene las direcciones, guarda la celda en la que se encuentra 
class Hormiga {
 private:
  Direcciones direccion_;
  Posicion posicion_actual_;
  Regla movimiento_;
  Mundo* mundo_;

 public:
  Hormiga(int semilla); //En esta semilla del random
  Hormiga(Posicion posicion);
  Hormiga();

};
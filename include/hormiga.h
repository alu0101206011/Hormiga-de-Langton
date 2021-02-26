class Mundo;

// Clase que tiene las direcciones, guarda la celda en la que se encuentra 
class Hormiga {
 private:
  Direcciones direccion_;
  Posicion posicion_actual_;
  Regla movimiento_;
  Mundo* mundo_;

 public:
  Hormiga(Mundo& mundo, int semilla); //En esta semilla del random
  Hormiga(Mundo& mundo, Posicion posicion);
  Hormiga(Mundo& mundo);

  Direcciones get_direccion(void) const;
  Posicion get_posicion_actual(void) const;
  Regla get_movimiento(void) const;
  Mundo* get_mundo(void) const;

  void set_direccion(const Direcciones&);
  void set_posicion_actual(const Posicion&);
  void set_movimiento(const Regla&);
  void set_mundo(Mundo* const&);

};

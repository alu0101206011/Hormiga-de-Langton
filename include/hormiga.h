class Mundo;

class Hormiga {
 private:
  Direcciones direccion_;
  Posicion posicion_actual_;
  Posicion posicion_siguiente_;
  Regla movimiento_;
  Mundo* mundo_;

 public:
  Hormiga(Mundo& mundo, int semilla);
  Hormiga(Mundo& mundo, int i, int j);
  Hormiga(Mundo& mundo);

  Direcciones get_direccion(void) const;
  Posicion get_posicion_actual(void) const;
  Posicion get_posicion_siguiente(void) const;
  Regla get_movimiento(void) const;
  Mundo* get_mundo(void) const;

  void set_direccion(const Direcciones&);
  void set_movimiento(const Regla&);
  void set_mundo(Mundo* const&);
  void set_posiciones(const Posicion&);
  void set_posiciones(const int&, const int&);

  void actualizar_posiciones(const Posicion&);
  void actualizar_posiciones(const int&, const int&);

  void cerebro(void);

  friend std::ostream& operator<<(std::ostream&, const Hormiga&);

 private:
  void set_posicion_actual(const Posicion&);
  void set_posicion_actual(const int&, const int&);
  void set_posicion_siguiente(const Posicion&);
  void set_posicion_siguiente(void);
};

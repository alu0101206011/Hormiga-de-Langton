class Mundo;

class Hormiga {
 protected:
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
  int get_color_actual(void) const;
  int get_color_siguiente(void);

  void set_direccion(const Direcciones&);
  void set_movimiento(const Regla&);
  void set_mundo(Mundo* const&);
  void set_posiciones(const Posicion&);
  void set_posiciones(const int&, const int&);
  void set_color_actual(const int&);
  void set_color_siguiente(const int&);

  void actualizar_posicion(const Posicion&);
  void actualizar_posicion(const int&, const int&);

  virtual void cerebro(void) = 0;

  bool operator<(const Hormiga&);
  friend std::ostream& operator<<(std::ostream&, const Hormiga&);

 private:
  void set_posicion_actual(const Posicion&);
  void set_posicion_actual(const int&, const int&);
  void set_posicion_siguiente(const Posicion&);

 protected:
  void set_posicion_siguiente(void);
};

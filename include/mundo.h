struct BoardSize {
  unsigned filas_, columnas_;
};

class Mundo {
 private:
  Celda*** tablero_;
  BoardSize size_;
  Hormiga** hormiga_;
  bool random_;

 public:
  Mundo(unsigned, unsigned); 
  Mundo();
  Mundo(int);

  ~Mundo();

  void inicio(void);

  Celda*** get_tablero(void) const;
  BoardSize get_size(void) const;
  Hormiga** get_hormiga(void) const;
  unsigned get_color(const Posicion&) const;

  void set_tablero(Celda*** const&);

  void movimiento_peligroso(void);

  friend std::ostream& operator<<(std::ostream&, const Mundo&);

 private:
  void crear_tablero(int random);
  void resize(const unsigned, const int);
  void ampliar_vertical(const unsigned, const unsigned, Celda***&);
  void ampliar_horizontal(const unsigned, const unsigned, Celda***&);
  void eliminar_espacio(Celda***, const unsigned&, const unsigned&);


};
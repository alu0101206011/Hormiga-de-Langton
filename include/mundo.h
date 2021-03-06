struct BoardSize {
  unsigned filas_, columnas_;
  int Xmin, Ymin, Xmax, Ymax;
};

typedef Vector<Vector<Celda>> MatrizCeldas;

class Mundo {
 private:
  MatrizCeldas tablero_;
  BoardSize size_;
  Hormiga** hormiga_;
  bool random_;

 public:
  Mundo(unsigned, unsigned); 
  Mundo();
  Mundo(int);

  ~Mundo();

  void inicio(void);

  MatrizCeldas get_tablero(void) const;
  BoardSize get_size(void) const;
  Hormiga** get_hormiga(void) const;
  unsigned get_color(const Posicion&) const;

  void set_tablero(MatrizCeldas const&);

  void movimiento_peligroso(Hormiga*);

  friend std::ostream& operator<<(std::ostream&, const Mundo&);

 private:
  void resize(const unsigned, const int);
  void ampliar_vertical(const unsigned, const unsigned, MatrizCeldas&);
  void ampliar_horizontal(const unsigned, const unsigned, MatrizCeldas&);
  void eliminar_espacio(MatrizCeldas, const int&, const int&);
  void set_size(int, int);

};
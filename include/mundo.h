const unsigned NUM_COLOR = 2;
const unsigned HORMIGA_SIZE = 1;
const unsigned ADD_SIZE = 1;

struct BoardSize {
  unsigned filas_, columnas_;
  int Xmin, Ymin, Xmax, Ymax;
};

typedef Vector<Vector<Celda>> MatrizCeldas;


class Mundo {
 private:
  MatrizCeldas tablero_;

 protected:
  BoardSize size_;
  bool random_;

 public:
  Mundo(unsigned, unsigned); 
  Mundo();
  Mundo(int);

  ~Mundo();

  MatrizCeldas get_tablero(void) const;
  MatrizCeldas& get_tablero(void);
  BoardSize get_size(void) const;
  Hormiga** get_hormiga(void) const;
  unsigned get_color(const Posicion&) const;

  void set_tablero(MatrizCeldas const&);
  void set_color(const Posicion&, int);

  virtual void world_edge(Hormiga*) = 0;

 protected: 
  Direcciones es_una_esquina(Posicion);

 private:
  void set_size(int, int);

};
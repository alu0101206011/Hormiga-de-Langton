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
  BoardSize size_;
  Hormiga** hormiga_;
  bool random_;

 public:
  Mundo(unsigned, unsigned); 
  Mundo();
  Mundo(int);

  ~Mundo();

  MatrizCeldas get_tablero(void) const;
  BoardSize get_size(void) const;
  Hormiga** get_hormiga(void) const;
  unsigned get_color(const Posicion&) const;

  void set_tablero(MatrizCeldas const&);
  void set_color(const Posicion&, int);

  void movimiento_peligroso(Hormiga*);
  void world_edge(Posicion, Hormiga**);

 private:
  void set_size(int, int);
  void change_size(Direcciones, int);
  void change_size_esquinas(Direcciones, int);
  void ampliar_arriba(int);
  void ampliar_izquierda(int);
  void ampliar_derecha(int);
  void ampliar_abajo(int);
  Direcciones es_una_esquina(Posicion);
};
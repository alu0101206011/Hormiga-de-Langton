const unsigned NUM_COLOR = 2;
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
  unsigned get_color(const Posicion&) const;
  Celda& get_celda(const Posicion&) const;
  Celda& get_celda_hormiga(Hormiga*);
  Celda& get_next_celda_hormiga(Hormiga*);

  void set_tablero(MatrizCeldas const&);
  void set_color(const Posicion&, int);

  virtual void world_edge(Hormiga*) = 0;  // quitarle virtual y que world_working o algo así sea el virtual

 protected: 
  Direcciones es_una_esquina(Posicion);

 private:
  void set_size(int, int);

};
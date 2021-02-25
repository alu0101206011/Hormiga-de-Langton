struct BoardSize {
  unsigned filas_, columnas_;
};

class Mundo {
 private:
  Celda*** tablero_;
  BoardSize size_;
  Hormiga** hormiga_;

 public:
  Mundo(unsigned, unsigned);
  ~Mundo();

  void inicio(void);

  Celda*** get_tablero(void) const;
  BoardSize get_size() const;

  void set_tablero(Celda*** const&);

  void resize(const unsigned);

  Celda& operator()(const unsigned int i, const unsigned int j) const;

  friend std::ostream& operator<<(std::ostream&, const Mundo&);

 private:
  void eliminar_espacio(Celda*** const&); 
  bool detectar_borde(const unsigned& i, const unsigned& j);

};
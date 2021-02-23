
class Mundo {
 private:
  Celda*** tablero_;
  unsigned filas_, columnas_;

 public:
  Mundo(int filas, int columnas);

  Celda*** get_tablero(void) const;
  unsigned get_filas(void) const;
  unsigned get_columnas(void) const;

  void set_tablero(const Celda***&);

  friend std::ostream& operator<<(std::ostream&, Mundo&);

};
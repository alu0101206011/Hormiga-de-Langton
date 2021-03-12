/// Clase Celda
/// Contiene la posición y el color

enum Color {Blanco, Negro};

class Celda {
 private:
  Posicion posicion_;
  unsigned color_;

 public:

  Celda(void);
  Celda(int, int, unsigned);

  Posicion get_posicion() const;
  unsigned get_color() const;

  void set_color(const unsigned&);

  friend std::ostream& operator<<(std::ostream&, const Celda&);
};

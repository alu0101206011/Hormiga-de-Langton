/// Clase de posiciones

class Posicion {
 private:
  int x_;
  int y_;
 public:
  Posicion();
  Posicion(int x, int y);
  
  int get_x(void) const;
  int get_y(void) const;

  void set_x(const int&);
  void set_y(const int&);

  bool operator==(const Posicion&);
  Posicion operator+(const Posicion&);
};
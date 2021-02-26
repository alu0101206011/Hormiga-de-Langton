enum Direcciones {arriba, derecha, abajo, izquierda};

class Movimiento {
 private:              //      0   1  2   3
  Posicion** direccion_; //  = { -1, 0, 1,  0}
                       //  = {  0, 1, 0, -1}
 public:
  Movimiento(void);
  ~Movimiento();

  Posicion** get_direccion(void) const;

  void set_direccion(Posicion** const&);
};
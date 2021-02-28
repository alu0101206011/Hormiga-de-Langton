enum Direcciones { arriba, derecha, abajo, izquierda };

const unsigned SIZE_DIRECTIONS = 4;

class Movimiento {
 private:              //      0   1  2   3
  Posicion** direcciones_; //  = { -1, 0, 1,  0}
                       //  = {  0, 1, 0, -1}
 public:
  Movimiento(void);
  ~Movimiento();

  Posicion** get_direcciones(void) const;
  Posicion* get_girar_direccion(Direcciones) const;
  Direcciones get_girar_derecha(const Direcciones) const;
  Direcciones get_girar_izquierda(const Direcciones) const;

  void set_direccion(Posicion** const&);
};
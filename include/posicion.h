/// Struct de posiciones

struct Posicion {
  unsigned x;
  unsigned y;
};

enum Direcciones {arriba, derecha, abajo, izquierda};

class Movimiento {
 private:              //      0   1  2   3
  Posicion* direccion; //  = { -1, 0, 1,  0}
                       //  = {  0, 1, 0, -1}
};
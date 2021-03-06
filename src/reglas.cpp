#include <iostream>

#include "../include/posicion.h"
#include "../include/movimiento.h"
#include "../include/celda.h"
#include "../include/reglas.h"
#include "../include/hormiga.h"
#include "../include/vector.h"
#include "../include/mundo.h"



int Regla::regla1(Hormiga* hormiga) {
/*   Posicion posicion_actual, posicion_siguiente;
  posicion_actual = hormiga->get_posicion_actual();
  posicion_siguiente = hormiga->get_posicion_siguiente();  
  if (hormiga->get_mundo()->get_color(posicion_actual) == hormiga->get_mundo()->get_color(posicion_siguiente)) {
    if (hormiga->get_mundo()->get_color(posicion_actual) == 0) {
      hormiga->get_mundo()->get_tablero()[posicion_actual.get_x()][posicion_actual.get_y()].set_color(1);
    } else if (hormiga->get_mundo()->get_color(posicion_siguiente) == 1) {
      hormiga->get_mundo()->get_tablero()[posicion_actual.get_x()][posicion_actual.get_y()].set_color(0);
    }
    hormiga->get_mundo()->movimiento_peligroso(hormiga);
    hormiga->actualizar_posiciones(posicion_siguiente);
    return 1;
  } */
  return 0;
}


int Regla::regla2(Hormiga* hormiga) {
/*   Movimiento next_move;
  Posicion posicion_actual, posicion_siguiente;
  posicion_actual = hormiga->get_posicion_actual();
  posicion_siguiente = hormiga->get_posicion_siguiente(); 
  if (hormiga->get_mundo()->get_color(posicion_actual) == 0) {
    hormiga->set_direccion(next_move.get_girar_izquierda(hormiga->get_direccion()));
    hormiga->get_mundo()->movimiento_peligroso(hormiga);
    if (posicion_actual != hormiga->get_posicion_actual())
      posicion_actual = hormiga->get_posicion_actual();
    hormiga->get_mundo()->get_tablero()[posicion_actual.get_x()][posicion_actual.get_y()].set_color(1);    
    hormiga->actualizar_posiciones(*next_move.get_next_pos(hormiga->get_direccion()) + posicion_actual);
    return 1; 
  }  */
  return 0;
}


int Regla::regla3(Hormiga* hormiga) {
/*   Movimiento next_move;
  Posicion posicion_actual, posicion_siguiente;
  posicion_actual = hormiga->get_posicion_actual();
  posicion_siguiente = hormiga->get_posicion_siguiente();
  if (hormiga->get_mundo()->get_color(posicion_actual) == 1) {
    hormiga->set_direccion(next_move.get_girar_derecha(hormiga->get_direccion()));
    hormiga->get_mundo()->movimiento_peligroso(hormiga);
    if (posicion_actual != hormiga->get_posicion_actual())
      posicion_actual = hormiga->get_posicion_actual();
    hormiga->get_mundo()->get_tablero()[posicion_actual.get_x()][posicion_actual.get_y()].set_color(0);
    hormiga->actualizar_posiciones(*next_move.get_next_pos(hormiga->get_direccion()) + hormiga->get_posicion_actual());
    return 1;
  } */
  return 0;
}
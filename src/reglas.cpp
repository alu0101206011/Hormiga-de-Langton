#include <iostream>

#include "../include/posicion.h"
#include "../include/movimiento.h"
#include "../include/celda.h"
#include "../include/reglas.h"
#include "../include/hormiga.h"
#include "../include/vector.h"
#include "../include/mundo.h"



int Regla::regla1(Hormiga* hormiga) {  
  if (hormiga->get_color_actual() == hormiga->get_color_siguiente()) {
    if (hormiga->get_color_actual() == Blanco) {
      hormiga->set_color_actual(Negro);
    } else if (hormiga->get_color_siguiente() == Negro) {
      hormiga->set_color_actual(Blanco);
    }
    hormiga->actualizar_posicion(hormiga->get_posicion_siguiente());
    return 1;
  } 
  return 0;
}

int Regla::regla2(Hormiga* hormiga) {
  Movimiento next_move;
  if (hormiga->get_color_actual() == Blanco) {
    hormiga->set_direccion(next_move.get_girar_izquierda(hormiga->get_direccion()));
    hormiga->set_color_actual(Negro);
    hormiga->actualizar_posicion(*next_move.get_next_pos(hormiga->get_direccion()) + hormiga->get_posicion_actual());
    return 1; 
  } 
  return 0;
}


int Regla::regla3(Hormiga* hormiga) {
  Movimiento next_move;
  if (hormiga->get_color_actual() == Negro) {
    hormiga->set_direccion(next_move.get_girar_derecha(hormiga->get_direccion()));
    hormiga->set_color_actual(Blanco);
    hormiga->actualizar_posicion(*next_move.get_next_pos(hormiga->get_direccion()) + hormiga->get_posicion_actual());
    return 1;
  }
  return 0;
}


int Regla::regla4(Hormiga* hormiga) {
  Movimiento next_move;
  if (hormiga->get_color_actual() == Blanco) {
    hormiga->set_direccion(next_move.get_girar_derecha(hormiga->get_direccion()));
    hormiga->set_color_actual(Negro);
    hormiga->actualizar_posicion(*next_move.get_next_pos(hormiga->get_direccion()) + hormiga->get_posicion_actual());
    return 1; 
  } 
  return 0;
}


int Regla::regla5(Hormiga* hormiga) {
  Movimiento next_move;
  if (hormiga->get_color_actual() == Negro) {
    hormiga->set_direccion(next_move.get_girar_izquierda(hormiga->get_direccion()));
    hormiga->set_color_actual(Blanco);
    hormiga->actualizar_posicion(*next_move.get_next_pos(hormiga->get_direccion()) + hormiga->get_posicion_actual());
    return 1;
  }
  return 0;
}
class MundoInfinito : public Mundo {
 public:
  MundoInfinito(unsigned, unsigned); 
  MundoInfinito();
  MundoInfinito(int);

  void world_edge(Hormiga*);

 private:
  void change_size(Direcciones, int);
  void change_size_esquinas(Direcciones, int);
  void ampliar_arriba(int);
  void ampliar_izquierda(int);
  void ampliar_derecha(int);
  void ampliar_abajo(int);
  void decrementar_arriba(int);
  void decrementar_izquierda(int);
  void decrementar_derecha(int);
  void decrementar_abajo(int);
};
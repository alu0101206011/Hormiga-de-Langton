class MundoFinito : public Mundo {
 public:
  MundoFinito(void);
  MundoFinito(unsigned, unsigned); 
  MundoFinito(int);

  void world_edge(Hormiga*);

 private:
  void movimiento_esquina(const Direcciones& esquina, Hormiga* hormiga);
  void movimiento_trivial(const Direcciones& pared, Hormiga* hormiga);
};
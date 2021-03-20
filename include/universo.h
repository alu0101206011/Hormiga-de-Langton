enum Velocidad {lento, medio, rapido};

bool ptr_comparison(Hormiga*, Hormiga*);

class Universo {
 private:
  Mundo* mundo_;
  std::list<Hormiga*> hormiga_list_;
  unsigned HORMIGA_SIZE;
 public:
  Universo(Mundo*, std::list<Hormiga*>, unsigned);
  Universo(Mundo*, std::list<Hormiga*>, int, unsigned);

  Mundo* get_mundo(void) const;
  std::list<Hormiga*> get_hormiga(void) const;
  unsigned get_hormiga_size(void) const;

  void next_hormiga_pos(void);
  void start_simulation(int, Velocidad);
  friend std::ostream& operator<<(std::ostream&, Universo&);
 
 private:
  void ordenar_lista(void);
  unsigned velocidad_simulacion(Velocidad);
  
};
class Universo {
 private:
  Mundo* mundo_;
  Hormiga** hormiga_;
 public:
  Universo();
  Universo(unsigned, unsigned);
  Universo(int);

  Mundo* get_mundo(void) const;
  Hormiga** get_hormiga(void) const;

  void start_simulation(int);
  friend std::ostream& operator<<(std::ostream&, const Universo&);
 
 private:
  void build_mundo(void);
  void build_mundo(int, int);
  void build_mundo(int);
  void build_hormiga(void);
  void build_hormiga(int, int);
  void build_hormiga(int);
};
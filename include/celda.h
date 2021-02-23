
class Celda {
 private:
  unsigned i_, j_;
  unsigned estado_;

 public:

  Celda(unsigned, unsigned, unsigned);

  unsigned get_i() const;
  unsigned get_j() const;
  unsigned get_estado() const;

  void set_estado(const unsigned&);

  friend std::ostream& operator<<(std::ostream&, const Celda&);
};
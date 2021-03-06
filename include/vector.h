template <class T> 
class Vector {
  int lower_, upper_;
  T *a_;

 public:
  Vector(int m, int n);

  ~Vector();

  int get_lower(void) const;
  int get_upper(void) const;

  void set_lower(const int&);
  void set_upper(const int&);

  void new_size(const int&, const int&);

  T& operator[](const int&);
  T& operator[](const int&) const;
};


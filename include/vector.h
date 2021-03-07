template <class T> 
class Vector {
  int lower_, upper_;
  T *a_;

 public:
  Vector(void);
  Vector(int, int);
  Vector(const Vector<T>&);

  ~Vector();

  int get_lower(void) const;
  int get_upper(void) const;

  void set_lower(const int&);
  void set_upper(const int&);

  void new_size(const int&, const int&);

  Vector<T>& operator=(const Vector<T>& v);

  T& operator[](const int&);
  T operator[](const int&) const;

 private:
  void remove(void);
  void build(void);
};


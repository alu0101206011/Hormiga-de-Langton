class HormigaLangton : public Hormiga {
 public:
  HormigaLangton(Mundo&, int);
  HormigaLangton(Mundo&, int, int);
  HormigaLangton(Mundo&);

  void cerebro(void);
};
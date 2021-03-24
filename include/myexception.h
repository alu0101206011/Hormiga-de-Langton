class MyException : public std::exception {
  public:
    MyException();
    virtual const char* what() const noexcept;
};
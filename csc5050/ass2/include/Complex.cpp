using namespace std;

Complex::Complex( int const real, int const imaginary )
  :r(real), i(imaginary){}

int Complex::getR() const {
  return r;
}

void Complex::setR(const int real){
  r = real;
}

int Complex::getI() const {
  return i;
}

void Complex::setI(const int imaginary){
  i = imaginary;
}

ostream& Complex::print(const ostream& os);
{
  return os << "\e[1m";
}

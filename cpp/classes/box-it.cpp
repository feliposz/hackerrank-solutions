

// Implement the class Box
class Box {
  // l,b,h are integers representing the dimensions of the box
  int l, b, h;

public:
  // The class should have the following functions :

  // Constructors:
  // Box();
  // Box(int,int,int);
  // Box(Box);
  Box() {
    this->l = 0;
    this->b = 0;
    this->h = 0;
  }

  Box(int l, int b, int h) {
    this->l = l;
    this->b = b;
    this->h = h;
  }
  Box(Box &other) {
    this->l = other.l;
    this->b = other.b;
    this->h = other.h;
  }

  // int getLength(); // Return box's length
  // int getBreadth (); // Return box's breadth
  // int getHeight ();  //Return box's height
  // long long CalculateVolume(); // Return the volume of the box

  int getLength() { return l; }
  int getBreadth() { return b; }
  int getHeight() { return h; }
  long long CalculateVolume() {
    return (long long)l * (long long)h * (long long)b;
  }

  // Overload operator < as specified
  // bool operator<(Box& b)
  bool operator<(Box &b) {
    if (this->l < b.l)
      return true;
    if (this->b < b.b && this->l == b.l)
      return true;
    if (this->h < b.h && this->b == b.b && this->l == b.l)
      return true;
    return false;
  }
};

// Overload operator << as specified
// ostream& operator<<(ostream& out, Box& B)

ostream &operator<<(ostream &out, Box &B) {
  out << B.getLength() << ' ' << B.getBreadth() << ' ' << B.getHeight();
  return out;
}


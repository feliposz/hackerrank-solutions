

class Complex(object):
    def __init__(self, real, imaginary):
        self.real = real
        self.imaginary = imaginary
        
    def __add__(self, no):
        return Complex(self.real + no.real, self.imaginary + no.imaginary)
        
    def __sub__(self, no):
        return Complex(self.real - no.real, self.imaginary - no.imaginary)
        
    def __mul__(self, no):
        return Complex(self.real * no.real - self.imaginary * no.imaginary, 
            self.real * no.imaginary + no.real * self.imaginary)

    def __truediv__(self, no):
        a, b = (self.real, self.imaginary)
        c, d = (no.real, no.imaginary)
        return Complex((a*c + b*d)/(c*c + d*d), (b*c - a*d)/(c*c + d*d))

    def mod(self):
        return Complex((self.real**2 + self.imaginary**2) ** 0.5, 0)

    def __str__(self):
        if self.imaginary == 0:
            result = "%.2f+0.00i" % (self.real)
        elif self.real == 0:
            if self.imaginary >= 0:
                result = "0.00+%.2fi" % (self.imaginary)
            else:
                result = "0.00-%.2fi" % (abs(self.imaginary))
        elif self.imaginary > 0:
            result = "%.2f+%.2fi" % (self.real, self.imaginary)
        else:
            result = "%.2f-%.2fi" % (self.real, abs(self.imaginary))
        return result



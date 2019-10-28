#include <iostream>

using namespace std;

int gcd (int a, unsigned int b){ // function for calculation of greatest common divider
    if (0 == b) return a;
    return gcd (b, a%b);
};

struct Rational{ // creation of Rational structure
    int m;
    unsigned int n;
    Rational(int a = 1, unsigned int b = 1){
        m = a / gcd (a, b);
        n = b / gcd (a, b);
    }
    Rational (Rational &X){ // constructor of copies (for Rational structure)
        m = X.m;
        n = X.n;
    }

    Rational &operator*= (Rational &b){ // *= operator overloading (for Rational structure)
        m *= b.m;
        n *= b.n;
        int g = gcd (m, n);
        m /= g;
        n /= g;
        return *this;
    }
    Rational &operator/= (Rational &b){ // /= operator overloading (for Rational structure)
        m *= b.n;
        n *= b.m;
        int g = gcd (m, n);
        m /= g;
        n /= g;
        return *this;
    };

    Rational &operator+= (Rational &b){ // += operator overloading (for Rational structure)
        m = m * b.n + b.m * n;
        n *= b.n;
        int g = gcd (m, n);
        m /= g;
        n /= g;
        return *this;
    };

    Rational &operator-= (Rational &b){ // -= operator overloading (for Rational structure)
        m = m * b.n - b.m * n;
        n *= b.n;
        int g = gcd (m, n);
        m /= g;
        n /= g;
        return *this;
    }
};



Rational operator* (Rational a, Rational &b){ // * operator overloading (for Rational structure)
    a *= b;
    int g = gcd (a.m, a.n);
    a.m /= g;
    a.n /= g;
    return a;
};

Rational operator/ (Rational a, Rational &b){ // / operator overloading (for Rational structure)
    a /= b;
    int g = gcd (a.m, a.n);
    a.m /= g;
    a.n /= g;
    return a;
};

Rational operator+ (Rational a, Rational &b){ // + operator overloading (for Rational structure)
    a += b;
    int g = gcd (a.m, a.n);
    a.m /= g;
    a.n /= g;
    return a;
};

Rational operator- (Rational a, Rational &b){ // - operator overloading (for Rational structure)
    a -= b;
    int g = gcd (a.m, a.n);
    a.m /= g;
    a.n /= g;
    return a;
};

bool operator> (Rational &a, Rational &b){ // > operator overloading (for Rational structure)
    return (a.m * b.n > a.n * b.m);
};

bool operator<= (Rational &a, Rational &b){ // <= operator overloading (for Rational structure)
    return !(a > b);
};

bool operator< (Rational &a, Rational &b){ // < operator overloading (for Rational structure)
    return (a.m * b.n < a.n * b.m);
};

bool operator>= (Rational &a, Rational &b){ // >= operator overloading (for Rational structure)
    return !(a < b);
};

bool operator== (Rational &a, Rational &b){ // == operator overloading (for Rational structure)
    return ((a.m == b.m) && (a.n == b.n));
};

bool operator!= (Rational &a, Rational &b){ // != operator overloading (for Rational structure)
    return !(a==b);
};

ostream& operator<< (std::ostream& out, const Rational &a){ // << output operator overloading (for Rational structure)
    return out << a.m << "/" << a.n;
};

istream& operator>> (std::istream& in, Rational &a){ // >> input overloading (for Rational structure)
    in >> a.m >> a.n;
    int g = gcd (a.m, a.n);
    a.m /= g;
    a.n /= g;
    return in;
};

void testing_rational (Rational &num1, Rational &num2){ // testing and output
    cout << "First number: " << num1 << '\n' << "Second number: " << num2 << '\n' << '\n';
    cout << "Division (with / operator): (" << num1 << ") / (" << num2 << ") = " << num1/num2 << '\n';
    cout << "First number: " << num1 << '\n' << "Second number: " << num2 << '\n' << '\n';
    cout << "Multiplication (with * operator): (" << num1 << ") * (" << num2 << ") = " << num1*num2 << '\n';
    cout << "First number: " << num1 << '\n' << "Second number: " << num2 << '\n' << '\n';
    cout << "Addition (with + operator): (" << num1 << ") + (" << num2 << ") = " << num1+num2 << '\n';
    cout << "First number: " << num1 << '\n' << "Second number: " << num2 << '\n' << '\n';
    cout << "Subtraction (with - operator): (" << num1 << ") - (" << num2 << ") = " << num1-num2 << '\n';
    cout << "First number: " << num1 << '\n' << "Second number: " << num2 << '\n' << '\n';
    if (num1 > num2) cout << num1 << " > " << num2 << '\n' << '\n';
    if (num1 >= num2) cout << num1 << " >= " << num2 << '\n' << '\n';
    if (num1 == num2) cout << num1 << " = " << num2 << '\n' << '\n';
    if (num1 <= num2) cout << num1 << " <= " << num2 << '\n'  << '\n';
    if (num1 < num2) cout << num1 << " < " << num2 << '\n'  << '\n';
    if (num1 != num2) cout << num1 << " != " << num2 << '\n'  << '\n';
    cout << "Multiplication (with *= operator): (" << num1;
    num1 *= num2;
    cout << ") * (" << num2 << ") = " << num1 << '\n';
    cout << "First number: " << num1 << '\n' << "Second number: " << num2 << '\n' << '\n';
    cout << "Division (with /= operator): (" << num1;
    num1 /= num2;
    cout << ") / (" << num2 << ") = " << num1 << '\n';
    cout << "First number: " << num1 << '\n' << "Second number: " << num2 << '\n' << '\n';
    cout << "Addition (with += operator): (" << num1;
    num1 += num2;
    cout << ") + (" << num2 << ") = " << num1 << '\n';
    cout << "First number: " << num1 << '\n' << "Second number: " << num2 << '\n' << '\n';
    cout << "Subtraction (with -= operator): (" << num1;
    num1 -= num2;
    cout << ") - (" << num2 << ") = " << num1 << '\n';
    cout << "First number: " << num1 << '\n' << "Second number: " << num2 << '\n' << '\n';
}

int main()
{
    Rational usnum1, usnum2;
    cout << "Input your first number:\n";
    cin >> usnum1;
    cout << "Input your second number:\n";
    cin >> usnum2;
    testing_rational(usnum1, usnum2);
    return 0;
}

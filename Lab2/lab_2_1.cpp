#include <iostream>
#include <cmath>

double f(double x) {
    return x - cos(x);
}

int main() {
    double a, b, c;
    double e = 0.0001;

    std::cout << "Enter a and b: ";
    std::cin >> a >> b;

    while ((b - a) > e) {
        c = (a + b) / 2.0;

        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    double res = (a + b) / 2.0;

    std::cout << "Result = " << res << std::endl;

    return 0;
}

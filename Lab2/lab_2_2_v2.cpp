#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double h = 0.2;
    double e = 0.000001;

    std::cout << std::setw(12) << "X"
              << std::setw(12) << "Y(x)"
              << std::setw(12) << "S(x)"
              << std::setw(8) << "N" << std::endl;

    for (double x = 0.0; x <= 1.0 + h / 2; x += h) {

        double y = (exp(x) + exp(-x)) / 2.0;

        double s = 1.0;
        double t = 1.0;
        int n = 0;

        while (true) {
            n++;
            t = t * (x * x) / ((2 * n - 1) * (2 * n));

            if (std::abs(t) < e) {
                n--;
                break;
            }

            s += t;
        }

        std::cout << std::fixed << std::setprecision(6);
        std::cout << std::setw(12) << x
                  << std::setw(12) << y
                  << std::setw(12) << s
                  << std::setw(8) << n << std::endl;
    }

    return 0;
}

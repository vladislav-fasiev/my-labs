#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int t = 0;
    int h = 0;
    int d = 0;
    bool p = 0;

    cout << "Ввод параметров звонка:" << endl;

    cout << "Длительность (мин): ";
    cin >> t;
    if (t <= 0) {
        cout << "Ошибка: время должно быть больше 0" << endl;
        return 1;
    }

    cout << "Час начала (0-23): ";
    cin >> h;
    if (h < 0 || h > 23) {
        cout << "Ошибка: неверный час" << endl;
        return 1;
    }

    cout << "День недели (1-7): ";
    cin >> d;
    if (d < 1 || d > 7) {
        cout << "Ошибка: неверный день" << endl;
        return 1;
    }

    cout << "Постоянный клиент (1-да, 0-нет): ";
    cin >> p;

    cout << endl;

    double price = 0.0;
    string name = "";

    if (d >= 1 && d <= 5) {
        if (h >= 8 && h < 22) {
            price = 5.0;
            name = "Будни (Дневной)";
        } else {
            price = 3.0;
            name = "Будни (Ночной)";
        }
    } else {
        price = 2.0;
        name = "Выходной тариф";
    }

    double s_base = t * price;
    double sk1 = 0.0; 
    double sk2 = 0.0; 

    if (t > 60) {
        sk1 = s_base * 0.10;
    }

    if (p == 1) {
        sk2 = s_base * 0.05;
    }

    double s_netto = s_base - sk1 - sk2;
    double nds = s_netto * 0.20;
    double total = s_netto + nds;

    cout << fixed << setprecision(2);

    cout << "=== ИТОГОВЫЙ РАСЧЕТ ===" << endl;
    cout << "Тариф: " << name << endl;
    cout << "Базовая цена: " << s_base << " руб" << endl;
    cout << "Скидка за время: " << sk1 << " руб" << endl;
    cout << "Скидка клиента: " << sk2 << " руб" << endl;
    cout << "Цена без НДС: " << s_netto << " руб" << endl;
    cout << "НДС 20%: " << nds << " руб" << endl;
    cout << "ИТОГО К ОПЛАТЕ: " << total << " руб" << endl;

    return 0;
}

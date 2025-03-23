#include <iostream>
using namespace std;

class Rupee {
private:
    long data;

public:
    Rupee(int rupee = 0) : data(rupee) {}

    Rupee operator-() const {
        return Rupee(-data);
    }

    Rupee operator+(const Rupee& obj) const {
        return Rupee(data + obj.data);
    }

    Rupee operator-(const Rupee& obj) const {
        return Rupee(data - obj.data);
    }

    Rupee& operator+=(const Rupee& obj) {
        data += obj.data;
        return *this;
    }

    Rupee& operator-=(const Rupee& obj) {
        data -= obj.data;
        return *this;
    }

    long getData() const {
        return data;
    }

    friend ostream& operator<<(ostream& os, const Rupee& e) {
        os << e.getData();
        return os;
    }
};

int main() {
    Rupee wholesale(20), retail;
    retail = wholesale;
    cout << "Wholesale price: " << wholesale << endl;
    cout << "Retail price: " << retail << endl;

    Rupee discount(2);
    retail -= discount;
    cout << "Retail price including discount: " << retail << endl;

    wholesale = Rupee(34);
    cout << "New wholesale price: " << wholesale << endl;

    retail = wholesale + Rupee(10);
    cout << "New retail price: " << retail << endl;

    Rupee profit(retail - wholesale);
    cout << "The profit: " << profit << endl;

    profit = -profit;
    cout << "The profit after unary minus: " << profit << endl;

    return 0;
}

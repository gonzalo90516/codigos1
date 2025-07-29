
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

bool is_curious(int num) {
    int original = num;
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += factorial(digit);
        num /= 10;
    }
    return sum == original;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        if (is_curious(num))
            cout << "Y\n";
        else
            cout << "N\n";
    }
    return 0;
}


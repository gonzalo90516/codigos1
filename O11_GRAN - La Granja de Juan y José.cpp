#include <iostream>
using namespace std;

int main() {
    long long X, Y;
    while (cin >> X >> Y && (X || Y)) {
        if (Y % 2 || Y < 2*X || Y > 4*X) {
            cout << "-1\n";
        } else {
            cout << 2*X - Y/2 << " " << Y/2 - X << "\n";
        }
    }
    return 0;
}

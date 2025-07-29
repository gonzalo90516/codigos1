#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

// Función para encontrar el número más pequeño de 0s y 1s divisible por X
string smallestMultiple(int X) {
    if (X == 0) return "";

    queue<pair<string, int>> q;
    unordered_set<int> visited;

    q.push({"1", 1 % X});
    visited.insert(1 % X);

    while (!q.empty()) {
        auto [numStr, remainder] = q.front();
        q.pop();

        if (remainder == 0) {
            return numStr;
        }

        // Agrega '0'
        int rem0 = (remainder * 10) % X;
        if (!visited.count(rem0)) {
            q.push({numStr + "0", rem0});
            visited.insert(rem0);
        }

        // Agrega '1'
        int rem1 = (remainder * 10 + 1) % X;
        if (!visited.count(rem1)) {
            q.push({numStr + "1", rem1});
            visited.insert(rem1);
        }
    }

    return "";
}

int main() {
    int X;
    while (cin >> X && X != 0) {
        cout << smallestMultiple(X) << endl;
    }
    return 0;
}

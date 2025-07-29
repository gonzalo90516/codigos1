#include<bits/stdc++.h>
using namespace std;
main()
{
    int n1, d1, n2, d2;
    while (true)
     {
        cin >> n1 >> d1 >> n2 >> d2;
        if (n1 == 0 && d1 == 0 && n2 == 0 && d2 == 0) break;
        if (n1 * d2 == n2 * d1) cout << "=" << endl;
        else cout << "!=" << endl;
    }
    return 0;
}


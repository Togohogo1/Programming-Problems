#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long a, b, a1, a2, a3;

    cin >> a >> b;

    a1 = a+b;
    a2 = abs(a - b);
    a3 = a*b;

    cout << max({a1, a2, a3});
    return 0;
}

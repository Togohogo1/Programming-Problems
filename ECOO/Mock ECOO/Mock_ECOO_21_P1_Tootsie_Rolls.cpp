#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    if (N < 3)
        cout << "Rocket!";
    else if (N > 7)
        cout << "Tootsie Roll!";
    else
        cout << "NO";
}

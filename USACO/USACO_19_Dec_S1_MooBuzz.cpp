#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long N;

    cin >> N;

    if (15*N/8 % 3 == 0 or 15*N/8 % 5 == 0)
        cout << 15*N/8 - 1;
    else
        cout << 15*N/8;
}
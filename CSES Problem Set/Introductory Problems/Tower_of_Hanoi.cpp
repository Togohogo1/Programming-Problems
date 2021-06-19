#include <bits/stdc++.h>

using namespace std;

int n;

void hanoi(int st, int aux, int ed, int disks) {
    if (!disks) {
        return;
    }

    hanoi(st, ed, aux, disks-1);
    cout << st << ' ' << ed << '\n';
    hanoi(aux, st, ed, disks-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    cout << pow(2, n) - 1 << '\n';
    hanoi(1, 2, 3, n);
}

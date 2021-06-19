#include <bits/stdc++.h>

using namespace std;

int N;

void hanoi(int disks, string start, string help, string end) {
    if (disks == 0)
        return;

    hanoi(disks-1, start, end, help);
    cout << start + end << '\n';
    hanoi(disks-1, help, start, end);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    hanoi(N, "A", "B", "C");
}

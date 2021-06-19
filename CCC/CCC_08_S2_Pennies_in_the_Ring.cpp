#include <bits/stdc++.h>

using namespace std;

int r = -1;

int pen(int rad) {
    int cnt = 0;

    for (int i = 0; i < rad; i++) {
        cnt += floor(sqrt(rad*rad - i*i));
    }

    return cnt*4 + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while (true) {
        cin >> r;

        if (r == 0)
            break;

        cout << pen(r) << '\n';
    }
}

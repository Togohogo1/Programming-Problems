#include <bits/stdc++.h>

using namespace std;

double nums, N1, N2, n1, n2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N1;

    for (int i = 0; i < N1; i++) {
        cin >> n1;
        nums += n1;
    }

    cin >> N2;

    for (int i = 0; i < N2; i++) {
        cin >> n2;

        nums += n2;
        N1 += 1;

        // one way to round to 3 decimal places
        printf("%.3f\n", nums/N1);
    }
}

#include <bits/stdc++.h>

using namespace std;

int N, flo[102], cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> flo[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int sum = 0;
            float avg = 0;

            if (i == j)
                cnt++;
            else {
                for (int k = i; k <= j; k++) {
                    sum += flo[k];
                }

                avg = sum / (float)(j-i+1);

                if (abs(avg - (int)avg) == 0) {
                    for (int k = i; k <= j; k++) {
                        if (flo[k] == (int)avg) {
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << cnt << '\n';
}

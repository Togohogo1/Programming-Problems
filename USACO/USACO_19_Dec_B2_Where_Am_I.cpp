#include <bits/stdc++.h>

using namespace std;

int N;
string S;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> S;

    for (int len = 1; len <= N; len++) {
        bool flag = true;

        for (int i = 0; i + len <= N; i++){
            string sub = S.substr(i, len);
            int p1 = S.find(sub), p2 = S.find(sub, p1+1);

            if (p2 != -1) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << len << endl;
            return 0;
        }
    }
}

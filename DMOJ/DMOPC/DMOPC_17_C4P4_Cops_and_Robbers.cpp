#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6+2;
int N, a, last, it, final[MAX], guard[MAX];
vector<int> aux;
set<int> police;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> guard[i];
    }

    for (int i = 0; i < N; i++) {
        if (!police.count(guard[i])) {
            final[i] = last;
            last = guard[i];
            police.insert(last);
        }
    }

    final[0] = last;

    for (int i = 1; i <= N; i++) {
        if (!police.count(i))
            aux.push_back(i);
    }

    if (police.size() == 1)
        cout << "-1\n";
    else {
        for (int i = 0; i < N; i++) {
            if (final[i] > 0)
                cout << final[i] << ' ';
            else {
                cout << aux[it++] << ' ';
            }
        }
    }
}

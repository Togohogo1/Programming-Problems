#include<bits/stdc++.h>

using namespace std;

int N, x, c;
set<int> s;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x;
        s.insert(x);
    }

    cout << s.size() << "\n";
}

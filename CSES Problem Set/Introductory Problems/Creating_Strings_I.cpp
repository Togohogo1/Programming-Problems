#include <bits/stdc++.h>

using namespace std;

string n;
bool vis[9];
set<string> words;

void fun(string tmp) {
    if (tmp.size() == n.size()) {
        words.insert(tmp);
    }

    for (int i = 0; i < n.size(); i++) {
        if (!vis[i]) {
            vis[i] = true;
            fun(tmp+n[i]);
            vis[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    sort(n.begin(), n.end());
    fun("");

    cout << words.size() << '\n';

    for (string i : words) {
        cout << i << '\n';
    }
}

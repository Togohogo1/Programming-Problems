#include <bits/stdc++.h>

using namespace std;

string s;

void fun(string s, string perm) {
    if (s == "")
        cout << perm << '\n';

    for (char i : s) {
        string t = s;
        t.erase(remove(t.begin(), t.end(), i), t.end());
        fun(t, perm+i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> s;
    sort(s.begin(), s.end());
    fun(s, "");
}

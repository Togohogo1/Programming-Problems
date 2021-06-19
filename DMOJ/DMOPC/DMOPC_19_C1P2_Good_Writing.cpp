#include<bits/stdc++.h>

using namespace std;

int Q, lvl, idx;
long long len[31];
string base= "Good writing is good writing is good writing.";
string pre = "Good writing is good ";
string mid = " writing is good ";
string suf = " is good writing.";

char fun(int lvl, int idx) {
    if (lvl == 0)
        return base[idx];

    // In the prefix section
    if (idx < pre.length())
        return pre[idx];

    idx -= pre.length();

    // First part that goes deeper
    if (idx < len[lvl-1])
        return fun(lvl-1, idx);

    idx -= len[lvl-1];

    // In the mid section
    if (idx < mid.length())
        return mid[idx];

    idx -= mid.length();

    // Second part that goes deeper
    if (idx < len[lvl-1])
        return fun(lvl-1, idx);

    idx -= len[lvl-1];

    // In the suffix section
    return suf[idx];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // Preprocessing len of each level
    len[0] = base.length();

    for (int i = 1; i <= 30; i++) {
        len[i] = pre.length() + len[i-1] + mid.length() + len[i-1] + suf.length();
    }

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> lvl >> idx;
        idx--;

        if (idx >= len[lvl])
            cout << ".\n";
        else
            cout << fun(lvl, idx) << '\n';
    }
}

#include<bits/stdc++.h>

using namespace std;

const int MM = 1e5+2, AP = 26;
int N, M, frq, toIdx, table[MM][AP], nxt[AP], freq[AP];
char let, ans[MM];
string fin;
vector<pair<int, pair<int, int>>> sug;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> let >> frq >> toIdx;
        sug.push_back({toIdx, {frq, let}});
    }

    sort(sug.begin(), sug.end());

    for (auto query : sug) {
        let = query.second.second;
        frq = query.second.first - freq[let-'a'];
        toIdx = query.first;

        if (frq == 0) {
            for (int i = nxt[let-'a']; i < toIdx; i++) {
                if (table[i][let-'a'] != -1) {
                    table[i][let-'a'] = -1;
                    nxt[let-'a'] = i+1;
                }
            }

        } else {
            for (int i = nxt[let-'a']; i < toIdx; i++) {
                // Once letters are used up, fill rest of row with -1
                if (frq == 0) {
                    table[i][let-'a'] = -1;
                    nxt[let-'a'] = i+1;
                    continue;
                }

                // Letter can be placed
                if (table[i][let-'a'] == 0) {
                    table[i][let-'a'] = 1;
                    freq[let-'a']++;
                    ans[i] = let;

                    // Only one letter per cell
                    for (int j = 0; j < AP; j++) {
                        if (table[i][j] == 0) {
                            table[i][j] = -1;  // Unusable row

                            // Ensures first cell available is selected to be next
                            if ((i+1) - nxt[j] <= 1)
                                nxt[j] = i+1;
                        }
                    }

                    if ((i+1) - nxt[let-'a'] <= 1)
                        nxt[let-'a'] = i+1;

                    frq--;
                }
            }
        }

        if (frq != 0) {
            cout << -1 << '\n';
            return 0;
        }
    }

    // Fill in unfilled cells
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < AP; j++) {
            if (table[i][j] == 0 && !ans[i]) {
                ans[i] = j+'a';
                break;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (!ans[i]) {
            cout << -1 << '\n';
            return 0;
        }

        fin += ans[i];

    }

    cout << fin << '\n';
}

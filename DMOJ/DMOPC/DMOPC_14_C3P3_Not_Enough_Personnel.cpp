#include <bits/stdc++.h>

using namespace std;

int N, Q, name, skill, new_skill, new_adapt;
bool found = false;
string temp;
pair<pair<int, int>, string> vets[502];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> vets[i].second >> vets[i].first.first;
        vets[i].first.second = i;
    }

    sort(vets, vets+N);
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> new_skill >> new_adapt;

        for (int j = 0; j < N; j++) {
            if (vets[j].first.first <= new_skill + new_adapt && vets[j].first.first >= new_skill) {
                found = true;
                temp = vets[j].second;
                break;
            }
        }

        cout << (found ? temp : "No suitable teacher!") << "\n";
        found = false;
    }
}

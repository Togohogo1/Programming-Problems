#include <bits/stdc++.h>

using namespace std;

int D, F, T, tim[1002], bark[1002], cnt[1002];
vector<int> graph[1002];
map<int, queue<int>> dist;
priority_queue<int> pq;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> D;

    for (int i = 1; i <= D; i++) {
        int wi;
        cin >> wi;
        bark[i] = wi;
    }

    cin >> F;

    for (int i = 1; i <= F; i++) {
        int di, dj;
        cin >> di >> dj;

        if (!count(graph[di].begin(), graph[di].end(), dj))
            graph[di].push_back(dj);
    }

    cin >> T;

    cnt[1]++;
    tim[1] = 0;
    pq.push(0);
    dist[0].push(1);

    int cVal = 0, cDog = 1;

    while (!pq.empty()) {
        cVal = -pq.top();
        cDog = dist[cVal].front();

        dist[cVal].pop();
        pq.pop();

        for (int nDog : graph[cDog]) {
            int nDist = bark[nDog] + cVal;

            if (tim[nDog] == 0 || (tim[nDog] < cVal && tim[nDog] < T)) {
                dist[nDist].push(nDog);
                pq.push(-nDist);
                tim[nDog] = nDist;

                if (nDist <= T)
                    cnt[nDog]++;
            }
        }
    }

    for (int i = 1; i <= D; i++) {
        cout << cnt[i] << '\n';
    }
}

#include <bits/stdc++.h>

using namespace std;

struct Cow {
    int x, y, id, gr;
};

bool cmpX(Cow c1, Cow c2) {
    return c1.x < c2.x;
}

bool cmpY(Cow c1, Cow c2) {
    return c1.y < c2.y;
}

int N, block[1002], indeg[1002];
vector<Cow> cowX, cowY;
vector<int> adj[1002];
char op;

void dfs(int u) {
    for (int v : adj[u]) {
        dfs(v);
        block[u] += block[v] + 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 1, x, y; i <= N; i++) {
        cin >> op >> x >> y;

        if (op == 'N')
            cowX.push_back({x, y, i, -1});
        else
            cowY.push_back({x, y, i, -1});
    }

    sort(cowX.begin(), cowX.end(), cmpX);
    sort(cowY.begin(), cowY.end(), cmpY);

    for (auto &cx : cowX) {
        for (auto &cy : cowY) {
            // Intersection
            if (cx.x >= cy.x && cx.y <= cy.y) {
                int dx = abs(cx.x-cy.x), dy = abs(cx.y-cy.y);
                // cx moving N haven't been stuck
                if (cx.gr < 0 && cy.gr < 0) {
                    // cy moving E gets stuck
                    if (dx > dy) {
                        cy.gr = dx;
                        indeg[cy.id] = 1;
                        adj[cx.id].push_back(cy.id);
                    // cx moving N gets stuck
                    } else if (dx < dy) {
                        cx.gr = dy;
                        indeg[cx.id] = 1;
                        adj[cy.id].push_back(cx.id);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!indeg[i])
            dfs(i);
    }

    for (int i = 1; i <= N; i++) {
        cout << block[i] << '\n';
    }
}

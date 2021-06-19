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

int N, grass[52];
vector<Cow> cowX, cowY;
char op;

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
            if (cx.x > cy.x && cx.y < cy.y) {
                int dx = abs(cx.x-cy.x), dy = abs(cx.y-cy.y);
                // cx moving N haven't been stuck
                if (cx.gr < 0 && cy.gr < 0) {
                    // cy moving E gets stuck
                    if (dx > dy) {
                        cy.gr = dx;
                        grass[cy.id] = dx;
                    // cx moving N gets stuck
                    } else if (dx < dy) {
                        cx.gr = dy;
                        grass[cx.id] = dy;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (grass[i] > 0)
            cout << grass[i] << '\n';
        else
            cout << "Infinity" << '\n';
    }
}

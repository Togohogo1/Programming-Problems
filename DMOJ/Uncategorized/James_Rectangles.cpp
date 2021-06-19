#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <map>

using namespace std;

int main() {
    int N, x, y, c = 0;
    double xm, ym, d;
    cin >> N;

    map<tuple<double, double, double>, int> sols;
    int pts[N][2];

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        pts[i][0] = x;
        pts[i][1] = y;
    }

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int x1 = pts[i][0], y1 = pts[i][1];
            int x2 = pts[j][0], y2 = pts[j][1];

            xm = (x1+x2) / 2.0;
            ym = (y1+y2) / 2.0;
            d = sqrt((x1-xm)*(x1-xm) + (y1-ym)*(y1-ym));

            if (d != 0) {
                sols.insert({{d, xm, ym}, 0});
                c += sols[{d, xm, ym}] / 2;
            }

            sols[{d, xm, ym}] += 1;
        }
    }

    cout << c/2 << "\n";
}

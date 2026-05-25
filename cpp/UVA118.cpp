//https://zerojudge.tw/ShowProblem?problemid=c082
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y;
    cin >> X >> Y;

    string dirs = "NESW";
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool scent[55][55] = {};

    int x, y;
    char c;
    string cmd;

    while (cin >> x >> y >> c >> cmd) {
        int d = dirs.find(c);
        bool lost = false;

        for (char op : cmd) {
            if (lost) break;

            if (op == 'L') {
                d = (d + 3) % 4;
            } 
            else if (op == 'R') {
                d = (d + 1) % 4;
            } 
            else {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx > X || ny < 0 || ny > Y) {
                    if (scent[x][y]) continue;

                    scent[x][y] = true;
                    lost = true;
                } else {
                    x = nx;
                    y = ny;
                }
            }
        }

        cout << x << ' ' << y << ' ' << dirs[d];
        if (lost) cout << " LOST";
        cout << '\n';
    }

    return 0;
}


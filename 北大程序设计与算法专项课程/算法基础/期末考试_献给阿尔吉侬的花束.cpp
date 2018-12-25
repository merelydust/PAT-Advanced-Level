// scanf读取char与换行符不得不说的坑爹故事
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 210;

struct node {
    int x, y, step;
    char data;
}mp[maxn][maxn];
node S, E;

int inq[maxn][maxn];
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

int row, col;
bool judge(int x, int y) {
    if (x < 0 || x >= row || y < 0 || y >= col || mp[x][y].data == '#' || inq[x][y]) return false;
    return true;
}

int solve() {
    queue<node> Q;
    Q.push(S); inq[S.x][S.y] = 1;
    while (!Q.empty()) {
        node fro = Q.front(); Q.pop();
        if (fro.x == E.x && fro.y == E.y) return fro.step;
        for (int i = 0; i < 4; ++i) {
            int newX = fro.x + X[i], newY = fro.y + Y[i];
            if (judge(newX, newY)) {
                mp[newX][newY].step = fro.step + 1;
                Q.push(mp[newX][newY]); inq[newX][newY] = 1;
            }
        }
    }
    return -1; // 无法到达
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> row >> col;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cin >> mp[i][j].data; mp[i][j].x = i; mp[i][j].y = j;
                if (mp[i][j].data == 'S') S = mp[i][j];
                else if (mp[i][j].data == 'E') E = mp[i][j];
            }
        }
        memset(inq, 0, sizeof(inq)); mp[S.x][S.y].step = 0;
        int ans = solve();
        if (ans != -1) printf("%d\n", ans);
        else printf("oop!\n");
    }
    return 0;
}

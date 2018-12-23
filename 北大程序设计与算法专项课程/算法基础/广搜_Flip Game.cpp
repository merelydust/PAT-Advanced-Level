#include <iostream>
using namespace std;

int chess[4][4];
int mincnt = 17; // 棋子翻转偶数次=翻转0次 翻转奇数次=翻转1次 所以最多翻16次 初始化为非法值

void build() {
    char c;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j <4; ++j) {
            cin >> c;
            if (c == 'w') chess[i][j] = 0;
            else chess[i][j] = 1;
        }
    }
}

void turn(int x, int y) { // 翻转第x行y列的棋子
    if (x >= 0 && x < 4 && y >= 0 && y < 4) chess[x][y] = !chess[x][y];
}

void flip(int now) { // 模拟翻转第now个棋子
    int i = now / 4; // 行号
    int j = now % 4; // 列号
    turn(i,j);
    turn(i+1,j);
    turn(i,j+1);
    turn(i-1,j);
    turn(i,j-1);
}

bool complete() {
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) cnt += chess[i][j];
    }
    if (cnt % 16 == 0) return true; // 如果cnt为16全黑或为0全白
    else return false;
}

void dfs(int now, int flipCnt) { // now当前棋子 flipCnt翻转的棋子个数
    if (complete()) {
        if (mincnt > flipCnt) mincnt = flipCnt; // 更新mincnt
        return;
    }
    if (now >= 16) return; // 棋子全部翻过一遍
    dfs(now+1, flipCnt); // 不翻转now的分支
    flip(now); // 翻转now的分支
    dfs(now+1, flipCnt+1);
    flip(now); // 结束翻转now的分支 还原状态
}

int main() {
    build();
    dfs(0, 0);
    if (mincnt == 17) cout << "Impossible" << endl;
    else cout << mincnt << endl;
    return 0;
}

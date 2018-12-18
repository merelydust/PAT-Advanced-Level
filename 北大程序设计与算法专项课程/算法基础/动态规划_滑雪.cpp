#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
int row, col, maxL = -1;
int arr[maxn][maxn] = {0};
int dp[maxn][maxn] = {0};
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

int cal(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    int preL = 0; // 该点向四周能滑的最长长度
    for (int i = 0; i < 4; ++i) {
        int newX = x + X[i], newY = y + Y[i];
        if (newX < 0 || newX >= row || newY < 0 || newY >= col) continue;
        if (arr[newX][newY] < arr[x][y]) preL = max(preL, cal(newX, newY));
    }
    dp[x][y] = preL + 1; // 该点能滑的最长长度=四周能滑的最长长度+1
    return dp[x][y];
}

int main() {
    scanf("%d %d", &row, &col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) scanf("%d", &arr[i][j]);
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) maxL = max(cal(i, j), maxL);
    }
    printf("%d\n", maxL);
    return 0;
}

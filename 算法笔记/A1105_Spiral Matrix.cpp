// 超时了两个测试点emmm回头再优化
// 将一个序列降序排列 填入一个顺时针螺旋矩阵
// 穷尽四个方向 直到遇到死胡同或已经访问过
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 10010; int n;
int arr[maxn] = {0}, ans[maxn][maxn] = {0};
int row, col;
bool vis[maxn][maxn] = {false};
int C[4] = {1, 0, -1, 0};
int R[4] = {0, 1, 0, -1}; // 右下左上四个走法对行列的影响

bool cmp(int a, int b) {
    return a > b;
}

bool judge(int r, int c, int cnt) { // 判断是否到死胡同
    if (r >= row || r < 0 || c >= col || c < 0 || vis[r][c]) return false;
    if (cnt > n) return false;
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    sort(arr, arr+n, cmp);
    row = col = int(sqrt(n));
    if (row * col < n) row = n / col;
    ans[0][0] = arr[0]; vis[0][0] = true; // 初始化起点
    int cnt = 1, r = 0, c = 0;
    while (cnt < n) {
        while (judge(r+R[0], c+C[0], cnt)) {
            r += R[0]; c += C[0]; ans[r][c] = arr[cnt++];
            vis[r][c] = true;
        }
        while (judge(r+R[1], c+C[1], cnt)) {
            r += R[1]; c += C[1]; ans[r][c] = arr[cnt++];
            vis[r][c] = true;
        }
        while (judge(r+R[2], c+C[2], cnt)) {
            r += R[2]; c += C[2]; ans[r][c] = arr[cnt++];
            vis[r][c] = true;
        }
        while (judge(r+R[3], c+C[3], cnt)) {
            r += R[3]; c += C[3]; ans[r][c] = arr[cnt++];
            vis[r][c] = true;
        }
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (j) printf(" ");
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

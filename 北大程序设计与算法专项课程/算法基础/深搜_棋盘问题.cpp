// 这道题输入有点坑啊 用stdio的话要考虑很多换行符的事情。。还是cin保险
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, cnt;
char arr[10][10]; int row[10], col[10], rec[10]; // rec[10]记录棋子放在第几行
void dfs(int now) { // 当前排了几个棋子
    for (int i = rec[now-1]; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (arr[i][j] == '#' && !row[i] && !col[j]) {
                rec[now] = i;
                row[i] = col[j] = 1;
                if (now == k) ++cnt;
                else dfs(now+1);
                row[i] = col[j] = 0;
            }
        }
    }
}

int main() {
    while (scanf("%d %d", &n, &k) != EOF) {
        if (n == -1 && k == -1) break;
        fill(row, row+10, 0); fill(col, col+10, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) cin >> arr[i][j];
        }
        cnt = 0; dfs(1);
        printf("%d\n", cnt);
    }
    return 0;
}

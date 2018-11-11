// n皇后问题 暴力法(高效枚举+递归实现排列)
// 普通暴力枚举 n^2里取n的排列数
// 高效枚举 每一列只会有有一个皇后->只会有一个行号->枚举行号的全排列再检验是否合法
// P[n] 下标i是列号 值P[i]是行号
#include <cstdio>
using namespace std;

int abs(int a) {
    if (a >= 0) return a;
    else return 0-a;
}
int cnt = 0; // 合法方案数
const int maxn = 100; int n;
int P[maxn] = {0}, hashtable[maxn] = {0};

void generateP(int index) {
    if (index == n+1) { // 一个排列已经生成
        bool flag = true; // 该排列是否有效
        for (int i = 1; i <= n; ++i) { // i是列
            for (int j = i+1; j <= n; ++j) {
                if (abs(i-j) == abs(P[i] - P[j])) flag = false; // 如果在一条对角线上
            }
        }
        if (flag) {
            cnt++; return;
        }
    }
    for (int r = 1; r <= n; ++r) {
        if (!hashtable[r]) { // 枚举行号
            P[index] = r; hashtable[r] = 1;
            generateP(index+1);
            hashtable[r] = 0;
        }
    }
}

int main() {
    n = 8;
    generateP(1);
    printf("%d\n", cnt);
    return 0;
}

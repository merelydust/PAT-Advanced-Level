// n皇后问题 回溯法
// 有可能当已经放置了一些皇后 剩下的皇后怎么放都不合法 直接返回上层
// 在到达递归边界前的某层 由于一些事实导致不需要子递归了 就可以直接返回上一层
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
    if (index == n+1) {
        cnt++; return; // 能到达这里的一定是合法的
    }
  
    for (int r = 1; r <= n; ++r) {
        if (!hashtable[r]) { // 枚举行号
            bool flag = true; // flag为true 当前皇后不会和之前皇后冲突
            for (int pre = 1; pre < index; ++pre) { // 遍历之前 列 的皇后 行号
                if (abs(index - pre) == abs(r - P[pre])) {
                    flag = false; break;
                }
            }
            if (flag) { // 如果可以把皇后放在r行
                P[index] = r; hashtable[r] = 1;
                generateP(index+1);
                hashtable[r] = 0;
            }
        }
    }
}

int main() {
    n = 8;
    generateP(1);
    printf("%d\n", cnt);
    return 0;
}

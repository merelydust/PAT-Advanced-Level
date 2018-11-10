#include <cstdio>
using namespace std;

int n; // n是要排列的数字个数
const int maxn = 10; int p[maxn+1];
int hashtable[maxn+1] = {0};
void generateP(int index) { // index是当前要排的位子序号
    if (index == n) { // 0~n-1位已经排完了 一种排列完成 递归出口outlet
        for (int i = 0; i < n; ++i) {
            printf("%d", p[i]);
        } printf("\n"); return;
    }
    //index还没到最后一位 按序枚举index处可以安置的数字
    for (int num = 1; num <= n; ++num) { // 枚举的功能就是得到 1开头的全排列(12xx..13..) 2开头的全排列...
        if (!hashtable[num]) { // 这个数字没被占用
            p[index] = num; hashtable[num] = 1;
            generateP(index+1); // index处安排好了 后面的index+1~n-1位 不管他 交给递归完成
            hashtable[num] = 0; // 后面都安排上了 已经在outlet输出了 解除当前该处数字的占用
        }
    }
}

int main() {
    n = 3;
    generateP(0); // 从第0位开始排列
    return 0;
}

/***
 牛跟牛之间有安全距离 即最小距离
 要求这个安全距离的最大值
 ***/
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int n, c;
int stall[maxn] = {0};

bool check(int tmpdis) { // 验证按照tmpdis的间隔 能否安排全部C头牛
    int nCow = 0; // 已安置的牛数量
    int nowRight = stall[0]; // 把第一头牛放在第一个区间
    for (int i = 1; i <= n; ++i) {
        if (nowRight <= stall[i]) { // 如果已安排区间的右端点在下一个栏点左边 则该右端点和该栏点构成一个新区间 可以安排进一只牛
            ++nCow; nowRight = stall[i] + tmpdis;
        }
    }
    if (nCow >= c) return true; // 如果可以安排的牛数>=给定的牛数
    else return false;
}

int main() {
    scanf("%d %d", &n, &c);
    for (int i = 1; i <= n; ++i) scanf("%d", &stall[i]);
    sort(&stall[1], (&stall[1])+n);
    int left = 1, right = (stall[n]-stall[0]) / (c-1), ans = 0;
    int mid = 0; // 如果只有一个栏点 right=0
    while (left <= right) {
        mid = (left + right) / 2;
        if (check(mid)) {
            ans = mid; // 保存此时的mid值 因为之后进行到退出循环操作时check(mid)可能是无效的
            left = mid + 1;
        }
        else right = mid-1; // 牛安排不完 tmpdis要拉小 右端点左移
    }
    printf("%d\n", ans);
    return 0;
}

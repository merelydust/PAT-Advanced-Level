/***
 用stl的合并函数最后一个测试点会超时 这种时候就要踏踏实实遍历
 IO说明：
 n-集合个数 接下来n行
 m-该集合元素个数 m个数字
 q-要查询的集合对数 接下来q行
 集合1 集合2
 ***/

#include <cstdio>
#include <set>
using namespace std;

const int N = 51;
set<int> st[N];

void cmp(int x, int y) {
    int totalNum = st[y].size(), sameNum = 0;
    for (set<int>::iterator it = st[x].begin(); it != st[x].end(); ++it) {
        if (st[y].find(*it) != st[y].end()) sameNum++;
        else totalNum++;
    }
    printf("%.1lf%%\n", sameNum * 100.0 / totalNum); // 先乘再除 比 先除再乘 误差小
}

int main() {
    int n, m, q, v, st1, st2;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &m);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &v); st[i].insert(v);
        }
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &st1, &st2);
        cmp(st1, st2);
    }
    return 0;
}

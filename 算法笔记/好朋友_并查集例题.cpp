#include <cstdio>
const int N = 110;

int father[N];
int isRoot[N] = {0};

void init(int n) {
    for (int i = 1; i <= n; ++i) father[i] = i;
}

int findFather(int x) { // 查找x所在集合的根节点
    int a = x; // x循环后会变成root 先存储原来的值
    while (father[x] != x) x = father[x];
    // 路径压缩
    while (father[a] != a) {
        int b = a;
        father[b] = x; // 不能一步到位把father[a]改成x 不然还怎么用father[a]更新a= =
        a = father[a];
    }
    return x;
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) father[faA] = faB;
}

int main() {
    int n, m, f1, f2;
    scanf("%d %d", &n, &m);
    init(n);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &f1, &f2);
        Union(f1, f2); // 合并朋友1和朋友2所在集合
    }
    // for (int i = 1; i <= n; ++i) isRoot[findFather(i)] = 1;
    for (int i = 1; i <= n; ++i) isRoot[father[i]] = 1; // 路径压缩过以后应该可以这样写
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans += isRoot[i];
    printf("%d\n", ans);
    return 0;
}

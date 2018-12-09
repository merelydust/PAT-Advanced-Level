/***
 同一张照片里的鸟属于同一颗树 -> 并查集
 树的数量 -> 父亲的数量
 鸟的数量 -> hash标记
 查鸟所属树 -> 查父亲
 ***/
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 10010;
int father[maxn];
bool roots[maxn] = {0}, birds[maxn] = {0};

void init() {
    for (int i = 1; i < maxn; ++i) father[i] = i;
}

int findFather(int x) {
    int a = x;
    while (father[x] != x) x = father[x];
    while (father[a] != a) {
        int b = a;
        a = father[a];
        father[b] = x;
    }
    return x;
}

void unionFather(int a, int b) {
    int faA = findFather(a), faB = findFather(b);
    if (faA != faB) father[faA] = faB;
}

int main() {
    init();
    int n; scanf("%d", &n);
    int treeNum = 0, birdNum = 0, k;
    while (n--) {
        scanf("%d", &k); int b; vector<int> v;
        while (k--) {
            scanf("%d", &b); v.push_back(b);
            if (!birds[b]) {
                birdNum++; birds[b] = 1;
            }
        }
        for (int i = 1; i < v.size(); ++i) unionFather(v[i-1], v[i]);
    }
    for (int i = 1; i <= birdNum; ++i) {
        int r = findFather(i);
        if (!roots[r]) {
            treeNum++; roots[r] = 1;
        }
    }
    printf("%d %d\n", treeNum, birdNum);
    int q; scanf("%d", &q);
    int a, b;
    while (q--) {
        scanf("%d %d", &a, &b);
        if (findFather(a) == findFather(b)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


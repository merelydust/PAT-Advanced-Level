#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int m, n;
void postOrder(int root, vector<int>& v) {
    if (root > n) return;
    postOrder(2*root, v); // 注意完全二叉树这样获取左右节点序号的话 需要从1开始编号
    postOrder(2*root+1, v);
    if (root != 1) printf("%d ", v[root]);
    else printf("%d\n", v[root]);
}

int main() {
    scanf("%d %d", &m, &n);
    while (m--) {
        vector<int> v(n+1);
        for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
        bool isMax = is_heap(v.begin()+1, v.end()); // 我怎么这么机智啊～hiahia~
        bool isMin = is_heap(v.begin()+1, v.end(), greater<int>());
        if (isMax) printf("Max Heap\n");
        else if (isMin) printf("Min Heap\n");
        else printf("Not Heap\n");
        postOrder(1, v);
    }
    return 0;
}

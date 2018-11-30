/***
 1.00 - r% -> r是0.01
 商品售出价格为 root的价格*1.01^(卖的人所在层数)
 到达了叶子节点才算卖出去 并计入总销售额
 ***/
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;


const int maxn = 100010;
struct node {
    vector<int> child;
    double amount;
}nodes[maxn];

double p, r, ans = 0.0;
void DFS(int index, int depth) { // index-正在访问的节点编号 depth层数
    if (nodes[index].child.empty()) { // 没有孩子->到达叶子节点
        ans += p * pow(1+r, depth) * nodes[index].amount; return;
    }
    for (int i = 0, len = nodes[index].child.size(); i < len; ++i) {
        DFS(nodes[index].child[i], depth+1);
    }
    
}

int main() {
    int n; scanf("%d %lf %lf", &n, &p, &r);
    r /= 100; int k, tmp; // 孩子数量 孩子序号
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        for (int j = 0; j < k; ++j){
            scanf("%d", &tmp); nodes[i].child.push_back(tmp);
        }
        if (k == 0) {
            scanf("%lf", &nodes[i].amount);
        }
    }
    DFS(0, 0);
    printf("%.1f\n", ans);
    return 0;
}

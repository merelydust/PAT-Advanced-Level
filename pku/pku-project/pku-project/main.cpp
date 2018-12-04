#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 10010;
struct node {
    int hh, mm, ss;
    int ptime, wtime;
    node() {
        wtime = 0;
    }
}nodes[maxn];

bool cmp(node a, node b) {
    if (a.hh != b.hh) return a.hh < b.hh;
    else if (a.mm < b.mm) return a.mm < b.mm;
    else return a.ss < b.ss;
}


int main() {
    int n, k; scanf("%d %d", &n, &k);
    node tmp;
    for (int i = 0; i < n; ++i) {
        scanf("%d:%d:%d %d", &tmp.hh, &tmp.mm, &tmp.ss, &tmp.ptime);
        if (tmp.hh >= 17) continue;
        else if (tmp.hh < 8) {
            
        }
        nodes[i] = tmp;
    }
    sort(nodes, nodes+n, cmp);
    queue<node> Q;
    for (int i = 0; i < 3; ++i) Q.push(nodes[i]); // 刚开门最前面三个人一起去
    int ocp = 3; // 当前被占用窗口数
    while (!Q.empty()) {
        
    }
}

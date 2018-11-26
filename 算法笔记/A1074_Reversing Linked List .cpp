/***
 建立结构体node 存储本身地址 data next地址
 建立vector<node> validNodes
 晴神的思路 把vector分为n/k块 每块反转输出 每个节点的next等于它前一个的地址
 每块末尾节点的next等于前一块末尾的地址preEnd
 ***/
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

const int maxn = 100010;
struct node {
    int address, data, next;
}nodes[maxn];

int main() {
    int head, n, k; scanf("%d %d %d", &head, &n, &k);
    node tmp;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &tmp.address, &tmp.data, &tmp.next);
        nodes[tmp.address] = tmp;
    }
    bool end = false;
    while (!end) {
        stack<node> s; vector<node> v;
        while (s.size() < k) {
            s.push(nodes[head]); v.push_back(nodes[head]); head = nodes[head].next;
            if (nodes[head].next == -1) {
                end = true; break; // 已经是最后一个节点
            }
        }
        if (s.size() == k) {
            while (!s.empty()) {
                printf("%05d %d ", s.top().address, s.top().data);
                if (s.top().next == -1) {
                    end = true; printf("-1\n");
                }
                else printf("%d\n", s.top().next);
                s.pop();
            }
        }
        else {
            for (int i = 0, len = v.size(); i < len; ++i) {
                printf("%05d %d ", v[i].address, v[i].data);
                if (v[i].next == -1) printf("-1\n");
                else printf("%05d\n", v[i].next);
            }
        }
    }
    return 0;
}

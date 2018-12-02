/***
 目前所有做错的链表题，都是因为没有更新next的地址QAQ
 调整后的链表 node的next就等于它下一个节点的address!
 
 建立nodes结构体数组
 开个一万大小的hashtable 访问过的值标记为1
 建两个node型的vector uv v
 遍历有效节点时 遇到访问过的值 push到v 否则push到uv
 ***/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int hashtable[maxn] = {0};
struct node {
    int address, data, next;
}nodes[maxn];

int main() {
    int head, n; scanf("%d %d", &head, &n);
    node tmp;
    while (n--) {
        scanf("%d %d %d", &tmp.address, &tmp.data, &tmp.next);
        nodes[tmp.address] = tmp;
    }
    node headNode = nodes[head]; bool end = false;
    vector<node> uv, v;
    while (!end) {
        if (hashtable[abs(headNode.data)]) v.push_back(headNode);
        else {
            uv.push_back(headNode); hashtable[abs(headNode.data)] = 1;
        }
        if (headNode.next == -1) break;
        headNode = nodes[headNode.next];
    }
    for (int i = 0, len = uv.size(); i < len; ++i) {
        printf("%05d %d ", uv[i].address, uv[i].data);
        if (i == len-1) printf("-1\n");
        else printf("%05d\n", uv[i+1].address);
    }
    for (int i = 0, len = v.size(); i < len; ++i) {
        printf("%05d %d ", v[i].address, v[i].data);
        if (i == len-1) printf("-1\n");
        else printf("%05d\n", v[i+1].address);
    }
}


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
    bool begin = true;
    int i =0;
    while (!end) {
        stack<node> s; vector<node> v;
        while (s.size() < k) {
            s.push(nodes[head]); v.push_back(nodes[head]); 
            if (nodes[head].next == -1) {
            	end = true; break; // 已经是最后一个节点
            }
			head = nodes[head].next;
        }
        if (s.size() == k) {
            while (!s.empty()) {
            	node now = s.top();
            	if(!begin) printf("%05d\n", now.address);
                printf("%05d %d ", now.address, now.data);
                s.pop();
                if(!s.empty()){
                    node next = s.top();
            		printf("%05d\n", next.address);
            		begin = true;
				}else{
					if (i+1==n) printf("-1\n");
					begin = false;
				}
				i++;
            }
        }
        else {
            for (int j = 0, len = v.size(); j < len; ++j) {
            	if(!begin) printf("%05d\n", v[j].address);
                printf("%05d %d ", v[j].address, v[j].data);
                if (v[j].next == -1) printf("-1\n");
                else printf("%05d\n", v[j+1].address);
                begin = true;
            }
        }
        
    }
    return 0;
}

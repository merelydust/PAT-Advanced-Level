/***
 先存储所有node
 从头节点开始遍历 把有效节点push到vector里
 对vector进行排序 输出
 ***/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10001;
struct node {
    int address, data, next;
};
vector<node> nodes;
bool cmp(node a, node b) {
    return a.data < b.data;
}

int main() {
    int n, head; scanf("%d %d", &n, &head);
    nodes.resize(200002);
    while(n--) {
    	node tmp;
        scanf("%d %d %d", &tmp.address, &tmp.data, &tmp.next);
        nodes[tmp.address] = tmp;
    }
    vector<node> validNodes; node headNode = nodes[head];
    while (headNode.address != -1) {
        validNodes.push_back(headNode); 
		if(headNode.next==-1){
			break;
		}
		headNode = nodes[headNode.next];
    }
    sort(validNodes.begin(), validNodes.end(), cmp);
	
    if (validNodes.empty()||head==-1) {
        printf("0 -1\n"); return 0;
    }
    printf("%d %05d\n", validNodes.size(), validNodes[0].address);
    for (int i = 0, len = validNodes.size(); i < len; ++i) {
        printf("%05d %d ", validNodes[i].address, validNodes[i].data);
        if (validNodes[i].next != -1) printf("%05d\n", validNodes[i].next);
        else printf("-1\n");
    }
    return 0;
}

#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 110; int n, m;
vector<int> children[maxn];
int hashtable[maxn];
bool isChild[maxn] = {false};

void DFS(int index, int depth) {
    hashtable[depth]++;
    for (int i = 0; i < children[index].size(); ++i) {
        DFS(children[index][i], depth+1);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int father, k, son;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &father, &k);
        while (k--) {
            scanf("%d", &son); children[father].push_back(son);
            isChild[son] = true;
        }
    }
    DFS(1, 1);
    int maxDepth = -1, maxPeople = 0;
    for (int i = 1; i < maxn; ++i) {
        if (hashtable[i] > maxPeople) {
            maxPeople = hashtable[i]; maxDepth = i;
        }
    }
    printf("%d %d\n", maxPeople, maxDepth);
    return 0;
}

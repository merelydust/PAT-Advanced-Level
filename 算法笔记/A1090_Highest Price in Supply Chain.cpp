#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100010;
vector<int> nodes[maxn];
int n; double p, r;

double maxDepth = -1; int num = 0;
void DFS(int index, int depth) {
    if (nodes[index].empty()) {
        if (depth > maxDepth) {
            maxDepth = depth; num = 1;
        }
        else if (depth == maxDepth) num++;
        return;
    }
    for (int i = 0; i < nodes[index].size(); ++i) {
        DFS(nodes[index][i], depth+1);
    }
}

int main() {
    scanf("%d %lf %lf", &n, &p, &r);
    r /= 100;
    int sup, root;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &sup);
        if (sup != -1) nodes[sup].push_back(i);
        else root = i;
    }
    DFS(root, 0);
    printf("%.2f %d\n", p*pow(1+r, maxDepth), num);
    return 0;
}

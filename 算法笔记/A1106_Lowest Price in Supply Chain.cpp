#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100010;
vector<int> children[maxn];

int lowestDepth = maxn, num = 0;
void DFS(int index, int depth) {
    if (children[index].empty()) {
        if (depth < lowestDepth) {
            lowestDepth = depth; num = 1;
        }
        else if (depth == lowestDepth) num++;
        return;
    }
    for (int i = 0; i < children[index].size(); ++i) {
        DFS(children[index][i], depth+1);
    }
}

int main() {
    int n; double p, r; scanf("%d %lf %lf", &n, &p, &r);
    r /= 100;
    int k, child;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &child); children[i].push_back(child);
        }
    }
    DFS(0, 0);
    printf("%.4f %d\n", p*pow(1+r, lowestDepth), num);
    return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int tree[maxn] = {0};
int numbers[maxn] = {0};

int i = 0, n;
void inOrder(int root) { // root的left是2*root right是2*root+1
    if (root > n) return;
    inOrder(2*root);
    tree[root] = numbers[i++];
    inOrder(2*root+1);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &numbers[i]);
    sort(numbers, numbers+n);
    inOrder(1); // 上面那个公式 需要root从1开始
    for (int i = 1; i <= n; ++i) {
        printf("%d", tree[i]);
        if (i != n) printf(" ");
    }
    printf("\n"); return 0;
}

// 投机取巧的我hiahia~
#include <cstdio>
using namespace std;

int main() {
    const int maxn = 100010; int nexts[maxn], hashtable[maxn];
    int head1, head2, n; scanf("%d %d %d", &head1, &head2, &n);
    if (head1 == head2) {
        printf("%05d\n", head1); return 0;
    }
    int address, next; char data;
    for (int i = 0; i < n; ++i) {
        scanf("%d %c %d", &address, &data, &next);
        nexts[address] = next;
    }
    int ans = -1;
    while(nexts[head1] != -1) {
        hashtable[nexts[head1]] = 1;
        head1 = nexts[head1];
    }
    while (nexts[head2] != -1) {
        if (hashtable[nexts[head2]]) {
            ans = nexts[head2]; break;
        }
        else head2 = nexts[head2];
    }
    if (ans == -1) printf("-1\n");
    else printf("%05d\n", ans);
    return 0;
}

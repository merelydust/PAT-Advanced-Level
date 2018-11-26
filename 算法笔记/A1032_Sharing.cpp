/***
 用数组下标模拟地址
 建一个next数组 存放下一个字符的地址 数组下标是当前字符的地址
 建一个hashtable 遍历第一个单词 地址被访问过该下标记为1
 遍历第二个单词 遇到被访问过的地址 返回地址 否则 返回-1
 ***/

#include <cstdio>
using namespace std;

int main() {
    const int maxn = 100010;
    int next[maxn] = {0}, hashtable[maxn] = {0};
    int head1, head2, n; scanf("%d %d %d", &head1, &head2, &n);
    int now, nxt; char ch;
    while (n--) {
        scanf("%d %c %d", &now, &ch, &nxt); next[now] = nxt;
    }
    while (head1 != -1) {
        hashtable[head1] = 1; head1 = next[head1];
    }
    bool find = false;
    while (head2 != -1) {
        if (hashtable[head2]) {
            find = true; break;
        }
        head2 = next[head2];
    }
    if (find) printf("%05d\n", head2);
    else printf("-1\n");
    return 0;
}

/***
 建栈模拟 now指向目标序列arr首位
 push(num) while(栈不空&&栈顶数字==arr[now]&&now<arr长度n) pop() now++
 如果now<长度n 返回NO 否则返回YES
 ***/
#include <cstdio>
#include <stack>
using namespace std;

int main() {
    int m, n , k; scanf("%d %d %d", &m, &n, &k);
    int arr[1010];
    while (k--) {
        for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
        int now = 0; stack<int> s;
        for (int i = 1; i <= n && now < n && s.size() <= m; ++i) {
            s.push(i);
            while (!s.empty() && s.top() == arr[now] && now < n) {
                s.pop(); ++now;
            }
        }
        if (now < n) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}

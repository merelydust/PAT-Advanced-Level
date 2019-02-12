#include <cstdio>
#include <stack>
using namespace std;

stack<int> s; int cnt = 0, n;
void solve(int in, int out) { // in已经入栈 out等待入栈
    if (out == 0) { // 元素已经全部入栈 out=0
        ++cnt; return;
    }
    else if (in == 0) solve(in+1, out-1); // 没有元素入栈 in = 0
    else if (out) { // 既能入栈又能出栈
        solve(in+1, out-1); // 继续入栈的分支
        solve(in-1, out); // 出栈的分支 出栈的元素被输出了而不是回到待定区 所以out不变
    }
}

int main() {
    scanf("%d", &n);
    solve(0, n);
    printf("%d\n", cnt);
    return 0;
}

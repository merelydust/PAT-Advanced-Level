#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, p, maxFacSum = -1; // 记录最大底数之和
vector<int> fac; // 存放0^p 1^p 2^p...i^p i^p<=n
vector<int> ans, tmp; // 存放最优底数序列和递归中的临时序列

int pow(int x) { // 计算x的p次方
    int ans = 1;
    for (int i = 0; i < p; ++i) ans *= x;
    return ans;
}

void init() {
    int i = 0, tmp = 0;
    while (tmp <= n) { // i^p不超过n时 不断把i^p加入fac
        fac.push_back(tmp); tmp = pow(++i);
    }
}

// 当前访问fac[index] nowK当前选中个数 sum序列当前数字之和 facSum当前底数之和
void DFS(int index, int nowK, int sum, int facSum) {
    if (sum == n && nowK == k) { // 找到一个满足的序列
        if (facSum > maxFacSum) { // 底数之和更优
            maxFacSum = facSum; ans = tmp; // 更新最优解
        } return;
    }
    if (sum > n || nowK > k) return; // 非法情况 直接返回
    if (index >= 1) { // index从1开始
        tmp.push_back(index); // 把底数index加入临时序列tmp
        DFS(index, nowK+1, sum+fac[index], facSum+index); // 选第index个数的分支
        tmp.pop_back(); // 选的分支结束后把刚加进去的数字pop掉
        DFS(index-1, nowK, sum, facSum); // 不选的分支
    }
}

int main() {
    scanf("%d %d %d", &n, &k, &p);
    init();
    DFS(fac.size()-1, 0, 0, 0); // 从fac的最后一位开始往前搜索
    if (maxFacSum == -1) printf("Impossible\n");
    else {
        printf("%d = %d^%d", n, ans[0], p);
        for (int i = 1; i < ans.size(); ++i) printf(" + %d^%d", ans[i], p);
    }
    return 0;
}

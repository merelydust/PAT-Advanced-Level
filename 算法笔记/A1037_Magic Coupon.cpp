// 思路 让同号最大的两个数相乘
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool big2small(long long a, long long b) {
    return a > b;
}

int main() {
    int nc, np;
    vector<long long> cPositive, cNegative, pPositive, pNegative;
    long long tmp;
    scanf("%d", &nc);
    for (int i = 0; i < nc; ++i) {
        scanf("%lld", &tmp);
        if (tmp >= 0) cPositive.push_back(tmp);
        else cNegative.push_back(tmp);
    }
    scanf("%d", &np);
    for (int i = 0; i < np; ++i) {
        scanf("%lld", &tmp);
        if (tmp >= 0) pPositive.push_back(tmp);
        else pNegative.push_back(tmp);
    }
    sort(cPositive.begin(), cPositive.end(), big2small);
    sort(pPositive.begin(), pPositive.end(), big2small);
    sort(cNegative.begin(), cNegative.end());
    sort(pNegative.begin(), pNegative.end());
    long long money = 0;
    int size1 = cPositive.size(), size2 = pPositive.size(), size3 = cNegative.size(), size4 = pNegative.size();
    for (int i = 0; i < size1 && i < size2; ++i) money += cPositive[i] * pPositive[i];
    for (int i = 0; i < size3 && i < size4; ++i) money += cNegative[i] * pNegative[i];
    printf("%lld\n", money);
    return 0;
}

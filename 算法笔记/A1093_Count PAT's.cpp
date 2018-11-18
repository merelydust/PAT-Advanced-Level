// PAT的个数等于=（A左边P的个数)*(A右边T的个数）* A的个数
// 为了更高效 这里的乘采用累加的方法
#include <iostream>
#include <string>
using namespace std;

int main() {
    const int maxn= 100010; long long div = 1000000007;
    int leftP[maxn] = {0}, rightTNum = 0, ans = 0;
    string s; cin >> s; int len = s.length();
    for (int i = 0; i < len; ++i) {
        if (i) leftP[i] = leftP[i-1];
        if (s[i] == 'P') leftP[i]++;
    }
    for (int i = len; i >= 0; --i) {
        if (s[i] == 'T') rightTNum++;
        else if (s[i] == 'A') ans = (ans + leftP[i]*rightTNum) % div;
    }
    printf("%d\n", ans);
    return 0;
}

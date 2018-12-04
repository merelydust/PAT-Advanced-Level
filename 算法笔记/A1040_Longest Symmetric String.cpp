/***
 边界 d[i][i]=1 d[i][i+1] = s[i]==s[i+1] ? 1 : 0
 转移 s[i] == s[j] dp[i+1][j-1] == 1 ? 1 : 0
     s[i] != s[j] dp[i][j] = 0
 为确保状态转移后的子串已经被判断 枚举子串长L来状态转移
 ***/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s; getline(cin, s); int ans = 1;
    int len = s.length(); int dp[1010][1010] = {0};
    for (int i = 0; i < len; ++i) { // 初始化
        dp[i][i] = 1;
        if (i < len-1) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = 1; ans = 2;
            }
        }
    }
    for (int l = 3; l <= len; ++l) {
        for (int i = 0; i+l-1 < len; ++i) { // 枚举长为l的子串的左右端点
            int j = i+l-1; // 右端点
            if (s[i] == s[j]) {
                if (dp[i+1][j-1]) {
                    dp[i][j] = 1; ans = l;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

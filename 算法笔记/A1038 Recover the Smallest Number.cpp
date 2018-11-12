// 晴神好聪明啊 一语点醒 原来可以cmp的时候就对拼接后的字符串排序了
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    return a+b < b+a; // "32" "321" -> "321" "32"
}

int main() {
    int n; cin >> n;
    string arr[10010];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n, cmp);
    string ans = "";
    for (int i = 0; i < n; ++i) ans += arr[i];
    while (ans != "" && ans[0] == '0') ans.erase(0, 1);
    if (ans == "") cout << "0" << endl;
    else cout << ans << endl;
    return 0;
}

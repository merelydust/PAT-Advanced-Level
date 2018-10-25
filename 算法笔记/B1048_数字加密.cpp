/***
这道题不严谨，b比a短要在左边补零才能通过，题目啥都没说= =。
***/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b; cin >> a >> b;
    int len1 = a.length(), len2 = b.length();
    if (len1 > len2) {
        int tmp = len1 - len2;
        string add = "";
        while (tmp--) add += '0';
        b = add + b;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string ans = b;
    char arr[] = {'J', 'Q', 'K'};
    int end = a.length() <= b.length() ? a.length() : b.length();
    
    for (int i = 0; i < end; ++i) {
        if (i % 2) {
            int tmp = b[i] - a[i];
            if (tmp < 0) tmp += 10;
            ans[i] = '0' + tmp;
        }
        else {
            int tmp = ((a[i]-'0') + (b[i]-'0')) % 13;
            if (tmp > 9) ans[i] = arr[tmp-10];
            else ans[i] = '0' + tmp;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}

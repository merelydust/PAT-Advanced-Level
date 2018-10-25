#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string cal(int n) {
    string ans = "";
    do { // 为了覆盖0的情况 进制转化一定要用do while 
        int tmp = n % 13;
        if (tmp < 10) ans += '0' + tmp;
        else ans += 'A' + (tmp - 10);
        n /= 13;
    } while (n);
    reverse(ans.begin(), ans.end());
    if (ans.length() == 1) ans = '0' + ans;
    return ans;
}

int main() {
    int tmp;
    cout << '#';
    for (int i = 0; i < 3; ++i) {
        cin >> tmp;
        cout << cal(tmp);
    }
    cout << endl;
    return 0;
}

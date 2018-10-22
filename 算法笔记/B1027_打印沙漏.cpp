/**
两个坑 没有remain的时候也要输出0 字符右边不打印空格
 **/
#include <iostream>
using namespace std;

int main() {
    int n;
    char ch;
    cin >> n >> ch;
    
    int i = 1;
    while (n >= 2*i*i-1) { // 用等差数列公示算出n最多支撑几行对称沙漏
        ++i;
    }
    --i; // n有剩余但不足以输出多一行时也进入了循环体 所以-1
    int line = 2 * i - 1; // 最长一行长度
    int remain = n - (2*i*i-1);
    for (int j = i; j >= 2; --j) {
        int thisline = 2 * j - 1;
        int space1 = (line - thisline) / 2;
        while (space1--) cout << ' ';
        for (int k = 0; k < thisline; ++k) cout << ch;
        cout << endl;
    }
    int space1 = (line-1) / 2;
    while (space1--) cout << ' ';
    cout << ch << endl;
    for (int j = 2; j <= i; ++j) {
        int thisline = 2 * j -1;
        int space1 = (line - thisline) / 2;
        while (space1--) cout << ' ';
        for (int k = 0; k < 2*j-1; ++k) cout << ch;
        cout << endl;
    }
    cout << remain << endl;
    return 0;
}

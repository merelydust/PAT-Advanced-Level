#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    char mark1, mark2;
    string num; int exp;
    mark1 = getchar();
    getline(cin, num, 'E');
    mark2 = getchar();
    cin >> exp;
    
    if (mark1 == '-') cout << '-'; // 输出负号
    if (!exp) {
        cout << num; return 0;
    }
    int dotpos = 1; // 原来小数点位置为1
    if (mark2 == '+') {
        cout << num[0]; // 输出原来小数点前的数
        dotpos += exp; // 小数点右移后的位置
        for (int i = 2; i <= dotpos; ++i) cout << num[i];
        if (dotpos < num.length()-1) { // 如果右移的范围没有超出num的长度
            cout << '.';
            for (int j = dotpos+1; j < num.length(); ++j) {
                cout << num[j];
            }
        }
        else if (dotpos > num.length()-1) { // 超出则补零
            int tmp = dotpos - (num.length()-1);
            while (tmp--) cout << '0';
        }
        // 右移的长度等于num长度时 不输出小数点
    }
    else if (mark2 == '-') {
        dotpos -= exp; // 小数点左移
        // 如果小数点移动了
        cout << "0.";
        dotpos++; // 右移n位只需要补n-1个零
        while (dotpos++ < 1) {
            cout << '0'; // 补零
        }
        cout << num[0]; // 原来的小数点不打印
        for (int i = 2; i < num.length(); ++i) {
            cout << num[i];
        }
    }
    cout << endl;
    return 0;
}

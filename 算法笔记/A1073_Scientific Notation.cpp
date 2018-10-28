#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    string strnum, base, strexp; cin >> strnum;
    int posE = strnum.find('E');
    strexp = strnum.substr(posE+1, strnum.length()-1-posE);
    int exp = stoi(strexp);
    base = strnum.substr(1, posE-1);
    if (exp == 0) {
        cout << base << endl; return 0;
    }
    if (strnum[0] == '-') cout << '-';
    base.erase(1,1); // 去除小数点
    strnum = base;
    
    if (exp >= 0) {
        if (exp > base.length() - 1) { // 如果右移到base长度后面 补零
            for (int i = 0; i < exp-(base.length()-1); ++i) strnum += '0';
        }
        else if (exp < base.length() - 1) strnum.insert(1+exp, "."); // 否则 在原小数点位(1)后exp个位置插入小数点
    }
    else {
        exp = 0 - exp;
        for (int i = 0; i < exp - 1; ++i) { // 补exp-1个0
            strnum = "0" + strnum;
        }
        strnum = "0." + strnum;
    }
    // 去除头部多余的0 不除0就会出现00.12这种错误 小数点前最多一个0 非零数字前不能有0
    // PAT这道题不需要这个操作 因为限定了  [+-][1-9].[0-9]+E[+-][0-9]+
    //    if (strnum.find('.') != string::npos) {
    //        int posdot = strnum.find('.')-1;
    //        for (int i = 0; i < posdot; ++i) {
    //            if (strnum[i] == '0') strnum.erase(i, 1);
    //            else break;
    //        }
    //    }
    //    else {
    //        for (int i = 0; i < strnum.length(); ++i) {
    //            if (strnum[i] == '0') strnum.erase(i, 1);
    //            else break;
    //        }
    //    }
    cout << strnum << endl;
    return 0;
}

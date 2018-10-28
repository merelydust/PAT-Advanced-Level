/***
 s.erase(pos) 删除字符串s从第pos个字符开始之后所有的字符（包括第pos个）
 s.erase（pos，n) 删除字符串s从第pos个字符开始的n个字符
 ***/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string unit[] = {"", "Shi", "Bai", "Qian"}; // 用len索引
    string secs[] = {"", "Wan", "Yi"}; // secs是加在unit后面的 个位节 万节 亿节 用seccnt索引
    string number[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    
    string n; cin >> n;
    if (n == "0") {
        cout << "ling" << endl;
        return 0;
    }
    string ans = "";
    if (n[0] == '-') {
        cout << "Fu "; n.erase(0, 1);
    }
    int seccnt = 0;
    int end = n.length()-1;
    for (; end >= 0; end -= 4) { // 四位为一段 end是sec的末端
        bool after0 = false;
        int start = end >= 3 ? end - 3 : 0; // start是sec的开端
        int len = end - start + 1 - 1; // 这个sec的长度 闭区间所以+1 为了索引所以-1
        string tmp = ""; // 该sec的读法
        for (int i = start; i <= end; ++i) {
            if (n[i] == '0') {
                len--;
                after0 = true;
            }
            else {
                if (after0) { // 只有被夹在两个非0数中间的0才被发音
                    tmp += " ling";
                    after0 = false;
                }
                if (tmp.length() != 0) tmp += " "; // 如果不是第一次插入tmp 要加空格
                tmp += number[n[i]-'0'];
                if (len > 0) tmp += ' '; //非个位的unit要输出 和数字间有空格
                tmp += unit[len--];
            }
        }
        if (seccnt > 0) tmp += " "; tmp += secs[seccnt++]; // 如果不是个位节 都要输出sec单位
        if (start != 0 && tmp[0] != ' ') tmp = " " + tmp; // 如果该段是" ling"开头就不需要拼接空格了
        ans = tmp + ans; // 因为是从后往前 所以tmp要接在ans前面
    }
    cout << ans << endl;
    return 0;
}

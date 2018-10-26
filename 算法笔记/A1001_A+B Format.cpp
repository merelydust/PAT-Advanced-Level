#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    b += a;
    if (b < 0) {
        cout << '-';
        b = 0 - b;
    }
    string sb = to_string(b);
    int len = sb.length();
    if (len < 4) {
        cout << sb << endl; return 0;
    }
    int num = len % 3;
    if (!num) num = 3;
    for (int i = 0; i < len; ++i) {
        cout << sb[i];
        if (i == num-1 && i != len-1) {
            cout << ','; num += 3;
        }
    }
    cout << endl;
    return 0;
}

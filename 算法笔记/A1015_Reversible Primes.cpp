/***
 把数字n转成d进制dn
 逆转dn 得到数字rdn //转换进制中直接得到rdn
 rdn转换成十进制的rn
 n和rn都为素数时输出Yes
 ***/
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string toD(int n, int d) {
    string rdn = "";
    while (n) {
        rdn += to_string(n % d); n /= d;
    }
    return rdn;
}

int to10(string rdn, int d) {
    int rn = 0, len = rdn.length(), mul = 1;
    for (int i = len-1; i >= 0; --i) {
        rn += (rdn[i] - '0') * mul; mul *= d;
    }
    return rn;
}

bool isPrime(int n) {
    if (n < 2) return false;
    int sqr = int(sqrt(1.0 * n));
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, d;
    while (true) {
        cin >> n; if (n < 0) return 0;
        cin >> d;
        int rn = to10(toD(n, d), d);
        if (isPrime(n) && isPrime(rn)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

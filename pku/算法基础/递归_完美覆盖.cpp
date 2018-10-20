/***
 当n=0, 标准答案里将其设为f(0)=1;
 n为奇数时，无法实现完全覆盖，将其设为0；
 其他情况下，
 f(2)=3,
 f(4)=3*f(2)+2,
 f(6)=3*f(4)+2*f(2)+2,
 f(n)=3*f(n-2)+2*(f(n-4)+f(n-6)+….+f(2))+2 = f(n-2)+2*(f(n-2)+f(n-4)+….+f(2))+2;
 source: https://blog.csdn.net/NNNNNNNNNNNNY/article/details/51596216
***/
#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    while(n!=-1) {
        if (n%2)
            cout << 0 << endl;
        else if (n==0)
            cout << 1 << endl;
        else {
            long long last=0, last_sum=0, cur=3;
            for (int i=4; i<=n; i=i+2){
                last = cur;
                last_sum += last;
                cur = 2*last_sum+last+2;
            }
            cout << cur << endl;
        }
        cin >> n;
    }
    return 0;
}

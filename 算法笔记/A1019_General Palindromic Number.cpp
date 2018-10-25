#include <iostream>
using namespace std;

int main() {
    int n, b; cin >> n >> b;
    int arr[40]; // 最低进制是2 n取值范围<=10^9 2的32次方就有10^9了吧 再乘16
    int cnt = 0;
    do {
        arr[cnt++] = n % b;
        n /= b;
    } while(n);
    int front = 0, rear = cnt-1;
    bool isP = true;
    for (; front != rear; ++front, --rear) {
        if (arr[front] != arr[rear]) {
            isP = false;
            break;
        }
    }
    if (isP) cout << "Yes" << endl;
    else cout << "No" << endl;
    for (int j = cnt-1; j >= 0; --j) {
        if (j != cnt-1) cout << ' ';
        cout << arr[j];
    }
    return 0;
}

#include <iostream>
#include <string.h> // 使用memset memcpy的头函数
using namespace std;

void binaryAdd(int arr[], int len) {
    arr[0]++;
    int i = 0;
    while(arr[i] == 2 && arr[len-1] <= 1) {
        arr[i+1]++;
        arr[i] -= 2;
        i++;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int mincnt = n * n + 1;
        int wall[n+2][n+2];
        memset(wall, 0, sizeof(wall)); // wall has -1 or 1
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                char tmp; cin >> tmp;
                if (tmp == 'y') wall[i][j] = 1;
                if (tmp == 'w') wall[i][j] = -1;
            }
        }
        int brush[n];
        memset(brush, 0, sizeof(brush)); // brush has 0 or 1
        brush[0] = -1;
        while(brush[n-1] <= 1) {
            int tmpwall[n+2][n+2]; // 巨坑啊，忘记清空wall找了两天才找出来的bug
            memcpy(tmpwall, wall, (n+2)*(n+2)*sizeof(int));
            binaryAdd(brush, n);
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (brush[i] == 1) {
                    cnt++;
                    tmpwall[1][i+1] *= -1;
                    tmpwall[0][i+1] *= -1;
                    tmpwall[2][i+1] *= -1;
                    tmpwall[1][i] *= -1;
                    tmpwall[1][i+2] *= -1;
                }
            } // brush first line
            // brush left lines
            for (int i = 2; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (tmpwall[i-1][j] == -1) {
                        cnt++;
                        tmpwall[i][j] *= -1;
                        tmpwall[i-1][j] *= -1;
                        tmpwall[i+1][j] *= -1;
                        tmpwall[i][j-1] *= -1;
                        tmpwall[i][j+1] *= -1;
                    }
                }
            }
            int last = 0;
            for (int i = 1; i <= n; i++) {
                last += tmpwall[n][i];
            }
            if (last == n) {
                if (cnt < mincnt) mincnt = cnt;
            }
        }
        if (mincnt > n*n) {
            cout << "inf" << endl;
        } else {
            cout << mincnt << endl;
        }
    }
    return 0;
}

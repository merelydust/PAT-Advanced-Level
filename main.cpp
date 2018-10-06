#include <iostream>
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
        int mincnt = n * n;
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
            binaryAdd(brush, n);
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (brush[i] == 1) {
                    cnt++;
                    wall[1][i+1] *= -1;
                    wall[0][i+1] *= -1;
                    wall[2][i+1] *= -1;
                    wall[1][i] *= -1;
                    wall[1][i+2] *= -1;
                }
            } // brush first lien
            // brush left lines
            for (int i = 2; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (wall[i-1][j] == -1) {
                        cnt++;
                        wall[i][j] *= -1;
                        wall[i-1][j] *= -1;
                        wall[i+1][j] *= -1;
                        wall[i][j-1] *= -1;
                        wall[i][j+1] *= -1;
                    }
                }
            }
            int last = 0;
            for (int i = 1; i <= n; i++) {
                last += wall[n][i];
            }
            if (last == n) {
                if (cnt < mincnt) mincnt = cnt;
                cout << "min way" << endl;
                for (int i = 0; i < n; i++) cout << brush[i] << ' ';
                cout << endl;
            }
        }
        cout << mincnt << endl;
    }
    return 0;
}

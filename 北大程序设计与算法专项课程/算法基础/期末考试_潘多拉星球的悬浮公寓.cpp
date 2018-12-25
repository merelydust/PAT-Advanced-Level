#include <iostream>
#include <cstring>
using namespace std;
int a[6][20][20];
int n, area = 0;
int d[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } }; //udlr
int nextSides[6][4] = { { 4,5,3,1 },{ 4,5,0,2 },{ 4,5,1,3 },{ 4,5,2,0 },{ 2,0,3,1 },{ 2,0,3,1 } }; //按题中面的顺序标号。

void dfs(int side, int i, int j) {
    if (a[side][i][j]) return;
    area++;
    a[side][i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int newI = i + d[k][0];
        int newJ = j + d[k][1];
        //fix (newI, newJ).
        int newSide = side;
        //当前所在面可以左、右扩展搜索。
        if (!(side == 4 || side == 5)) {
            if (newJ < 0) {
                newSide = nextSides[side][2];
                newJ = n - 1;
            } //搜到左侧一面，置纵坐标新的一面的最右端。
            if (newJ >= n) {
                newSide = nextSides[side][3];
                newJ = 0;
            } //搜到右侧一面，置纵坐标新的一面的最左端。
        }
        if (!(side == 1 || side == 3)) {
            if ((newI < 0 || newI >= n) && side == 2) { newJ = n - 1 - newJ; }  //面2因为是反面，所以需要翻转坐标。
            if (newI < 0) newSide = nextSides[side][0], (side == 2 || side == 4) ? newI = 0 : newI = n - 1;
            if (newI >= n) newSide = nextSides[side][1], (side == 0 || side == 5) ? newI = n - 1 : newI = 0;
            if (newSide != side && newSide == 2)
                newJ = n - 1 - newJ;
        }
        if (!(side == 0 || side == 2)) {
            switch (side) {
                case 4:
                    if (newJ < 0) newSide = nextSides[side][2], newJ = newI, newI = 0;
                    if (newJ >= n) newSide = nextSides[side][3], newJ = n - 1 - newI, newI = 0;
                    break;
                case 5:
                    if (newJ < 0) newSide = nextSides[side][2], newJ = newI, newI = n - 1;
                    if (newJ >= n) newSide = nextSides[side][3], newJ = n - 1 - newI, newI = n - 1;
                    break;
                case 1:
                    if (newI < 0) newSide = nextSides[side][0], newI = n - 1 - newJ, newJ = n - 1;
                    if (newI >= n) newSide = nextSides[side][1], newI = n - 1 - newJ, newJ = n - 1;
                    break;
                case 3:
                    if (newI < 0) newSide = nextSides[side][0], newI = newJ, newJ = 0;
                    if (newI >= n) newSide = nextSides[side][1], newI = newJ, newJ = 0;
                    break;
            }
        }
        if (!a[newSide][newI][newJ]) {
            dfs(newSide, newI, newJ);
        }
    }
}

int main() {
    //  freopen("in.txt", "r", stdin);
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> n;
        for (int side = 0; side < 6; side++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> a[side][i][j];
                }
            }
        }
        
        int num = 0, maxArea = 0;
        for (int side = 0; side < 6; side++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (!a[side][i][j]) {
                        num++;
                        area = 0;
                        dfs(side, i, j);
                        if (area > maxArea) {
                            maxArea = area;
                        }
                    }
                }
            }
        }
        cout << num << " " << maxArea << endl;
    }
    return 0;
}

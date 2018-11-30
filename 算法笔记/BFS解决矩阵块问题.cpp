// 一个m*n的矩阵 分布着0和1 相邻(上下左右)的1构成块 单个1也算一块 问矩阵中共有几块
// BFS
#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 100;
struct node {
    int x, y; // 位置坐标
}Node;

int n, m;
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0}; // 对应上下左右走法

bool judge(int x, int y) { // 判断位置x，y是否需要访问的1
    if (x >= n || x < 0 || y >= m || y < 0) return false; // 越界
    if (matrix[x][y] == 0 || inq[x][y]==true) return false; // 当前位置为0或已入过队
    return true;
}

// BFS函数访问位置(x, y)所在的块 将该块中所有1位置的inq都设置为true
void BFS(int x, int y) {
    queue<node> Q;
    Node.x = x, Node.y = y; // 当前节点坐标为x,y
    Q.push(Node); inq[x][y] = true;
    while (!Q.empty()) {
        node top = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) { // 循环四次 得到四个相邻位置
            int newX = top.x + X[i]; int newY = top.y + Y[i];
            if (judge(newX, newY)) {
                Node.x = newX; Node.y = newY;
                Q.push(Node); inq[newX][newY] = true;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) scanf("%d", &matrix[x][y]);
    }
    int ans = 0; // 存放块数
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) { // 枚举每一个位置
            if (matrix[x][y] == 1 && !inq[x][y]) {
                ans++; BFS(x, y); // 访问整个块 将整个块的1的inq都标记为true
            }
        }
    }
    printf("%d", ans); return 0;
}

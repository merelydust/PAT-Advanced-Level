/***
 IO说明：
 输入 M行 N列 L层 T阈值
 接下来有L个 m*n的矩阵
 
 输出core总数
 一个core块 只有相邻（上下左右前后）的1的总数>=T时才被加入total
 
 思路：块状广搜 标记式
 ***/
#include <cstdio>
#include <queue>
using namespace std;

struct node {
    int x, y, z;
}Node;

int m, n, slice, T;
int pixel[1300][150][70];
bool inq[1300][150][70] = {false};
int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};

bool judge(int x, int y, int z) {
    if (x >= m || x < 0 || y >= n || y < 0 || z >= slice || z < 0) return false; // 越界
    if (!pixel[x][y][z] || inq[x][y][z]) return false; // 节点不是所求值或者已经入队
    return true;
}

int BFS(int x, int y, int z) {
    int cores = 0; Node.x = x; Node.y = y; Node.z = z;
    queue<node> Q; Q.push(Node); inq[x][y][z] = true;
    while (!Q.empty()) {
        node fro = Q.front(); Q.pop(); cores++;
        for (int i = 0; i < 6; ++i) {
            int newX = X[i] + fro.x, newY = Y[i] + fro.y, newZ = Z[i] + fro.z;
            if (judge(newX, newY, newZ)) {
                Node.x = newX; Node.y = newY; Node.z = newZ;
                Q.push(Node); inq[newX][newY][newZ] = true;
            }
        }
    }
    if (cores >= T) return cores;
    else return 0;
}

int main() {
    scanf("%d %d %d %d", &m, &n, &slice, &T);
    int ans = 0;
    for (int z = 0; z < slice; ++z) {
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) scanf("%d", &pixel[x][y][z]);
        }
    }
    for (int z = 0; z < slice; ++z) {
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if(pixel[x][y][z] && !inq[x][y][z]) ans += BFS(x, y, z);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int x, y, data;
    node* pre;
    node() {
        pre = NULL;
    }
}matrix[5][5];

int inq[5][5] = {0};
int ans = 50; vector<node> path;
int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};

bool judge(int x, int y) {
    if (x < 0 || x > 4 || y < 0 || y > 4 || matrix[x][y].data || inq[x][y]) return false;
    return true;
}

void bfs() {
    queue<node> Q;
    Q.push(matrix[0][0]);
    while (!Q.empty()) {
        node fro = Q.front(); Q.pop();
        inq[0][0] = 1;
        if (fro.x == 4 && fro.y == 4) return;
        for (int i = 0; i < 4; ++i) {
            int newX = fro.x + X[i], newY = fro.y+Y[i];
            if (judge(newX, newY)) {
                node Node; Node.x = newX; Node.y = newY;
                matrix[newX][newY].pre = &(matrix[fro.x][fro.y]); // 队列传入的是副本～所以手动操作matrix
                Q.push(Node); inq[Node.x][Node.y] = 1;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &matrix[i][j].data);
            matrix[i][j].x = i; matrix[i][j].y = j;
        }
    }
    bfs();
    node* ptr = &(matrix[4][4]);
    while (ptr != NULL) {
        path.push_back(*(ptr));
        ptr = ptr->pre;
    }
    for (int i = path.size()-1; i >= 0; --i) {
        printf("(%d, %d)\n", path[i].x, path[i].y);
    }
    return 0;
}


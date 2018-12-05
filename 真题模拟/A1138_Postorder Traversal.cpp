/***
 树的先序遍历得到根 在中序遍历里根据根划分左右子树
 ***/
#include <cstdio>

const int maxn = 50010; int n;
int pre[maxn] = {0}, in[maxn] = {0};

bool flag = false;
void create(int preL, int preR, int inL, int inR) {
    if (preL > preR || flag) return; // 序列为空直接返回 或已经找到最左端点
    int k; // 根在中序序列里的位置
    for (k = inL; k < inR; ++k) {
        if (in[k] == pre[preL]) break;
    }
    int leftNum = k - inL;
    create(preL+1, preL+leftNum, inL, k-1);
    create(preL+leftNum+1, preR, k+1, inR);
    if (!flag) {
        printf("%d\n", in[k]); flag = true;
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &pre[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &in[i]);
    create(0, n-1, 0, n-1);
    return 0;
}

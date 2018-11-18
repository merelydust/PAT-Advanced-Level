#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
int origin[maxn], cpyOri[maxn], changed[maxn];
int n;

bool isSame(int a[], int b[]) {
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void printArray(int a[]) {
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

bool insertSort() {
    bool flag = false;
    for (int i = 1; i < n; ++i) { // 插入排序 第一位左边为空 不需要操作 所以i从1开始
        if (i != 1 && isSame(cpyOri, changed)) flag = true; // 不是初始序列且相同
        int tmp = cpyOri[i], j = i; // 用tmp暂存主元（要插入的元素）的值 j从右往左使主元左侧有序
        while (j >= 1 && cpyOri[j-1] > tmp) { //把大于主元的数往右挪
            cpyOri[j] = cpyOri[j-1]; --j;
        }
        cpyOri[j] = tmp; // 找到了插入位置 插入主元的值
        if (flag) return true; // 在这里返回 同时完成了目标序列的下一轮排序
    }
    return false;
}

void mergeSort() {
    bool flag = false;
    for (int step = 2; step / 2 <= n; step *= 2) {
        if (step != 2 && isSame(cpyOri, changed)) flag  = true;
        for (int i = 0; i < n; i += step) sort(cpyOri+i, cpyOri+min(i+step, n)); //一组一组地排序
        if (flag) return;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &origin[i]); cpyOri[i] = origin[i];
    }
    for (int i = 0; i < n; ++i) scanf("%d", &changed[i]);
    if (insertSort()) {
        printf("Insertion Sort\n"); printArray(cpyOri);
    }
    else {
        printf("Merge Sort\n");
        for (int i = 0; i < n; ++i) cpyOri[i] = origin[i];
        mergeSort(); printArray(cpyOri);
    }
    return 0;
}

/***
 先插入排序 比较是否相等
 否则 就是堆排序
 ***/
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110; int n;
int origin[maxn], mid[maxn]; // 存储原序列和中间序列

bool cmpArr(int a[], int b[]) {
    for (int i = 1; i <= n; ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void printArr(int arr[]) {
    for (int i = 1; i <= n; ++i) {
        if (i != 1) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

bool isInsert() {
    for (int i = 3; i <= n+1; ++i) { // 初始序列不算中间序列
        sort(origin+1, origin+i); // 02测试点没过是因为sort函数没从1而是0开始排列
        if (cmpArr(origin, mid)) {
            if (i <= n) sort(origin, origin+i+1);
            return true;
        }
    }
    return false;
}

void downAdjust(int low, int high) {
    int i = low, j = 2 * i; // i为欲调整节点 j是i孩子中较大者 初始为左孩子
    while (j <= high) { // 当有左孩子
        if (j+1 <= high && mid[j+1] > mid[j]) { // 如果有右孩子且比左孩子大
            j = j+1;
        }
        if (mid[j] > mid[i]) {
            swap(mid[j], mid[i]); i = j; j = i * 2;// 保持i为欲调整节点
        }
        else break; // 调整结束
    }
}

void heapSort() {
    int k = 2;
    while (mid[1] > mid[k]) ++k;
    swap(mid[1], mid[--k]);
    downAdjust(1, k-1); // 相当于是删除堆顶的操作
    printArr(mid);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &origin[i]);;
    for (int i = 1; i <= n; ++i) scanf("%d", &mid[i]);
    if (isInsert()) {
        printf("Insertion Sort\n");
        printArr(origin);
    }
    else {
        printf("Heap Sort\n");
        heapSort();
    }
    return 0;
}

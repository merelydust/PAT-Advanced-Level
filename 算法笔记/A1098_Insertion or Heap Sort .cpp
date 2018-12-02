/***
 先插入排序 比较是否相等
 否则 就是堆排序
 ***/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 110; int n;
int origin[maxn], mid[maxn];; // 存储原序列和中间序列

bool cmpArr(int a[], int b[]) {
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void printArr(int arr[]) {
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

bool isInsert() {
    for (int i = 1; i <= n; ++i) {
        sort(origin, origin+i);
        if (cmpArr(origin, mid)) {
            if (i < n) sort(origin, origin+i+1);
            return true;
        }
    }
    return false;
}

int findMax(int arr[], int wall) { // 找到序列中最大值的序号
    int maxV = -1, maxI = 0;
    for (int i = 0; i <= wall; ++i) {
        if (arr[i] > maxV) {
            maxV = arr[i]; maxI = i;
        }
    }
    return maxI;
}

void heapSort(vector<int> cpyorigin) {
    vector<int> vmid(mid, mid+n);
    make_heap(cpyorigin.begin(), cpyorigin.end());
    for (int i = 0; i < n; ++i) {
        swap(cpyorigin[i], cpyorigin[n-1-i]);
        make_heap(cpyorigin.begin(), cpyorigin.end()-1-i);
        if (cpyorigin == vmid) {
            if(i) swap(cpyorigin[i], cpyorigin[n-1-i]);
            printArr(&cpyorigin[0]); return;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &origin[i]);
    vector<int> cpyorigin(origin, origin+n);
    for (int i = 0; i < n; ++i) scanf("%d", &mid[i]);
    if (isInsert()) {
        printf("Insertion Sort\n");
        printArr(origin);
    }
    else {
        printf("Heap Sort\n");
        heapSort(cpyorigin);
    }
    return 0;
}

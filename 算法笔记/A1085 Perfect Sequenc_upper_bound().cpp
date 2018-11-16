// 二分查找法 使用upper_bound函数
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int n, p, a[maxn]; // a为升序

int main() {
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a+n);
    int ans = 1; // 最大长度 至少有一个数
    for (int i = 0; i < n; ++i) {
        int end = upper_bound(a+i+1, a+n, (long long)a[i] * p) - a; // 上限为这个东西
        ans = max(ans, end - i);
    }
    printf("%d\n", ans);
    return 0;
}


//// 二分查找法 （暴力枚举复杂度为n^2 会超时）
//// 排序后从左到右扫描数列 对于每一个a[i] 寻找从a[i+1]到a[n-1]中第一个超过a[i]*p的数字的位置end
//// 这样 end-i就是对位置i而言满足a[j] <= a[i]*p的最远长度
//// 取所有end-i的最大值即为所求 复杂度为logn
//#include <cstdio>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//
//const int maxn = 100010;
//int n, p, a[maxn]; // a为升序
//
//int binarySearch(int i, long long x) { // 在[i+1, n-1]中寻找第一个大于x的数的位置
//    if (a[n-1] <= x) return n; // 如果所有数都不大于x
//    int left = i+1, right = n-1, mid;
//    while (left < right) { // 注意是<不是<= 因为x不需要真的存在于队列中 ==的时候就是把x该在的位置返回
//        mid = (left + (right-left)/2);
//        if (a[mid] > x) right = mid; // mid处符合条件 说明第一个符合条件在mid处或者mid的左边
//        else left = mid+1;
//    }
//    return left; // while结束的时候left==right
//}
//
//int main() {
//    scanf("%d %d", &n, &p);
//    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
//    sort(a, a+n);
//    int ans = 1; // 最大长度 至少有一个数
//    for (int i = 0; i < n; ++i) {
//        int end = binarySearch(i, (long long)a[i] * p); // 第一个大于x的数字的位置
//        ans = max(ans, end - i);
//    }
//    printf("%d\n", ans);
//    return 0;
//}

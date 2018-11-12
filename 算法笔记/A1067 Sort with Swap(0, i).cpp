// 目标是 pos[i] = i 即数字i的位置正好是i
// 题目要求交换中介只能是数字0
// 那么当数字0不在位置0上 数字0应该把它所处的位置i还给数字i 即交换pos[0]和pos[pos[0]] 数字i所在位置为pos[pos[0]]
// 当数字0在位置0上 检查剩下的位置是否还有错乱
// 若有 将数字0的位置与找到的第一个错乱的位子交换 借助0的帮助 让正确的数字回到这个错乱的位置上
// 为避免超时 每次搜寻 从最小的错乱位置start开始
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    int pos[100010]; int num;
    int unsort = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num); pos[num] = i; // num在i位置
        if (num && num != i) unsort++;
    }
    int start = 1, cnt = 0;
    while (unsort) {
        if (pos[0] == 0) {
            while (start < n) {
                if (pos[start] != start) {
                    swap(pos[0], pos[start]); cnt++; break;
                }
                start++;
            }
        }
        while (pos[0] != 0) {
            swap(pos[0], pos[pos[0]]); // 将0与pos[0]交换
            cnt++; unsort--;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

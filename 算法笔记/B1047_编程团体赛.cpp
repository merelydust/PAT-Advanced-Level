#include <cstdio>
using namespace std;

int main() {
    int hash[1001] = {0};
    int n; scanf("%d", &n);
    while (n--) {
        int num, eat, grade; scanf("%d-%d %d", &num, &eat, &grade);
        hash[num] += grade;
    }
    int max = -1, maxindex = 0;
    for (int i = 1; i < 1001; ++i) {
        if (hash[i] > max) {
            max = hash[i]; maxindex = i;
        }
    }
    printf("%d %d", maxindex, max);
    return 0;
}

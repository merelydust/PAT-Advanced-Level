#include <cstdio>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    int arr[110];
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    int before = 0, time = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > before) time += 6 * (arr[i] - before);
        else if (arr[i] < before) time += 4 * (before - arr[i]);
        time += 5;
        before = arr[i];
    }
    printf("%d\n", time);
    return 0;
}

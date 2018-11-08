#include <cstdio>
using namespace std;

int main() {
    int arr[100001] = {0};
    int hash[10001] = {0};
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]); hash[arr[i]]++;
    }
    int win = 0;
    for (int i = 0; i < n; ++i) {
        if (hash[arr[i]] == 1) {
            win = arr[i]; break;
        }
    }
    if (win) printf("%d\n", win);
    else printf("None\n");
    return 0;
}

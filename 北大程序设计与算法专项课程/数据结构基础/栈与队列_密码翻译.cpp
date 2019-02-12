#include <cstdio>
#include <cctype>

int main() {
    int n; scanf("%d", &n);
    char c; scanf("%c", &c); // 数字后面也有换行符
    while (n--) {
        while (scanf("%c", &c) != EOF && c != '\n') {
            if (isalpha(c)) {
                ++c;
                if (c == 91) c = 65;
                else if (c == 123) c = 97;
            }
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}

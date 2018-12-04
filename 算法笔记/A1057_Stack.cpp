#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int base = 316; // 每316一块
int table[1010] = {0}; // 记录每块的数字数量
int hashtable[maxn] = {0}; // 记录某数字出现次数

void peekM(int k) {
    int sum = 0, idx = 0;
    while (sum + table[idx] < k) sum += table[idx++];
    int num = idx * base; // idx块内第一个数字
    while (sum + hashtable[num] < k) sum += hashtable[num++];
    printf("%d\n", num);
}

int main() {
    int n; scanf("%d", &n);
    char command[20] = {0}; int key;
    stack<int> s;
    while (n--) {
        scanf("%s", command);
        switch (command[1]) {
            case 'o':
                if (!s.empty()) {
                    printf("%d\n", s.top());
                    hashtable[s.top()]--; table[s.top()/base]--;
                    s.pop();
                } else printf("Invalid\n");
                break;
            case 'u':
                scanf("%d", &key); s.push(key);
                hashtable[key]++; table[key/base]++;
                break;
            case 'e':
                if (s.empty()) {
                    printf("Invalid\n"); break;
                }
                int pos = s.size(); // 中位数位置
                if (pos % 2) pos = (pos+1) / 2;
                else pos /= 2;
                peekM(pos);
                break;
        }
    }
    return 0;
}

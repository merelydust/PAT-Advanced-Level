// 第一次用了一个骚气的vector数组 只过了2/3 第二次改成传统方法就过了。。
// 这个故事告诉我们 先用传统方法 攻破不了再出奇招
// 晴神说 把每个年龄的前100名另存在一个valid数组里取遍历 不然会超时
// 不过经过实践 并没有超时（大雾
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct peo {
    string name;
    int age, wealth;
};

bool cmp(peo a, peo b) {
    if (a.wealth != b.wealth) return a.wealth > b.wealth;
    if (a.age != b.age) return a.age < b.age;
    return a.name < b.name;
}

int main() {
    int n, k; scanf("%d %d", &n, &k);
    peo people[n];
    for (int i = 0; i < n; ++i) {
        char arr[100] = {0};
        scanf("%s %d %d", arr, &people[i].age, &people[i].wealth);
        people[i].name = arr; // scanf只能读入字符数组 但string可以直接接收字符数组
    }
    sort(people, people+n, cmp);
    for (int i = 1; i <= k; ++i) {
        printf("Case #%d:\n", i);
        int m, amin, amax; scanf("%d %d %d", &m, &amin, &amax);
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (cnt == m) break;
            if (people[j].age >= amin && people[j].age <= amax) {
                printf("%s %d %d\n", people[j].name.c_str(), people[j].age, people[j].wealth);
                cnt++;
            }
        }
        if (!cnt) printf("None\n");
    }
    return 0;
}

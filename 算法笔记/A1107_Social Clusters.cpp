/***
 两个人爱好里只要有一个相同 就合并到一个集合里
 ***/
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int hobbies[maxn] = {0}; // 下标为爱好编号 值为喜欢的人的编号
int father[maxn] = {0};
int isRoot[maxn] = {0}; // 下标为根节点序号 值为集合中的人

void init(int n) {
    for (int i = 1; i <= n; ++i) father[i] = i;
}

int findFather(int x) {
    int a = x;
    while (father[x] != x) x = father[x];
    while (father[a] != a) { // 路径压缩
        int b = a;
        a = father[a];
        father[b] = x; // 不能一步到位把father[a]改成x 不然还怎么用father[a]更新啊！！
    }
    return x;
}

void unionFather(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) father[faA] = faB;
}

bool cmp(int a, int b){
    return a > b;
}

int main() {
    int n, k, hobby; scanf("%d", &n);
    init(n);
    for (int i = 1; i <= n; ++i) { // 人的编号为i
        scanf("%d: ", &k);
        for (int j = 0; j < k; ++j) { // 一共k个爱好
            scanf("%d", &hobby);
            if (!hobbies[hobby]) hobbies[hobby] = i; // 如果该爱好还没人选过
            unionFather(findFather(hobbies[hobby]), i); // 否则 和之前选这个爱好的人的合集合并
        }
    }
    for (int i = 1; i <= n; ++i) {
        isRoot[findFather(i)]++;
    }
    int setNum = 0;
    for (int i = 1; i <= n; ++i) {
        if (isRoot[i]) setNum++; // 莫装逼～！老实遍历！！
    }
    printf("%d\n", setNum);
    sort(isRoot+1, isRoot+1+n, cmp);
    for (int i = 1; i <= setNum; ++i) {
        if (i != 1) printf(" ");
        printf("%d", isRoot[i]);
    }
    printf("\n");
    return 0;
}

/***
 使用map: name-set<int>的数据结构
 IO说明：
 n-有几个人来查询 k-总共几门课
 接下来k行（index:1～k） 课程编号-i 选课人数-ni
                       ni个名字
 n个要查询的名字
 
 对于每个要查询的名字（查询顺序） 输出 名字 选课总数 选的课索引（升序）
 ***/
#include <cstdio>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, k; scanf("%d %d", &n, &k);
    map<string, set<int> > m;
    int tmpi, tmpni; char name[10] = {0};
    for (int i = 0; i < k; ++i) {
        scanf("%d %d", &tmpi, &tmpni);
        while (tmpni--) {
            scanf("%s", name); m[name].insert(tmpi);
        }
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s", name); printf("%s %d", name, m[name].size());
        if (m[name].size()) {
            set<int>::iterator it = m[name].begin();
            for (; it != m[name].end(); ++it) printf(" %d", *it);
        }
        printf("\n");
    }
    return 0;
}

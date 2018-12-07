#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, vector<int> > mp; // 每个物品编号对应一些它的相克物品合集
void isValid() {
    int hashtable[1000000] = {0}; vector<int> goods;
    int k, good; scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &good); goods.push_back(good);
        hashtable[good] = 1;
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < mp[goods[i]].size(); ++j) {
            if (hashtable[ mp[goods[i]][j] ]) {
                printf("No\n"); return;
            }
        }
    }
    printf("Yes\n"); return;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    int a, b;
    while (n--) { // 读取相克物品对
        scanf("%d %d", &a, &b);
        mp[a].push_back(b); mp[b].push_back(a);
    }
    while (m--) isValid();
    return 0;
}

/***
 模拟反思 第一次用STL的find方法超时了一个测试点
 就用哈希表在读入数据时判断 默认没有重复ID 结果答案错误了俩
 emmm还是不能抱有侥幸心理 除非题目给定 否则不要做主观预设
 ***/

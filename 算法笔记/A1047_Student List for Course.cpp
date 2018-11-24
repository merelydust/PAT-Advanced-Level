/***
 vector<string>类型的数组
 IO说明：
 n-学生总数 k-课程总数
 接下来n行： 名字 参加课程总数c c个课程编号
 
 输出：课程编号(1~k) 选课学生数
 字典序的名字 一行一个
 ***/
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, k; scanf("%d %d", &n, &k);
    vector<string> arr[2510]; char name[10] = {0}; int c, index;
    for (int i = 0; i < n; ++i) {
        scanf("%s %d", name, &c);
        while (c--) {
            scanf("%d", &index); arr[index].push_back(name);
        }
    }
    for (int i = 1; i <= k; ++i) {
        printf("%d %d\n", i, arr[i].size());
        if (arr[i].empty()) continue;
        sort(arr[i].begin(), arr[i].end());
        for (int j = 0, len = arr[i].size(); j < len; ++j) printf("%s\n", arr[i][j].c_str());
    }
    return 0;
}

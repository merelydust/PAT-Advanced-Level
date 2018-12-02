// 人和人之间有时长的通话记录就是带权值的边
#include <iostream>
#include <string>
#include <map>
using namespace std;

const int maxn = 2018;
const int INF = 10 << 10;

map<int, string> int2str; // 编号转姓名
map<string, int> str2int; // 姓名转编号
map<string, int> gang; // 头目对应人数
int G[maxn][maxn] = {0}, weight[maxn] = {0}; // 邻接矩阵G 点权weight
int n, k, numPerson=0; // 边数n 下限k 总人数numPerson
bool vis[maxn] = {false};

// DFS访问单个连通块 nowVisit为当前访问的编号
// head为头目 numMember为成员编号 totalValue为连通块的总边权
void DFS(int nowVisit, int& head, int& numMember, int& totalValue) {
    numMember++; // 成员人数加一
    vis[nowVisit] = true;
    if (weight[nowVisit] > weight[head]) head = nowVisit;
    for (int i = 0; i < numPerson; ++i) { // 枚举所有人
        if (G[nowVisit][i] > 0) { // 如果从nowVisit可以访问到i
            totalValue += G[nowVisit][i]; // 连通块的总边权增加该边
            G[nowVisit][i] = G[i][nowVisit] = 0; // 删除这条边 防止回头
            if (vis[i] == false) DFS(i, head, numMember, totalValue); // 递归访问子节点
        }
    }
}

// DFS遍历整个图 获取整个连通块的信息
void DFSTraverse() {
    for (int i = 0; i < numPerson; ++i) {
        if (!vis[i]) {
            int head = i, numMember = 0, totalValue = 0;
            DFS(i, head, numMember, totalValue);
            if (numMember > 2 && totalValue > k) gang[int2str[head]] = numMember;
        }
    }
}

int change(string str) {
    if (str2int.find(str) != str2int.end()) return str2int[str];
    else {
        str2int[str] = numPerson;
        int2str[numPerson] = str;
        return numPerson++;
    }
}

int main() {
    int w; string s1, s2;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> s1 >> s2 >> w; // 输入两个端点和边权
        int id1 = change(s1), id2 = change(s2);
        weight[id1] += w; // 点权增加
        weight[id2] += w;
        G[id1][id2] += w; // id1->id2 边权增加
        G[id2][id1] += w; // id2->id2 边权增加
    }
    DFSTraverse();
    cout << gang.size() << endl;
    map<string, int>::iterator it;
    for (it = gang.begin(); it != gang.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}

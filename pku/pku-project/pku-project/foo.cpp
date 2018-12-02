///***
// 区分点权和边权 点权最大的是头 边权达到阈值才是有效帮派
// 两个人之间的有时长的通话记录就是一条带权值的边 -> 用图模拟
// 使用DFS枚举每个连通块 点权最高的是头
// 需要注意 因为dfs遍历是通过枚举节点u的子节点v
// 如果图中存在环 即两个已经被访问过的v中间还有一条边(u->v1, u->v2, v1-v2)
// 为了不重复计算(u->v1 v1->u) 使用完一条边权后就要将其归0
// ***/
//#include <iostream>
//#include <map>
//#include <string>
//using namespace std;
//
//const int maxn = 2018; // 最多1000条通话记录 所以最多两千人
//int n, k, people = 0; // 记录总人数 同时作为姓名对应的序号
//int G[maxn][maxn] = {0}, weight[maxn] = {0}; // G存储边权， weight存储点权
//bool vis[maxn] = {false};
//map<string, int> str2int;
//map<int, string> int2str;
//map<string, int> gang; // 头头名字-帮派人数
//
//int getID(string s) {
//    if (str2int.find(s) != str2int.end()) return str2int[s];
//    else {
//        str2int[s] = people;
//        int2str[people] = s;
//        return people++;
//    }
//}
//
//void DFS(int nowVisit, int& head, int& totalValue, int& numMember) { // totalValue大于阈值才是有效帮派
//    numMember++; // 该连通块内人数++
//    vis[nowVisit] = true;
//    if (weight[nowVisit] > weight[head]) head = nowVisit;
//    for (int i = 0; i < people; ++i) { // 枚举所有人
//        if (G[nowVisit][i] > 0) { // 如果从nowVisit可以访问到i
//            totalValue += G[nowVisit][i]; G[nowVisit][i] = G[i][nowVisit] = 0; // 累积边权 用完归零
//            // 把vis[i]的判断放在累积权值之后 就能包括环的边即已经访问过的两个节点之间的边了
//            if (!vis[i]) DFS(i, head, totalValue, numMember);
//        }
//    }
//}
//
//void DFSTraverse() { // 遍历整个图获取全部帮派信息
//    for (int u = 0; u < people; ++u) { // 枚举每个顶点即每个人
//        if (!vis[u]) { // 没有被访问过 是个新帮派
//            int head = u, totalValue = 0, numMember = 0;
//            DFS(u, head, totalValue, numMember);
//            if (numMember > 2 && totalValue > k) gang[int2str[head]] = numMember;
//        }
//    }
//}
//
//int main() {
//    cin >> n >> k; string s1, s2; int time;
//    for (int i = 0; i < n; ++i) {
//        cin >> s1 >> s2 >> time;
//        int id1 = getID(s1), id2 = getID(s2);
//        weight[id1] += time; weight[id2] += time;
//        G[id1][id2] += time; G[id2][id1] += time; // 一对人可能会打多次电话
//    }
//    DFSTraverse();
//    cout << gang.size() << endl;
//    map<string, int>::iterator it = gang.begin();
//    for (; it != gang.end(); ++it) {
//        cout << it->first << " " << it->second << endl;
//    }
//    return 0;
//}

/***
 IO说明：
 选手总数np 一个组的选手数ng
 np个老鼠的体重 没有重复体重 （0——np）
 np个选手序号 （乱序）
 
 输出最后每个选手的名次（按照原序列）
 
 思路：用结构体mouse存储选手体重 选手名次 用队列挨个处理
      每次晋级的老鼠数量 = 当前这轮组的数量
      每一轮没有晋级的老鼠排名 = group+1
      比如4个人晋级下一轮 没晋级的这一轮就都是并列第5名
 ***/

#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 1010;
struct mouse {
    int weight, r;
}mice[maxn];

int main() {
    int np, ng, order;
    scanf("%d %d", &np, &ng);
    // mice数组是静止的 等着被赋予名次
    for (int i = 0; i < np; ++i) scanf("%d", &mice[i].weight);
    queue<int> q;
    for (int i = 0; i < np; ++i) { // 大家排队比赛 每ng个为一组
        scanf("%d", &order); q.push(order); // 编号就相当于指针啦 不用把mice元素搬来搬去
        // 通过指针把名次传输给mice元素
    }
    int nowTotal = np, group; // nowTotal当前这轮的选手总数 group组数
    while (q.size() != 1) { // 角逐到只剩一个->第一名
        if (nowTotal % ng == 0) group = nowTotal / ng;
        else group = nowTotal / ng + 1;
        for (int i = 0; i < group; ++i) { // 找出每一组中最重的
            int maxID = q.front(); // 最重老鼠的编号
            for (int j = 0; j < ng; ++j) {
                if (i * ng + j >= nowTotal) break; // 如果最后一组个数不足ng个 提前退出循环
                if (mice[q.front()].weight > mice[maxID].weight) maxID = q.front();
                mice[q.front()].r = group + 1; q.pop(); // 顺便赋予每一个选手名次
            }
            q.push(maxID);
        }
        nowTotal = group; // group个选手晋级到下一轮
    }
    mice[q.front()].r = 1;
    for (int i = 0; i < np; ++i) {
        if (i) printf(" ");
        printf("%d", mice[i].r);
    }
    return 0;
}



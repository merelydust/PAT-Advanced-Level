/***
 IO说明：
 第一行 书的总数N(<=10000) 接下来N*6行
 书的7位ID
 书名字符串
 作者名字符串 (只有一位作者)
 书的关键词们 以空格分隔 (<=5个)
 出版商字符串
 出版年份【1000，3000】
 （总关键词不超过1000个 总出版社不超过1000个 书的信息输入完成后）
 M 查询总数(<=1000) 接下来M行 每行采取以下一种查询方式
 1: 书名
 2: 作者名
 3: 关键词
 4: 出版商名
 5: a 4-digit number representing the year
 
 对每一条查询 首先输出原始查询语句
 按升序输出查到的书ID 每个ID占一行
 如果没找到 输出 Not Found
 ***/

// 思路：空间换时间 对每一种查询方式都建立一个map string-set<int>
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
using namespace std;

void query(map<string ,set<int> >& mp, string& q) {
    if (mp.find(q) == mp.end()) printf("Not Found\n");
    else {
        set<int>::iterator it;
        for(it = mp[q].begin(); it != mp[q].end(); ++it) printf("%07d\n", *it);
    }
}

int main() {
    int n; cin >> n;
    map<string, set<int> > title2id, author2id, key2id, publish2id, year2id;
    int id; string tmp;
    while (n--) {
        cin >> id; char c = getchar();
        getline(cin, tmp); title2id[tmp].insert(id);
        getline(cin, tmp); author2id[tmp].insert(id);
        while (cin >> tmp) {
            key2id[tmp].insert(id);
            c = getchar();
            if (c == '\n') break;
        }
        getline(cin, tmp); publish2id[tmp].insert(id);
        cin >> tmp; year2id[tmp].insert(id);
    }
    int m; cin >> m; int tag; string q;
    while (m--) {
        scanf("%d: ", &tag); getline(cin, q);
        cout << tag << ": " << q << endl;
        set<int>::iterator it;
        switch (tag) {
            case 1:
                query(title2id, q); break;
            case 2:
                query(author2id, q); break;
            case 3:
                query(key2id, q); break;
            case 4:
                query(publish2id, q); break;
            case 5:
                query(year2id, q); break;
        }
    }
    return 0;
}

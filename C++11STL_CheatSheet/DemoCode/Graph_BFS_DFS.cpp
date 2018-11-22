#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b) )

//定义图的定点
typedef struct Vertex {
    int id;
    vector<int> connectors;    //存储节点的后续连接顶点编号
    
    Vertex() : id(-1) {}
    Vertex(int nid) : id(nid) {}
} Vertex;

//定义Graph的邻接表表示
typedef struct Graph {
    vector<Vertex> vertexs;   //存储定点信息
    int nVertexs;              //计数：邻接数
    bool isDAG;               //标志：是有向图吗
    
    Graph(int n, bool isDAG) : nVertexs(n), isDAG(isDAG) { vertexs.resize(n); }
    
    //向图中添加边
    bool addEdge(int id1, int id2) {
        if (!(MAX(id1, id2) < vertexs.size())) return false;
        
        if (isDAG) {
            vertexs[id1].connectors.push_back(id2);
        }
        else {
            vertexs[id1].connectors.push_back(id2);
            vertexs[id2].connectors.push_back(id1);
        }
        return true;
    }
    
    //广度优先搜索
    vector<int> BFS(int start) {
        set<int> visited;
        vector<int> g, rst;
        g.push_back(start);
        visited.insert(start);
        while(g.size() > 0) {
            int id = g[0];
            g.erase(g.begin());
            rst.push_back(id);
            for(int i = 0; i < vertexs[id].connectors.size(); i++) {
                int id1 = vertexs[id].connectors[i];
                if (visited.count(id1) == 0) {
                    g.push_back(id1);
                    visited.insert(id1);
                }
            }
        }
        return rst;
    }
    
    //深度优先搜索
    vector<int> DFS(int start) {
        set<int> visited;
        vector<int> g, rst;
        g.push_back(start);
        //cout << "push " << start << " ";
        visited.insert(start);
        rst.push_back(start);
        bool found;
        while(g.size() > 0) {
            int id = g[g.size()-1];
            found = false;
            for(int i = 0; i < vertexs[id].connectors.size(); i++) {
                int id1 = vertexs[id].connectors[i];
                if (visited.count(id1) == 0) {
                    g.push_back(id1);
                    rst.push_back(id1);
                    visited.insert(id1);
                    //cout << "push " << id1 << " ";
                    found = true;
                    break;
                }
            }
            if (!found) {
                int id2 = g[g.size()-1];
                rst.push_back(-1 * id2);
                //cout << "pop " << id2 << " ";
                g.pop_back();
            }
        }
        //cout << endl;
        return rst;
    }
} Graph;

int main() {
    Graph g(8, false);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(6, 7);
    vector<int> bv = g.BFS(0);
    cout << "宽度优先搜索节点顺序：";
    for(int j = 0; j < bv.size(); j++)
        cout << bv[j] << " ";
    cout << endl;
    
    cout << "深度优先搜索节点顺序：";
    Graph g1(6, false);
    g1.addEdge(0, 1);
    g1.addEdge(0, 4);
    g1.addEdge(0, 5);
    g1.addEdge(1, 5);
    g1.addEdge(4, 5);
    g1.addEdge(5, 2);
    g1.addEdge(5, 3);
    g1.addEdge(2, 3);
    vector<int> route = g1.DFS(0);
    for(int i = 0; i < route.size(); i++)
        cout << route[i] << " ";
    cout << endl;
    
    char ch;
    cin >> ch;
    return 0;
}


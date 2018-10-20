#include<iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int wi, di;
    vector<int> last(M+1, 0);
    vector<int> next(M+1, 0);
    for (int i=0; i<N; i++)
    {
        cin >> wi >> di;
        copy(next.begin(), next.end(), last.begin());
        for(int j=wi; j<=M; j++) {
            next[j] = max(last[j], last[j-wi]+di);
        }
    }
    cout << next[M] << endl;
    return 0;
}

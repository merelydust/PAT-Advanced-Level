#include <iostream>
#include <vector>
using namespace std;

int fun(const vector<int>& a, const vector<int>& b, const int sum) {
    int res=0;
    for (int i=0; i<a.size(); i++) {
        if (a.at(i)>0) {
            if (sum >= i) {
                res += a.at(i) * b.at(sum-i);
            }
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int sum=0;
    int a=0, b=0;
    int temp_a=0, temp_b=0;
    while(n--) {
        vector<int> vector_a(10001, 0), vector_b(10001, 0);
        cin >> sum;
        cin >> a;
        for(int i=0; i<a; i++) {
            cin >> temp_a;
            vector_a.at(temp_a)++;
        }
        cin >> b;
        for(int i=0; i<b; i++) {
            cin >> temp_b;
            vector_b.at(temp_b)++;
        }
        cout << fun(vector_a, vector_b, sum) << endl;
    }
    return 1;
}

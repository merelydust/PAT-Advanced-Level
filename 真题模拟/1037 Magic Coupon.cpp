#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool toSmall(int a, int b) {
    return a > b;
}

int main() {
    vector<int> positiveC, negativeC, positiveP, negativeP;
    int n, tmp; scanf("%d", &n);
    while(n--) {
        scanf("%d", &tmp);
        if (tmp > 0) positiveC.push_back(tmp);
        else if (tmp < 0) negativeC.push_back(tmp);
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &tmp);
        if (tmp > 0) positiveP.push_back(tmp);
        else if (tmp < 0) negativeP.push_back(tmp);
    }
    int money = 0;
    sort(positiveC.begin(), positiveC.end(), toSmall); sort(positiveP.begin(), positiveP.end(), toSmall);
    sort(negativeC.begin(), negativeC.end()); sort(negativeP.begin(), negativeP.end());
    for (int i = 0, j = 0, len1 = positiveC.size(), len2 = positiveP.size(); i < len1 && j < len2; ++i, ++j) money += positiveC[i] * positiveP[j];
    for (int i = 0, j = 0, len1 = negativeC.size(), len2 = negativeP.size(); i < len1 && j < len2; ++i, ++j) money += negativeC[i] * negativeP[j];
    printf("%d\n", money);
    return 0;
}

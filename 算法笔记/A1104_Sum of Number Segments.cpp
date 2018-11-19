// 每个数会出现(n - i) * (i + 1)次 i是数字的序号 从0开始
// 虽然是找规律题 可以这样理解
// 一个序列中的第i个数字 它后面（算上它自己）有n-i个数字 所以在以它开头的子序列中它会被算n-i次 子序列为{n}的情况在这里被囊括
// 同时 它前面的数字 有一个的话 以它开头的子序列中就可以拼接到后面 它又会被算一轮 -> 前面的数字有k个 组合数=(k+1)(n-i)
// 所以 它被加的总次数 = （前面的数字个数+1）* (后面的数字即n-i)

#include <iostream>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    double tmp = 0;
    double sum = 0;
    for(int i = 0; i < n; ++i){
        scanf("%lf", &tmp);
        sum += (tmp * (n - i) * (i + 1));
    }
    printf("%.2f\n", sum);
    return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, k;
    while( cin >> n >> k )
    {
        int num[n+1][n+1];             // 表示把n分成k个数的dp数组;
        int num1[n+1][n+1];            // 表示把n分成不相等正整数的dp数组;
        int g[55][55], f[55][55];      // g数组为偶数dp数组， f数组为奇数dp数组;
        int i, j;
        // 初始化;
        for( i=0; i<=n; i++ )
        {
            for( j=0; j<=n; j++ )
            {
                num[i][j] = num1[i][j] = f[i][j] = g[i][j] = 0;
            }
        }
        // 这就是上面说的其中两种。
        for( i=1; i<=n; i++)
        {
            for( j=1; j<=n; j++)
            {
                if( i < j )
                {
                    num[i][j] = 0;
                    num1[i][j] = num1[i][j-1];
                }
                if( i == j )
                {
                    num[i][j] = 1;
                    num1[i][j] = 1 + num1[i][j-1];
                }
                if( i > j )
                {
                    num[i][j] = num[i-1][j-1] + num[i-j][j];
                    num1[i][j] = num1[i-j][j-1] + num1[i][j-1];
                }
            }
        }
        //  这里是最晕的，只要记住就好了,搞懂也没多大意义;
        f[0][0]=1; g[0][0]=1;
        for( i=1; i<=n; i++ )
        {
            for( j=1; j<=i; j++)
            {
                g[i][j] = f[i-j][j];
                f[i][j] = f[i-1][j-1] + g[i-j][j];
                
            }
        }
        
        cout << num[n][k] <<endl;
        cout << num1[n][n] <<endl;
        int sum = 0;
        for( i=0; i<=n; i++)
            sum += f[n][i];
        cout << sum <<endl;
    }
    return 0;
}


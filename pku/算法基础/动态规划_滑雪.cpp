#include <iostream>

using namespace std;

int data[102][102], longest[102][102];
int m,n;

int cal(int i, int j)
{
    int max = 0;//保存周围节点的最大长度，最优子问题的变形;
    if (longest[i][j] > 0)
        return longest[i][j];
    if ( i-1>=0 && data[i][j]>data[i-1][j] && max<cal(i-1,j))
        max = cal(i-1,j);
    if ( j-1>=0 && data[i][j]>data[i][j-1] && max<cal(i,j-1))
        max = cal(i,j-1);
    if( i+1<m && data[i][j]>data[i+1][j] && max<cal(i+1,j))
        max = cal(i+1,j);
    if( j+1<n && data[i][j]>data[i][j+1] && max<cal(i,j+1))
        max = cal(i,j+1);
    return longest[i][j] = max+1;
    
}



int main()
{
    int i,j;
    int maxway = 0;
    
    cin>>m>>n;
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
        {
            cin>>data[i][j];
            longest[i][j] = 0;
        }
    for(i=0; i<m; i++)
        for (j=0; j<n; j++)
        {
            longest[i][j] = cal(i,j);
            if(maxway<longest[i][j])
                maxway = longest[i][j];
        }
    cout<<maxway<<endl;
}

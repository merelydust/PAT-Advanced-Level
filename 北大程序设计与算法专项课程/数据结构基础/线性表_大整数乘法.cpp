#include<iostream>
#include<string>
using namespace std;
const int maxn = 210;

int main()
{
    string str1, str2; cin >> str1 >> str2;
    int len1 = str1.length(), len2 = str2.length();
    int  i, j;
    int a[maxn], b[maxn], ans[2*maxn]={0};
    for(i=len1-1, j=0; i>=0; i--) a[j++]=str1[i]-'0';
    for(i=len2-1, j=0; i>=0; i--) b[j++]=str2[i]-'0';
    for( i=0; i<len1; ++i)
    {
        for(j=0; j<len2; ++j)
        {
            ans[i+j]+=a[i]*b[j];
            if( ans[i+j]>=10 )//大于9进位
            {
                ans[i+j+1]+=ans[i+j]/10;
                ans[i+j]%=10;
            }
        }
    }
    //长度为len1和len的两数相乘，最多有len1+len2位，最少有len1+len2-1位
    i=len1+len2-1;
    if( ans[i]==0 )//检验第len1+len2位是否为0,若为0， 则不输出
        i--;
    for(i; i>=0; i--)//输出
        cout<<ans[i];
    cout<<endl;
}

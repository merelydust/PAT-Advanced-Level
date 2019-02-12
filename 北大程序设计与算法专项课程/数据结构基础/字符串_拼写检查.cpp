#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a[10001];
    int i=0;
    int j;
    while(cin>>a[i])
    {
        if(a[i]=="#")
            break;
        i++;
    }
    string x;
    string b;
    while(cin>>x)
    {
        b="";
        if(x=="#")
            break;
        for(j=0;j<i;j++)
        {
            if(a[j]==x)
                break;
            if(a[j].size()-x.size()==0)
            {
                int k;
                for(k=0;k<x.size();k++)
                    if(a[j][k]!=x[k])
                        break;
                string c=x;
                c[k]=a[j][k];
                if(c==a[j])
                    b=b+" "+a[j];
            }
            else if(a[j].size()-x.size()==-1)
            {
                int l=0;
                for(int k=0;k<x.size();k++)
                {
                    if(a[j][l]==x[k])
                        l++;
                }
                if(l==a[j].size())
                    b=b+" "+a[j];
            }
            else if(a[j].size()-x.size()==1)
            {
                int l=0;
                for(int k=0;k<a[j].size();k++)
                {
                    if(a[j][k]==x[l])
                        l++;
                }
                if(l==x.size())
                    b=b+" "+a[j];
            }
        }
        if(j!=i)
            cout<<x<<" is correct"<<endl;
        else
            cout<<x<<":"<<b<<endl;
    }
    return 0;
}

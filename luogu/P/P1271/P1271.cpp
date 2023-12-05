#include <iostream>
using namespace std;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int c[n+1];
    fill(c,c+n+1,0);
    int t;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&t);
        c[t]++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<c[i];j++)
        {
            printf("%d ",i);
        }
    }
    return 0;
}
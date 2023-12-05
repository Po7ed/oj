#include <bits/stdc++.h>
using namespace std;
int s,a[1005],u[1005];//定义qaq
int find(int x)//求每个数最大公约数的和
{
int ans=0;//记住，一定要把ans初始化为0，一定要把ans初始化为0，一定要把ans初始化为0，重要的事说三遍；
for(int i=1;i<x;i++)
if(x%i==0)
ans+=i;
return ans;
}
int main()
{
cin>>s;
for(int i=1;i<=s;i++)
a[i]=find(i);//把和赋值给a[i]
for(int i=1;i<=s;i++)
{

    for(int j=s;j>=i;j--)  
    {
        u[j]=max(u[j],u[j-i]+a[i]);//01背包基本模板  
    }  
}  
cout<<u[s];//输出  

return 0;//每天一个return 0，身心更健康
}
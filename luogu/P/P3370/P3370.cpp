#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
    set<string> a;
    string s;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    	cin>>s;
    	a.insert(s);
	}
	printf("%d",a.size());
}
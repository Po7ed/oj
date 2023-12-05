#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a,b,c;
	cin>>a>>b>>c;
	set<string> z;
	string s;
	for(int i=1;i<=a;i++)
	{
		cin>>s;
		z.insert(s);
	}
	for(int i=1;i<=b;i++)
	{
		cin>>s;
		z.erase(s);
	}
	for(int i=1;i<=c;i++)
	{
		cin>>s;
		z.insert(s);
	}
	for(string t:z)
	{
		cout<<t<<"\n";
	}
	return 0;
}
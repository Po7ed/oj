#include <iostream>
#include <map>
using namespace std;
int main()
{
	string s;
	map<char,int> a;
	int m=-1;
	while(cin>>s)
	{
		for(char c:s)
		{
			a[c]++;
		}
	}
	for(char c='A';c<='Z';c++)
	{
		m=max(m,a[c]);
	}
	for(int i=m;i>0;i--)
	{
		for(char c='A';c<='Z';c++)
		{
			printf("%c%c"," *"[int(bool(a[c]>=i))]," \n"[int(bool(c=='Z'))]);
		}
	}
	for(char c='A';c<='Z';c++)
	{
			printf("%c%c",c," \n"[int(bool(c=='Z'))]);
	}
	return 0;
}
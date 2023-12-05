#include <iostream>
#include <cctype>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		if(islower(s[i]))
		{
			s[i]=toupper(s[i]);
		}
	}
	cout<<s<<endl;
	return 0;
}
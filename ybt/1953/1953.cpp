#include <iostream>
using namespace std;

int main()
{
	string s;
	bool bf=1;
	cin>>s;
	if(s[0]=='-')
	{
		printf("-");
		s.erase(s.begin());
	}
	for(int i=s.length()-1;i>=0;i--)
	{
		if(bf&&s[i]=='0')
		{
			continue;
		}
		bf=0;
		printf("%c",s[i]);
	}
	return 0;
}
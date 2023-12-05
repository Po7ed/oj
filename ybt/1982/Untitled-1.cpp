#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	string s;
	char t;
	int c=0;
	cin>>s;
	for(int i=0;!s.empty();i++)
	{
		sscanf(s.c_str(),"%c",&t);
		if(t=='1')
			c++;
		s.erase(s.begin());
	}
	printf("%d",c);
	return 0;
}
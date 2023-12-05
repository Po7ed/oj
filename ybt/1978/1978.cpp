#include <iostream>
#include <string>
using namespace std;

int main()
{
	int c=0;
	string s;
	getline(cin,s);
	for(int i=0;i<s.length();i++)
		if(s[i]!=' ')
			c++;
	cout<<c;
	return 0;
}
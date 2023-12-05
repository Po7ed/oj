#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	bool b=1;
	
	for (auto c:s)
	{
		if(b)
		{
			if(c=='_'||isalpha(c));else
			{
				printf("no");
				return 0;
			}
		}
		else
		{
			if(c=='_'||isalpha(c)||isdigit(c));else
			{
				printf("no");
				return 0;
			}
		}
		b=0;
	}
	printf("yes");
	return 0;
}
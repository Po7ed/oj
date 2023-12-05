#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define c s[i]
typedef pair<int,int> p;
#define type first
#define id second
#define f 1
#define y 0

int main()
{
	string s;
	cin>>s;
	vector<p> k;
	int l=s.length();
	bool b[l+1];
	fill(b,b+l+1,false);
	for(int i=0;i<l;i++)
	{
		switch(c)
		{
			case '(':
				k.push_back({y,i});
			break;
			case ')':
				if(!k.empty()&&k.back().type==y)
				{
					b[k.back().id]=true;
					b[i]=true;
					k.pop_back();
				}
			break;
			case '[':
				k.push_back({f,i});
			break;
			case ']':
				if(!k.empty()&&k.back().type==f)
				{
					b[k.back().id]=true;
					b[i]=true;
					k.pop_back();
				}
			break;
		}
	}
	for(int i=0;i<l;i++)
	{
		if(!b[i])
		{
			switch(c)
			{
				case '(':
					printf("%c)",s[i]);
				break;
				case ')':
					printf("(%c",s[i]);
				break;
				case '[':
					printf("%c]",s[i]);
				break;
				case ']':
					printf("[%c",s[i]);
				break;
			}
		}
		else
			printf("%c",s[i]);
	}
	return 0;
}
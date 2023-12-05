#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> A,B;
	int t;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		A.push_back(t);
	}
	char on[n+2];
	memset(on,'A',sizeof(on));
	reverse(A.begin(),A.end());
	queue<pair<char,char>> out;
	int cnt=0;
	for(int i=n;i>0;i--)
	{
		if(on[i]=='A')
		{
			while(A.back()!=i)
			{
				// puts("A B");
				out.push({'A','B'});
				on[A.back()]='B';
				cnt++;
				B.push_back(A.back());
				A.pop_back();
			}
			// puts("A C");
			out.push({'A','C'});
			on[i]='C';
			cnt++;
			A.pop_back();
		}
		else if(on[i]=='B')
		{
			while(B.back()!=i)
			{
				// puts("B A");
				out.push({'B','A'});
				on[B.back()]='A';
				cnt++;
				A.push_back(B.back());
				B.pop_back();
			}
			// puts("A C");
			out.push({'B','C'});
			on[i]='C';
			cnt++;
			B.pop_back();
		}
	}
	printf("%d\n",cnt);
	// for(pair<char,char> p:out)
	while(!out.empty())
	{
		printf("%c %c\n",out.front().first,out.front().second);
		out.pop();
	}
	return 0;
}

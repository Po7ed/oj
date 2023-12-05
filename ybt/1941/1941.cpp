#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("out.txt","w",stdout);
	for(int i=0;i<=1024;i++)
	{
		stringstream ss;
		ss<<fixed<<pow(2.0L,i);
		cout<<"\""<<ss.str()<<"\","<<flush;
	}
	return 0;
}
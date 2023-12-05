#include <iostream>
// #include <algorithm>
using namespace std;

void reverse(string s)
{
	if(s.empty())return;
	char c=s.front();
	s.erase(s.begin());
	reverse(s);
	cout<<c<<flush;
}

int main()
{
	string s;
	cin>>s;
	// reverse(s.begin(),s.end());
	reverse(s);
	// cout<<s<<endl;
	return 0;
}
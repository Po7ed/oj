#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string,string> m;

string find(string s)
{
	if(!m.count(s))return s;
	return find(m[s]);
}

int main()
{
	string f;
	while(1)
	{
		string s;
		cin>>s;
		if(s[0]=='$')return 0;
		if(s[0]=='#')
		{
			f.clear();
			f.push_back(s[1]);
			f.push_back(s[2]);
			f.push_back(s[3]);
			f.push_back(s[4]);
			f.push_back(s[5]);
			f.push_back(s[6]);
		}
		if(s[0]=='+')
		{
			string t;
			t.push_back(s[1]);
			t.push_back(s[2]);
			t.push_back(s[3]);
			t.push_back(s[4]);
			t.push_back(s[5]);
			t.push_back(s[6]);
			m[t]=f;
		}
		if(s[0]=='?')
		{
			string t;
			t.push_back(s[1]);
			t.push_back(s[2]);
			t.push_back(s[3]);
			t.push_back(s[4]);
			t.push_back(s[5]);
			t.push_back(s[6]);
			cout<<t<<" "<<find(t)<<endl;
		}
	}
	return 0;
}
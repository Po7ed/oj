#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
string s;
string ts;
int n;
bool a[100001];//³õÖµ 
set<int> fw;
int main()
{
	getline(cin,s);
	ts=s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		a[i]=(bool)t;
	}
	vector<pair<bool,set<int>>> v;
	while(!s.empty())
	{
		char f=s[0];
		if(f=='x')
		{
			s.erase(s.begin());
			int x;
			sscanf(s.c_str(),"%d",&x);
			pair<bool,set<int>> tmp;
			tmp.first=a[x];
			tmp.second.clear();
			tmp.second.insert(x);
			v.push_back(tmp);
			while(!s.empty()&&s[0]!=' ')
				s.erase(s.begin());
			if(!s.empty())s.erase(s.begin());
		}
		else if(f=='!'||f=='|'||f=='&')
		{
			s.erase(s.begin());
			if(!s.empty())
				s.erase(s.begin());
			if(f=='!')
			{
				pair<bool,set<int>> tmp=v.back();
				v.pop_back();
				tmp.first=!tmp.first;
				v.push_back(tmp);
			}
			if(f=='|')
			{
				pair<bool,set<int>> tmp1,tmp2;
				tmp1=v.back();
				v.pop_back();
				tmp2=v.back();
				v.pop_back();
				pair<bool,set<int>> push;
				push.first=tmp1.first||tmp2.first;
//				if(tmp1.first&&tmp2.first)
//				{
//					fw.insert(tmp1.second.begin(),tmp1.second.end());
//					fw.insert(tmp2.second.begin(),tmp2.second.end());
//				}
				if(tmp1.first)
				{
					fw.insert(tmp2.second.begin(),tmp2.second.end());
				}
				if(tmp2.first)
				{
					fw.insert(tmp1.second.begin(),tmp1.second.end());
				}
				push.second.insert(tmp1.second.begin(),tmp1.second.end());
				push.second.insert(tmp2.second.begin(),tmp2.second.end());
				v.push_back(push);
			}
			if(f=='&')
			{
				pair<bool,set<int>> tmp1,tmp2;
				tmp1=v.back();
				v.pop_back();
				tmp2=v.back();
				v.pop_back();
				pair<bool,set<int>> push;
				push.first=tmp1.first&&tmp2.first;
//				if(!tmp1.first&&!tmp2.first)
//				{
//					fw.insert(tmp1.second.begin(),tmp1.second.end());
//					fw.insert(tmp2.second.begin(),tmp2.second.end());
//				}
				if(!tmp1.first)
				{
					fw.insert(tmp2.second.begin(),tmp2.second.end());
				}
				if(!tmp2.first)
				{
					fw.insert(tmp1.second.begin(),tmp1.second.end());
				}
				push.second.insert(tmp1.second.begin(),tmp1.second.end());
				push.second.insert(tmp2.second.begin(),tmp2.second.end());
				v.push_back(push);
			}
		}
	}
	bool ans=v.back().first;
	int ask;
	scanf("%d",&ask);
	int t;
	for(int i=1;i<=ask;i++)
	{
		scanf("%d",&t);
//		vector<bool> v;
		if(fw.count(t))
			printf("%d\n",(int)ans);
		else
			printf("%d\n",(int)(!ans));
		s=ts;
	}
	return 0;
}

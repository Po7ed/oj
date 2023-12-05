#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	vector<double> v;
	vector<string> sv;
	string s;
	getline(cin,s);
	while(!s.empty())
	{
		double n=0;
		char c;
		if(sscanf(s.c_str(),"%lf",&n))
		{
			stringstream ss;
			ss<<n;
			sv.insert(sv.begin(),ss.str());
			while(s.front()!=' '&&!s.empty())
				s.erase(s.begin());
			if(!s.empty())s.erase(s.begin());
		}
		else if(sscanf(s.c_str(),"%c",&c))
		{
			stringstream ss;
			ss<<c;
			sv.insert(sv.begin(),ss.str());
			s.erase(s.begin());
			s.erase(s.begin());
		}
	}
	while(!sv.empty())
	{
		double n=0;
		char c;
		if(sscanf(sv.front().c_str(),"%lf",&n))
		{
			v.push_back(n);
		}
		else if(sscanf(sv.front().c_str(),"%c",&c))
		{
			double a=0,b=0;
			a=v.back();v.pop_back();
			b=v.back();v.pop_back();
			switch(c)
			{
				case '+':v.push_back(a+b);break;
				case '-':v.push_back(a-b);break;
				case '*':v.push_back(a*b);break;
				case '/':v.push_back(a/b);break;
			}
		}
		sv.erase(sv.begin());
	}
	printf("%lf",v.back());
	return 0;
}
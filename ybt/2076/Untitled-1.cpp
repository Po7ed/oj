#include<bits/stdc++.h>
using namespace std;
bool f(string s){
	long long a,b,c,d,e;
	if(sscanf(s.c_str() ,"%lld.%lld.%lld.%lld:%lld", &a, &b, &c, &d, &e)!=5)
		return 0; 
	if(a<0||a>255||b<0||b>255||c<0||c>255||d<0||d>255||e<0||e>65535) return 0;
	stringstream ss;
	ss<<a<<'.'<<b<<'.'<<c<<'.'<<d<<':'<<e;
	if(ss.str()!=s)return 0;
	return 1;
}
map<string,int> m;
string op,ad;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op>>ad;
		if(!f(ad)){
			printf("ERR\n");
			continue;
		}
		if(op[0]=='s'){
			if(m[ad]) printf("FAIL\n");
			else{
				m[ad]=i;
				printf("OK\n");
			}
		}
		else{
			if(!m.count(ad))printf("FAIL\n");
			else printf("%d\n",m[ad]);
		}
	}
	return 0;
}
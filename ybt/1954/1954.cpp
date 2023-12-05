#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s,w;
	bool b=1,f=1;
	int c=0,bi=0;
	getline(cin,s);
	getline(cin,w);
	//printf("%d",(int)w.empty());
	for(int i=0;!w.empty();i++)
	{
		b=1;
		string t;
		// cout<<__LINE__<<endl;
		while(w.front()!=' ')
		{
			if(w.empty())goto con;
			t.push_back(w.front());//cout<<"del"<<w.front()<<endl;
			w.erase(w.begin());
		}
		w.erase(w.begin());
		// cout<<t<<endl;
		con:
		//printf("%d$%d\n",s.length(),t.length());
		if(s.length()==t.length())
		{
			for(int j=0;j<s.length();j++)
			{
				//printf("%c*%c",tolower(s[j]),tolower(t[j]));
				if(tolower(s[j])!=tolower(t[j]))
					b=0;
			}
			// cout<<endl;
			if(b&&f){bi=i;f=0;}
			if(b)c++/*,printf("(+)\n")*/;
			// cout<<c<<"&"<<i<<endl;
		}
		// else cout<<"!&"<<endl;
	}
	if(c==0)
	{
		printf("-1");
		return 0;
	}
	printf("%d %d",c,bi);
	return 0;
}
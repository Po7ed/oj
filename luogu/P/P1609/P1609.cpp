#include <iostream>
using namespace std;
int main()
{
	string s,t;
	cin>>s;
	int l=s.length()-1;
	t=s;
	bool is999=true;
	for(char c:s)
	{
		if(c!='9')
		{
			is999=false;
			break;
		}
	}
	if(is999)
	{
		t="1";
		t.append(s.length(),'0');
		s=t;
		l++;
		// cout<<s<<"\n";
	}
	int i=0;
    for(i=0;i<=l-i;i++)
	{
		t[i]=t[l-i]=s[i];
	}
	i=s.length()/2;
    if(t<=s)
	{
        while(t[i]=='9')
		{
			i--;
		}
		t[i]=t[l-i]=++t[i];
        for(i++;i<=l-i;i++)
		{
			t[i]=t[l-i]='0';
		}
    }
	cout<<t<<"\n";
    return 0;
}

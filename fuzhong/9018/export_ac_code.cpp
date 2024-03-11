// Problem1000:
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cout<<n+1<<flush;
	return 0;
}
// Problem1001:
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float a,b,h;
	cin>>a>>b>>h;
	cout<<fixed<<setprecision(2)<<(a+b)*h/2<<endl;
	return 0;
}
// Problem1002:
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float c;
	cin>>c;
	cout<<fixed<<setprecision(1)<<c*9/5+32<<endl;
	return 0;
}
// Problem1004:
#include <iostream>
using namespace std;

int main()
{
	long long a,b;
	cin>>a>>b;
	cout<<a<<"+"<<b<<"="<<a+b<<endl;
	cout<<a<<"-"<<b<<"="<<a-b<<endl;
	cout<<a<<"*"<<b<<"="<<a*b<<endl;
	cout<<a<<"/"<<b<<"="<<a/b<<"..."<<a%b<<endl;
	return 0;
}
// Problem1005:
#include <iostream>
using namespace std;

int main()
{
	short a,b,c;
	cin>>a>>b>>c;
	b+=a/3;
	c+=a/3;
	a/=3;
	a+=b/3;
	c+=b/3;
	b/=3;
	a+=c/3;
	b+=c/3;
	c/=3;
	cout<<a<<" "<<b<<" "<<c<<endl;
	return 0;
}
// Problem1005:
#include <iostream>
using namespace std;

int main()
{
	short a,b,c;
	cin>>a>>b>>c;
	b+=(a-a%3)/3;
	c+=(a-a%3)/3;
	a=(a-a%3)/3;
	a+=(b-b%3)/3;
	c+=(b-b%3)/3;
	b=(b-b%3)/3;
	a+=(c-c%3)/3;
	b+=(c-c%3)/3;
	c=(c-c%3)/3;
	cout<<a<<" "<<b<<" "<<c<<endl;
	return 0;
}
// Problem1006:
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	float a,b,c,p,s;
	cin>>a>>b>>c;
	if(a+b>c&&a+c>b&&b+c>a)
	{
		p=(a+b+c)/2;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		cout<<fixed<<setprecision(2)<<s<<flush;
	}
	else
		cout<<"No solution."<<flush;
	return 0;
}
// Problem1007:
#include <iostream>
using namespace std;

int main()
{
	short y;
	cin>>y;
	cout<<((y%4==0&&y%100!=0||y%400==0)?"yes":"no")<<endl;
	return 0;
}
// Problem1015:
#include <iostream>
using namespace std;
int main()
{
	double cm,kg,s;
	cin>>cm>>kg;
	s=(cm-100)*0.9;
	if(kg>s*1.1)
		cout<<"fat"<<flush;
	else if(kg<s*0.9)
		cout<<"thin"<<flush;
	else
		cout<<"standard"<<flush;
	return 0;
}
// Problem1019:
#include <iostream>
using namespace std;

int main()
{
	short n=0;
	long long s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		s+=i*(i+1);
	}
	cout<<s<<flush;
	return 0;
}

// Problem1020:
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	a[1]=a[2]=1;
	for (int i = 3; i <= n; i++)
	{
		a[i]=a[i-2]+a[i-1];
	}
	cout<<a[n]<<flush;
	return 0;
}
// Problem1021:
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	bool first=1;
	short a=0,b=0,c=0,t=0;
	cin>>a>>b;
	for(short i=a;i<=b;i++)
	{
		t=pow(i/100,3)+pow((i%100)/10,3)+pow((i%10),3);
		if(t==i)
		{
			if(first)
			{
				cout<<i<<flush;
				first=0;
			}
			else
				cout<<" "<<i<<flush;
			c+=1;
		}
	}
	if(c==0)
		cout<<"No Answer"<<flush;
	return 0;
}

// Problem1022:
#include <iostream>
using namespace std;

int gys(int n,int m)
{
	if(n<m)
	{
		if(m%n==0)
			return n;
		else
			return gys(n,m%n);
	}
	if(n>m)
	{
		if(n%m==0)
			return m;
		else
			return gys(m,n%m);
	}
	return 1;
}

int main()
{
	int n,m;
	cin>>n>>m;
	cout<<gys(n,m)<<flush;
	return 0;
}

// Problem1023:
#include <iostream>
using namespace std;

int main()
{
	double s,m;
	int n=1;
	cin>>m;
	for(;s<m;n+=2)
		s+=1.00/n;
	n-=2;
	cout<<n<<flush;
	return 0;
}

// Problem1025:
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n=0,max=0;
	cin>>n;
	int a[n];
	cin>>a[0];
	for (int i = 1; i <= n-1; i++)
	{
		cin>>a[i];
		if(a[i]+a[i-1]>max)max=a[i]+a[i-1];
	}
	if(a[0]+a[n-1]>max)max=a[0]+a[n-1];
	cout<<max;
	return 0;
}
// Problem1026:
#include <iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int len=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='.')
			{len=i;break;}
	}
	len--;
	// printf("%d\n",len);
	for(int i=0;i<=len/2;i++)
	{
		if(s[i]!=s[len-i]){printf("no");return 0;}
	}
	printf("yes");
	return 0;
}
// Problem1028:
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n=0;
	cin>>n;
	int a[n][n];
	int imin[n];//各行最小
	int jmax[n];//各列最大
	int bookim[n][2];
	int bookjm[n][2];
	bool bookno=1;
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++)
	{
		imin[i]=100000;
		jmax[i]=-100000;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			if(imin[i]>a[i][j])
			{
				imin[i]=a[i][j];
				bookim[i][0]=i;
				bookim[i][1]=j;
			}
			if(jmax[j]<a[i][j])
			{
				jmax[j]=a[i][j];
				bookjm[j][0]=i;
				bookjm[j][1]=j;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(imin[i]==jmax[bookim[i][1]])
		{
			cout<<i+1<<endl<<bookim[i][1]+1<<endl;
			bookno=0;
		}
	}
	if(bookno)
		cout<<"no"<<endl;
	return 0;
}
// Problem1029:
#include <iostream>
using namespace std;

int main()
{
	short n=0,max=-10001,min=10001,t;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(t>max)max=t;
		if(t<min)min=t;
	}
		
	cout<<max-min<<flush;
	return 0;
}

// Problem1031:
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n=0;
	cin>>n;
	int a[n][n];
	bool bookfirst=1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i==j||j==0)
				a[i][j]=1;
			else
				a[i][j]=a[i-1][j]+a[i-1][j-1];
			if(!bookfirst) cout<<" "<<flush;
			bookfirst=0;
			cout<<a[i][j]<<flush;
		}
		bookfirst=1;
		cout<<endl;
	}
	return 0;
}
// Problem1032:
#include <iostream>
using namespace std;
int main()
{
	int n=0;
	scanf("%d",&n);
	int a[n+1][6];
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
		a[i][4]=a[i][1]+a[i][2]+a[i][3];
		a[i][0]=i;a[i][5]=0;
	}
	for(int i=n;i>1;i--)
		for(int j=1;j<i;j++)
			if(a[j][4]<a[j+1][4])
				swap(a[j],a[j+1]);
	for(int i=1;i<=n;i++)
	{
		// if(i==1){a[i][5]=1;continue;}
		if(a[i-1][4]==a[i][4])
			a[i][5]=a[i-1][5];
		else a[i][5]=i;
		// else a[i][5]=a[i-1][5]+1;
	}
	for(int i=n;i>1;i--)
		for(int j=1;j<i;j++)
			if(a[j][0]>a[j+1][0])
				swap(a[j],a[j+1]);
	for(int i=1;i<=n;i++)
		printf("%8d%8d%8d%8d%8d%8d\n",a[i][0],a[i][1],a[i][2],a[i][3],a[i][4],a[i][5]);
	return 0;
}
// Problem1033:
#include <iostream>
#include <string.h>
using namespace std;

int n=0,sum=0,k=0;//k:奇偶轮步数矫正
int a[10][10];

void move(int t,int dir,int ii,int jj,int last);//last:上次数字终值 t:本轮步数
int main()
{
	cin>>n;
	move(n,0,-1,n-1,1);
	int x,y;
	cin>>x>>y;
	cout<<a[x-1][y-1]<<endl;
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j];
		cout<<endl;
	}*/
	return 0;
}

void move(int t,int dir,int ii,int jj,int last)
{
	if(t==0)
		return;
	int i=0;
	for(;i<t;i++)
	{
		switch(dir)
		{
		case 0:ii++;a[ii][jj]=last+i;break;
		case 1:jj--;a[ii][jj]=last+i;break;
		case 2:ii--;a[ii][jj]=last+i;break;
		case 3:jj++;a[ii][jj]=last+i;break;
		}
	}
	k++;
	k%=2;
	dir++;
	move(t-k,dir%=4,ii,jj,last+t);
}
// Problem1034:
#include <iostream>
using namespace std;
int main()
{
	int n=0,t=0,k=0;
	cin>>n>>k;
	for (int i = 1; i<=n; i++)//line
	{
		for (int j = 1; j <= k; j++)
		{
			t=n-i;for (int ii = 1; ii <= t; ii++)cout<<" "<<flush;
			t=2*i-1;for (int ii = 1; ii <= t; ii++)cout<<"*"<<flush;
			t=n-i;for (int ii = 1; ii <= t; ii++)cout<<" "<<flush;
		}
		cout<<endl;
	}
	return 0;
}
// Problem1036:
#include <iostream>
using namespace std;

int main()
{
	double f;
	int t;
	cin>>f>>t;
	cout<<((f<75&&t<=2230)?"BAD":"OK")<<endl;
	return 0;
}
// Problem1038:
#include <iostream>
using namespace std;

int main()
{
	short n=0,s=0,c=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(s==33||s==34)
			c+=1;
	}
	cout<<c<<flush;
	return 0;
}

// Problem1039:
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    double first, needs, target, M;
    scanf("%lf", &target);
    first = 2.0;
    n = 1;
    needs = first;
    M = first;
    while (1)       //死循环
    {
        if (needs > target)     //判断是否符合条件
        {
            printf("%d\n", n);
            break;
        }
        M = M * 0.98;   //每一步为上一步的98%，M（=2.0）的累积
        needs += M;     //总共游的距离needs（=2.0）的累加
        n++;
    }
    return 0;
}
// Problem1043:
#include <iostream>
using namespace std;

int main()
{
	int a,b,c,d,h,m;
	cin>>a>>b>>c>>d;
	h=c-a;
	m=d-b;
	if(m<0)
	{
		h-=1;
		m+=60;
	}
	cout<<h<<" "<<m<<endl;
	return 0;
}
// Problem1048:
#include <iostream>
using namespace std;

int main()
{
	bool book=0;
	int x=0,m=0,n=0,y=0,z=0;
	cin>>x>>m>>n;
	int ly=(m-3*x-5)/4,lz=(m-3*x-4)/5;
	for(int i=1;i<=ly;i++)
	{
		for(int j=1;j<=lz;j++)
		{
			if((m-3*x==4*i+5*j)&&(n-x==2*i+4*j))
			{
				y=i;z=j;
				book=1;
				break;
			}
		}
		if(book)break;
	}
	if(y==0||z==0)
	cout<<"No Answer"<<flush;
	else
	cout<<y<<" "<<z<<flush;
	return 0;
}
// Problem1050:
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n=0,k=0,dir=0,sum=0;
	cin>>n>>k;
	int a[n+2][n+2],book[n+2][n+2];
	memset(a,0,sizeof(a));
	memset(book,0,sizeof(book));
	for(int i=0;i<n+2;i++)
		for(int j=0;j<n+2;j++)
			if(i==0||j==0||i==n+1||j==n+1)
				book[i][j]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	int i=1,j=1;
	for(int c=0;c<k;c++)
	{
		sum+=a[i][j];
		book[i][j]=1;
		switch(dir)
		{
		case 0:i++;break;
		case 1:j++;break;
		case 2:i--;break;
		case 3:j--;break;
		}
		if(book[i][j]==1)
		{
			switch(dir)
			{
			case 0:i--;break;
			case 1:j--;break;
			case 2:i++;break;
			case 3:j++;break;
			}
			dir++;
			dir%=4;
			switch(dir)
			{
			case 0:i++;break;
			case 1:j++;break;
			case 2:i--;break;
			case 3:j--;break;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}

// Problem1052:
#include <iostream>
using namespace std;

int main()
{
	int i=0,j=0;
	int t=0;
	short max=0;
	cin>>i>>j;
	for (int c=i;c<=j;c++)
	{
		int s=1;
		t=c;
		//cout<<"c:"<<c<<endl;
		while(t!=1)
		{
			s++;
			//cout<<"s:"<<s<<endl;
			if(t%2==0)
				t/=2;
			else
				t=t*3+1;
		}
		if (s>max)max=s;
	}
	cout<<max<<flush;
	return 0;
}
// Problem1074:
#include <iostream>
using namespace std;

int main()
{
	string s;
	bool bf=1;
	cin>>s;
	if(s[0]=='-')
	{
		printf("-");
		s.erase(s.begin());
	}
	for(int i=s.length()-1;i>=0;i--)
	{
		if(bf&&s[i]=='0')
		{
			continue;
		}
		bf=0;
		printf("%c",s[i]);
	}
	return 0;
}
// Problem1075:
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
string str, key, k;
bool is_first = true;
int qwq = 0;
int ans_add; //第一个需求单词的位置（ans address）
int first_address=0; //指每一个单词开头的位置，提前记录，如果是第一个需求单词就把它记录到ans里
int main()
{
    getline(cin, key);
    getline(cin, str);
    for (int i = 0; i < key.length(); i++)
        key[i] = toupper(key[i]);  //强转大写（小写->大写，大写不变）
    for (int i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
//上述两步都转换为小写（tolower）也可以，只需要保证需求单词和字符串大小写一致即可
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            if (k == key) 
            {
                qwq++; //单词数++
                if (is_first) //如果找到的单词是第一个
                {
                    ans_add = first_address; //标记地址
                    is_first = false; //标记第一个已访问
                }
            }
            first_address = i + 1;//下一个单词的开头是空格结束的下一个
            k.clear(); //clear字符串清空操作
        }
        else
            k += str[i]; //string类型的字符串可以实现加法操作，此操作是将str[i]的内容添加到k的后面
    }
    if (is_first)
    {
        cout << "-1" << endl;
    }
    else
        cout << qwq << " " << ans_add << endl;
    return 0;
}

// Problem1076:
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
typedef pair<int,int> P;
/// @brief l[i].first => index | l[i].second => point
P l[200001],win[100001],los[100001];
int li,wini,losi,winj,losj;
int w[200001];
int n,r,q;

bool cmp(P x,P y)
{
	return (x.second==y.second&&x.first<y.first)||x.second>y.second;
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d %d %d",&n,&r,&q);n*=2;
	li=0;
	for(int i=1;i<=n;i++)
	{
		P t;
		scanf("%d",&t.second);
		t.first=i;
		l[li++]=t;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	sort(l,l+n,cmp);
	for(int i=1;i<=r;i++)
	{
		wini=0;losi=0;
		for(int i=0;i<n;i+=2)
			if(w[l[i].first]>w[l[i+1].first])
			{
				l[i].second++;
				win[wini++]=l[i];
				los[losi++]=l[i+1];
			}
			else
			{
				l[i+1].second++;
				win[wini++]=l[i+1];
				los[losi++]=l[i];
			}
		li=0;winj=0;losj=0;
		while(winj!=wini&&losj!=losi)
			if((win[winj].second==los[losj].second&&win[winj].first<los[losj].first)||
			win[winj].second>los[losj].second)
				l[li++]=win[winj++];
			else
				l[li++]=los[losj++];
		if(wini!=winj)
			while(wini!=winj)
				l[li++]=win[winj++];
		else
			while(losi!=losj)
				l[li++]=los[losj++];
	}
	printf("%d",l[q-1].first);
	// system("pause");
	return 0;
}
// Problem1079:
#include <iostream>
#include <cmath>
using namespace std;

bool p(int x)
{
//	printf("p#%d\n",x);
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)return false;
	}
	return true;
}

int f(int x)
{
//	printf("f#%d\n",x);
	int r=0;
	while(x)
	{
		r+=(x&1);
		x>>=1;
	}
	return r;
}

int main()
{
	int n,k,c=0;
	scanf("%d %d",&n,&k);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int m=pow(2,n),s=0;
	for(int i=0;i<m;i++)
	{
		if(f(i)==k)
		{
			int x=i;
			for(int j=0;j<n;j++)
			{
				s+=(a[j]*(x&1));
				x>>=1;
			}
			if(p(s))
			{
				c++;
			}
			s=0;
		}
	}
	printf("%d",c);
}
// Problem1080:
#include <iostream>
#include <cstdio> 
#include <cstring>
#include <vector>
#include <map>
using namespace std;
int k;
vector<int> n;
map<int,vector<int>> m;
vector<int> ans={1};

bool vis[10];
int dfs(int d)
{
	int r=1;
	if(m.count(d))
	{
		int l=m[d].size();
		for(int i=0;i<l;i++)
		{
			if(!vis[m[d][i]])
			{
				vis[m[d][i]]=true;
				r+=dfs(m[d][i]);

			}
		}
	}
	return r;
}

void multiply(int a)
{
	int lans=ans.size();
	int x=0;
	for(int i=0;i<lans;i++)
	{
		ans[i]=ans[i]*a+x;
		if(i!=lans-1)
		{
			x=(ans[i]/10);
			ans[i]%=10;
		}
		else
		{
			ans.push_back(ans[i]/10);
			ans[i]%=10;
		}
	}
}

int main()
{
	
	char c=getchar();
	while(c!=' ')
	{
	    n.push_back(c-'0');
	    c=getchar();
	}
	scanf("%d",&k);
	int u,v;
	for(int i=0;i<k;i++)
	{
		scanf("%d %d",&u,&v);
		m[u].push_back(v);
	}
	int ln=n.size();
	for(int i=0;i<ln;i++)
	{
		memset(vis,0,sizeof(vis));
		vis[n[i]]=true;
		multiply(dfs(n[i]));
	}
	while(!ans.back())ans.pop_back();
	int lans=ans.size();
	for(int i=lans-1;i>=0;i--)
	{
		printf("%d",ans[i]);
	}
	puts("");

	return 0;
}

// Problem1095:
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int w[n+1],v[n+1],f[m+1];
	memset(w,0,sizeof(w));
	memset(v,0,sizeof(v));
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		int tw,tv;
		scanf("%d %d",&tw,&tv);
		w[i]=tw;v[i]=tw*tv;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			if(j-w[i]>=0)
				f[j]=(f[j]>(v[i]+f[j-w[i]])?f[j]:(v[i]+f[j-w[i]]));
		}
	}
	printf("%d",f[m]);
	return 0;
}
// Problem1102:
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(n%i==0)
		{
			cout<<n/i<<endl;
			return 0;
		}
	}
	return 0;
}
// Problem1109:
#include <iostream>
using namespace std;
int a[200000];
void qsort(int b,int e)
{
	if(b==e)return;
	int i=b+1,j=e;
	while(i<=j)
	{
		if(a[j]<a[b])
			if(a[i]>a[b])
			{
				swap(a[i],a[j]);
				i++,j--;
			}
			else i++;
		else j--;
	}
	swap(a[b],a[j]);
	if(i==e+1)
	{
		qsort(b,e-1);
		return;
	}
	qsort(b,j);
	qsort(i,e);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(0,n-1);
	int last=-1,count=0;
	for(int i=0;i<n;i++)
	{
		if(last!=a[i]){if(i)printf("%d\n",count);printf("%d ",a[i]);count=1;last=a[i];}
		else count++,last=a[i];
	}
	printf("%d",count);
	return 0;
}
// Problem1119:
#include <iostream>
using namespace std;

int main()
{
	int a,b,c;char n;
	scanf("%d-%d-%d-%c",&a,&b,&c,&n);
	int b1,b2,b3;
	b1=b/100;b2=(b%100)/10;b3=b%10;
	int c1,c2,c3,c4,c5;
	c1=c/10000;c2=(c%10000)/1000;c3=(c%1000)/100;c4=(c%100)/10;c5=c%10;
	int tn=0;tn=(a+b1*2+b2*3+b3*4+c1*5+c2*6+c3*7+c4*8+c5*9)%11;
	char cn;
	if(tn>=0&&tn<=9)cn=(char)(tn+48);
	else cn='X';
	if(cn==n)printf("Right");
	else printf("%d-%d-%d-%c",a,b,c,cn);
	return 0;
}
// Problem1124:
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,m;//有m行n列
	scanf("%d",&n);m=n;
	int a[m+2][n+2];
	int dp[m+2][n+2][m+2][n+2];
	memset(a,0,sizeof(a));
	int q,w,e;
	while(1)
	{
        scanf("%d %d %d",&q,&w,&e);
        if(!(q||w||e))break;
	    a[q][w]=e;
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				for(int l=1;l<=n;l++)
				{
					//printf("#%d,%d,%d,%d\n",i,j,k,l);
					dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]));
					if(i==k&&j==l)
					{
						dp[i][j][k][l]+=a[i][j];
					}
					else
					{
						dp[i][j][k][l]+=(a[i][j]+a[k][l]);
					}
				}
			}
		}
	}
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				for(int l=1;l<=n;l++)
				{
					printf("%d,%d,%d,%d:%d ",i,j,k,l,dp[i][j][k][l]);
				}
				puts("");
			}
			puts("");
			puts("");
		}
		puts("");
		puts("");
		puts("");
	}*/
	printf("%d",dp[m][n][m][n]);
	return 0;
}
// Problem1138:
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int n,c=0;
//int que[10001][3];///////////////////////
// int que[100000001][3];
// int head=0,tail=0;
typedef pair<pair<int,int>,int> P;
queue<P> que;
bool vis[1001][1001];
P nul;
int main()
{
	memset(vis,1,sizeof(vis));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int l,i1,j1,i2,j2;
		scanf("%d",&l);
		scanf(" %d %d",&i1,&j1);i1+=2;j1+=2;
		scanf(" %d %d",&i2,&j2);i2+=2;j2+=2;
		if((i1==i2)&&(j1==j2))
			puts("0");
		else
		{
			for(int i=2;i<=l+1;i++)
				for(int j=2;j<=l+1;j++)
					vis[i][j]=0;
			/*head=0;tail=0;*/c=0;//C步数
			que.push(nul);
			que.back().first.first=i1;que.back().first.second=j1;que.back().second=c;//tail++;
	//		tail%=10000;
			vis[i1][j1]=1;
			while(1)
			{
				if(!vis[que.front().first.first-2][que.front().first.second-1])
				{
					vis[que.front().first.first-2][que.front().first.second-1]=1;
					que.push(nul);
					que.back().first.first=que.front().first.first-2;
					que.back().first.second=que.front().first.second-1;
					que.back().second=que.front().second+1;
					// tail++;
	//				tail%=10000;/////////////////////
	
					if((que.back().first.first==i2)&&(que.back().first.second==j2)){printf("%d\n",que.back().second);break;}
				}
				if(!vis[que.front().first.first-2][que.front().first.second+1])
				{
					vis[que.front().first.first-2][que.front().first.second+1]=1;
					que.push(nul);
					que.back().first.first=que.front().first.first-2;
					que.back().first.second=que.front().first.second+1;
					que.back().second=que.front().second+1;
					// tail++;
	//				tail%=10000;//////////////////////////////
		
					if((que.back().first.first==i2)&&(que.back().first.second==j2)){printf("%d\n",que.back().second);break;}
				}
				if(!vis[que.front().first.first-1][que.front().first.second-2])
				{
					vis[que.front().first.first-1][que.front().first.second-2]=1;
					que.push(nul);
					que.back().first.first=que.front().first.first-1;
					que.back().first.second=que.front().first.second-2;
					que.back().second=que.front().second+1;
					// tail++;
	//				tail%=10000;//////////////////////////////////

					if((que.back().first.first==i2)&&(que.back().first.second==j2)){printf("%d\n",que.back().second);break;}
				}
				if(!vis[que.front().first.first-1][que.front().first.second+2])
				{
					vis[que.front().first.first-1][que.front().first.second+2]=1;
					que.push(nul);
					que.back().first.first=que.front().first.first-1;
					que.back().first.second=que.front().first.second+2;
					que.back().second=que.front().second+1;
					// tail++;
	//				tail%=10000;////////////////////////////////////

					if((que.back().first.first==i2)&&(que.back().first.second==j2)){printf("%d\n",que.back().second);break;}
				}
				if(!vis[que.front().first.first+1][que.front().first.second-2])
				{
					vis[que.front().first.first+1][que.front().first.second-2]=1;
					que.push(nul);
					que.back().first.first=que.front().first.first+1;
					que.back().first.second=que.front().first.second-2;
					que.back().second=que.front().second+1;
					// tail++;
	//				tail%=10000;/////////////////////////////////
				// printf("*5 %d %d\n",que.back().first.first-2,que.back().first.second-2);
					if((que.back().first.first==i2)&&(que.back().first.second==j2)){printf("%d\n",que.back().second);break;}
				}
				if(!vis[que.front().first.first+1][que.front().first.second+2])
				{
					vis[que.front().first.first+1][que.front().first.second+2]=1;
					que.push(nul);
					que.back().first.first=que.front().first.first+1;
					que.back().first.second=que.front().first.second+2;
					que.back().second=que.front().second+1;
					// tail++;
	//				tail%=10000;/////////////////////////////////

					if((que.back().first.first==i2)&&(que.back().first.second==j2)){printf("%d\n",que.back().second);break;}
				}
				if(!vis[que.front().first.first+2][que.front().first.second-1])
				{
					vis[que.front().first.first+2][que.front().first.second-1]=1;
					que.push(nul);
					que.back().first.first=que.front().first.first+2;
					que.back().first.second=que.front().first.second-1;
					que.back().second=que.front().second+1;
					// tail++;
		//			tail%=10000;///////////////////////////////////////

					if((que.back().first.first==i2)&&(que.back().first.second==j2)){printf("%d\n",que.back().second);break;}
				}
				if(!vis[que.front().first.first+2][que.front().first.second+1])
				{

					vis[que.front().first.first+2][que.front().first.second+1]=1;
					que.push(nul);
					que.back().first.first=que.front().first.first+2;
					que.back().first.second=que.front().first.second+1;
					que.back().second=que.front().second+1;
					// tail++;
			//		tail%=10000;////////////////////////////////

					if((que.back().first.first==i2)&&(que.back().first.second==j2)){printf("%d\n",que.back().second);break;}
				}
				// head++;
				que.pop();
		//		head%=10000;///////////////////////////////////////////////
				c++;
			}
		}
	}
	// system("pause");
	return 0;
}

// Problem1139:
#include <iostream>
#include <vector>
using namespace std;
#define F1 1
#define F2 -1
#define D1 2
#define D2 -2
#define P12 3
#define P21 -3

typedef pair<vector<int>,pair<int,int>> P;
bool used[101][101];

void print(P t)
{
//	printf("%d;%d\n",t.second.first,t.second.second);
	printf("%d\n",t.first.size());
	for(int i:t.first)
	{
		switch(i)
		{
		case F1:
			puts("FILL(1)");
			break;
		case F2:
			puts("FILL(2)");
			break;
		case D1:
			puts("DROP(1)");
			break;
		case D2:
			puts("DROP(2)");
			break;
		case P12:
			puts("POUR(1,2)");
			break;
		case P21:
			puts("POUR(2,1)");
			break;
		}
	}
	exit(0);
//	return;
}

int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	vector<P> v;
	P tmp;
	tmp.first.clear();
	tmp.second.first=tmp.second.second=0;
	v.push_back(tmp);
	while(!v.empty())
	{
		P t=v.front();
		v.erase(v.begin());
		P tt;
		//F1
		tt=t;
		tt.second.first=a;
		tt.first.push_back(F1);
		if(!used[tt.second.first][tt.second.second])
			v.push_back(tt);
		if(tt.second.first==c||tt.second.second==c)
			print(tt);
		used[tt.second.first][tt.second.second]=1;
		//F2
		tt=t;
		tt.second.second=b;
		tt.first.push_back(F2);
		if(!used[tt.second.first][tt.second.second])
			v.push_back(tt);
		if(tt.second.first==c||tt.second.second==c)
			print(tt);
		used[tt.second.first][tt.second.second]=1;
		//D1
		tt=t;
		tt.second.first=0;
		tt.first.push_back(D1);
		if(!used[tt.second.first][tt.second.second])
			v.push_back(tt);
		if(tt.second.first==c||tt.second.second==c)
			print(tt);
		used[tt.second.first][tt.second.second]=1;
		//D2
		tt=t;
		tt.second.second=0;
		tt.first.push_back(D2);
		if(!used[tt.second.first][tt.second.second])
			v.push_back(tt);
		if(tt.second.first==c||tt.second.second==c)
			print(tt);
		used[tt.second.first][tt.second.second]=1;
		//P12
		tt=t;
		if(b-tt.second.second>tt.second.first)
		{
			tt.second.second+=tt.second.first;
			tt.second.first=0;
		}
		else
		{
			tt.second.first-=(b-tt.second.second);
			tt.second.second=b;
		}
		tt.first.push_back(P12);
		if(!used[tt.second.first][tt.second.second])
			v.push_back(tt);
		if(tt.second.first==c||tt.second.second==c)
			print(tt);
		used[tt.second.first][tt.second.second]=1;
		//P21
		tt=t;
		if(a-tt.second.first>tt.second.second)
		{
			tt.second.first+=tt.second.second;
			tt.second.second=0;
		}
		else
		{
			tt.second.second-=(a-tt.second.first);
			tt.second.first=a;
		}
		tt.first.push_back(P21);
		if(!used[tt.second.first][tt.second.second])
			v.push_back(tt);
		if(tt.second.first==c||tt.second.second==c)
			print(tt);
		used[tt.second.first][tt.second.second]=1;
	}
	puts("impossible");
	return 0;
}

// Problem1143:
#include <iostream>
using namespace std;
int a[1001][1001];
int main()
{
	int r,m=-0x3f3f3f3f;
	scanf("%d",&r);
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=i;j++)
		{
			scanf("%d",&a[i][j]);
			a[i][j]+=max(a[i-1][j-1],a[i-1][j]);
		}
	}
	for(int i=1;i<=r;i++)
		m=max(m,a[r][i]);
	printf("%d",m);
	return 0;
}
// Problem1145:
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int G[101][3];
int w[101];
bool vis[101];
int bfs(int r)
{
	int c=0;
	queue<pair<int,int>> q;
	memset(vis,0,sizeof(vis));
	q.push(make_pair(r,0));
	vis[r]=true;
	while(!q.empty())
	{
		pair<int,int> t=q.front();
		q.pop();
		for(int i=0;i<=2;i++)
		{
			if(G[t.first][i]&&(!vis[G[t.first][i]]))
			{
				q.push(make_pair(G[t.first][i],t.second+1));
				vis[G[t.first][i]]=true;
				c+=(w[G[t.first][i]]*(t.second+1));
			}
		}
	}
	return c;
}
int main()
{
	int n,m=0x3f3f3f3f;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&w[i],&G[i][1],&G[i][2]);
		G[G[i][1]][0]=i;G[G[i][2]][0]=i;
	}	
	for(int i=1;i<=n;i++)
	{
		m=min(m,bfs(i));
	}
	printf("%d",m);
	return 0;
}
/*
9
21 2 3
91 4 5
12 0 0
9 6 0
5 7 0
97 0 0
76 8 0
7 9 0
99 0 0
*/
// Problem1152:
#include <iostream>
#include <string.h>
using namespace std;
int n,m,c=0;
bool vis[101][101];
int que[10000][2];
int head=0,tail=0;

void bfs()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!vis[i][j])
			{
				que[tail][0]=i;que[tail][1]=j;tail++;tail%=n*m;
				vis[que[head][0]][que[head][1]]=1;
				do
				{
					if(!vis[que[head][0]-1][que[head][1]])
					{
						que[tail][0]=que[head][0]-1;
						que[tail][1]=que[head][1];
						tail++;tail%=n*m;
						vis[que[head][0]-1][que[head][1]]=1;
					}
					if(!vis[que[head][0]+1][que[head][1]])
					{
						que[tail][0]=que[head][0]+1;
						que[tail][1]=que[head][1];
						tail++;tail%=n*m;
						vis[que[head][0]+1][que[head][1]]=1;
					}
					if(!vis[que[head][0]][que[head][1]-1])
					{
						que[tail][0]=que[head][0];
						que[tail][1]=que[head][1]-1;
						tail++;tail%=n*m;
						vis[que[head][0]][que[head][1]-1]=1;
					}
					if(!vis[que[head][0]][que[head][1]+1])
					{
						que[tail][0]=que[head][0];
						que[tail][1]=que[head][1]+1;
						tail++;tail%=n*m;
						vis[que[head][0]][que[head][1]+1]=1;
					}
					head++;head%=n*m;
				}
				while(head!=tail);
				c++;
				head=0;tail=0;
			}
	return;
}

int main()
{
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			vis[i][j]=1;
	scanf("%d %d",&n,&m);
	cin.ignore(1024,'\n');
	for(int i=1;i<=n;i++)
	{
		string s;
		getline(cin,s);
		for(int j=1;j<=m;j++)
			if(s[j-1]-48)vis[i][j]=0;
	}
	bfs();
	printf("%d",c);
	return 0;
}
// Problem1164:
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,m;//有m行n列
	scanf("%d %d",&m,&n);
	int a[m+2][n+2];
	int dp[m+2][n+2][m+2][n+2];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				for(int l=1;l<=n;l++)
				{
					//printf("#%d,%d,%d,%d\n",i,j,k,l);
					dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]));
					if(i==k&&j==l)
					{
						dp[i][j][k][l]+=a[i][j];
					}
					else
					{
						dp[i][j][k][l]+=(a[i][j]+a[k][l]);
					}
				}
			}
		}
	}
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				for(int l=1;l<=n;l++)
				{
					printf("%d,%d,%d,%d:%d ",i,j,k,l,dp[i][j][k][l]);
				}
				puts("");
			}
			puts("");
			puts("");
		}
		puts("");
		puts("");
		puts("");
	}*/
	printf("%d",dp[m][n][m][n]);
	return 0;
}
// Problem1202:
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[1]=1;
	int m=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[i]>=a[j])dp[i]=max(dp[j]+1,dp[i]);
			else dp[i]=max(dp[i],1);
		}
		m=max(m,dp[i]);
	}
	printf("%d",m);
	return 0;
}
// Problem1203:
#include <iostream>
#include <string.h>
char a[2000],b[2000];
int dp[2000][2000];
using namespace std;
int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(dp,0,sizeof(dp));
	scanf("%s %s",a,b);
	int la=strlen(a),lb=strlen(b);
	for(int i=1;i<=la;i++)
	{
		for(int j=1;j<=lb;j++)
		{
			if(a[i-1]==b[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	printf("%d",dp[la][lb]);
	return 0;
}
// Problem1233:
#include <iostream>
#include <string.h>
using namespace std;
int n;
int a[14];
bool cu[14][14];
int count=0; 

void book(int i,int j)
{
	cu[i][j]=1;
	for(int c=0;1;c++)
	{
		bool b=1;
		if(i-c>0&&j-c>0)cu[i-c][j-c]=1,b=0;
		if(i-c>0)cu[i-c][j]=1,b=0;
		if(i-c>0&&j+c<=n)cu[i-c][j+c]=1,b=0;
		if(j-c>0)cu[i][j-c]=1,b=0;
		if(j+c<=n)cu[i][j+c]=1,b=0;
		if(i+c<=n&&j-c>0)cu[i+c][j-c]=1,b=0;
		if(i+c<=n)cu[i+c][j]=1,b=0;
		if(i+c<=n&&j+c<=n)cu[i+c][j+c]=1,b=0;
		if(b)break;
	}
}
void dfs(int ln)
{
	if(ln>n)
	{
		count++;
		if(count>3)return;
		printf("%d",a[1]);
		for(int i=2;i<=n;i++)
		{
			printf(" %d",a[i]);
		}
		puts("");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!cu[ln][i])
		{
			bool cucpy[14][14];
			memcpy(cucpy,cu,sizeof(cu));
			book(ln,i);
			a[ln]=i;
			dfs(ln+1);
			a[ln]=0;
			memcpy(cu,cucpy,sizeof(cucpy));
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	printf("%d",count);
	return 0;
}

// Problem1261:
#include <iostream>
using namespace std;
int n;
int m=1;
int a[21];
int sum;
void dfs(int step)
{
	if(sum>n)return;
	if(sum==n)
	{
		printf("%d=%d",n,a[1]);
		for(int i=2;i<=n;i++)
		{
			if(a[i])
				printf("+%d",a[i]);
		}
		puts("");
		return;
	}
	int tm=m;
	for(int i=m;i<=n;i++)
	{
		m=i;
		a[step]=i;
		sum+=i;
		dfs(step+1);
		sum-=i;
		a[step]=0;
		m=tm;
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}

// Problem1267:
#include <iostream>
#include <cstring>
using namespace std;

int n,m,p;
int f[5001];
int father(int a)
{
	if(f[a]!=-1&&f[a]!=a)
	{
		return father(f[a]);
	}
	else
	{
		return a;
	}
}

int main()
{
	scanf("%d %d %d",&n,&m,&p);
	int u,v;
	for(int i=0;i<=n;i++)
	{
		f[i]=-1;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		f[father(u)]=father(v);
	}
	for(int i=0;i<p;i++)
	{
		scanf("%d %d",&u,&v);
		if(father(u)==father(v))
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}
/*
6 5 4
1 2
2 3
2 6
3 6
4 5
1 6
1 5
4 6
5 2
*/
// Problem1274:
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int m=-1;
	int a[100],dp[100];
	int i=0;
	while(scanf("%d",&a[i])!=EOF)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(a[j]>=a[i])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		m=max(m,dp[i]);
		i++;
	}
	printf("%d",m);
	return 0;
}
// Problem1275:
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int main()
{
	int m=-1,mi=-1;
	int a[100],dp[100];
	vector<int> v[100];
	int i=0;
	while(scanf("%d",&a[i])!=EOF)
	{
		dp[i]=1;v[i].push_back(a[i]);
		for(int j=0;j<i;j++)
		{
			if(a[j]>=a[i]&&dp[i]<dp[j]+1)
			{
				dp[i]=dp[j]+1;
				v[i]=v[j];
				v[i].push_back(a[i]);
			}
		}
		// m=max(m,dp[i]);
		if(m<dp[i])
		{
			m=dp[i];
			mi=i;
		}
		i++;
	}
	printf("%d\n",m);
	for(int t:v[mi])
	{
		printf("%d ",t);
	}
	return 0;
}
// Problem1276:
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int main()
{
	int m=-1;
	int a[100],dp[100];
	int i=0;
	vector<int> sys={0x3f3f3f3f};
	while(scanf("%d",&a[i])!=EOF)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(a[j]>=a[i])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		m=max(m,dp[i]);
		auto p=lower_bound(sys.begin(),sys.end(),a[i]);
		if(p!=sys.end())
		{
			*p=a[i];
		}
		else
		{
			sys.push_back(a[i]);
		}
		i++;
	}
	printf("%d\n%d",m,sys.size());
	return 0;
}
// Problem1303:
#include <iostream>
using namespace std;
int main()
{
	int l,r,c=0;
	scanf("%d %d",&l,&r);
	for(int i=l;i<=r;i++)
	{
		if(i%10==2)c++;
		if(i/10%10==2)c++;
		if(i/100%10==2)c++;
		if(i/1000%10==2)c++;
	}
	printf("%d",c);
	return 0;
}
// Problem1304:
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int k=m+1,t=0;
	int a[m+n+1];
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while(k<=m+n)
	{
		for(int i=1;i<=m;i++)
		{
			a[i]--;
			if(a[i]==0)a[i]=a[k],k++;
		}
		t++;
	}
	cout<<t<<endl;
	return 0;
}
// Problem1305:
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

typedef struct dot
{
	int x,y;
	double d;
	friend bool operator < (dot d1,dot d2)
	{
		return d1.d<d2.d;
	}
}dot;

dot a,b;
int n;
priority_queue<dot> qa,qb;

int main()
{
	scanf("%d %d %d %d",&a.x,&a.y,&b.x,&b.y);
	scanf(" %d",&n);
	for(int i=0;i<n;i++)
	{
		dot t;
		scanf("%d %d",&t.x,&t.y);
		t.d=sqrt(pow(t.x-a.x,2)+pow(t.y-a.y,2));
		qa.push(t);
	}
	double mind=pow(qa.top().d,2);
	while(!qa.empty())
	{
		dot t=qa.top();
		qa.pop();
		t.d=sqrt(pow(t.x-b.x,2)+pow(t.y-b.y,2));
		qb.push(t);
		double d=pow(qa.top().d,2)+pow(qb.top().d,2);
		if(d<mind)mind=d;
	}
	cout<<(int)mind<<endl;
	return 0;
}
// Problem1333:
#include <iostream>
#include <cstdio>
#define PI 3.14
using namespace std;
int main()
{
	float r;
	cin>>r;
	printf("%.2lf",r*r*PI);
	return 0;
}
// Problem1334:
#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	cout<<n+m<<endl;
	return 0;
}
// Problem1337:
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cout<<2*n+2<<endl;
	return 0;
}
// Problem1338:
#include <iostream>
using namespace std;
int main()
{
	char a,b,c;
	cin>>a>>b>>c;
	cout<<c<<b<<a<<endl;
	return 0;
}
// Problem1339:
#include <iostream>
using namespace std;

int main()
{
	double a;
	cin>>a;
	cout<<(a<1.5?"FREE":"TICKET")<<endl;
	return 0;
}
// Problem1340:
#include <iostream>
using namespace std;

int main()
{
	double a;
	cin>>a;
	cout<<((a<=30&&a>=25)?"good":"bad")<<endl;
	return 0;
}
// Problem1343:
#include <iostream>
using namespace std;

int main()
{
	double t=0;
	cin>>t;
	if(t>30)
		cout<<"sad"<<flush;
	else if(t<20)
		cout<<"sleeping"<<flush;
	else
		cout<<"happy"<<flush;
	return 0;
}
// Problem1344:
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main()
{
	double speed=0.00;
	int i=0;
	cin>>speed;
	for(;speed>0.05;i+=1)
		speed*=0.6;
	cout<<i+2<<endl;
	return 0;
}

// Problem1347:
#include <iostream>
using namespace std;

int main()
{
	int b=0;
	cin>>b;
	if (b>10)
		cout<<20*b*0.8<<flush;
	else
		cout<<20*b<<flush;
	return 0;
}
// Problem1348:
#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<((b%a==0&&c%a==0)?"yes":"no")<<endl;
	return 0;
}
// Problem1349: #include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a>=b&&a>=c)
		cout<<a<<flush;
	else if(b>=a&&b>=c)
		cout<<b<<flush;
	else if(c>=a&&c>=b)
		cout<<c<<flush;
	return 0;
}
// Problem1350:
#include <iostream>
using namespace std;
int main()
{
	int p4,p5=0,p6=0,m;
	cin>>m;
	p4=m/4;
	switch(m%4)
	{
		case 1:
			p5=1;
			p4-=1;
			break;
		case 2:
			p6=1;
			p4-=1;
			break;
		case 3:
			p5=1;
			p6=1;
			p4-=2;
			break;
	}
	cout<<p6<<" "<<p5<<" "<<p4<<flush;
	return 0;
}
// Problem1351:
#include <iostream>
using namespace std;

int main()
{
	short n=0;
	unsigned long long s=1;
	cin>>n;
	for(int i=1;i<=n;i++)
		s*=i;
	cout<<s<<flush;
	return 0;
}

// Problem1353:
#include <iostream>
using namespace std;

int main()
{
	short n=0,p=0,f=0,t=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(t<=100&&t>=85)
			p+=1;
		if(t<60)
			f+=1;
	}
	cout<<p<<" "<<f<<flush;
	return 0;
}

// Problem1356:
#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	string s="\0";
	int l=0,d=0;
	getline(cin,s);
	for(int i=0;i<s.length();i+=1)
	{
		if(s[i]=='.')
			break;
		if(islower(s[i]))
			l+=1;
		if(isdigit(s[i]))
			d+=1;
	}
	cout<<l<<endl<<d<<endl;
	return 0;
}

// Problem1357:
#include <iostream>
using namespace std;

int main()
{
	int t=0,c=0;
	do
	{
		cin>>t;
		if (t>0)c+=1;
	} while (t!=0);
	cout<<c<<flush;
	return 0;
}

// Problem1359:
#include <iostream>
using namespace std;

int main()
{
	int m,g;
	cin>>m;
	g=m/4;
	g=g+4*g/50;
	cout<<g<<endl;
	return 0;
}
// Problem1370:
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n=0,sum=0,t=0;
	cin>>n;
	for(int i=0;i<n*n;i++)
	{
		cin>>t;
		sum+=t;
	}
	cout<<sum<<flush;
	return 0;
}
// Problem1388:
#include <iostream>
#include <deque>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	deque<int> d;
	bool b[2*n];
	fill(b,b+2*n,false);
	for(int i=0;i<2*n;i++)
	{
		d.push_back(i);
	}
	int j=0;
	for(int i=0;i<n;i++)
	{
		j+=(m-1);
		j%=(2*n-i);
		b[d[j]]=true;
		d.erase(d.begin()+j);
	}
	for(int i=0;i<2*n;i++)
	{
		if(!(i%50)&&i)
			puts("");
		printf("%c",(b[i]?'B':'G'));
	}
	return 0;
}
// Problem1403:
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int t,m;
	scanf("%d %d",&t,&m);
	int v[m+1],w[m+1];
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&w[i],&v[i]);
	}
	int dp[t+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++)
		for(int j=1;j<=t;j++)
		{
			dp[j]=max(dp[j],(j-w[i]>=0?dp[j-w[i]]+v[i]:dp[j]));
		}
	printf("max=%d",dp[t]);
	return 0;
}
// Problem1413:
#include <iostream>
using namespace std;
int main()
{
	int x,r,c=0;
	scanf("%d %d",&r,&x);
	for(int i=1;i<=r;i++)
	{
		if(i>=0)if(i%10==x)c++;
		if(i>=10)if(i/10%10==x)c++;
		if(i>=100)if(i/100%10==x)c++;
		if(i>=1000)if(i/1000%10==x)c++;
		if(i>=10000)if(i/10000%10==x)c++;
		if(i>=100000)if(i/100000%10==x)c++;
		if(i>=1000000)if(i/1000000%10==x)c++;
	}
	printf("%d",c);
	return 0;
}
// Problem1421:
#include <iostream>
using namespace std;
int n;
bool used[10];
int a[10];
void dfs(int step)
{
	if(step>n)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%5d",a[i]);
		}
		puts("");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!used[i])
		{
			used[i]=1;
			a[step]=i;
			dfs(step+1);
			a[step]=0;
			used[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}

// Problem1422:
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	// int dp[n+1];memset(dp,0,sizeof(dp));
	int sum=0,t,m=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		sum=max(t,sum+t);
		m=max(m,sum);
	}
	printf("%d",m<0?0:m);
	return 0;
}
// Problem1423:
#include <iostream>
#include <string.h>
using namespace std;
int n;
int a[11];
bool cu[11][11];
bool no=1;

void book(int i,int j)
{
	cu[i][j]=1;
	for(int c=0;1;c++)
	{
		bool b=1;
		if(i-c>0&&j-c>0)cu[i-c][j-c]=1,b=0;
		if(i-c>0)cu[i-c][j]=1,b=0;
		if(i-c>0&&j+c<=n)cu[i-c][j+c]=1,b=0;
		if(j-c>0)cu[i][j-c]=1,b=0;
		if(j+c<=n)cu[i][j+c]=1,b=0;
		if(i+c<=n&&j-c>0)cu[i+c][j-c]=1,b=0;
		if(i+c<=n)cu[i+c][j]=1,b=0;
		if(i+c<=n&&j+c<=n)cu[i+c][j+c]=1,b=0;
		if(b)break;
	}
}
void dfs(int ln)
{
	if(ln>n)
	{
		no=0;
		for(int i=1;i<=n;i++)
		{
			printf("%5d",a[i]);
		}
		puts("");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!cu[ln][i])
		{
			bool cucpy[11][11];
			memcpy(cucpy,cu,sizeof(cu));
			book(ln,i);
			a[ln]=i;
			dfs(ln+1);
			a[ln]=0;
			memcpy(cu,cucpy,sizeof(cucpy));
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	if(no)printf("no solute!");
	return 0;
}

// Problem1434:
#include <iostream>
#include <string.h>
#include <vector>
#define INF 0x3f3f3f3f
#define NUL 0
#define R 1
#define L 2
#define U 3
#define D 4
using namespace std;
typedef pair<int,pair<int,int>> P;
char a[102][102];
int mt[102][102];
int fd[102][102];
int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	memset(mt,INF,sizeof(mt));
	memset(a,(int)'1',sizeof(a));
	char c;
	vector<P> v;
	for(int i=1;i<=n;i++)
	{
		scanf("\n");
		for(int j=1;j<=m;j++)
		{
			a[i][j]=getchar();
			getchar();
		}
	}
	int x1,y1,x2,y2;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	v.push_back(make_pair(0,make_pair(x1,y1)));
	mt[x1][y1]=0;
	a[x1][y1]='S';
	a[x2][y2]='T';
	do
	{
		P t=v.front();
		v.erase(v.begin());
		if((a[t.second.first-1][t.second.second]=='0'
		||a[t.second.first-1][t.second.second]=='T')
		&&fd[t.second.first][t.second.second]!='D')//up
		{
			fd[t.second.first-1][t.second.second]=U;
			if(fd[t.second.first-1][t.second.second]==NUL)
			{
				mt[t.second.first-1][t.second.second]=0;
				fd[t.second.first-1][t.second.second]=U;
				if(a[t.second.first-1][t.second.second]!='T')
					v.push_back(make_pair(t.first+1,
					make_pair(t.second.first-1,t.second.second)));
			}
			else
			{
				int tmp=mt[t.second.first][t.second.second];
				if(fd[t.second.first][t.second.second]==L
				||fd[t.second.first][t.second.second]==R)
				{
					tmp++;
				}
				if(a[t.second.first-1][t.second.second]!='T'
				&&tmp<mt[t.second.first-1][t.second.second])
				{
					v.push_back(make_pair(t.first+1,
					make_pair(t.second.first-1,t.second.second)));
					mt[t.second.first-1][t.second.second]=tmp;
				}
				if(a[t.second.first-1][t.second.second]=='T'
				&&tmp<mt[t.second.first-1][t.second.second])
				{
					mt[t.second.first-1][t.second.second]=tmp;
				}
			}
		}
		if((a[t.second.first][t.second.second-1]=='0'
		||a[t.second.first][t.second.second-1]=='T')
		&&fd[t.second.first][t.second.second]!='R')//left
		{
			fd[t.second.first][t.second.second-1]=L;
			if(fd[t.second.first][t.second.second-1]==NUL)
			{
				mt[t.second.first][t.second.second-1]=0;
				fd[t.second.first][t.second.second-1]=L;
				if(a[t.second.first][t.second.second-1]!='T')
					v.push_back(make_pair(t.first+1,
					make_pair(t.second.first,t.second.second-1)));
			}
			else
			{
				int tmp=mt[t.second.first][t.second.second];
				if(fd[t.second.first][t.second.second]==U
				||fd[t.second.first][t.second.second]==D)
				{
					tmp++;
				}
				if(a[t.second.first][t.second.second-1]!='T'
				&&tmp<mt[t.second.first][t.second.second-1])
				{
					v.push_back(make_pair(t.first+1,
					make_pair(t.second.first,t.second.second-1)));
					mt[t.second.first][t.second.second-1]=tmp;
				}
				if(a[t.second.first][t.second.second-1]=='T'
				&&tmp<mt[t.second.first][t.second.second-1])
				{
					mt[t.second.first][t.second.second-1]=tmp;
				}

			}
		}
		if((a[t.second.first][t.second.second+1]=='0'
		||a[t.second.first][t.second.second+1]=='T')
		&&fd[t.second.first][t.second.second]!='L')//right
		{
			fd[t.second.first][t.second.second+1]=R;
			if(fd[t.second.first][t.second.second+1]==NUL)
			{
				mt[t.second.first][t.second.second+1]=0;
				fd[t.second.first][t.second.second+1]=R;
				if(a[t.second.first][t.second.second+1]!='T')
					v.push_back(make_pair(t.first+1,
					make_pair(t.second.first,t.second.second+1)));
			}
			else
			{
				int tmp=mt[t.second.first][t.second.second];
				if(fd[t.second.first][t.second.second]==U
				||fd[t.second.first][t.second.second]==D)
				{
					tmp++;
				}
				if(a[t.second.first][t.second.second+1]!='T'
				&&tmp<mt[t.second.first][t.second.second+1])
				{
					v.push_back(make_pair(t.first+1,
					make_pair(t.second.first,t.second.second+1)));
					mt[t.second.first][t.second.second+1]=tmp;
				}
				if(a[t.second.first][t.second.second+1]=='T'
				&&tmp<mt[t.second.first][t.second.second+1])
				{
					mt[t.second.first][t.second.second+1]=tmp;
				}
			}
		}
		if((a[t.second.first+1][t.second.second]=='0'
		||a[t.second.first+1][t.second.second]=='T')
		&&fd[t.second.first][t.second.second]!='U')//down
		{
			fd[t.second.first+1][t.second.second]=D;
			if(fd[t.second.first+1][t.second.second]==NUL)
			{
				mt[t.second.first+1][t.second.second]=0;
				fd[t.second.first+1][t.second.second]=D;
				if(a[t.second.first+1][t.second.second]!='T')
					v.push_back(make_pair(t.first+1,
					make_pair(t.second.first+1,t.second.second)));
			}
			else
			{
				int tmp=mt[t.second.first][t.second.second];
				if(fd[t.second.first][t.second.second]==L
				||fd[t.second.first][t.second.second]==R)
				{
					tmp++;
				}
				if(a[t.second.first+1][t.second.second]!='T'
				&&tmp<mt[t.second.first+1][t.second.second])
				{
					v.push_back(make_pair(t.first+1,
					make_pair(t.second.first+1,t.second.second)));
					mt[t.second.first+1][t.second.second]=tmp;
				}
				if(a[t.second.first+1][t.second.second]=='T'
				&&tmp<mt[t.second.first+1][t.second.second])
				{
					mt[t.second.first+1][t.second.second]=tmp;
				}
			}
		}
	}
	while(!v.empty());
	printf("%d",mt[x2][y2]);
	return 0;
}

// Problem1499:
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n=0,sum=0,c=0;
	double ave;
	cin>>n;
	short p[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		sum+=p[i];
	}
	ave=(double)sum/n;
	for(int i=0;i<n;i++)
	{
		if(p[i]<ave)
			c++;
	}
	cout<<c<<flush;
	return 0;
}
// Problem1502:
#include <iostream>
using namespace std;

int main()
{
	int s=0;
	cin>>s;
	int a[s];
	int i=0;
	for (; i < s; i++)
		cin>>a[i];
	i--;
	for (; i >= 0; i--)
		cout<<a[i]<<" "<<flush;
	return 0;
}
// Problem1506:
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n=0,sum=0,t=0;
	cin>>n;
	for(int i=0;i<n*n;i++)
	{
		cin>>t;
		if(i%(n+1)==0)
			sum+=t;
	}
	cout<<sum<<flush;
	return 0;
}
// Problem1508:
#include <iostream>
using namespace std;


int main()
{
	int sl;
	cin>>sl;
	for(int i=0;i<sl;i++)
	{
		for(int j=0;j<sl;j++)
			cout<<"*"<<flush;
		cout<<endl;
	}
	return 0;
}

// Problem1510:
#include <iostream>
using namespace std;


int main()
{
	int sl;
	cin>>sl;
	sl+=1;
	int i=1,j=sl-1;
	if (!j)
	{
		cout<<"*"<<endl;
		return 0;
	}
	while(j!=0)
	{
		int j1=j;
		while (j1!=1)
		{
			cout<<" "<<flush;
			j1--;
		}
		int i1=i;
		while(i1!=0)
		{
			cout<<"*"<<flush;
			i1--;
		}
		j--;
		i+=2;
		cout<<endl;
	}
	return 0;
}

// Problem1511:
#include <iostream>
using namespace std;
int main()
{
	int n=0,t=0;
	cin>>n;
	for (int i = 1; i<=n; i++)//line
	{
		t=n-i;for (int i = 1; i <= t; i++)cout<<" "<<flush;
		t=2*i-1;for (int i = 1; i <= t; i++)cout<<"*"<<flush;
		cout<<endl;
	}
	for (int i = n-1; i >= 1; i--)
	{
		t=n-i;for (int i = 1; i <= t; i++)cout<<" "<<flush;
		t=2*i-1;for (int i = 1; i <= t; i++)cout<<"*"<<flush;
		cout<<endl;
	}
	return 0;
}
// Problem1513:
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int a[101];
	memset(a,0,101*sizeof(int));
	int t=0;
	while (1)
	{
		cin>>t;
		if (t==0)
			break;
		a[t]+=1;
	}
	for (int i = 1; i<=100; i++)
	{
		if(a[i]!=0)
			cout<<i<<" "<<a[i]<<endl;
	}
	return 0;
}
// Problem1541:
#include <iostream>
using namespace std;

int n;

bool vis[10];
int dis[10];
void dfs(int step)
{
	if(step==n)
	{
		for(int i=0;i<n;i++)
		{
			if(i==n-1)printf("%d",dis[i]);
			else printf("%d ",dis[i]);
		}
		puts("");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			dis[step]=i;
			dfs(step+1);
			vis[i]=false;
		}
	}
}

int main()
{
	scanf("%d",&n);
	dfs(0);
	return 0;
}
// Problem1587:
#include <iostream>
using namespace std;
int main()
{
	int n,a[101],c=0; 
	bool f[20000];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			f[a[i]+a[j]]=1;
	for(int i=1;i<=n;++i)
		if(f[a[i]])
			c++;
	printf("%d",c);
    return 0;
}
// Problem1636:
#include <iostream>
using namespace std;

int main()
{
	unsigned long long n;
	cin>>n;
	unsigned long long a[n];
	a[1]=1;
	a[2]=2;
	for (int i = 3; i <= n; i++)
	{
		a[i]=a[i-2]+a[i-1];
	}
	cout<<a[n]<<flush;
	return 0;
}
// Problem1648:
#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	cout<<m-n<<endl;
	return 0;
}
// Problem1654:
#include <iostream>
using namespace std;

int main()
{
	short n=0;
	unsigned long long s=1,ss=0;
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		s=1;
		for(int ii=1;ii<=i;ii++)
			s*=ii;
		ss+=s;
	}
	cout<<ss<<flush;
	return 0;
}

// Problem1657:
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n,t;
	cin>>n;
	int sum=0,pro=1;
	for(int i=1;i<=n;i++)
	{
		pro=1;
		for(int j=1;j<=i;j++)
		{
			cin>>t;
			pro*=t;
		}
		sum+=pro;
	}
	cout<<sum<<endl;
	return 0;
}

// Problem1660:
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n=0,m=0,sum=0;
	double ave=0;
	cin>>n>>m;
	int a[n+2][m+2];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			sum+=a[i][j];
		}
	ave=(double)sum/(n*m);
	for(int j=1;j<=m;j++)
	{
		a[0][j]=a[n][j];
		a[n+1][j]=a[1][j];
	}
	for(int i=1;i<=n;i++)
	{
		a[i][0]=a[i][m];
		a[i][m+1]=a[i][1];
	}
	bool bn=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]>ave&&a[i][j]>a[i+1][j]&&a[i][j]>a[i][j+1]&&a[i][j]>a[i-1][j]&&a[i][j]>a[i][j-1])
			{
				bn=0;
				cout<<i<<" "<<j<<endl;
			}
	if(bn)
		cout<<"no answer"<<endl;
	return 0;
}

// Problem1673:
#include <iostream>
#include <string>
#include <string.h>

using namespace std;
int main()
{
	string s;
	getline(cin,s);
	for(auto c:s)
	{
		if(islower(c))
			printf("%c",toupper(c));
		else if(isupper(c))
			printf("%c",tolower(c));
		else
			printf("%c",c);
	}
	
	return 0;
}
// Problem1684:
#include <iostream>
using namespace std;
int main()
{
	int k=0;
	cin>>k;
	int gold=0,date=0,i=1;
	for(;date<k;i++)
	{
		gold+=i*i;
		date+=i;
	}
	printf("%d",gold-(date-k)*(i-1));
	return 0;
}
// Problem1685:
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	char a[n+2][m+2];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>a[i][j];
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			int sum=0;
			if(a[i][j]!='*')
			{
				if(a[i][j-1]=='*') sum++;
				if(a[i][j+1]=='*') sum++;
				if(a[i-1][j]=='*') sum++;
				if(a[i+1][j]=='*') sum++;
				if(a[i-1][j-1]=='*') sum++;
				if(a[i-1][j+1]=='*') sum++;
				if(a[i+1][j-1]=='*') sum++;
				if(a[i+1][j+1]=='*')sum++;
			}
			else
			{
				printf("*");
				continue;
			}
			printf("%d",sum);
		}
		puts("");
	}
	return 0;
}
// Problem1712:
#include <iostream>
#include <deque>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	deque<int> d;
	bool b[2*n];
	fill(b,b+2*n,false);
	for(int i=0;i<2*n;i++)
	{
		d.push_back(i);
	}
	int j=0;
	for(int i=0;i<n;i++)
	{
		j+=(m-1);
		j%=(2*n-i);
		b[d[j]]=true;
		d.erase(d.begin()+j);
	}
	for(int i=0;i<2*n;i++)
	{
		if(!(i%50)&&i)
			puts("");
		printf("%c",(b[i]?'B':'G'));
	}
	return 0;
}
// Problem1713:
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int t,m;
	scanf("%d %d",&t,&m);
	int v[m+1],w[m+1];
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&w[i],&v[i]);
	}
	int dp[t+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++)
		for(int j=1;j<=t;j++)
		{
			dp[j]=max(dp[j],(j-w[i]>=0?dp[j-w[i]]+v[i]:dp[j]));
		}
	printf("max=%d",dp[t]);
	return 0;
}
// Problem1721:
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,W;
	scanf("%d",&n);
	int v[n+1],w[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&w[i],&v[i]);
	}
	scanf("%d",&W);
	int dp[n+1][W+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(j-w[i]>=0)
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
			else dp[i][j]=dp[i-1][j];
		}
	}
	printf("%d",dp[n][W]);
	return 0;
}
// Problem1721:
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int t,m;
	scanf("%d",&m);
	int v[m+1],w[m+1];
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&w[i],&v[i]);
	}
	scanf("%d",&t);
	int dp[t+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++)
		for(int j=t;j>=1;j--)
		{
			dp[j]=max(dp[j],(j-w[i]>=0?dp[j-w[i]]+v[i]:dp[j]));
		}
	printf("%d",dp[t]);
	return 0;
}
// Problem1728:
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n,e;

struct node
{
	vector<int> sons;
	bool color;
};

bool bfs(node p[])
{
	queue<int> q;
	q.push(1);
	bool vis[n+1];
	memset(vis,0,sizeof(vis));
	vis[1]=true;
	while(!q.empty())
	{
		int r=q.front();
		q.pop();
		int l=p[r].sons.size();
		for(int i=0;i<l;i++)
		{
			if(!vis[p[r].sons[i]])
			{
				vis[p[r].sons[i]]=true;
				p[p[r].sons[i]].color=!p[r].color;
				q.push(p[r].sons[i]);
			}
			else
			{
				if(p[p[r].sons[i]].color==p[r].color)
				{
// cout<<p[r].sons[i]<<"与"<<r<<"水火不容"<<endl;
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	scanf("%d %d",&n,&e);
	node p[n+1];
	int u,v;
	for(int i=1;i<=e;i++)
	{
		scanf("%d %d",&u,&v);
		p[u].sons.push_back(v);
		p[v].sons.push_back(u);
	}
	puts(bfs(p)?"YES":"NO");
	return 0;
}
// Problem1729:
#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int in=0,out=0;
	vector<int> to;
	bool null=false;
};

int main()
{
	int n;
	scanf("%d",&n);
	node p[n+1];
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		// scanf("%d %d",&a,&b);
		p[a].to.push_back(b);
		p[a].out++;
		p[b].in++;
	}
	vector<int> s,ans;
	for(int i=1;i<=n;i++)
	{
		p[i].null=false;
		if(p[i].in==0)
		{
			s.push_back(i);
			p[i].null=true;
		}
	}
	while(!s.empty())
	{
		int f=s.front();
		ans.push_back(f);
		for(int t:p[f].to)
		{
			p[t].in--;
			if(p[t].in==0&&!p[t].null)
			{
				s.push_back(t);
				p[t].null=true;
			}
		}
		s.erase(s.begin());
	}
	if(ans.size()==n)
	{
		for(int t:ans)
		{
			printf("%d ",t);
		}
	}
	else
	{
		puts("-1");
		/* for(int t:ans)
		{
			printf("%d ",t);
		}
		puts("---");
		for(int t:s)
		{
			printf("%d ",t);
		} */
	}
	return 0;
}
// Problem1767:
#include <iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<(a>b?b-a+12:b-a)<<flush;
	return 0;
}
// Problem1793:
#include <iostream>
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<"a="<<(a<b?a:b)<<" b="<<(a<b?b:a)<<endl;
	return 0;
}
// Problem1793:
#include <iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<"a="<<(a>b?b:a)<<" b="<<(a>b?a:b)<<flush;
	return 0;
}
// Problem1794:
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double ave=0.00,sum=0.00;
	short t=0,i=0,b=-1001,s=1001;
	while (cin>>t)
	{
		if(t>b)b=t;
		if(t<s)s=t;
		sum+=t;
		i+=1;
	}
	ave=sum/i;
	cout<<s<<endl<<b<<endl<<fixed<<setprecision(3)<<ave<<endl;
	return 0;
}

// Problem1794:
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main()
{
	double ave=0.00,sum=0.00;
	short t=0,i=0,b=-1001,s=1001;
	while (cin>>t)
	{
		if(t>b)b=t;
		if(t<s)s=t;
		sum+=t;
		i+=1;
	}
	ave=sum/i;
	cout<<s<<endl<<b<<endl<<fixed<<setprecision(3)<<ave<<endl;
	return 0;
}

// Problem1802:
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n=0;
	cin>>n;
	bool book[n];
	short p[n];
	memset(book,0,sizeof(book));
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	for(int i=0;i<n;i++)
	{
		if(i==0)
			if(p[0]<p[1])
			{
				book[1]=1;
				continue;
			}
		if(i==n-1)
			if(p[n-1]<p[n-2])
			{
				book[n-2]=1;
				continue;
			}
		if(p[i]<p[i-1])
			book[i-1]=1;
		if(p[i]<p[i+1])
			book[i+1]=1;
	}
	short c=0;
	for (int i=0;i<n;i++)
	{
		if(book[i]==1)
			c++;
	}
	short max=0,maxc=0;
	for (int i=0;i<n;i++)
	{
		if (p[i]==max)
		{
			maxc++;
		}
		else if (p[i]>max)
		{
			maxc=1;
			max=p[i];
		}
	}
	cout<<c<<" "<<maxc<<flush;
	return 0;
}
// Problem1927:
#include <iostream>
using namespace std;
int main()
{
	string a,b;
	cin>>a;
	while(cin>>b)
	{
		if(a.find(b)!=string::npos)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
// Problem1992:
#include <iostream>
#include <map>
using namespace std;
typedef pair<int,int> P;
int main()
{
	map<int,P> m;
	int n,q;
	scanf("%d %d",&n,&q);
	int last=-1;
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==last)
		{
			m[t].second=i;
		}
		else
		{
			m[t].first=m[t].second=i;
		}
		last=t;
	}
	for(int i=0;i<q;i++)
	{
		int t;
		scanf("%d",&t);
		if(!m.count(t))
			printf("No Solution.\n");
		else
			printf("%d %d\n",m[t].first,m[t].second);
	}
	return 0;
}
// Problem1992:
#include <iostream>
using namespace std;
int w[200001][3];
int search(int l,int r,int a)
{
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(w[mid][0]==a)return mid;
		if(w[mid][0]>a)r=mid-1;
		else l=mid+1;
	}
	return -1;
}

int main()
{
	int n,q;
	int k=1,v;
	w[0][0]=-1;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&v);//scanf("%d",w[i]);
		if(v!=w[k-1][0]){w[k][0]=v;w[k][1]=i;w[k][2]=i;k++;}
		else{w[k-1][2]=i;}
	}
	k--;
	int a;
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&a);
		if(w[k][0]<a||w[1][0]>a)
		{
			printf("No Solution.\n");
			continue;
		}
		int index=search(1,k,a);
		if(index==-1)
		{
			printf("No Solution.\n");
			continue;
		}
		 printf("%d %d\n",w[index][1],w[index][2]);
	}
	return 0;
}
// Problem1992:
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int w[200001][3];
struct node
{
	int x,y,z;
}a[200001];

int search(int l,int r,int a)
{
	int mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(w[mid][0]==a)return mid;
		if(w[mid][0]>a)r=mid-1;
		else l=mid+1;
	}
	return 0;
}

bool cmp1(node p,node q)
{
	return p.x<q.x;
}
bool cmp2(node p,node q)
{
	return p.y<q.y;
}


int main()
{
	int n,q;
	int k=1,v;
	w[0][0]=-1;
	a[0].x=-1;a[0].y=0;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&v);
		if(v!=w[k-1][0]){w[k][0]=v;w[k][1]=i;w[k][2]=i;k++;}
		else{w[k-1][2]=i;}
	}
	k--;
	
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&a[i].x);
		a[i].y=i;
	}

	sort(a,a+q,cmp1);
	
	for(int i=1;i<=q;i++)
	{
		if(w[k][0]<a[i].x||w[1][0]>a[i].x)a[i].z=0;
		if(a[i].x==a[i-1].x)a[i].z=a[i-1].z;
		else
		{
			//a[i].z=search(a[i-1].z+1,k,a[i].x);
			a[i].z=search(1,k,a[i].x);
		}
	}
	sort(a,a+q,cmp2);
	for(int i=1;i<=q;i++)
	{
		if(a[i].z==0)printf("No Solution.\n");
		else printf("%d %d\n",w[a[i].z][1],w[a[i].z][2]);
	}
	return 0;
}
// Problem2161:
#include <iostream>
using namespace std;int main(){int a=0,b=0,c=0;cin>>a>>b>>c;cout<<0.2*a+0.3*b+0.5*c;return 0;}
// Problem2324:
#include <iostream>
using namespace std;

constexpr int N=1145;

int dp[N][N],v[N];
int n,m,o;

int main()
{
	scanf("%d %d %d",&n,&m,&o);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",v+i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=min(i,o);j;j--)
		{
			for(int k=v[i];k<=m;k++)
			{
				dp[j][k]=max(dp[j][k],dp[j-1][k-v[i]]+v[i]);
			}
		}
	}
	int ans=0;
	for(int oo=1;oo<=o;oo++)
	{
		ans=max(ans,dp[oo][m]);
	}
	printf("%d",ans);
	return 0;
}
// Problem2327:
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int c=0;
	string s;
	getline(cin,s);
	for(int i=0;i<s.length();i++)
		if(s[i]!=' ')
			c++;
	cout<<c;
	return 0;
}
// Problem2336:
#include <iostream>
using namespace std;

int main()
{
	int a=0,b=0,c=0,d=0;
	cin>>a>>b>>c>>d;
	cout<<(a*10+b)/(c*10+d)<<flush;
	return 0;
}
// Problem2339:
#include <iostream>
using namespace std;

int main()
{
	short n=0,i=2,c=1;
	cin>>n;
	for(;i<n;i*=2)
		c++;
	cout<<c<<flush;
	return 0;
}
// Problem2340:
#include <iostream>
using namespace std;

int main()
{
	short n=0;
	unsigned long long s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		if(i%7==0||i%10==7||i/10==7);else
			s+=i*i;
	cout<<s<<flush;
	return 0;
}
// Problem2342:
#include <iostream>
using namespace std;

int main()
{
	int a=0,b=0;
	cin>>a>>b;
	cout<<(a/b+1)*2<<flush;
	return 0;
}
// Problem2344:
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	short n=0,a=1;
	double s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		s+=(double)a/i;
		a*=-1;
	}
	cout<<fixed<<setprecision(4)<<s<<flush;
	return 0;
}
// Problem2350:
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	for(auto c:s)
	{
		if(s.find_first_of(c)==s.find_last_of(c))
		{
			printf("%c",c);
			return 0;
		}
	}
	printf("no");
	return 0;
}
// Problem2361:
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int d,n,m,jj;
	scanf("%d %d %d",&d,&n,&m);
	int w[d+1][n+1];
	for(int i=1;i<=d;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&w[i][j]);
		}
	}
	jj=m;
	int j;
	for(int dd=1;dd<=d-1;dd++){
		 int f[jj+1];
		 for(int jjj=0;jjj<=jj;jjj++)f[jjj]=0;
		//f[0]=0;
		for(int i=1;i<=n;i++){
			for(j=w[dd][i];j<=jj;j++){
				if(f[j]<f[j-w[dd][i]]+(w[dd+1][i]-w[dd][i]))
				{f[j]=f[j-w[dd][i]]+(w[dd+1][i]-w[dd][i]);
			//printf("--%d/%d--%d ",i,j,f[j]);}
				}
			}
		//printf("\n");
		}
		//j--;//-------------------
		//printf("---jj=%d f[j]=%d\n",jj,f[j]);
		jj=jj+f[jj];
		
		//printf("---jj=%d\n",jj);
	}
	printf("%d",jj);
return 0;
}
// Problem2362:
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	string s;
	char t;
	int c=0;
	cin>>s;
	for(int i=0;!s.empty();i++)
	{
		sscanf(s.c_str(),"%c",&t);
		if(t=='1')
			c++;
		s.erase(s.begin());
	}
	printf("%d",c);
	return 0;
}

// Problem2363:
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int link[100001][2];//conection u--v
int l[100001][2];//st u--l
int que[1000001];//queue u or v
int dist[100001][2];//the most shortest distance
int wkidx=-1,step=1,head,tail,tailtmp,lon;
int n,m,q,k=1;//n:worker number,m:connect number ,q:list number
vector<int> a[100001];

int main()
{
	memset(dist,-1,sizeof(dist));
	scanf("%d %d %d",&n,&m,&q);
	//100000
	for(int i=1;i<=m;i++)// connections
	{
		int u,v;
		scanf("%d %d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
		/* link[i][0]=u;
		link[i][1]=v; [worker u] 's[connection index]is v */
	}
	//100000
	for(int i=1;i<=q;i++)// work list
	{
		int w,y;
		scanf("%d %d",&w,&y);
		l[i][0]=w;
		l[i][1]=y;
	}
	que[1]=1;dist[1][0]=2;
	head=1;
	tail=2;
	do
	{
		int len=tail-head;
		for(int i=1;i<=len;i++)
		{
			for(int j=0;j<a[que[head]].size();j++)
			{
				if(dist[a[que[head]][j]][step%2]==-1)
				{
					dist[a[que[head]][j]][step%2]=step;
					// if(dist[que[head]][!(step%2)]!=-1)
					// 	dist[que[head]][!(step%2)]=step+1;
					que[tail]=a[que[head]][j];
					tail++;
				}
			//	else if(dist[a[que[head]][j]][0]==-1||dist[a[que[head]][j]][1]==-1)
				//	que[tail]=a[que[head]][j],tail++;
			}
			
			head++;
		}
		step++;
	}
	while (head!=tail);
	for(int i=1;i<=q;i++)
	{
		if((l[i][1]%2==0)&&(dist[l[i][0]][0]!=-1)&&(l[i][1]>=dist[l[i][0]][0]))
		{
			printf("Yes\n");
		}
		else if((l[i][1]%2!=0)&&(dist[l[i][0]][1]!=-1)&&(l[i][1]>=dist[l[i][0]][1]))
		{
			printf("Yes\n");
		}
		else printf("No\n");
	}

	return 0;
}
// Problem2363:
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int link[100001][2];//conection u--v
int l[100001][2];//st u--l
int que[1000001];//queue u or v
int dist[100001][2];//the most shortest distance
int wkidx=-1,step=1,head,tail,tailtmp,lon;
int n,m,q,k=1;//n:worker number,m:connect number ,q:list number
vector<int> a[100001];

int main()
{
	//freopen("P5663_18.in","r",stdin);
	//freopen("out.txt","w",stdout);
	memset(dist,-1,sizeof(dist));
	scanf("%d %d %d",&n,&m,&q);
	//100000
	for(int i=1;i<=m;i++)// connections
	{
		int u,v;
		scanf("%d %d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
		/* link[i][0]=u;
		link[i][1]=v; [worker u] 's[connection index]is v */
	}
	//100000
	for(int i=1;i<=q;i++)// work list
	{
		int w,y;
		scanf("%d %d",&w,&y);
		l[i][0]=w;
		l[i][1]=y;
	}
	que[1]=1;dist[1][0]=2;
	head=1;
	tail=2;
	do
	{
		int len=tail-head;
		for(int i=1;i<=len;i++)
		{
			for(int j=0;j<a[que[head]].size();j++)
			{
				// if(a[que[head]][j]==41840){freopen("CON","r",stdin);freopen("CON","w",stdout);system("pause");freopen("P5663_18.in","r",stdin);freopen("out.txt","w",stdout);}
				if(dist[a[que[head]][j]][step%2]==-1)
				{
					dist[a[que[head]][j]][step%2]=step;
					// if(dist[que[head]][!(step%2)]!=-1)
					// 	dist[que[head]][!(step%2)]=step+1;
					que[tail]=a[que[head]][j];
					tail++;
				}
			
			}
			
			head++;
		}
		step++;
	}
	while (head!=tail);
	for(int i=1;i<=q;i++)
	{
		if((l[i][1]%2==0)&&(dist[l[i][0]][0]!=-1)&&(l[i][1]>=dist[l[i][0]][0]))
		{
			printf("Yes\n");
		}
		else if((l[i][1]%2!=0)&&(dist[l[i][0]][1]!=-1)&&(l[i][1]>=dist[l[i][0]][1]))
		{
			printf("Yes\n");
		}
		else printf("No\n");
	}

	return 0;
}
// Problem2363:
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> e[114514];
int diso[114514],dise[114514];

void bfs()
{
	queue<int> q;
	q.push(1);
	int len,u,dep=0;
	while(!q.empty())
	{
		dep++;
		len=q.size();
		for(int i=0;i<len;i++)
		{
			u=q.front();
			q.pop();
			for(int v:e[u])
			{
				if((dep&1)&&!diso[v])// odd
				{
					diso[v]=dep;
					q.push(v);
				}
				else if(!(dep&1)&&!dise[v])// even
				{
					dise[v]=dep;
					q.push(v);
				}
			}
		}
	}
}

int main()
{
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	bfs();
	for(int i=0;i<q;i++)
	{
		scanf("%d %d",&u,&v);
		if(v&1)
		{
			if(!diso[u]||diso[u]>v)
			{
				puts("No");
			}
			else
			{
				puts("Yes");
			}
		}
		else
		{
			if(!dise[u]||dise[u]>v)
			{
				puts("No");
			}
			else
			{
				puts("Yes");
			}
		}
	}
	return 0;
}
// Problem2366:
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	string s;
	string a[100];int at=0;
	cin>>s;
	bool bd=0;
	for(auto c:s)
	{
		if(isdigit(c))
		{
			if(bd)
			{
				a[at].push_back(c);
			}
			else
			{
				a[++at].push_back(c);
			}
			bd=1;
		}
		else bd=0;
	}
	int sum=0;
	for(int i=1;i<=at;i++)
		sum+=atof(a[i].c_str());
	printf("%d",sum);
	return 0;
}
// Problem2406:
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	bool g[51];
	memset(g,0,sizeof(g));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=50;j+=i)
			g[j]=!g[j];
	int c=0;
	for(int i=1;i<=50;i++)
		if(g[i])
			c++;
	printf("%d",c);
	return 0;
}
// Problem2439:
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
typedef pair<int,pair<int,int>> P;
int main()
{
	int n,m;
	scanf("%d",&n);m=n;
	char a[1002][1002];
	memset(a,1,sizeof(a));
	char c;
	vector<P> v;
	for(int i=1;i<=n;i++)
	{
		scanf("\n");//输入字符数组时，注意'\n'会留在缓冲区 
		for(int j=1;j<=m;j++)
		{
			scanf("%c",&a[i][j]);
			// if(a[i][j]=='S')
			// {
			// 	a[i][j]='1';
			// 	v.push_back(make_pair(0,make_pair(i,j)));
			// }
		}
	}
	int x1,y1,x2,y2;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	v.push_back(make_pair(0,make_pair(x1,y1)));
	a[x1][y1]='1';
	a[x2][y2]='T';
	do
	{
		P t=v.front();
		v.erase(v.begin());
		if(a[t.second.first-1][t.second.second]=='T')
		{
			printf("%d",t.first+1);
			return 0;
		}
		if(a[t.second.first-1][t.second.second]=='0')
		{
			a[t.second.first-1][t.second.second]='1';
			v.push_back(make_pair(t.first+1,make_pair(t.second.first-1,t.second.second)));
		}
		if(a[t.second.first][t.second.second-1]=='T')
		{
			printf("%d",t.first+1);
			return 0;
		}
		if(a[t.second.first][t.second.second-1]=='0')
		{
			a[t.second.first][t.second.second-1]='1';
			v.push_back(make_pair(t.first+1,make_pair(t.second.first,t.second.second-1)));
		}
		if(a[t.second.first][t.second.second+1]=='T')
		{
			printf("%d",t.first+1);
			return 0;
		}
		if(a[t.second.first][t.second.second+1]=='0')
		{
			a[t.second.first][t.second.second+1]='1';
			v.push_back(make_pair(t.first+1,make_pair(t.second.first,t.second.second+1)));
		}
		if(a[t.second.first+1][t.second.second]=='T')
		{
			printf("%d",t.first+1);
			return 0;
		}
		if(a[t.second.first+1][t.second.second]=='0')
		{
			a[t.second.first+1][t.second.second]='1';
			v.push_back(make_pair(t.first+1,make_pair(t.second.first+1,t.second.second)));
		}
	}
	while(!v.empty());
	return 0;
}
// Problem2461:
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	int n=0,p[601];
	memset(p,0,sizeof(p));
	short w=0;
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		int t=0,sum=0;
		scanf("%d",&t);
		p[t]++;
		int j=600;
		for(;sum<(1>=(int)floor(i*w/100)?1:(int)floor(i*w/100));j--)
			sum+=p[j];
		j++;
		if(i!=1)
			printf(" ");
		printf("%d",j);
	}
	return 0;
}
// Problem2494:
#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	cout<<60*n+m<<endl;
	return 0;
}
// Problem2497:
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	while(!s.empty())
	{
		char cs[200];
		sscanf(s.c_str(),"%s",cs);
		printf("%s ",cs);
		while(s.front()!=' '&&!s.empty())
			s.erase(s.begin());
		while(s.front()==' '&&!s.empty())
			s.erase(s.begin());
	}
	puts("");
	return 0;
}
// Problem2499:
#include <iostream>
#include <string.h>
using namespace std;
int n;
bool used[13];
int a[13];

bool prime_num(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)return 0;
	}
	return 1;
}

void dfs(int step)
{
	if(step>n)
	{
		if(!prime_num(a[1]+a[n]))
			return;
		printf("%d",a[1]);
		for(int i=2;i<=n;i++)
		{
			printf(" %d",a[i]);
		}
		puts("");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(prime_num(a[step-1]+i)&&!used[i])
		{
			used[i]=1;
			a[step]=i;
			dfs(step+1);
			a[step]=0;
			used[i]=0;
		}
	}
}
int main()
{
	int c=1;
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		memset(used,0,sizeof(used));
		a[1]=1;
		used[1]=1;
		printf("Case %d:\n",c);
		dfs(2);
		puts("");
		c++;
	}
	return 0;
}

// Problem2514:
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	int c=0,n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(c<=a[i])c++;
	}
	printf("%d",c);
	return 0;
}
// Problem2532:
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int fvv;
	string s;
	cin>>fvv>>s;
	// cin>>s;
	reverse(s.begin(),s.end());
	long long ans=0;
	for(char c:s)
	{
		if(ans>(long long)1e18)
		{
			puts("-1");
			return 0;
		}
		ans+=(c=='B'?1:0);
		ans<<=1;
	}
	printf("%lld",ans>>1);
	return 0;
}
// Problem2536:
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef pair<bool,int> P;
int n;
bool a[100001];//初值 
int c=0;
//map<int,int> bcj;
int bcj[1000000];

int main()
{
	char tc;
	vector<int> vi;
	do
	{
		tc=getchar();
		if(tc=='x')
		{
			int x;
			scanf("%d",&x);
			vi.push_back(x);
		}
		else if(tc=='|')
		{
			vi.push_back(-1);
		}
		else if(tc=='&')
		{
			vi.push_back(-2);
		}
		else
		{
			vi.push_back(-3);
		}
	}
	while(getchar()==' ');
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	vector<P> v;
	for(int ii=0;ii<vi.size();ii++)
	{
		int i=vi[ii];
		if(i<0)
		{
			if(i==-3)
			{
				P tmp=v.back();
				v.pop_back();
				tmp.first=!tmp.first;
				bcj[tmp.second]=ii;
				tmp.second=ii;
				v.push_back(tmp);
			}
			else
			{
				P tmp1,tmp2;//取出两个 
				tmp1=v.back();
				v.pop_back();
				tmp2=v.back();
				v.pop_back();
				P push;//暂存运算
				if(i==-1)
				{
					push.first=tmp1.first||tmp2.first;
					if(!tmp1.first)
					{
						bcj[tmp2.second]=ii;
					}
					if(!tmp2.first)
					{
						bcj[tmp1.second]=ii;
					}
				}
				if(i==-2)
				{
					push.first=tmp1.first&&tmp2.first;
					if(tmp1.first)
					{
						bcj[tmp2.second]=ii;
					}
					if(tmp2.first)
					{
						bcj[tmp1.second]=ii;
					}
				}
				push.second=ii;
				v.push_back(push);
			}
		}
		else
		{
			P tmp;
			tmp.first=a[i];
			tmp.second=i+500000;
			v.push_back(tmp);
		}
	}
	bool ans=v.back().first;
	int ask;
	scanf("%d",&ask);
	int t;
	for(int i=1;i<=ask;i++)
	{
		scanf("%d",&t);
		int k=0;
		for(int f=t+500000;f;f=bcj[f])
			k=f;
		if(k==vi.size()-1)printf("%d\n",(int)(!ans));
		else printf("%d\n",(int)ans);
	}
	return 0;
}
// Problem2537:
#include <stdio.h>
using namespace std;

int main()
{
	unsigned long long n,l,r;
	scanf("%llu %llu %llu",&n,&l,&r);
	unsigned long long k=l+((n-1)-l%n);
	if(k>=r)
		printf("%llu",r%n);
	else
		printf("%llu",n-1);
	return 0;
}
// Problem2538:
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct value
{
	int val;
	int index;
};

bool cmp(value x,value y)
{
	return x.val<y.val||(x.val==y.val&&x.index<y.index);
}

int main()
{
	int n=0,q=0;
	cin>>n>>q;
	value a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].val);
		a[i].index=i;
	}
	int m[n+1];
	stable_sort(a+1,a+n+1,cmp);
	for(int j=1;j<=n;j++)
		m[a[j].index]=j;
	for(int c=0;c<q;c++)
	{
		int op=0;
		scanf("%d",&op);
		if(op==1)
		{
			int x=0,v=0;
			scanf("%d %d",&x,&v);
				if(a[m[x]].val>v)
				{
					a[m[x]].val=v;
					for(int j=m[x];j>=2;j--)
						if(a[j].val<a[j-1].val||(a[j].val==a[j-1].val&&a[j].index<a[j-1].index))
							{swap(a[j],a[j-1]);m[a[j].index]++;m[a[j-1].index]--;}
						else break;
				}
				if(a[m[x]].val<v)
				{
					a[m[x]].val=v;
					for(int j=m[x];j<=n-1;j++)
						if(a[j].val>a[j+1].val||(a[j].val==a[j+1].val&&a[j].index>a[j+1].index))
							{swap(a[j],a[j+1]);m[a[j].index]--;m[a[j+1].index]++;}
						else break;
				}
			//for(int j=1;j<=n;j++)
			//	m[a[j].index]=j;
		}
		if(op==2)
		{
			int x=0;
			scanf("%d",&x);
			printf("%d\n",m[x]);
		}
	}
	return 0;
}
// Problem2539:
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <map>
using namespace std;

map<string,int>ip;

bool check(string ad)
{
	int a=0,b=0,c=0,d=0,e=0;
	char t1=0,t2=0,t3=0,t4=0;
	sscanf(ad.c_str(),"%d%c%d%c%d%c%d%c%d",&a,&t1,&b,&t2,&c,&t3,&d,&t4,&e);
	if(a<0||a>255||b<0||b>255||c<0||c>255||d<0||d>255||e<0||e>65535)return 0;
	if(t1!='.'||t2!='.'||t3!='.'||t4!=':')return 0;
	stringstream ss;
	ss<<a<<'.'<<b<<'.'<<c<<'.'<<d<<':'<<e;
	if(ss.str()!=ad)return 0;
	return 1;
}

int main()
{
	int n=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		string op,ad;
		cin>>op>>ad;
		if(!check(ad))
			printf("ERR\n");
		else
		{
			if(op[0]=='S')
			{
				if(ip[ad]==0)
				{
					ip[ad]=i;
					printf("OK\n");
				}
				else
					printf("FAIL\n");
			}
			else
			{
				if(ip[ad]!=0)
					printf("%d\n",ip[ad]);
				else
					printf("FAIL\n");
			}
		}
	}
	//system("pause>nul");
	return 0;
}
// Problem2539:
#include <iostream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

string g;
string get()
{
	cin>>g;
	int a,b,c,d,e;
	char d1,d2,d3,c4;
	sscanf(g.c_str(),"%d%c%d%c%d%c%d%c%d",&a,&d1,&b,&d2,&c,&d3,&d,&c4,&e);
	if(d1!='.'||d2!='.'||d3!='.'||c4!=':'||
	a<0||b<0||c<0||d<0||e<0||a>255||b>255||c>255||d>255||e>65535)
	{
		return "x";
	}
	stringstream ss;
	ss<<a<<'.'<<b<<'.'<<c<<'.'<<d<<':'<<e;
	string t=ss.str();
	if(t!=g)
	{
		return "x";
	}
	return t;
}

map<string,int> m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	string type,ip;
	for(int i=1;i<=n;i++)
	{
		cin>>type;
		ip=get();
		if(ip=="x")
		{
			cout<<"ERR"<<"\n";
			continue;
		}
		if(type[0]=='S')
		{
			if(m[ip])
			{
				cout<<"FAIL"<<"\n";
			}
			else
			{
				m[ip]=i;
				cout<<"OK"<<"\n";
			}
		}
		else
		{
			if(m[ip])
			{
				cout<<m[ip]<<"\n";
			}
			else
			{
				cout<<"FAIL"<<"\n";
			}
		}
	}
	return 0;
}
// Problem2541:
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
	int n=0,m=0;
	scanf("%d %d",&n,&m);

	long long int board[n+2][m+1];
	long long int sum[n+2][2];
	long long int sum1[n+2][2];//从本点向上和向右方向中的最大值
	long long int sum2[n+2][2];//从本点向下方向的最大值
	long long int ms=-10000000000000000;


	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&board[i][j]);
		}

	for(int j=0;j<=1;j++)
		for(int i=0;i<=n+1;i++)
		{
		sum[i][j]=ms;
		sum1[i][j]=ms;
		sum2[i][j]=ms;
		}
	sum[n][1]=board[n][m];

	for(int i=n-1;i>=1;i--)//赋值第j列
	{
		sum[i][1]=sum[i+1][1]+board[i][m];
	}
	for(int j=1;j<=m;j++)//赋值
	{
		board[0][j]=ms;
		board[n+1][j]=ms;
	}

	for(int j=m-1;j>=1;j--)//开始循环
	{
//cout<<"----"<<j<<endl;	
		for(int i=1;i<=n;i++)//先算本点向上和 右方向的大值
		{
			if (sum1[i-1][0]>=sum[i][1])
			{
				sum1[i][0]=board[i][j]+sum1[i-1][0];
			}
			else sum1[i][0]=board[i][j]+sum[i][1];

// cout<<sum1[i][0]<<endl;
		}	
// cout<<endl;
		for(int i=n;i>=1;i--)//本点向下方向的大值
		{
			if (sum2[i+1][0]>=sum[i+1][1]+board[i+1][j])
			{
				sum2[i][0]=board[i][j]+sum2[i+1][0];
			}
			else sum2[i][0]=board[i][j]+board[i+1][j]+sum[i+1][1];

//cout<<sum2[i][0]<<endl;

		}	
//cout<<endl;
		for(int i=1;i<=n;i++)
		{
			if (sum1[i][0]<=sum2[i][0])sum[i][0]=sum2[i][0];
			else sum[i][0]=sum1[i][0];
//cout<<sum[i][0]<<endl;

		}	
//cout<<endl;

		for(int i=1;i<=n;i++)
		{
		sum[i][1]=sum[i][0];
		}

//cout<<j<<"----"<<endl;		
	}

	printf("%lld",sum[1][0]);
	return 0;
}
// Problem2541:
#include <iostream>
using namespace std;

typedef long long ll;

ll a[1145][1145],dp[1145][1145],fu[1145][1145],fd[1145][1145];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	fill(*dp,*dp+(1145*1145),-0x3f3f3f3f3f3f3f3fll);
	fill(*fu,*fu+(1145*1145),-0x3f3f3f3f3f3f3f3fll);
	fill(*fd,*fd+(1145*1145),-0x3f3f3f3f3f3f3f3fll);
	dp[1][0]=fu[1][0]=fd[1][0]=0ll;
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			fu[i][j]=max(fu[i-1][j],dp[i][j-1])+a[i][j];
		}
		for(int i=n;i>0;i--)
		{
			fd[i][j]=max(fd[i+1][j],dp[i][j-1])+a[i][j];
			dp[i][j]=max(fu[i][j],fd[i][j]);
		}
	}
	printf("%lld",dp[n][m]);
	return 0;
}
// Problem2544:
#include <iostream>
using namespace std;
int main()
{
	int n=0;
	scanf("%d",&n);
	if(n%2==1){printf("-1");return 0;}
	int i=0,x=1;
	while(x<=n)x*=2;
	x/=2;
	while(n!=0)
	{
		if(n<x){x/=2;continue;}
		n-=x;
		printf("%d ",x);
		x/=2;
	}
	return 0;
}
// Problem2548:
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	cin>>s;
	int sc=0,val=0,len=s.length(),ansor=0,ansand=0;
	#define c s[i]
	for(int i=0;i<len;i++)
	{
		if(sc)
		{
			if(c=='(')
			{
				int k=1;
				while(k)
				{
					i++;
					if(c=='(')
					{
						k++;
					}
					else if(c==')')
					{
						k--;
					}
				}
			}
			else if(c==')'||c=='|'&&sc==1)
			{
				sc=0;
			}
			else if(c=='&'&&sc==1)
			{
				sc=1;
				ansand++;
			}
			else if(c=='|'&&sc==2)
			{
				sc=2;
				ansor++;
			}
		}
		else
		{
			if(c=='0')val=0;
			if(c=='1')val=1;
			if(val==0&&c=='&')
			{
				sc=1;
				ansand++;
			}
			else if(val==1&&c=='|')
			{
				sc=2;
				ansor++;
			}
		}
	}
	printf("%d\n%d %d",val,ansand,ansor);
	return 0;
}
// 
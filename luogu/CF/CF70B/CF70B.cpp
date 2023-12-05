#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define c s[i]

int main()
{
	int n;
	scanf("%d\n",&n);//一定要读入回车，否则 getline 会出错
	string s;
	getline(cin,s);//读入一整行
	int len=0,siz=s.size();//len:当前句子长度 siz:整个字符串长度
	vector<int> mes;
	for(int i=0;i<siz;i++)
	{
		if(c=='.'||c=='?'||c=='!')//如果句子结束
		{
			len++;
			if(len>n)//如果超限，输出不可能
			{
				puts("Impossible");
				return 0;
			}
			if(!mes.empty()&&mes.back()+len+1<=n)//能合并
			{
				mes.back()+=(len+1);//就合并
			}
			else
			{
				mes.push_back(len);//创建新消息
			}
			// printf("%d\n",len);
			i++;//跳过空格
			len=0;
		}
		else
		{
			len++;//否则长度加 1
		}
	}
	printf("%d\n",mes.size());//输出消息数量
	return 0;
}
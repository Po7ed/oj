#include <iostream>
using namespace std;
double exp()
{
	char s[10];
	scanf("%s",s);
	double value=0;
	// if(c==' ')scanf("%c",&c);
	// cout<<c<<endl;
	switch(s[0])
	{
		case '+':value=exp()+exp();break;
		case '-':value=exp()-exp();break;
		case '*':value=exp()*exp();break;
		case '/':value=exp()/exp();break;
		default:value=atof(s);
	}
	return value;
}
int main()
{
	printf("%f",exp());
	return 0;
}
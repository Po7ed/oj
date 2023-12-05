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

#include <iostream>
using namespace std;
int main()
{
	unsigned n;
	scanf("%u",&n);
	n=((n&0xffff0000)>>16)+((n&0xffff)<<16);
	printf("%u",n);
}
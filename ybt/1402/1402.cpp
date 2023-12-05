#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char ct[1001],pt[1001],key[101];
	scanf("%s\n%s",key,ct);
	for(int i=0;i<strlen(key);i++)
	{
		if(isupper(key[i]))key[i]+=32;
	}
	for(int i=0;i<strlen(ct);i++)
	{
		if(isupper(ct[i]))
			pt[i]=(ct[i]-(key[i%(strlen(key))]-97)-65+26)%26+65;
		if(islower(ct[i]))
			pt[i]=(ct[i]-(key[i%(strlen(key))]-97)-97+26)%26+97;
		printf("%c",pt[i]);
	}
	puts("");
	return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int d=(int)ceil(sqrt(n*8+1)/2-(double)1/2),p=(double)(d*(d-1))/2;
    if(d&1)
    {
        printf("%d/%d",d+1-(n-p),n-p);
    }
    else
    {
        printf("%d/%d",n-p,d+1-(n-p));
    }
    return 0;
}
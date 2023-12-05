#include <iostream>
#include <vector>
//#include <random>
#include <random> 
using namespace std;
const int N=1145141;
//int a[N];
//vector<int> v;
int n;

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%d",&n);
	srand(*(new char));
	printf("%d %d",rand()%n,rand()%n);
	return 0;
}

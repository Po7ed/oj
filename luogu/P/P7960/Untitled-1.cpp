#include <bits/stdc++.h>
using namespace std;
bool f[30000001];
int nx[30000001], sg;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= 10000100; i++)
	{
		if (f[i] == 0)
		{
			string s;
			s = to_string(i);
			int j = 0;
			int m = s.size();
			while (j <= m)
			{
				if (s[j] == '7')
				{
					f[i] = 1;
					for (int k = i; k <= 10000100; k += i)
					{
						f[k] = 1;
					}
				}
				j++;
			}
			nx[sg] = i;
			sg = i;
		}
	}
	while (n--)
	{
		int a;
		cin >> a;
		if (f[a])
		{
			cout << -1 << endl;
		}
		else
		{
			cout << nx[a] << endl;
		}
	}
	return 0;
}
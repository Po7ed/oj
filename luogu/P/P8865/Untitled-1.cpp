for (int i = 0; i < n; ++i)
{
	for (int j = m - 1; j >= 0; --j)
	{
		if (a[i][j] != '1')
		{
			right[i][j] = right[i][j + 1] + 1;
			if (i > 1 && a[i - 1][j] != '1' && right[i - 2][j] > 0)
				up[i][j] = up[i - 1][j] + right[i - 2][j] - 1;
			int c = (right[i][j] - 1) * up[i][j] % p, f = 1ll * c * (down[i][j] - 1) % p;
			if ((ans1 += c) >= p)
				ans1 -= p;
			if ((ans2 += f) >= p)
				ans2 -= p;
		}
	}
}
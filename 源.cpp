#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,W;
	int w[100];
	int v[100];
	int x[100];//判断是否装进背包
	int c[100][100];
	cin >> n>>W;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
		x[i] = 0;
	}
	for (int i = 0; i <= W; i++)
		c[0][i] = 0;
	for (int i = 1; i <= n; i++)
		c[i][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (w[i] > j)
				c[i][j] = c[i - 1][j];
			else
				c[i][j] = max(c[i - 1][j], c[i - 1][j - w[i]] + v[i]);
		}
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= W; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	int i = n;
	int j = W;
	while (i > 0)
	{
		if (c[i][j] > c[i - 1][j])
		{
			x[i] = 1;
			j -= w[i];
		}
			i--;
	}
	cout << c[n][W] << endl;
	for (int i = 1; i <= n; i++)
	{
		if (x[i] == 1)
			cout << i << " ";
	}
	system("pause");
}
#include<iostream>
using namespace std;
int g[10][10];

bool ok(int u, int x, int y)
{

	for (int i = 0; i < 9; i++)
	{
		if (g[x][i] == u || g[i][y] == u)
			return false;
	}
	x = x / 3 * 3;
	y = y / 3 * 3;
	//ȷ���Ź���������ͬ���� 
	for (int j = x; j < x + 3; j++)
	{
		for (int k = y; k < y + 3; k++)
		{
			if (g[j][k] == u)return false;
		}
	}
	return true;

}
//�������� 
void dfs(int x, int y)
{
	if (x == 9 && y == 0)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (j)cout << " ";
				cout << g[i][j];
			}
			puts("");
		}
		return;
	}
	if (y == 9)dfs(x + 1, 0);//���� 
	else
	{//�ж���һ�����Ƿ�����ͬ������ 
		if (g[x][y])
			dfs(x, y + 1);
		else
		{
			for (int i = 0; i <= 9; i++)//��һ����ö��
				if (ok(i, x, y))
				{
					g[x][y] = i;
					dfs(x, y + 1);
					g[x][y] = 0;
				}
		}
	}
}
int main() {

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> g[i][j];
	dfs(0, 0);
	return 0;

}







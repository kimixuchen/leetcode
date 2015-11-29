#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
private:
	const int _MAX = 0x3f3f3f3f;
	vector<vector<int>> dp;
	int minHealth;

public:
	int calculateMinimumHP(vector<vector<int>>& dungeon)
	{
		int max;
		int w = dungeon.size();
		int h = dungeon[0].size();
		dp.assign(dungeon.begin(), dungeon.end());
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				dp[i][j] = 0;
			}
		}
		int req;
		for (int i = w - 1; i >= 0; i--)
		{
			for (int j = h - 1; j >= 0; j--)
			{
				if (dungeon[i][j] > 0)
					req = 1;
				else
					req = 1 - dungeon[i][j];
				if (i < w - 1 || j < h - 1)
				{
					int min1 = _MAX;
					if (i + 1 < w && j < h)
					{
						min1 = dp[i + 1][j];
					}
					if (i < w && j + 1 < h)
					{
						min1 = min(min1, dp[i][j + 1]);
					}
					if (req + dungeon[i][j] - min1 < 0)
						req += min1 - dungeon[i][j] - req;
				}
				
				dp[i][j] = req;
			}
		}
		
		return dp[0][0];
	}
};

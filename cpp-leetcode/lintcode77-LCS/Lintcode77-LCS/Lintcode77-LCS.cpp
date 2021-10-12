// Lintcode77-LCS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <string>
using namespace std;
static const int N = 1000;

static const int N = 1000;
class Solution {
public:
    int longestCommonSubsequence(string A, string B) {
		int dp[N + 1][N + 1];
		int m = A.size();
		int n = B.size();
		int max1 = 0;
		A = ' ' + A;
		B = ' ' + B;
		for (int i = 1; i <= m; i++)
			dp[i][0] = 0;
		for (int j = 1; j <= n; j++)
			dp[0][j] = 0;

		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (A[i] == B[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				max1 = max(max1, dp[i][j]);
			}
		}
        return max1;
    }
};

int main()
{
    return 0;
}


#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

int main()
{
	int M, N; // M(背包容量，M<=200)和N(物品数量，N<=30)；
	std::cin >> M >> N;
	int dp[N + 1][M + 1];

	// dp数组初始化全部 0;
	for (int i = 0; i < N + 1; i++)
		for (int j = 0; j < M + 1; j++)
			dp[i][j] = 0;
	int Wi[N + 1] = {0};
	int Ci[N + 1] = {0};
	memset(Wi, 0, sizeof(Wi));
	memset(Ci, 0, sizeof(Ci));
	for (int i = 1; i < N + 1; i++)
	{
		std::cin >> Wi[i] >> Ci[i];
	}
	/* for (int i = 0; i < N + 1; i++)
	{
		std::cout << Wi[i] << Ci[i] << std::endl;
	} */

	for(int i=1; i<N+1; i++)
	{
		for(int j=1; j<M+1; j++)
		{
			if(j >= Wi[i]) // 如果可以装下
			{
				dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-Wi[i]]+Ci[i]);
			}
			else // 装不下
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}



	for(int i=0; i<N+1; i++)
	{
		for(int j=0; j<M+1; j++)
		{
			std::cout << dp[i][j] << " ";
		}
		std::cout << std::endl;
	}





	std::cout << dp[N][M] ;

	return 0;
}
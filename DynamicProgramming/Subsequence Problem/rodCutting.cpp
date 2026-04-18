int fun(int ind, int size, vector<int>& price, vector<vector<int>>& dp){
	if(ind == 0) return price[0]*size;

	if(dp[ind][size] != -1) return dp[ind][size];

	int notTake = fun(ind-1, size, price, dp);

	int take = 0;
	if(ind+1 <= size){
		take = price[ind] + fun(ind, size - (ind+1), price, dp);
	}

	return dp[ind][size] = max(take, notTake);
}

// int cutRod(vector<int> &price, int n)
// {
// 	vector<vector<int>> dp(n, vector<int>(n+1, -1));
// 	return fun(n-1, n, price, dp);
// }

int cutRod(vector<int> &price, int n)
{
	vector<int> cur(n+1, 0);
	
	for(int size = 1; size <= n; size++){
		cur[size] = size*price[0];
	}

	for(int ind = 1; ind < n; ind++){
		for(int size = 1; size <= n; size++){
			int notTake = cur[size];

			int take = 0;
			if(ind+1 <= size){
				take = price[ind] + cur[size - (ind+1)];
			}

			cur[size] = max(take, notTake);
		}
	}

	return cur[n];
}


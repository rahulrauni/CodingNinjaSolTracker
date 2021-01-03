int knapsack(int *weight, int *values, int n, int maxWeight,int **ans) {
	// Base case
	if(n == 0 || maxWeight == 0) {
		return 0;
	}
    if(ans[n][maxWeight]!=-1){
        return ans[n][maxWeight];
    }

	if(weight[0] > maxWeight) {
		ans[n][maxWeight]= knapsack(weight + 1, values + 1, n - 1, maxWeight,ans);
        return ans[n][maxWeight];
	}

	// Recursive calls
	int x = knapsack(weight + 1, values + 1, n - 1, maxWeight - weight[0],ans) + values[0];
	int y = knapsack(weight + 1, values + 1, n - 1, maxWeight,ans);
    ans[n][maxWeight]=max(x, y);
	return ans[n][maxWeight];
}
int knapsack_mem(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    int **ans = new int*[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=new int[maxWeight+1];
        for(int j = 0; j <= maxWeight; j++) {
			ans[i][j] = -1;
		}
    }
    return knapsack(weight, value, n , maxWeight,ans);
    
}

int knapsack_dp(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    int **ans = new int*[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=new int[maxWeight+1];
    }
    for(int i=0;i<=maxWeight;i++){
        ans[0][i]=0;
    }
    for(int j=1;j<=n;j++){
        ans[0][j]=0; 
    }
    for(int i = 1; i <= n; i++) {
		for(int w = 1; w <=maxWeight ; w++) {
            if (weight[n-i] > w) 
                ans[i][w] = ans[i - 1][w];
               
            else
                 ans[i][w] = max(value[n-i] 
                          + ans[i - 1][w - weight[n-i]], 
                          ans[i - 1][w]); 
        }
    }
    return ans[n][maxWeight];
}
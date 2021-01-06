int countWaysToMakeChange_DP(int denominations[], int n, int value){
	//Write your code here
    int **ans = new int*[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=new int[value+1];
    }
    for(int i=0;i<=value;i++){
        ans[0][i]=0;
    }
    for(int j=1;j<=n;j++){
        ans[j][0]=1; 
    }
    for(int i = 1; i <= n; i++) {
		for(int w = 1; w <=value ; w++) {
            if (denominations[n-i] > w) 
                ans[i][w] = ans[i - 1][w];
               
            else
                 ans[i][w] =ans[i][w - denominations[n-i]]+ ans[i - 1][w];
        }
    }
    return ans[n][value];
    
}


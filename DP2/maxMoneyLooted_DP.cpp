int maxMoneyLooted(int *arr, int n,int *ans)
{
	//Write your code here
    if(n<=0){
        return 0;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    
    int a= maxMoneyLooted(arr+2,n-2,ans)+arr[0];
    int b = maxMoneyLooted(arr+1,n-1,ans);
    ans[n]= max(a,b);
    return ans[n];
    
}

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
   int *ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return maxMoneyLooted(arr,n,ans);
    
}

int maxMoneyLooted_DP(int *arr, int n)
{
	//Write your code here
   int *ans = new int[n+1];
   ans[0]=0;
   ans[1]=arr[0];
    for(int i=2;i<=n;i++){
       ans[i]= max((ans[i-2]+arr[i-1]),ans[i-1]) ;
    }
    return ans[n];
    
    
}

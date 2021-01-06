int getAllWays(int a, int b) {
    int *arr= new int[a+1];
    int upto = (int)(pow(a, 1.0/b)) +1;
    arr[0] = 1;
    for(int index = 1; index <= upto; ++index){
        int power = (int)pow(index, b);
        for(int j = a; j >= power; j--){
            arr[j] += arr[j-power];
        }
    }
    return arr[a];
}

#include<bits/stdc++.h>
int getAllWays(int a, int b,int c) {
	// Write your code here
    if((int)pow(c,b)==a){
        return 1;
    }
    if((int)pow(c,b)>a){
        return 0;
    }
    int ans = getAllWays(a,b,c+1)+getAllWays(a-(int)pow(c,b),b,c+1);
    return ans;
    
}
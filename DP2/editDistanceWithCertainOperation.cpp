int editDistance_DP(string s1, string s2)
{
	//Write your code here
    
    int  **output=new int*[s1.size()+1];
    for(int i=0;i<=s1.size();i++){
        output[i] = new int[s2.size()+1];
    }
    for(int i=0;i<=s2.size();i++){
        output[0][i]=i;
    }
    for(int i=1;i<=s1.size();i++){
        output[i][0]=i;
    }
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[s1.size()-i]==s2[s2.size()-j]){
                output[i][j]=output[i-1][j-1];
            }else{
                int a = output[i-1][j];
                int b= output[i][j-1];
                int c= output[i-1][j-1];
                output[i][j]= 1+min(a,min(b,c));
            }
        }
    }
    return output[s1.size()][s2.size()];
      
}



#include <bits/stdc++.h>
int editDistance(string s1, string s2,int **output) {
	// Write your code here
    int m= s1.size();
    int n=s2.size();
    if(s1.size()==0 && s2.size()==0){
        return 0;
    }else if(s1.size()==0){
        return s2.size();
    }else if(s2.size()==0){
        return s1.size();
    }
    if(output[m][n]!=-1){
        return output[m][n];
    }
    int ans;
    if(s1[0]==s2[0]){
        ans= editDistance(s1.substr(1),s2.substr(1),output);
    }else{
        int a = editDistance(s1.substr(1),s2,output);
        int b= editDistance(s1,s2.substr(1),output);
        int c= editDistance(s1.substr(1),s2.substr(1),output);
        ans= 1+min(a,min(b,c));
    }
    output[m][n]=ans;
    return ans;
}
int editDistance_mem(string s1, string s2)
{
	//Write your code here
    
    int  **output=new int*[s1.size()+1];
    for(int i=0;i<=s1.size();i++){
        output[i] = new int[s2.size()+1];
        for(int j=0;j<=s2.size();j++){
            output[i][j]=-1;
        }
    }
    return editDistance(s1,s2,output);
}


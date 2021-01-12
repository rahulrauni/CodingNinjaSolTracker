#include <iostream>
#include <vector>
using namespace std;
vector<int> getpath(int** edges, int n, bool* visited, int v1, int v2){
   visited[v1]=true;
    if(v1==v2){
        vector <int> temp;
        temp.push_back(v1);
        return temp;
    }
     vector <int> ans;
    for(int i=0;i<n;i++){
        if(i==v1){
            continue;
        }
        if(!visited[i] && edges[v1][i]){
            ans= getpath(edges,n,visited,i,v2);
             if(!ans.empty()){
                  ans.push_back(v1);
                  return ans;
             }
        }
        
    }
    return ans;
    
}

int main() {
    // Write your code here
     int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++)edges[i][j]=0;
    }
    
    
      for(int i=0;i<e;i++){
          int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
      }
        int v1,v2;
        cin>>v1>>v2;
        bool *vis=new bool[n];
        for(int i=0;i<n;i++){
            vis[i]=false;
        }
        if(n==0 || e==0){
            return 0;
        }

       vector<int> v=getpath(edges,n,vis,v1,v2);

       for(int i=0;i<v.size();i++){
           cout<<v.at(i)<<" ";
       }
    return 0;
}
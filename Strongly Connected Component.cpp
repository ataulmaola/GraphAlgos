#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int node,edge,visited[100];
vector<int>adj[100],nadj[100];
stack<int> st;
void dfs1(int v){
    visited[v]=1;
    int i,lim,x;
    lim=adj[v].size();
    for(i=0;i<lim;i++){

        x=adj[v][i];
        if(visited[x]==0){
           dfs1(x);
        }
    }
    st.push(v);

}
void dfs2(int v){
    visited[v]=1;
    cout<<v<<" ";
    int i,lim,x;
    lim=nadj[v].size();
    for(i=0;i<lim;i++){

        x=nadj[v][i];
        if(visited[x]==0){
           dfs2(x);
        }
    }
    st.push(v);

}
int main(){
   cin>>node>>edge;
   int i,j,x,y;
   for(i=1;i<=edge;i++){
      cin>>x>>y;
      adj[x].push_back(y);
      nadj[y].push_back(x);
   }
   for(i=1;i<=node;i++){
      if(visited[i]==0){
      dfs1(i);
      }
   }
   for(i=1;i<=node;i++){
     visited[i]=0;

   }
   while(!st.empty()){
      x=st.top();
      st.pop();
      if(visited[x]==0){
        dfs2(x);}
        cout<<endl;
      }

   return 0;

}

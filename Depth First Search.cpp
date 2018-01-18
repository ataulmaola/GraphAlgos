#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int t, node,edge,d[100],f[100],par[100];
vector<int>adj[100],b_edge[100],f_edge[100],c_edge[100];
char color[100];
void dfs(int u){
   color[u]='g';
   t=t+1;
   d[u]=t;
   printf("discovered %d, at %d\n",u,d[u]);
   int i,lim,v;
   lim=adj[u].size();
   for(i=0;i<lim;i++){
    v=adj[u][i];
    if(color[v]=='w')
        {par[v]=u;
        dfs(v);}
    else if(color[v]=='g')
        b_edge[u].push_back(v);
    else if(color[v]=='b'){
        if(d[u]<d[v])
            f_edge[u].push_back(v);
            else if(d[v]<d[u])
            c_edge[u].push_back(v);}
    }

    t=t+1;
    f[u]=t;
    color[u]='b';
    printf("finished %d at %d\n",u,f[u]);}



int main(){
   cout<<"how many nodes: ";
   cin>>node;
    cout<<"how many edges: ";
   cin>>edge;
   int i,j,x,y;
   cout<<"input edge:\n";
   for(i=1;i<=edge;i++){
      cin>>x>>y;
      adj[x].push_back(y);
   }
    for(i=1;i<=node;i++){
      color[i]='w';
      par[i]=-1;
   }
   t=0;
   for(i=1;i<=node;i++){
    if(color[i]=='w'){
        dfs(i);
    }
   }
   int lim;
   cout<<"back edge\n";
   for(i=1;i<=node;i++){
      x=i;
      lim=b_edge[x].size();
      for(j=0;j<lim;j++){
        y=b_edge[x][j];
        cout<<x<<"-"<<y<<endl;
      }
   }
   cout<<"Cross edge\n";
   for(i=1;i<=node;i++){
      x=i;
      lim=c_edge[x].size();
      for(j=0;j<lim;j++){
        y=c_edge[x][j];
        cout<<x<<"-"<<y<<endl;
      }
   }
   cout<<"Forward edge\n";
   for(i=1;i<=node;i++){
      x=i;
      lim=f_edge[x].size();
      for(j=0;j<lim;j++){
        y=f_edge[x][j];
        cout<<x<<"-"<<y<<endl;
      }
   }
}

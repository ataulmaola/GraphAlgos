#include<bits/stdc++.h>
using namespace std;

#define MAX 100
#define INF 999999
#define NIL -1
int p[100];

void Find_path(int x,int s){
   if(x==s){
        cout<<x<<"->";
   }
   else{
        Find_path(p[x],s);
        cout<<x<<"->";
   }
}
int main()
{
    vector<int>adj[MAX];
    int n,edge,i,j,lim1,lim2;
    int d[100];
    char color[100];
    cout<<"Enter the number of nodes: ";
    cin>>n;/// number of nodes in the Graph
    cout<<"Enter the number of edges: ";
    cin>>edge;/// number of nodes in the Graph
    cout<<"Enter the edges "<<endl;
    for(i=0;i<edge;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(i=1;i<=n;i++){
        cout<<i<<"=>";
        lim1=adj[i].size();
        for(j=0;j<lim1;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
    for(i=1;i<=n;i++){
        color[i]='w';
        d[i]=INF;
        p[i]=NIL;
    }
    int src;
    cout<<"Enter the source: ";
    cin>>src;
    color[src]='g';
    d[src]=0;
    p[src]=NIL;

    queue<int>q;

    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        int lim3=adj[u].size();
        for(int i=0;i<lim3;i++){
           int v=adj[u][i];
            if(color[v]=='w'){
                color[v]='g';
                d[v]=d[u]+1;
                p[v]=u;
                q.push(v);
            }
        }
        color[u]='b';
    }
    cout<<endl<<endl;
    int o;
    cout<<"Enter destination Node: ";
    cin>>o;
    Find_path(o,src);

}


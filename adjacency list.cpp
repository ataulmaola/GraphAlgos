#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int main()
{
    vector<int>adj[MAX];//
    int n,edge,i,j,lim;

    cout<<"Enter the number of nodes: ";
    cin>>n;/// number of nodes in the Graph
    cout<<"Enter the number of edges: ";
    cin>>edge;/// number of nodes in the Graph
    cout<<"Enter the edges "<<endl;

    for(i=0; i<edge; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<endl<<"So the graph in adjacency list ;

        for(i=1;i<=n;i++){
        cout<<i<<"=>";
        lim=adj[i].size();
        for(j=0;j<lim;j++){
        cout<<adj[i][j]<<" ";
    }
        cout<<endl;
    }
    }

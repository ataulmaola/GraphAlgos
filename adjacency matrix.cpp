#include<bits/stdc++.h>
using namespace std;
int adjm[100][100];
int main()
{
    int i,j,k,n,edge,e1,e2,cost;
    cout<<"Enter the number of nodes: ";
    cin>>n;/// number of nodes in the Graph
    cout<<"Enter the number of edges: ";
    cin>>edge;/// number of nodes in the Graph
    cout<<"Enter the edges and cost: "<<endl;
    for(i=1;i<=edge;i++){
        cin>>e1>>e2>>cost;
        adjm[e1][e2]=cost;
        adjm[e2][e1]=cost;
    }
     cout<<endl<<"So the graph in adjacency matrix ;

    for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)
        {
        cout<<adjm[i][j]<<" ";
    }
     cout<<endl;
    }
}

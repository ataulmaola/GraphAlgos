#include<bits/stdc++.h>
using namespace std;

int indeg[100];
int taken[100];

int main()
{
    int node,edge;
    vector<int>adj[100];
    int x,y;
    cout<<"How many nodes:";
    cin>>node;
    cout<<"How many edges: ";
    cin>>edge;
    for(int i=0;i<edge;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    int cnt=0;
    while(cnt!=node){
        for(int i=1;i<=node;i++){
            if(indeg[i]==0 && !taken[i]){
                cnt++;
                taken[i]=1;
                cout<<i<<endl;
                int lim= adj[i].size();
                for(int j=0;j<lim;j++){
                    x=adj[i][j];
                    if(!taken[x]){
                        indeg[x]--;
                    }
                }
            }
        }
    }
    return 0;
}

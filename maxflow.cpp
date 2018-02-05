#include <bits/stdc++.h>
#define NIL 99999999
using namespace std;

int cap[100][100],flow[100][100],res[100][100];
int visited[100],par[100];
#define NIL -1
#define MAX 1<<22
int main()
{
    memset(cap,NIL,sizeof(cap));
    memset(flow,NIL,sizeof(flow));
    int i,j,x,y;
    int node,edges,source,sink;
    cout<<endl<<"Enter the number of nodes :";
    cin>>node;
    cout<<endl<<"Enter the number of edges :";
    cin>>edges;
    cout<<endl<<"Enter the number of source :";
    cin>>source;
    cout<<endl<<"Enter the number of sink :";
    cin>>sink;

    for(i=1; i<=edges; i++)
    {
        cin>>x>>y;
        cin>>cap[x][y];
        flow[x][y]=0;
    }
    while(1)
    {
        memset(res,0,sizeof(res));
        for(i=1; i<=node; i++)
        {
            for(j=1; j<=node; j++)
            {
                if(flow[i][j]!=NIL)
                {
                    if(cap[i][j]-flow[i][j]!=0)
                    {
                        res[i][j]=cap[i][j]-flow[i][j];
                    }
                    if(flow[i][j]!=0)
                    {
                        res[j][i]=flow[i][j];
                    }
                }

            }
        }
        memset(visited,0,sizeof(visited));
        memset(par,NIL,sizeof(par));
        queue<int>q;
        q.push(source);
        par[source]=source;
        visited[source]=1;
        while(!q.empty())
        {
            x=q.front();
            q.pop();
            for(i=1; i<=node; i++)
            {
                if(res[x][i] && visited[i] == 0)
                {
                    q.push(i);
                    visited[i]=i;
                    par[i]=x;

                }
            }
        }
        if(visited[sink]==0)
            break;
        int min_path=MAX;
        for(y=sink; y!=source; y=par[y])
        {
            x=par[y];
            if(res[x][y]< min_path)
            {
                min_path=res[x][y];
            }
        }
        for(y=sink; y!=source; y=par[y])
        {
            x=par[y];
            if(flow[x][y]!=NIL)
            {
                flow[x][y]+=min_path;
            }
            else
            {
                flow[x][y]-=min_path;
            }
        }
    }
    int total=0;
    for(i=1; i<=node; i++)
    {
        if(flow[i][sink]!=NIL)
        {
            total+=flow[i][sink];
        }

    }
    cout<<total<<endl;
    for(i=1; i<=node; i++)
    {
        for(j=1; j<=node; j++)
        {
            if(flow[i][j]!=NIL)
            {
                cout<<i<<" >> "<<j<<": "<<flow[i][j]<<endl;
            }
        }
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int par[100];
class edge
{
public:
    int u,v,w;

};
bool cmp(edge ob1,edge ob2)
{

    return ob1.w<ob2.w;
}
void make_set(int n)
{
    int i;
    for(i=1; i<=n; i++)
    {
        par[i]=i;
    }
}
int find(int r)
{
    if (par[r]==r) return r;
    else
    {
        int q= find(par[r]);
        return q;
    }
}

int main()
{
    int node,en,x,y,w,i;
    cout<<"how many node: ";
    cin>>node;
    cout<<"how many edge: ";
    cin>>en;
    vector<edge>ev;
    edge ob;
    cout<<"input endpoint and weight:\n";
    for(i=0; i<en; i++)
    {
        cin>>ob.u>>ob.v>>ob.w;
        ev.push_back(ob);
    }
    sort(ev.begin(),ev.end(),cmp);
    cout<<"\nafter sort\n";
    for(i=0; i<en; i++)
    {
        cout<<ev[i].u<<","<<ev[i].v<<"->"<<ev[i].w<<endl;

    }
    make_set(node);
    int cnt=0;
    int sum=0;
    cout<<"\nMST:\n";
    for(i=0; cnt!=node-1; i++)
    {
        int g,h;
        g=ev[i].u;
        h=ev[i].v;
        int  pg=find(g);
        int ph=find(h);
        if(pg!=ph)
        {
            par[pg]=ph;
            sum+=ev[i].w;
            cout<<g<<","<<h<<endl;
            cnt++;
        }
    }
    cout<<sum;
    return 0;
}

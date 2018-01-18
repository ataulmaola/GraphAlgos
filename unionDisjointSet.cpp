#include<bits/stdc++.h>
using namespace std;
int par[100];
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
    if(par[r]==r)
    {
        return r;
    }
    else
    {
        int q=find(par[r]);
        return q;
    }
}
void make_union(int x,int y)
{
    int u=find(x);
    int v=find(y);
    if(u!=v)
    {
        par[u]=v;
    }
}
int main()
{
    int n,i,x,y,p;
    cout<<"How many people: ";
    cin>>n;
    make_set(n);
    cout<<"How many pairs: ";
    cin>>p;
    cout<<"Input pairs: \n";
    for(i=1;i<=p;i++){
        cin>>x>>y;
        make_union(x,y);
    }
    int cnt=0;
    for(i=1;i<=n;i++)
        if(par[i]==i)
            cnt++;
        cout<<cnt;
    return 0;


}

#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> v;
    int n,x,i,lim;
    cout<< "How many elements: ";
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x;
        v.push_back(x);
    }
    lim= v.size();
    cout<< "Size of vector:"<<lim<<endl;
    cout<<"The elements are";
    for(i=0;i<n;i++){
        cout<<" "<<v[i];
    }

}

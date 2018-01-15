#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int>q;
    q.push(120);
    q.push(454);
    q.push(23);
    int a=q.size();
    cout<<"Size: "<<a<<endl;
    cout<<"In front: "<<q.front()<<endl;
    q.pop();
    q.pop();
    q.pop();
    a=q.size();

    cout<<"Size: "<<a<<endl;
    if(q.empty()==true)
        cout<<"Queue is empty"<<endl;
    cout<<"In front: "<<q.front()<<endl;
}

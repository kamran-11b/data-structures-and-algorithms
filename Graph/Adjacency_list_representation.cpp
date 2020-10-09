#include<bits/stdc++.h>
using namespace std;

#define   mx  100
vector<int>v[mx];

int main()
{
    int node;
    cin>>node;
    for(int i=1; i<=node+1; i++)
    {
       int x,y;
       cin>>x>>y;

       v[x].push_back(y);
    }
    for(int i=1; i<=node; i++)
    {
        cout<<"Node "<<i<<"-> ";
        for(int j=0; j<v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

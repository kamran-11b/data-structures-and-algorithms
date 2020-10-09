#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define mx 100

vector<int>adj[mx];

int main()
{

    int nodes,edges;
    cin>>nodes;
    cin>>edges;
    for(int i=0; i<edges; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i=1; i<=nodes; i++)
    {
        cout<<"Adjacency list of node "<<i<<": ";
        for(int j=0; j<adj[i].size(); j++)
        {
            cout << adj[i][j]<<" ";
        }
        cout<<endl;
    }

}

/*
input
4
5
1 2
2 4
3 1
3 4
4 2

*/

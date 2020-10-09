#include<bits/stdc++.h>
using namespace std;

#define  mx  100000
vector<int>adj[mx];
bool visited[mx];

void dfs(int source)//s is source vertex
{
    visited[source]=true;
    for(int i=0; i<adj[source].size(); i++)
    {
        if(visited[adj[source][i]]==false)
            dfs(adj[source][i]);
    }
}

void initialize()
{
    for(int i=0; i<mx; i++)
    {
        visited[i]=false;
    }
}
int main()
{

    int nodes,edges;
    cin>>nodes>>edges;
    initialize();
    for(int i=0; i<edges; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int c=0;//Number of connected components.
    for(int i=1; i<=nodes; i++)
    {
        if(visited[i]==false)
        {
            dfs(i);
            c++;
        }
    }
    cout<<c<<endl;
}

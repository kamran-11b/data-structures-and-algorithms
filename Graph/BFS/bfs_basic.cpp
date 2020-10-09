#include<bits/stdc++.h>
using namespace std;
#define   ll     long long
#define   mx     1000


vector<int>adj[mx];
int visited[mx];

void edge(int a, int b)
{
    adj[a].push_back(b);
    //for directed graph not add this line
    adj[b].push_back(a);
}

// start is the starting vertex
// n is the number of vertex
int bfs(int start,int n)
{
    memset(visited,0,sizeof n);

    queue<int>q;
    q.push(start);
    visited[start]=1;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<": ";
        for(int i=0; i<adj[u].size(); i++)
        {
            if(visited[adj[u][i]]==0)
            {
                int v=adj[u][i];
                cout<<v<<" ";
                visited[v]=1;
                q.push(v);
            }
        }
        cout<<endl;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        edge(x,y);
    }
    bfs(0,n);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==1)
        {
            cout<<i<<endl;
        }
    }
}

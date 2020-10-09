#include<bits/stdc++.h>
using namespace std;
#define   ll     long long
#define   mx     1000


vector<int>adj[mx];
bool visited[mx];
int level[mx];
int k;
void edge(int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int bfs(int start,int x)
{
    queue<int>q;
    q.push(start);

    level[start]=1;
    visited[start]=1;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                level[v]=level[u]+1;

                if(level[v]==x)
                {
                    k++;
                }
                visited[v]=1;
                q.push(v);
            }
        }
    }
    cout<<k<<endl;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        edge(x,y);
    }
    int m;
    cin>>m;
    bfs(1,m);
}
/*

20
11 1
1 2
13 3
15 4
17 5
11 6
2 7
1 8
15 9
4 10
15 12
5 13
2 14
17 15
15 16
11 17
15 18
9 19
16 20
2

output: 3

/*

#include<bits/stdc++.h>
using namespace std;

#define   ll     long long
#define   mx     100005

vector<int>adj[mx];
int visited[mx];
int in[mx],out[mx];
queue<int>q;

void edge(int a,int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void bfs(int s)
{
    memset(visited,0,sizeof visited);
    memset(out,0,sizeof out);
    memset(in,0,sizeof in);

    q.push(s);
    visited[s]=1;
    out[s]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int i=0; i<adj[node].size(); i++)
        {
            int v=adj[node][i];

            if(visited[v]==0)
            {
                if(out[node]==1)
                {
                    printf("%d %d\n",node,v);
                    in[v]=1;
                    visited[v]=1;
                    q.push(v);
                }
                else if(in[node]==1)
                {
                    printf("%d %d\n",v,node);
                    out[v]=1;
                    visited[v]=1;
                    q.push(v);
                }
            }
        }
    }

}

int main()
{
    //freopen("A.txt","r",stdin);
    //freopen("B.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        printf("Case %d:\n",i);
        int n;
        scanf("%d",&n);
        for(int j=0; j<n-1; j++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            edge(x,y);
        }
        bfs(1);
    }
}
/*

J.Yet Another Longest Path Problem

2
3
1 2
2 3
4
2 1
1 3
4 1

/*


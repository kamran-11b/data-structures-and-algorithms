#include<bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define SIZE 100

int adj[SIZE][SIZE];
int colour[SIZE];
int parent[SIZE];
int dis[SIZE];
//int time = 0;

void dfs(int vertex);
void dfsVisit(int u , int vertex);

int main()
{
    freopen("input.txt" , "r" , stdin);
    int vertex;
    int edge;
    cin >> vertex >> edge;
    cout << "Vertex is : " << vertex <<endl;
    cout << "Edge is : " << edge <<endl;

    int node1,node2;
    for(int i = 0 ; i< edge ; i++)
    {
        //cout << "Enter 2 Nodes : ";
        cin >> node1 >> node2;
        adj[node1][node2] = 1;
        adj[node2][node1] = 1;

    }
    for(int i = 0 ; i < vertex ; i++)
    {
        for(int j = 0 ; j < vertex ; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    dfs(vertex);
}


void dfs(int vertex)
{
    for(int i = 0 ; i < vertex ; i++)
        colour[i] = WHITE;
    //time = 0;
    cout << "DFS is ";
    for(int i = 0 ; i<vertex ; i++)
    {
        if(colour[i] == WHITE)
        {
            dfsVisit(i , vertex);
        }
    }
}

void dfsVisit(int u , int vertex)
{
    colour[u] = GRAY;
    //dis[u] = time+1;
    for(int i = 0 ; i<vertex ; i++)
    {
        if(adj[u][i] == 1)
        {
            int v = i;
            if(colour[v] == WHITE)
            {
                parent[v] = u;
                dfsVisit(v , vertex);
            }
        }
    }
    colour[u] = BLACK;
    cout << u << " ";

}
/********************/
#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;
int dist[MAXN+1],dist1[MAXN+1];
vector<int> v[MAXN+1];
void dfs(int x,int p,int s,int *dist)
{
    dist[x]=s;
    for(int i=0; i<v[x].size(); i++)
        if(v[x][i]!=p)
            dfs(v[x][i],x,s+1,dist);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,x,y,maxi=-1;
    cin>>n>>m;
    for(int i=0; i<(n-1); i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0,0,dist);
    dfs(m,0,0,dist1);
    for(int i=1; i<=n; i++)
        if(dist1[i]<dist[i])
            maxi=max(maxi,dist[i]);
    cout<<(2*maxi)<<"\n";
    return 0;
}
/**************************************/

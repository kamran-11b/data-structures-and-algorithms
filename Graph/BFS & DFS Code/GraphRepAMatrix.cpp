#include<bits/stdc++.h>
using namespace std;

#define mx  100
bool ar[mx][mx];

void initialize()
{
    for(int i=1; i<=mx; i++)
    {
        for(int j=1; j<=mx; j++)
        {
            ar[i][j]=false;
        }
    }
}

int main()
{

    int nodes;
    int edges;
    int x,y;
    cin>>nodes;
    cin>>edges;

    initialize();

    for(int i=0; i<edges; i++)
    {
        cin>>x>>y;
        ar[x][y]=true;
    }

    cout<<endl;

    for(int i=1; i<=nodes; i++)
    {
        for(int j=1; j<=nodes; j++)
        {
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }
}
/*
input:

4
5
1 2
2 4
3 1
3 4
4 2
Output:

0 1 0 0
0 0 0 1
1 0 0 1
0 1 0 0
*/

#include<bits/stdc++.h>
using namespace std;
#define mx  25

char grid[mx][mx];
int x,y,ans;

int dr[]= {-1,0,1,0};
int dc[]= {0,1,0,-1};

void bfs(int r,int c)
{
    grid[r][c]='#';
    for(int i=0; i<4; i++)
    {
        int dx=r+dr[i];
        int dy=c+dc[i];

        if(dx>=0 && dy>=0 && dx<y && dy<x && grid[dx][dy]=='.')
        {
            bfs(dx,dy);
            ans++;
        }
    }

}
int main()
{
    int t;
    cin>>t;
    for(int tt=1; tt<=t; tt++)
    {
        int sx,sy;
        cin>>x>>y;
        for(int i=0; i<y; i++)
        {
            for(int j=0; j<x; j++)
            {
                cin>>grid[i][j];

                if(grid[i][j]=='@')
                {
                    sx = i;
                    sy = j;
                }
            }
        }
        ans=1;
        bfs(sx,sy);
        cout<<"Case "<<tt<<": "<<ans<<endl;
    }
}

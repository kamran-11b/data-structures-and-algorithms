#include<bits/stdc++.h>
using namespace std;

#define mx   100

vector< pair<int,int> > v[mx];

vector< pair<int,int> >:: iterator it;

/*If there is an edge from node a to node b with weight w,
 the adjacency list of node a contains the pair (b, w).*/

int main()
{
    cin.tie(NULL);
    int node;
    cin>>node;
    int edge=node+1;

    for(int i=1; i<=edge; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        v[x].push_back(make_pair(y,w));

    }
    for(int i=1; i<=node; i++)
    {
        cout<<"Node "<<i<<":"<<endl;
        for(it = v[i].begin(); it!=v[i].end(); it++)
        {
            cout<<i<<"<->"<<it->first<<": "<<it->second<<"  "<<endl;
        }
        cout<<endl;
    }

}

/*
4
1 2 5
2 3 7
2 4 6
3 4 5
4 1 2
*/


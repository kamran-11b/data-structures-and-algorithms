#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mx 100001

int arr[mx];
int tree[mx*3];

void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    //tree[node] = tree[Left] + tree[Right];
}

void update(int node, int b, int e, int i,int j, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i)
    {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i,j, newvalue);
    update(Right, mid + 1, e, i,j, newvalue);

}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        arr[i]=0;
    }

    init(1, 1, n);


    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

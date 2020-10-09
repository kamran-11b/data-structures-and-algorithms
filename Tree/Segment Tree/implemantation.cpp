#include<bits/stdc++.h>
using namespace std;
#define mx 1000009
#define ll long long
int tree[mx*3];
int ar[mx];
int arr[mx];
void sei()
{
    for(int i=1; i<mx; i++)
    {
        arr[i]=i;
    }
    for(int i=2; i*i<mx; i++)
    {
        if(arr[i]==i)
        {
            for(int j=2*i; j<mx; j+=i)
            {
                if(arr[j]==j)arr[j]=i;
            }
        }
    }
}


void build(int node ,ll b,ll e)
{
    if(b==e)
    {
        tree[node]=arr[ar[b]];
        return;
    }
    int L=2*node;
    int R=2*node+1;
    int mid=(b+e)/2;
    build(L,b,mid);
    build(R,mid+1,e);
    tree[node]=max(tree[L],tree[R]);
}

int query(int node ,ll b,ll e,ll i,ll j)
{
    if(i>e || j<b)
        return 1;
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    int L=2*node;
    int R=(2*node)+1;
    int mid=(b+e)/2;
    int q1=query(L,b,mid,i,j);
    int q2=query(R,mid+1,e,i,j);
    return max(q1,q2);

}
void update(int node ,ll b,ll e,ll i,ll j)
{
    if(i>e || j<b)
        return;
    if(tree[node]==1)
        return;
    if(b==e)
    {
        ar[i]/=arr[ar[i]];
        tree[node]=arr[ar[i]];
        return;
    }
    int L=2*node;
    int R=(2*node)+1;
    int mid=(b+e)/2;
    update(L,b,mid,i,j);
    update(R,mid+1,e,i,j);
    tree[node]=max(tree[L],tree[R]);
}
int main()
{
    int t,f=1;
    sei();
    arr[1]=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        for(int i=1; i<=n; i++)
        {
            cin>>ar[i];
        }
        build(1,1,n);
        while(m--)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            if(x==0)
            {
                update(1,1,n,y,z);
            }
            else
            {
                cout<<query(1,1,n,y,z)<<" ";
            }
        }
        cout<<endl;
    }

}

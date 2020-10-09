#include<bits/stdc++.h>
using namespace std;





int maximum(int ar[], int n)
{
    int res = ar[0];

    for (int i = 1; i < n; i++)
        res = max(res, ar[i]);

    return res;
}

int maximunSubarray(int ar[],int n)
{
    int mx=maximum(ar,n);
    if(mx<0)
        return mx;

    int p=0,s=0;
    for(int i=0; i<n; i++)
    {
        s=max(ar[i],s+ar[i]);
        p=max(s,p);
    }
    return p;
}








void maximunSubarrayn3(int ar[],int n)
{
    // straightforward O(n^3) solution
    int p=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            int s=0;
            for(int k=i; k<=j; k++)
            {
                s+=ar[k];
            }
            p=max(p,s);
        }
    }
    cout<<p<<endl;
}

void maximunSubarrayn2(int ar[],int n)
{
    // straightforward O(n^2) solution
    int p=0;
    for(int i=1; i<=n; i++)
    {
        int s=0;
        for(int j=i; j<=n; j++)
        {
            s+=ar[j];
            p=max(p,s);
        }
    }
    cout<<p<<endl;
}

void maximunSubarrayn(int ar[],int n)
{
    // straightforward O(n) solution

    int p=0,s=0;
    for(int i=1; i<=n; i++)
    {
        s=max(ar[i],s+ar[i]);
        p=max(s,p);
    }
    cout<<p<<endl;
}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=1; i<=n; i++)
    {
        cin>>ar[i];
    }
    //maximunSubarrayn3(ar,n);
    //maximunSubarrayn2(ar,n);
    maximunSubarrayn(ar,n);
}

//input: −1 2 4 −3 5 2 −5 2
// output: 10

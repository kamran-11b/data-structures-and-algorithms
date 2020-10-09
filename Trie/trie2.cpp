#include<bits/stdc++.h>
using namespace std;

int k,id;
string ss;
struct node
{
    bool m;
    node* next[26+1];
    node()
    {
        m=false;
        for(int i=0; i<26; i++)
        {
            next[i]=NULL;
        }
    }
};
node *root =NULL;


void Insert(string s,int len)
{
    node* a=root;
    int x=len-1;
    for(int i=0; i<len; i++)
    {
        int id = s[i]-'a';
        if(a->next[id]!=NULL && i==x)
        {
            k=1;
        }
        if(a->next[id]==NULL)
        {
            a->next[id]=new node();
        }
        a=a->next[id];
        if(a->m==true)
        {
            k=1;
        }
    }
    a->m=1;
}

bool Search(string s,int len)
{
    node *a=root;
    for(int i=0; i<len; i++)
    {

        int id = s[i]-'a';
        if(a->next[id]==NULL)
        {
            return false;
        }
        a=a->next[id];
    }
    return a->m;
}


void del(node* a)
{
    for(int i=0; i<26; i++)
    {
        if(a->next[i])
        {
            del(a->next[i]);
        }
    }
    delete(a);
}

int main()
{
    root =new node();
    k=0;
    int f=0;
    int n;
    cin>>n;
    string s;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        Insert(s,s.size());
        if(k==1 && !f){
            f=1;
            ss=s;
        }

    }
    if(f==1)
    {
        cout<<"BAD SET"<<endl;
        cout<<ss<<endl;
    }
    else
        cout<<"GOOD SET"<<endl;
    del(root);
}


#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<istream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int id,m;
struct node
{
    bool mark;
    node* next[11];
    node()
    {
        mark=false;
        for(int i=0; i<10; i++)
        {
            next[i]=NULL;
        }
    }
};
node* root=NULL;

void Insert(string s)
{
    int nay=0;
    node* newnode=root;
    for(int i=0; i<s.size(); i++)
    {
        int id=s[i]-'0';
        if(newnode->next[id]==NULL)
        {
            nay=1;
            newnode->next[id]=new node();
        }
        if(newnode->mark==1)
        {
            m=0;
        }
        newnode=newnode->next[id];
    }
    if(nay==0)
    {
        m=0;
    }
    newnode->mark=1;
}

bool Search(string s)
{
    node* newnode=root;
    for(int i=0; i<s.size(); i++)
    {
        int id=s[i]-'0';
        if(newnode->next[id]==NULL)
        {
            return false;
        }
        newnode=newnode->next[id];
    }
    return newnode->mark;
}

void del(node* newnode)
{
    for(int i=0; i<10; i++)
    {
        if(newnode->next[i])
        {
            del(newnode->next[i]);
        }
    }
    delete(newnode);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        m=1;
        root =new node();
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            Insert(s);
        }
        if(m==1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        del(root);
    }
}

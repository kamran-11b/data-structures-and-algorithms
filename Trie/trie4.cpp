
#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<istream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
{
    int c=0;
    bool mark;
    node* next[2];
    node()
    {
        mark=false;
        for(int i=0; i<2; i++)
        {
            next[i]=NULL;
        }
    }
};
node* root=NULL;

void Insert(string s)
{
    node* newnode=root;
    for(int i=0; i<s.size(); i++)
    {
        int id=s[i]-'0';
        if(newnode->next[id]==NULL)
        {
            newnode->next[id]=new node();
        }
        newnode=newnode->next[id];
        newnode->c++;
    }
    newnode->mark=1;
}

int Search(string s)
{
    node* newnode=root;
    for(int i=0; i<s.size(); i++)
    {
        int id=s[i]-'0';
        if(newnode->next[id]==NULL)
        {
            return 0;
        }
        newnode=newnode->next[id];
    }
    return newnode->c;
}


void del(node* newnode)
{
    for(int i=0; i<2; i++)
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
    root =new node();
    while(t--)
    {
        string a;
        cin>>a;
        Insert(a);
    }
    del(root);
}



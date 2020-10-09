#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};

Node *insert(Node *root,int value)
{
    if(root==NULL)
        root = new Node(value);
    else
    {
        if(value <root->data)
            root->left = insert(root->left,value);
        else
            root->right = insert (root->right,value);
    }
    return root;
}

void Preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

bool find(Node *root,int value)
{
    if(root==NULL)
        return 0;
    else if(root->data==value)
        return 1;
    else
    {
        if(value < root->data)
            find(root->left,value);
        else
            find(root->right,value);
    }
}

Node *find_min(Node *root)
{
    if(root->left==NULL)
        return root;
    return find_min(root->left);
}

Node *find_max(Node *root)
{
    if(root->right==NULL)
        return root;
    return find_max(root->right);
}

int maxDepth(Node* root)
{
    if(root==NULL)
        return 0;
    int x=maxDepth(root->left);
    int y=maxDepth(root->right);
    return max(x,y)+1;
}

int minDepth(Node* root)
{
    if(root==NULL)
        return 0;

    int x=minDepth(root->left);
    int y=minDepth(root->right);
    if(x==0 || y==0)
        return max(x,y)+1;
    else
        return min(x,y)+1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node *root=NULL;
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            root=insert(root,x);
        }
        Preorder(root);
        cout<<endl;

        Node *mi=find_min(root);
        Node *mx=find_max(root);
        cout<<mi->data<<endl;
        cout<<mx->data<<endl;
        cout<<"Max Depth: "<<maxDepth(root)<<endl;
        cout<<"Min Depth: "<<minDepth(root)<<endl;
        int q;
        cin>>q;
        while(q--)
        {
            int x;
            cin>>x;
            if(find(root,x))
                cout<<"Data is Present"<<endl;
            else
                cout<<"Data not Present"<<endl;
        }
    }
}

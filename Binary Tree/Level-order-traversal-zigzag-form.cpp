
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
vector<int> findSpiral(Node *root);

Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i < ip.size())
    {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        if(currVal != "N")
        {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        if(currVal != "N")
        {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main()
{
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for(int x : vec)
            cout<<x<<" ";
        cout << endl;
    }
    return 0;
}

vector<int> findSpiral(Node *root)
{
    vector<int> v;
    if(root == NULL)
        return v;
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            Node* temp = s1.top();
            s1.pop();
            v.push_back(temp->data);

            if(temp->left!=NULL)
                s2.push(temp->left);
            if(temp->right != NULL)
                s2.push(temp->right);
        }
        while(!s2.empty())
        {
            Node* temp = s2.top();
            s2.pop();
            v.push_back(temp->data);

            if(temp->right != NULL)
                s1.push(temp->right);
            if(temp->left!=NULL)
                s1.push(temp->left);
        }
    }
    return v;
}

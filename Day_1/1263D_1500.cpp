#include <bits/stdc++.h>
using namespace std;
int parent[1000001];
int size[1000001];

int ulp(int node)
{
    if (parent[node] == node)
        return node;

    return parent[node] = ulp(parent[node]);
}

void merge(int a, int b)
{
    int u = ulp(a);
    int v = ulp(b);

    if (u == v)
    {
        return;
    }
    else
    {
        if (size[u] > size[v])
        {
            parent[v] = u;
            size[u] += size[v];
        }
        else
        {
            parent[u] = v;
            size[v] += size[u];
        }
    }
}

int main()
{
    int n;
    cin >> n;

      for(int i=0;i<=1000000;i++)
    {
        parent[i]=i;
        size[i]=1;
    }

    string arr[n];
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        for(char ch : arr[i])
        {
            mp[ch - '0'].push_back(i);
        }
    }

    for(auto x:mp)
    {
        for(int i=1;i<x.second.size();i++)
        {
            merge(x.second[0],x.second[i]);
        }
    }

    int c=0;
    
    for(int i=0;i<n;i++)
    {
        if(parent[i]==i)
        c++;
    }
    cout<<c<<endl;



}
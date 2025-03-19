

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main() 
{

    int t;
    cin>>t;
    while(t--)
    {
        ll n,st,end;
        cin>>n>>st>>end;

        vector<int> graph[n+1];

        for(int i=1;i<=n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        vector<int> visited(n+1,0);
        visited[st]=-1;
        queue<int>q;
        q.push(st);

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
           
            for(auto it:graph[node])
            {
                if(visited[it]==0)
                {
                    visited[it]=node;
                    q.push(it);
                }

                if(it==end)
                {
                   
                    break;
                }
            }
        }

        vector<int> path;

       map<int,int> mp;
        path.push_back(end);
        mp[end]=1;
        while(visited[end]!=-1)
        {
            path.push_back(visited[end]);
            mp[visited[end]]=1;
            end=visited[end];
        }

        reverse(path.begin(),path.end());
        for(int i=1;i<=n;i++)
        {
            if(mp[i]==0)
            {
                path.push_back(i);
            }
        }

        for(auto it:path)
        {
            cout<<it<<" ";
        }
        cout<<endl;

        
    }
}
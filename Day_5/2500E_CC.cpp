//https://www.codechef.com/problems/TREECUTXOR


#include<bits/stdc++.h>
using namespace std;


vector<pair<int,int>> ans;

void dfs(vector<int> graph[],int node,int parent)
{
         for(auto child:graph[node])
         {
                if(child!=parent)
                {
                   dfs(graph,child,node);
                   ans.push_back({node,child});
                }
         }



}

int main()
{
       int t;
       cin>>t;
       while(t--)
       {
            int n;
            cin>>n;
            ans.clear();
            vector<int> graph[n+2];
            for(int i=1;i<n;i++)
                 {
                    int u,v;
                    cin>>u>>v;
                    graph[u].push_back(v);
                    graph[v].push_back(u);

                 }

              dfs(graph,1,0)   ;

    
                 if(n==2)
                 {
                    cout<<1<<endl;
                    cout<<1<<" "<<2<<" "<<1<<endl;

                  



                 }
                 else {

                    cout<<0<<endl;
                    int k=2;
                      for(pair<int,int> p : ans)
                      {
                        cout<<p.first<<" "<<p.second<<" ";
                         if((n-1)%2!=0 && k!=0)
                         {
                            cout<<p.first<<endl;
                            k--;

                         }else {
                            cout<<p.second<<endl;

                         }
                      }


                 }
       }
}
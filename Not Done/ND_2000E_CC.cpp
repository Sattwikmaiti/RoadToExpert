// https://www.codechef.com/problems/XSQR



#include<bits/stdc++.h>
using namespace std;
#define ll long long int 


ll nc2(int n)
{
    return (n*(n-1))/2;
}

int main()
{
     int t;
     cin>>t;
     while(t--)
     {
            ll n;
            cin>>n;
            ll arr[n];
            //even odd
            map<int,int> mp;

            vector<pair<int,int>> bits;
            for(int i=0;i<33;i++)
            {
                bits.push_back({0,0});
            }
            bool zero=false;

            for(int i=0;i<n;i++)
            {
                cin>>arr[i];
                mp[arr[i]]=1;
                if(arr[i]==0)
                 zero=true;
                int x= arr[i]==0 ? 0 : log2(arr[i])+1   ;


                if(arr[i]%2!=0)
                  bits[x].second++;
                  else bits[x].first++;


                   
            }
            

            ll ans=0;
            set<vector<int>> st;
             if(zero)
             {
                sort(arr,arr+n);

                for(int i=1;i<n;i++)
                {
                     for(int j=i+1;j<n;j++)
                     {
                        if(mp[arr[i]^arr[j]]==1)
                        {
                            vector<int> v;
                            v.push_back(arr[i]);
                            v.push_back(arr[j]);
                            v.push_back(arr[i]^arr[j]);
                            sort(v.begin(),v.end());
                            st.insert(v);
                        }


                     }
                }

             }

             ans+=st.size();

            //  for(int i=2;i<=32;i++)
            //    cout<<i<<" "<<bits[i].first<<" "<<bits[i].second<<endl;
            

             for(int i=2;i<=32;i++)
             {
                



                pair<int,int> p=bits[i];

                if(p.first==0 && p.second==0)
                    continue;
                   
                   
                 
                for(int j=i+1;j<=32;j++)
                {

                    pair<int,int> q=bits[j];
                     if(q.first==0 && q.second==0)
                    continue;

                    ans+= (p.first* p.second *q.first*q.second) ;

                  cout<<i<<" "<<j<<" "<<bits[j].first<<" "<<bits[j].second<<" "<<bits[i].first<<" "<<bits[i].second<<endl;

                    vector<int> pro={p.first,p.second,q.first,q.second};
                    for(int i=0;i<pro.size();i++)
                     {
                        for(int j=i+1;j<pro.size();j++)
                        {
                            ans+=nc2(pro[i])*nc2(pro[j]);
                        }
                     }
                    

                }
             }


             cout<<ans*24<<endl;
           


     }
}
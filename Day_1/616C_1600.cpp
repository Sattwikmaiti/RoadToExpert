#include <bits/stdc++.h>
using namespace std;

#define ll long long int

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
    int n, m;
    cin >> n >> m;


    for(int i=0;i<=1000000;i++)
    {
        parent[i]=i;
        size[i]=1;
    }

    char arr[n][m];
    int pos[n][m];

    int k = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            
            pos[i][j] = k;
            k++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (arr[i][j] == '*')
                continue;

            if (i + 1 < n && arr[i + 1][j] == '.')
            {
                merge(pos[i][j], pos[i + 1][j]);
            }
            if (j + 1 < m && arr[i][j + 1] == '.')
            {
                merge(pos[i][j], pos[i][j + 1]);
            }
            if (i - 1 >= 0 && arr[i - 1][j] == '.')
            {
                merge(pos[i][j], pos[i - 1][j]);
            }
            if (j - 1 >= 0 && arr[i][j - 1] == '.')
            {
                merge(pos[i][j], pos[i][j - 1]);
            }
        }
    }


//     for(int i=0;i<n;i++)
//     { 
//         for(int j=0;j<n;j++)
//         { 
//             cout<<size[parent[pos[i][j]]]<<" ";
//         }
//         cout<<endl;
//     }

//   cout<<endl;
//        for(int i=0;i<n;i++)
//     { 
//         for(int j=0;j<n;j++)
//         { 
//             cout<<parent[pos[i][j]]<<" ";
//         }
//         cout<<endl;
//     }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.')
            {
                cout << ".";
                continue;
            }

            ll s=0;

            set<int> ulps;

            if(i+1<n && arr[i+1][j]=='.')
            {
                      ulps.insert(ulp(parent[pos[i+1][j]]));
            }
            if(j+1<m && arr[i][j+1]=='.')
            {
                      ulps.insert(ulp(parent[pos[i][j+1]]));
            }
            if(i-1>=0 && arr[i-1][j]=='.')
            {
                      ulps.insert(ulp(parent[pos[i-1][j]]));
            }
            if(j-1>=0 && arr[i][j-1]=='.')
            {
                      ulps.insert(ulp(parent[pos[i][j-1]]));
            }

            for(auto x:ulps)
            {
                s+=size[x];
            }
            s++;

            cout<<s%10;

        }
        cout<<endl;
    }
}
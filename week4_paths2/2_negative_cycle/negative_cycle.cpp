#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
using namespace std;

const int inf = numeric_limits<int>::max();

int isCyclic(int start, int v, int visited[], int recStack[], vector<vector<int> > &adj, std::vector<int> &ans)
{
  int i,j;
  if(visited[v] == 0)
  {
    visited[v] = 1;
    recStack[v] = 1;

    for(i=0; i<adj[v].size(); i++)
    {
      int u = adj[v][i];
      // if(!visited[u] && isCyclic(start, u, visited, recStack, adj, ans))
      // {
      //   ans.push_back(u+1);
      //   return 1;
      // }
      // else if(recStack[u])
      // {
      //   ans.push_back(u+1);
      //   return 1;
      // }

      // if(u == start)
      // {
      //   ans.push_back(u+1);
      //   return 1;
      // }
      // else
      {
        int k = isCyclic(start, u, visited, recStack, adj, ans);
        if(k == 1)
        {
          ans.push_back(v+1);
          return 1;
        }
      }
    }
  }
  else
  {
    if(v == start)
    {
      ans.push_back(v+1);
      return 1;
    }
  }

  recStack[v] = 0;
  return 0;
}

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here

  // int i,j,k,n;
  // n = adj.size();

  // int visited[n] = {0};
  // int recStack[n] = {0};
  // std::vector<int> ans;

  // for(i=0; i<n; i++)
  // {
  //   ans.clear();
  //   for(j=0; j<n; j++)
  //   {
  //       recStack[j] = visited[j] = 0;
  //   }
  //   if(isCyclic(i, i, visited, recStack, adj, ans))
  //   {
  //     // cout<<"for "<<i+1<<"\n";
  //     // for(j=0; j<n; j++)
  //     // {
  //     //   if(recStack[j])
  //     //     cout<<j+1<<" ";
  //     // }
  //     // cout<<"\n";
  //     // return 1;

  //     // for(j=0; j<ans.size(); j++)
  //     // {
  //     //   cout<<ans[j]<<" ";
  //     // }
  //     // cout<<"\n";

  //     int total = 0;
  //     for(j=ans.size()-1; j>0; j--)
  //     {
  //       int p = ans[j] - 1;
  //       int q = ans[j-1] - 1;
  //       for(k=0; k<adj[p].size(); k++)
  //       {
  //         if(adj[p][k] == q);
  //           break;
  //       }
  //       total += cost[p][k];
  //     }
  //     // cout<<"total = "<<total<<"\n";
  //     if(total < 0)
  //     {
  //       return 1;
  //     }
  //   }
  // }

  // return 0;

  vector<long> dist(adj.size(), inf);
  dist[0] = 0;
  for (int i = 0; i < adj.size(); i++) 
  {
      for(int u = 0; u < adj.size(); u++)
      {
        for (int k = 0; k < adj[u].size(); k++) 
        {
          int v = adj[u][k];
          if(dist[v] > dist[u] + cost[u][k]) 
          {
            dist[v] = dist[u] + cost[u][k];
            if(i == adj.size() - 1) 
              return 1;
          }
        }
     }
  }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost) << "\n";
}

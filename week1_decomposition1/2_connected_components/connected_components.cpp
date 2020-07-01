#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::vector;
using std::pair;
using namespace std;

void func(vector<vector<int> > &adj,int visited[], int x)
{
  visited[x] = 1;
  int i;
  for(i=0; i<adj[x].size(); i++)
  {
    if(visited[adj[x][i]] == 0)
    {
      func(adj, visited, adj[x][i]);
    }
  }
}
int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  //write your code here
  int n = adj.size();
  int visited[n] = {0};
  int i;

  while(1)
  {
    for(i=0; i<n; i++)
    {
      if(visited[i] == 0)
      {
        res++;
        func(adj, visited, i);
      }
    }
    int flag = 0;
    for(i=0; i<n; i++)
    {
      if(visited[i] == 0)
        flag = 1;
    }
    if(flag == 0)
    {
      break;
    }
  }
  
  return res;
}


int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}

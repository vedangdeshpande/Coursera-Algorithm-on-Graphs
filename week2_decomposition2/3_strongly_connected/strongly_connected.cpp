#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using std::vector;
using std::pair;
using namespace std;

vector<vector<int> > reversetheEdges(vector<vector<int> > &adj)
{
  vector<vector<int> > reverseadj(adj.size(), vector<int>());
  for(int i = 0; i < adj.size(); i++)
  {  
    for(int j = 0; j < adj[i].size(); j++)
    {
     reverseadj[adj[i][j]].pb(i);
     }
  }
  return reverseadj;
}

void dfs(vector<vector<int> > &adj, int x, vector<int> &visited, stack<int> &st)
{ 
  visited[x] = 1;
    
  for (int i = 0; i < adj[x].size(); i++) 
  {
      if(!visited[adj[x][i]])
      {
        visited[adj[x][i]] = 1;
        dfs(adj, adj[x][i], visited, st);
      } 
  }
   
  st.push(x);
}

int number_of_strongly_connected_components(vector<vector<int> > adj) 
{
  int result = 0;
  stack<int> st;
   
  vector<int> visited(adj.size(), 0);
  
  int i;
  for (i = 0; i < adj.size(); i++)
  {
    if(!visited[i])
    {
    dfs(adj, i, visited, st);
    }
  }
    
  vector<vector<int> > reverseadj = reversetheEdges(adj);
  
  for(i = 0; i < adj.size(); i++) 
  {
    visited[i] = 0;
  }
  
  
  while (!st.empty()) 
  {
    int x = st.top();
    st.pop();
 
    if (!visited[x]) 
    {
      stack<int> componentst;
      dfs(reverseadj, x, visited, componentst);
      result++;
    }
  }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj);
}


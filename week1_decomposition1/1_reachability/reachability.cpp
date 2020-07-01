#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::vector;
using std::pair;
using namespace std;


int reach(vector<vector<int> > &adj, int x, int y,int visited[]) {
  //write your code here
	int i;
	if(visited[x] == 1)
	{
		return 0;
	}
	visited[x] = 1;
	for(i=0; i<adj[x].size(); i++)
	{
		if(adj[x][i] == y)
		{
			return 1;
		}
		else
		{
			//cout<<x<<" "<<y<<" "<<adj[x][i]<<endl;
			int ans = reach(adj, adj[x][i], y, visited);
			if(ans == 1)
				return 1;
		}
	}
  return 0;
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
  int visited[n] = {0};
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1, visited)<<endl;
}

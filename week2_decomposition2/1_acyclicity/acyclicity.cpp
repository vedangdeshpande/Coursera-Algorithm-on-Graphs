#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
using std::vector;
using std::pair;
using namespace std;

int iscyclic(int x, int visited[], int stack[], vector<vector<int> > &adj)
{
	// cout<<x+1<<endl;
	int i;
	if(visited[x] == 0)
	{
		visited[x] = 1;
		stack[x] = 1;

		for(i=0; i<adj[x].size(); i++)
		{
			int r = stack[adj[x][i]];
			int p = visited[adj[x][i]];
			int q = iscyclic(adj[x][i], visited, stack, adj);
			
			//cout<<adj[x][i]+1<<" p = "<<p<<" q = "<<q<<" r = "<<r<<endl;
			if((p == 0) && (q == 1))
			{
				// cout<<"hi "<<x<<endl;
				// cout<<adj[x][i]+1<<endl;
				return 1;
			}	
			else if(r == 1)
			{
				// cout<<"hi "<<x<<endl;
				// cout<<adj[x][i]+1<<endl;
				return 1;
			}
			else
			{

			}
		}
	}

	// if(stack[x] == 1)
	// 	return 1;

	stack[x] = 0;

	return 0;
}
int acyclic(vector<vector<int> > &adj, int n) {
  //write your code here

	int visited[n] = {0};
	int stack[n] = {0};
	int i;
	for(i=0; i<n; i++)
	{
		int a = iscyclic(i, visited, stack, adj);
		if(a == 1)
		{
			//cout<<"answer by "<<i+1<<endl;
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
  }

  // for(int i=0; i<n; i++)
  // {
  // 	cout<<i+1<<" - ";
  // 	for(int j=0; j<adj[i].size(); j++)
  // 	{
  // 		cout<<adj[i][j]+1<<" ";
  // 	}
  // 	cout<<endl;
  // }

  std::cout << acyclic(adj, n)<<endl;
}

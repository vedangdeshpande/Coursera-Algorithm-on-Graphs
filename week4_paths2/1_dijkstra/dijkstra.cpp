#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using namespace std;
#define MAX 100005

int minDistance(int dist[], int sptset[], int v)
{
	int min = MAX;
	int min_index, i;

	for(i=0; i<v; i++)
	{
		if(sptset[i] == 0 && dist[i] <= min)
		{
			min = dist[i];
			min_index = i;
		}
	}

	return min_index;
}

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t, int v) {
  //write your code here

	int i,j,k;
	int dist[v],sptset[v];

	for(i=0; i<v; i++)
	{
		dist[i] = MAX;
		sptset[i] = 0;
	}
	dist[s] = 0;

	for(i=0; i<v-1; i++)
	{
		int x = minDistance(dist, sptset, v);
		sptset[x] = 1;

		for(j=0; j<adj[x].size(); j++)
		{
			int y = adj[x][j];
			if(!sptset[y])
			{
				if(dist[x] != MAX && dist[x] + cost[x][j] < dist[y])
				{
					dist[y] = cost[x][j] + dist[x];
				}
			}
		}
	}

  if(dist[t] == MAX)
  {
  	return -1;
  }
  
  return dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t, n);
}

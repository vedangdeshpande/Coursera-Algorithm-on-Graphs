#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using std::vector;
using namespace std;

double inf = numeric_limits<int>::max();

void minInd(vector<vector<double>> &dist, int mini, int minj)
{
	double min = inf;
	int i,j;
	int n = dist.size();
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(min > dist[i][j])
			{
				min = dist[i][j];
				mini = i; 
				minj = j;
			}
		}
	}
}

int cycle(int x, int adj[])
{
	while(adj[x] != x)
	{
		adj[x] = adj[adj[x]];
		x = adj[x];
	}
	return x;
}

void unionthem(int i, int j, int adj[])
{
	int x = cycle(i, adj);
	int y = cycle(j, adj);
	adj[x] = adj[y];
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here

  int i,j,x1,x2,y1,y2;
  int n = x.size();
  vector<vector<double>> dist(n, vector<double>(n));
  for(i=0; i<n; i++)
  {
  	for(j=0; j<n; j++)
  	{	
  		if(i == j)
  		{
  			dist[i][j] = inf;
  			continue;
  		}
  		x1 = x[i];
  		y1 = y[i];
  		x2 = x[j];
  		y2 = y[j];
  		dist[i][j] = (double)pow((pow(x1-x2, 2) + pow(y1-y2, 2)), 0.5);
  	}
  }

  int mini,minj;
  int adj[n];
  for(i=0; i<n; i++)
  {
  	adj[i] = i;
  }

  int count = 1;
  while(count < n)
  {	
  	// minInd(dist, mini, minj);
  	double min = inf;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(min > dist[i][j])
			{
				min = dist[i][j];
				mini = i; 
				minj = j;
			}
		}
	}
	dist[mini][minj] = inf;
  	if(cycle(mini, adj) != cycle(minj, adj))
  	{
  		result += min;
  		unionthem(mini, minj, adj);
  		count++;
  	}
  }

  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}

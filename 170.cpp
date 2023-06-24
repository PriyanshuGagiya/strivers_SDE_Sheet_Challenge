#include <bits/stdc++.h> 

//https://www.codingninjas.com/studio/problems/kruskal-s-minimum-spanning-tree-algorithm_8230804?challengeSlug=striver-sde-challenge&leftPanelTab=1
class Disjoint {
private:
  vector<int> parent, size;

public:
  Disjoint(int n) 
  {
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
      parent[i] = i;
    size.resize(n + 1, 1);
  }

  int findParent(int node) 
  {
    if (node == parent[node])
      return node;
    return parent[node] = findParent(parent[node]);
  }

  void unionBySize(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);

    if (size[pu] > size[v]) {
      parent[pv] = pu;
      size[pu] += size[pv];
    } else {
      parent[pu] = pv;
      size[pv] += size[pu];
    }
  }
};
bool cmp(vector<int> &a, vector<int> &b)
{
	return a[2] < b[2];
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) 
{
  sort(graph.begin(), graph.end(),cmp);
  Disjoint d(n);
  int sum = 0;
  for (auto i : graph) 
  {
    int wt = i[2], u = i[0], v = i[1];
    if (d.findParent(u) != d.findParent(v)) 
	{
      sum += wt;
      d.unionBySize(u, v);
    }
  }

  return sum;
}

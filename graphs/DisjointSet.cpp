#include <bits/stdc++.h>
using namespace std;


class DisjointSet {
	vector<int> rank, parent, size;
public:
	DisjointSet(int n) {
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
		size.resize(n + 1, 1);
		for (int i = 0; i <= n ; i++) {
			parent[i] = i;
		}
	}
	int findUltimateParent(int u) {
		if (parent[u] == u) {
			return u;
		}
		return parent[u] = findUltimateParent(parent[u]);
	}
	void unionByRank(int u, int v) {
		int ulp_u = findUltimateParent(u);
		int ulp_v = findUltimateParent(v);

		if (rank[ulp_u] < rank[ulp_v]) {
			parent[ulp_u] = ulp_v;
		}
		else if (rank[ulp_v] < rank[ulp_u]) {
			parent[ulp_v] = ulp_u;
		}
		else {
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}
	}
	void unionBySize(int u, int v) {
		if (size[u] < size[v]) {
			parent[u] = v;
			size[v] += size[u];
		}
		else {
			parent[v] = u;
			size[u] += size[v];
		}
	}
	void print(int n) {
		cout << "Printing rank" << endl;
		for (int i = 1; i <= n; i++) {
			cout << rank[i] << " ";
		}
		cout << endl;
		cout << "Printing parent" << endl;
		for (int i = 1; i <= n; ++i)
		{
			cout << parent[i] << " ";
		}`
		cout << endl;
	}

};


int main() {

	DisjointSet ds(7);
	ds.unionByRank(1, 2);
	ds.unionByRank(2, 3);
	ds.unionByRank(4, 5);
	ds.unionByRank(6, 7);
	ds.unionByRank(5, 6);
	if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
		cout << "Same" << endl;
	}
	else cout << "Not Same" << endl;
	ds.unionByRank(3, 7);
	if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
		cout << "Same" << endl;
	}
	else cout << "Not Same" << endl;
	ds.print(7);


}
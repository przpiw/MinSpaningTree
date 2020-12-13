
class UnionFind
{
	std::vector<size_t> rank;
	std::vector<size_t> parent;

public:
	void init(size_t n) {
		rank.resize(n);
		parent.resize(n);

		for (size_t i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 0;
		}

	}
	size_t find(size_t n) {
		/*while (parent[n] != n) {
			n = parent[n];
		}
		return n;
*/
		if (parent[n] == n)
			return n;
		size_t r = find(parent[n]);
		parent[n] = r;
		return r;
	}
	void merge(size_t x, size_t y) {
		size_t rx = find(x);
		size_t ry = find(y);

		if (rank[rx] > rank[ry]) {
			parent[ry] = rx;
		}
		else if (rank[rx] < rank[ry]) {
			parent[rx] = ry;
		}
		else {
			parent[rx] = ry;
			rank[rx] += 1;
		}
	}

};


#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <iostream>
#include <vector>

class UnionFind {
	public:
		UnionFind(int);
		int find(int);
		void unite(int i, int j);

	private:
		std::vector<int> parent;
		std::vector<int> rank;
};

#endif

#include "UnionFind.tpp"
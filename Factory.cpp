#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <queue>
#include "Graph.h"
#include <functional>
#include "MaxHeap.h"
#include "UnionFind.h"
#include "MinSpanTreeAlgorithm.h"
#include "Kruskal.h"
#include "KruskalUF.h"
#include "Prim1.h"
#include "Prim2.h"
#include "Prim3.h"
#include "Factory.h"

	MinSpanTreeAlgorithm* Factory::create(AlgorithmFamily family, size_t vertexCount) {
		if (family == AlgorithmFamily::PRIM)
		{
			if (vertexCount < 10) {
				return new Prim1();
			}
			else
				return new Prim3();
		}

		if(family == AlgorithmFamily::KRUSKAL)
		{
			if (vertexCount < 10) {
				return new Kruskal();
			}
			else
				return new KruskalUF();
		}

	};

#include <iostream>
#include <fstream>
#include <vector>
#include "Graph.h"
#include "MinSpanTreeAlgorithm.h"
#include "Factory.h"












int main()
{
	Graph *g = Graph::load("graph1.txt");
	g->print();
	MinSpanTreeAlgorithm *alg = Factory::create(Factory::PRIM, g->vertices.size());
	std::vector<Edge*> r = alg->start(g);
	//Prim3 p;
	//std::vector<Edge*> r = p.start(g);
	//MaxHeap<int> heap;
	/*int t[10];
	heap.insert(t, 0, 5);
	heap.insert(t, 1, 1);
	heap.insert(t, 2, 2);
	heap.insert(t, 3, 7);
	heap.insert(t, 4, 15);
	heap.insert(t, 5, 8);*/

	

	for (size_t i = 0; i < r.size(); i++) {
		std::cout << i + 1 << " ";
		std::cout << r[i]->source->index << " ";

		std::cout << r[i]->dest->index << " ";
		std::cout << r[i]->weight << std::endl;
	}
	delete alg;
	system("Pause");
	return 0;
}

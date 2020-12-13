class Prim2 : public MinSpanTreeAlgorithm {
	std::set<Edge*> edges;
	std::vector<bool> inTree;
	std::vector<Edge*> d;
public:
	std::vector<Edge*> start(Graph *g) override{
		Vertex *start = g->vertices[0];

		inTree.resize(g->vertices.size());
		for (size_t i = 0; i < inTree.size(); i++) {
			inTree[i] = 0;
		}
		inTree[0] = 1;

		/*for (size_t k = 0; k < edges.size(); k++) {

		}*/
		auto comp = [](Edge *e1, Edge*e2) {return e1->weight > e2->weight; };
		std::priority_queue <Edge*, std::vector<Edge*>, decltype(comp)> pq(comp);
		for (size_t j = 0; j < start->edges.size(); j++) {
			pq.push(start->edges[j]);
		}

		while (!pq.empty()) {
			int min = std::numeric_limits<int>::max();
			std::set<Edge*>::iterator min_it;
			Edge * minEdge = pq.top();
			pq.pop();
			if (!inTree[minEdge->dest->index] || !inTree[minEdge->source->index]) {
				d.push_back(minEdge);
				if (d.size() == g->vertices.size() - 1)
					break;
				inTree[minEdge->dest->index] = true;
				inTree[minEdge->source->index] = true;
				for (size_t l = 0; l < minEdge->dest->edges.size(); l++) {
					pq.push(minEdge->dest->edges[l]);
				}
			}
		}
		return d;
	}
};

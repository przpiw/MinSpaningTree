class Prim1:public MinSpanTreeAlgorithm {
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
		for (size_t j = 0; j < start->edges.size(); j++) {
			edges.insert(start->edges[j]);
		}
		/*for (size_t k = 0; k < edges.size(); k++) {

		}*/
		while (!edges.empty() && d.size() != g->vertices.size() - 1) {
			int min = std::numeric_limits<int>::max();
			std::set<Edge*>::iterator min_it;
			for (std::set<Edge*>::iterator it = edges.begin(), e = edges.end(); it != e;) {
				Edge *ed = *it;
				if (!inTree[ed->dest->index] || !inTree[ed->dest->index]) {
					if (ed->weight < min) {
						min = ed->weight;
						min_it = it;
					}
					++it;
				}
				else
					it = edges.erase(it);
			}
			d.push_back(*min_it);
			inTree[(*min_it)->dest->index] = true;
			inTree[(*min_it)->source->index] = true;
			for (size_t l = 0; l < (*min_it)->dest->edges.size(); l++) {
				edges.insert((*min_it)->dest->edges[l]);
			}
		}
		return d;
	}
};
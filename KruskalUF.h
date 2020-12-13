class KruskalUF:public MinSpanTreeAlgorithm {
public:
	std::vector<Edge*> start(Graph *graph) override{
		std::vector<Edge*> edges;
		for (size_t i = 0; i < graph->vertices.size(); i++) {
			Vertex *v = graph->vertices[i];
			for (size_t j = 0; j < v->edges.size(); j++) {
				if (v->edges[j]->source == v)
					edges.push_back(v->edges[j]);
			}
		}
		std::sort(edges.begin(), edges.end(), [](Edge* e1, Edge* e2) {return e1->weight < e2->weight; });
		UnionFind uf;
		uf.init(graph->vertices.size());

		std::vector<Edge*> minTree;
		for (size_t k = 0; k < edges.size(); k++) {
			size_t dr = uf.find(edges[k]->dest->index);
			size_t sr = uf.find(edges[k]->source->index);

			if (dr != sr) {
				minTree.push_back(edges[k]);
				if (minTree.size() == graph->vertices.size() - 1)
					break;
				uf.merge(dr, sr);
			}
		}
		return minTree;
	}
};
class Kruskal : public MinSpanTreeAlgorithm {
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
		std::vector<size_t> colors;
		colors.resize(graph->vertices.size());
		for (size_t j = 0; j < graph->vertices.size(); j++) {
			colors[j] = j;
		}

		std::vector<Edge*> minTree;
		for (size_t k = 0; k < edges.size(); k++) {
			if (colors[edges[k]->dest->index] != colors[edges[k]->source->index]) {
				minTree.push_back(edges[k]);
				if (minTree.size() == graph->vertices.size() - 1)
					break;
				size_t tempDest = colors[edges[k]->dest->index];
				size_t tempSource = colors[edges[k]->source->index];
				for (size_t l = 0; l < colors.size(); l++) {
					if (colors[l] == tempDest)
						colors[l] = tempSource;
				}
			}
		}
		return minTree;

	}
};

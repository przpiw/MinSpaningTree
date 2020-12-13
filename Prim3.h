class Prim3 : public MinSpanTreeAlgorithm {
	std::set<Edge*> edges;
	std::vector<bool> inTree;
	std::vector<Edge*> d;
public:


	std::vector<Edge*> start(Graph *g) override {
		struct VertexData {
			Vertex *v;
			Edge *e;
			size_t index;
			bool inTree;
		};

		//std::priority_queue <VertexData*, std::vector<VertexData*>, decltype(comp)> pq(comp);
		class PrimMaxHeap :public MaxHeap<VertexData*, std::function<bool(VertexData*, VertexData*)>> {
		public:
			PrimMaxHeap(std::function<bool(VertexData*, VertexData*)> comp) :MaxHeap(comp) {
			}
			void itemMoved(VertexData* &item, size_t newIndex) override {
				item->index = newIndex;
			}
		};
		std::vector<VertexData> vdata;
		vdata.resize(g->vertices.size());
		for (size_t i = 0; i < vdata.size(); i++) {
			vdata[i].v = g->vertices[i];
			vdata[i].e = nullptr;
			vdata[i].inTree = false;
		}

		Vertex *start = g->vertices[0];


		auto comp = [](VertexData *vd1, VertexData*vd2) {
			if (!vd1->e)
				return true;
			if (!vd2->e)
				return false;
			return vd1->e->weight > vd2->e->weight; };
		PrimMaxHeap heap(comp);
		std::vector<VertexData*> tvertexData;
		tvertexData.resize(g->vertices.size());

		vdata[0].inTree = true;
		heap.insert(&tvertexData[0], 0, &vdata[0]);
		size_t heapSize = 1;


		while (heapSize) {
			int min = std::numeric_limits<int>::max();
			std::set<Edge*>::iterator min_it;
			VertexData * vd = heap.removeTop(&tvertexData[0], heapSize);
			heapSize--;
			vd->inTree = true;
			if (vd->e != nullptr) {
				d.push_back(vd->e);
				std::cout << vd->v->index << std::endl;
			}
			for (size_t l = 0; l < vd->v->edges.size(); l++) {
				Vertex *neighbour;
				if (vd->v->edges[l]->source == vd->v)
					neighbour = vd->v->edges[l]->dest;
				else
					neighbour = vd->v->edges[l]->source;
				VertexData *nData = &vdata[neighbour->index];
				if (!nData->inTree) {
					if (nData->e == nullptr) {
						nData->e = vd->v->edges[l];
						heap.insert(&tvertexData[0], heapSize, nData);
						heapSize++;
					}
					else {
						if (nData->e->weight > vd->v->edges[l]->weight) {
							nData->e = vd->v->edges[l];
							heap.increasedKey(&tvertexData[0], nData->index);
						}
					}
				}
			}

		}
		return d;
	}

};
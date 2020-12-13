class Vertex;
class Edge {
public:
	Vertex *dest;
	Vertex *source;
	size_t weight;
};
class Vertex {
public:
	std::vector<Edge*> edges;
	size_t index;

};

//class Heap {
//	int capacity;
//	int curSize;
//	int *arr;
//public:
//	Heap(int cap) {
//		curSize = 0;
//		capacity = cap;
//		arr = new int[cap];
//	}
//
//	void insertKey(int k) {
//		if(curSize == capacity)
//			throw std::runtime_error("Could not insert");
//
//		curSize++;
//		
//	
//};

class Graph {
public:
	Graph(size_t vertexCount) {
		vertices.resize(vertexCount);
		for (size_t i = 0; i < vertexCount; i++) {
			vertices[i] = new Vertex();
			vertices[i]->index = i;
		}
	}

	void connect(size_t x, size_t y, size_t weight) {
		if (x == y) {
			throw std::invalid_argument("Invalid Argument");
		}
		Edge *edge = new Edge();
		edge->source = vertices[x];
		edge->dest = vertices[y];
		edge->weight = weight;
		vertices[x]->edges.push_back(edge);
		vertices[y]->edges.push_back(edge);

	}
	void disconnect(Edge *e) {
		for (size_t i = 0; i < e->dest->edges.size(); i++) {
			if (e->dest->edges[i] == e) {
				e->dest->edges.erase(e->dest->edges.begin() + i);
				break;
			}
		}
		for (size_t j = 0; j < e->source->edges.size(); j++) {
			if (e->source->edges[j] == e) {
				e->source->edges.erase(e->source->edges.begin() + j);
				break;
			}
		}
		delete e;

	}
	static Graph* load(const std::string path) {
		std::ifstream in;
		in.open(path);
		if (!in.is_open()) {
			throw std::runtime_error("Could not open the file");
		}
		size_t vertexCount;
		in >> vertexCount;
		Graph *graph = new Graph(vertexCount);
		while (true) {
			int from;
			int to;
			int weight;
			in >> from;
			in >> to;
			in >> weight;
			if (!in)
				break;
			graph->connect(from - 1, to - 1, weight);
		}
		in.close();
		return graph;
	}
	~Graph() {
		for (size_t i = 0; i < vertices.size(); i++) {
			while (vertices[i]->edges.size()) {
				disconnect(vertices[i]->edges.front());
			}
		}
		for (size_t j = 0; j < vertices.size(); j++) {
			delete vertices[j];
		}
	}

	void print() {
		for (size_t i = 0; i < vertices.size(); i++) {
			Vertex *v = vertices[i];
			for (size_t j = 0; j < v->edges.size(); j++) {
				std::cout << i + 1 << " ";
				std::cout << v->edges[j]->dest->index << " ";
				std::cout << v->edges[j]->weight << std::endl;
			}
		}
	}
	std::vector<Vertex*> vertices;

};
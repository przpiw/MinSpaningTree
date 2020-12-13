class Factory {
public:
	enum AlgorithmFamily{
		KRUSKAL,PRIM
	};
	static MinSpanTreeAlgorithm* create(AlgorithmFamily family, size_t vertexCount);
};
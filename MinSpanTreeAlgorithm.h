
class MinSpanTreeAlgorithm {
public:
	virtual std::vector<Edge*> start(Graph *g) = 0;
	virtual ~MinSpanTreeAlgorithm() = default;
};
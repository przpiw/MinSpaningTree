#pragma once

template <class T,class Compare=std::less<T>> class MaxHeap
{
public:
	MaxHeap(Compare c = std::less<T>()) {
		_c = c;
	}
	void pushUp(T *t, size_t index) {
		size_t parent = (index - 1) / 2;
		while (index > 0 && _c(t[parent], t[index])) {
			std::swap(t[parent], t[index]);
			itemMoved(t[parent], parent);
			itemMoved(t[index], index);
			index = parent;
			parent = (index - 1) / 2;
		}
	}
	virtual void itemMoved(T &item, size_t newIndex) {}
	void increasedKey(T *heap, size_t itemIndex) {
		pushUp(heap, itemIndex);
	}
	
	void pushDown(T *t,size_t heapSize, size_t index) {
		while (true) {
			size_t lchild = 2 * index + 1;
			size_t rchild = 2 * index + 2;
			size_t max = index;
			if (lchild < heapSize && _c(t[index], t[lchild])) {
				max = lchild;
			}
			if (rchild < heapSize && _c(t[max], t[rchild])) {
				max = rchild;
			}

			if (max != index) {
				std::swap(t[max], t[index]);
				itemMoved(t[max], max);
				itemMoved(t[index], index);
				index = max;
			}
			else
				break;
		}
	}

	T&& removeTop(T *t, size_t heapSize) {
		std::swap(t[0], t[heapSize-1]);
		itemMoved(t[0], 0);
		itemMoved(t[heapSize - 1], heapSize-1);
		pushDown(t, heapSize, 0);
		return std::move(t[heapSize - 1]);
	}

	void insert(T *t, size_t heapSize, const T& element) {
		t[heapSize] = element;
		itemMoved(t[heapSize], heapSize);
		pushUp(t,heapSize);
	}

	
	Compare _c;
};


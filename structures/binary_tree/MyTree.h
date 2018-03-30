#include <vector>



template<class T>
struct Node;

template<class T>
using NodePtr = Node<T> *;

template<class T>
struct Node{
	T data;
	std::vector<NodePtr<T>> children;
	
}


template<class T>
struct Tree{
	NodePtr<T> root;
}

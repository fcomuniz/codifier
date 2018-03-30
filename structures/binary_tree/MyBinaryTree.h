
template<class T>
struct MyBinaryTreeNode;

template<class T>
using MBTNPtr = MyBinaryTreeNode<T> *;


template<class T>
struct MyBinaryTreeNode{
	MyBinaryTreeNode(): left(nullptr), right(nullptr){

	}
	MyBinaryTreeNode(T data):data(data),left(nullptr), right(nullptr){

	}
	virtual ~MyBinaryTreeNode(){
		delete left;
		delete right;
		left = nullptr;
		right = nullptr;
	}

	T data;
	MBTNPtr<T> left = nullptr;
	
	MBTNPtr<T> right = nullptr;
};

template<class T, typename F>
void inOrderTraversal(MBTNPtr<T> node, F visitFunction){
	if(node != nullptr){
		inOrderTraversal(node->left, visitFunction);
		visitFunction(node);
		inOrderTraversal(node->right,visitFunction);
	}	
}

template<class T, typename F>
void preOrderTraversal(MBTNPtr<T> node, F visitFunction){
	if(node != nullptr){
		visitFunction(node);
		preOrderTraversal(node->left,visitFunction);
		preOrderTraversal(node->right,visitFunction);
	}
}
template<class T, typename F>
void postOrderTraversal(MBTNPtr<T> node, F visitFunction){
	if(node != nullptr){
		postOrderTraversal(node->right,visitFunction);
		visitFunction(node);
		postOrderTraversal(node->left, visitFunction);
	}	
}


template<class T>
MBTNPtr<T> findLowestCommonAncestorBST(MBTNPtr<T> root, T value1, T value2){
	auto auxval = value1;
	value1 = min(value1, value2);
	value2 = max(auxval,value2);
	while(root != nullptr){
		T currVal = root->data;			
		if(currVal >= value1 && currVal <= value2 ){
			return root;
		} else if(currVal < value1){
			root = root->left;
		} else {
			root = root->right;
		}
	}	
	return root;
}

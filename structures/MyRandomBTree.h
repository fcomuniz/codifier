#include <iostream>
#include <random>
#include <vector>

template<class T>
struct mrbtn;

template<class T>
using MRBPtr = mrbtn<T>*; 

template<class T>
struct mrbtn{
	int count = 1;
	T data;
	MRBPtr<T> left = nullptr;
	MRBPtr<T> right = nullptr;

};

template<class T>
struct MyRandomBinaryTree{
	private:
	
	MRBPtr<T> head = nullptr;
	std::random_device rd;
	std::mt19937 gen;
	MRBPtr<T> getRandomNode(MRBPtr<T> ptr){
		if(ptr == nullptr) return ptr;
		int count = ptr->count;
		int leftcount = 0, rightcount = 0;			
		if(ptr->left != nullptr) leftcount = ptr->left->count;
		if(ptr->right != nullptr) rightcount = ptr->right->count;
		std::uniform_int_distribution<> dis(1,count);	
		auto val = dis(gen);
		if(val == 1){
			return ptr;
		}else if(val > 1 && val <= leftcount){
			return getRandomNode(ptr->left);
		}else {
			return getRandomNode(ptr->right);
		}
	}
	public:
	MyRandomBinaryTree() : gen(rd){

	}
	MRBPtr<T> getRandomNode(){
		return getRandomNode(ptr);
	}

}

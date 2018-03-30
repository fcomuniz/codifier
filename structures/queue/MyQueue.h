#include <iostream>
#include <sstream>
#include <vector>

template<class T>
struct QueueNode;

template<class T>
using QNPtr = QueueNode<T> *;
template <class T>
struct QueueNode{
	T data;
	QNPtr<T> next = nullptr;
	QueueNode(T data) : data(data), next(nullptr){

	}
	QueueNode(): next(nullptr){

	}
	virtual ~QueueNode(){
		delete next;
		next = nullptr;
	}
};
template <class T>
class MyQueue{

	QNPtr<T> first = nullptr;
	QNPtr<T> last = nullptr;

	public:
	virtual ~MyQueue(){

	}
	void add(T data){
		auto t = new QueueNode<T>(data);
		if (last != nullptr){
			last->next = t;
		}
		last = t;
		if(first == nullptr){
			first = last;
		}
	}
	T remove(){
		if (first == nullptr) throw std::runtime_error("The Queue is empty, can't remove element");
		T data = first->data;
		first = first->next;
		if(first == nullptr){
			last = nullptr;	
		}
		return data;
	}

	T peek(){
		if(first == nullptr) throw std::runtime_error("The Queue is empty, can't peek element");
		return first->data;
	}

	bool isEmpty(){
		return first == nullptr;
	}

};


template<class T>
MyQueue<T> readQueue(std::istream & stream){
	std::string a;
	std::getline(stream,a);
	std::stringstream ss;
	ss.str(a);
	MyQueue<T> mq;
	T data;
	while(ss >> data){
		mq.add(data);
	}
	return mq;
}



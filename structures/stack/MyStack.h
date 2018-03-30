#include <iostream>
#include <sstream>
#include <vector>


template<class T>
struct StackNode;

template<class T>
using SNPtr = StackNode<T> *;

template <class T>
struct StackNode{
	T data;
	SNPtr<T> next;
	StackNode(T data) : data(data), next(nullptr){

	}
	StackNode(): next(nullptr){

	}
	virtual ~StackNode(){
		delete next;
		next = nullptr;
	}
	std::ostream & operator<<(std::ostream & stream){
		stream << " " << data;
		if(next != nullptr){
			next->operator<<(stream);
		}
		return stream;
	}
};

template <class T>
class MyStack{
	SNPtr<T> top = nullptr;
	const int maxSize = 10000;
	int amount = 0;

	public:
	MyStack() : maxSize(100000){

	}

	T pop(){
		if(top == nullptr) throw std::runtime_error("popped empty stack");
		T item = top->data;
		auto aux = top;
		top = top->next;
		aux->next = nullptr;
		delete aux;
		amount--;
		return item;
	}
	void push(T data){
		if(amount == maxSize) throw std::runtime_error("stack full, can't push more data into it");
		auto node = new StackNode<T>(data);
		node->next = top;
		top = node;
		amount++;
	}
	T peek(){
		if(top == nullptr) throw std::runtime_error("peeked empty stack");

		return top->data;
	}
	bool isEmpty(){
		return top == nullptr;
	}
	bool isFull(){
		return amount == maxSize;
	}
	std::ostream & operator<<(std::ostream & stream)
	{
		top->operator<<(stream);
		return stream << std::endl;
	}
};


template<typename T>
class SetOfStacks{
	std::vector<MyStack<T>> stacks;
	public:
	void push(T data){
		if(isEmpty()) stacks.push_back(MyStack<T>());
		if(stacks.back().isFull()) stacks.push_back(MyStack<T>());		    auto & stackToAdd = stacks.back();
		stackToAdd.push(data);
	}
	T pop(){
		if(isEmpty()) throw std::runtime_error("Can't pop item, set is empty");
		if(stacks.back().isEmpty()) stacks.pop_back();
		auto data = stacks.back().pop();
		if(stacks.back().isEmpty()) stacks.pop_back();
		return data;
	}
	bool isEmpty(){
		return stacks.size() == 0;
	}

	T popAt(int index){
		if(index < 0 || index > stacks.size() -1){
			throw std::out_of_range("Index is out of range for popping the Stacks"); 
		}
		auto data = stacks[index].pop();
		return data;
	}
	T peek(){
		if(stacks.back().isEmpty()) stacks.pop_back();
		return stacks.back().peek();
	}


};

template<typename T>
MyStack<T> readStack(std::istream & stream = std::cin){
	MyStack<T> stack;
	std::stringstream ss;
	std::string a;
	getline(stream,a);
	ss.str(a);
	T data;
	while(ss >> data){
		stack.push(data);
	}
	return stack;
}


template<class T>
void sortStackWithAnotherStack(MyStack<T> & stack){
	if(stack.isEmpty()) return;
	T auxVal = stack.pop();
	MyStack<T> auxStack;
	bool isSorted = false;
	while(!isSorted){
		bool hasSwapped = false;
		while(!stack.isEmpty()){
			if(stack.peek() < auxVal){
				hasSwapped = true;
				auxStack.push(stack.pop());
				stack.push(auxVal);
				while(!auxStack.isEmpty()){
					stack.push(auxStack.pop());
				}

			} else {
				auxStack.push(auxVal);
			}
			auxVal = stack.pop();
		}
		isSorted = !hasSwapped;
		stack.push(auxVal);	
		while(!auxStack.isEmpty()){
			stack.push(auxStack.pop());
		}
		auxVal = stack.pop();
	}
	stack.push(auxVal);
	
}


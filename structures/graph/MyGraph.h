#include <map>
#include <iostream>
#include <vector>
#include <sstream>
template<class T>
struct MyGraphNode;

template<class T>
using MGNPtr = MyGraphNode<T> *;

template<class T>
struct MyGraphNode{
	MyGraphNode(){}
	MyGraphNode(T data) : data(data){

	}
	T data;
	std::vector<MGNPtr<T>> adj;
	std::vector<MGNPtr<T>> incoming;
	friend std::istream & operator>>(std::istream & stream, MyGraphNode & node){
		return stream >> node.data;
	}
};

template<class T>
struct MyGraph{
	virtual ~MyGraph(){
		clearNodes();
	}
	std::map<T,MGNPtr<T>> nodes;
	void clearNodes(){
		for(auto & val : nodes){
			delete val.second;
			val.second = nullptr;
		}
		nodes.clear();
	}

	
	
	
};

template<class T>
void initializeGraph(MyGraph<T> & graph, std::istream & stream = std::cin){
	 graph.clearNodes();
         std::string a;
	 getline(stream,a);    
	 T val;
	 std::stringstream ss; 
	 ss.str(a);          
	 while(ss >> val){
		 graph.nodes.emplace(std::make_pair(val,new MyGraphNode<T>(val)));
		 
	 }
	 while(getline(stream,a)){
		 ss.clear();
		 ss.str(a);
		 T pos;
		 ss >> pos;
		 try{
			 auto auxPtr = graph.nodes.at(pos);
			 while(ss >> val){
				 auxPtr->adj.push_back(graph.nodes.at(val));
				 
			 }   
			 
		 } catch(std::exception & e){ 
			 std::cerr << e.what() << std::endl;
		 }
		 
	 }
	 return;
}

template<class T>
void printGraph(MyGraph<T> & graph, std::ostream & stream = std::cout){
	for(auto & elem : graph.nodes){
		stream << elem.first << ": ";
			for(auto & auxElem : elem.second->adj){
				stream << auxElem->data << " ";
			
			}   
		stream << std::endl;
	
	}   
		
}




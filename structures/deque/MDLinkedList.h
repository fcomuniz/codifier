
template<class T>
struct MDLLNode;

template<class T>
using MDLLPtr = MDLLNode<T>*;

template<class T>
struct MDLLNode{
	T val;
	MDLLPtr<T> np = nullptr;
	MDLLNode(T val) : val(val){

	}
};
using namespace std;

template<class T>
struct MDLinkedList{
	private:
	MDLLPtr<T> head = nullptr;
	MDLLPtr<T> tail = nullptr;
	int size_m = 0;
	
	void push(T & data, MDLLPtr<T> & root, MDLLPtr<T> & end){
		MDLLPtr<T> node;
		try{
			node = new MDLLNode<T>(data);
			node->np = root;
			if(size_m){
				root->np = (MDLLPtr<T>)(((long)root->np) ^ (long)node);
			} 
			root = node;
			if(!size_m){
				end = node;
			}
			size_m++;
		} catch (std::bad_alloc & e){
			std::cerr << e.what() << std::endl;
			throw;	
		} catch(std::exception & e){
			std::cerr << e.what() << std::endl;
		}
	}

	void pop(MDLLPtr<T> & root, MDLLPtr<T> & end){
		if(!size_m) throw std::runtime_error("trying to pop empty list");
		auto n = root; 
		root = root->np;
		if(root){
			root->np =(MDLLPtr<T>) ((long) n ^ (long) root->np);
		}
		size_m--;
		if(!size_m) end=nullptr;
		n->np = nullptr;
		delete n;	
	}

	public:
	virtual ~MDLinkedList(){
		if(!size_m){
			return;
		}
		if(!(size_m -1)){
			
			delete head;
			return;
		}
		if(!(size_m -2)){
			delete head->np;
			delete head;
			return;
		}
		auto r1 = head;
		auto r2 = head->np;	
		while(r1 != tail){
			auto aux = r1;	
			delete r1;
			r1 = r2;
			r2 = (MDLLPtr<T>)((long)aux ^ (long) r2->np);
		}
		delete tail;

	}
	void push_front(T data){
		push(data,head,tail);
	}
	
	void pop_front(){
		pop(head,tail);
	}
	T front(){
		if(!size_m)
			throw std::runtime_error("trying to get the head of empty list");
		return head->val;
	}
	T back(){
		if(!size_m)
			throw std::runtime_error("trying to get the head of empty list");
		return tail->val;
		
	}
	
	void push_back(T data){
		push(data,tail,head);
	}
	void pop_back(){
		pop(tail,head);	
	}

	int size(){
		return size_m;
	}
		

	void reverse(){
		auto aux = head;
		head = tail;
		tail = aux;	
	}

	template<class Func>
	void traverseList(Func  f){
		if(size_m){
			f(head->val);
			if(size_m-1){
				auto n = head;
				auto n2 = head->np;
				while(n != tail){
					f(n2->val);	
					auto aux = n;
					n = n2;
					n2 = (MDLLPtr<T>)((long) aux ^(long) n2->np);
				}
								
			} 
		}		
	}
};




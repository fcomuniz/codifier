#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
template<class T>
struct SLLNode;

template<class T>
using SLLNodePtr = SLLNode<T> *;

template<class T>
struct SLLNode{
	SLLNode(): next(nullptr){

	}
	SLLNode(T elem) : elem(elem), next(nullptr){

	}
	virtual ~SLLNode(){
		delete next;
		next = nullptr;
	}
	T elem;
	SLLNodePtr<T> next;

};
template<class T>
void addSLLNode(SLLNodePtr<T> & root, T data){
	auto aux = root;
	root = new SLLNode<T>(data);
	root->next = aux;
}
template<class T>
void printList(SLLNodePtr<T> head, ostream & stream = std::cout){
	while(head != nullptr){
		stream << head->elem << " ";
		head = head->next;
	}
	stream << endl;
}

template<class T>
void removeduplicates(SLLNodePtr<T> head){
	if(head == nullptr) return;
	if(head->next == nullptr) return;
	SLLNodePtr<T> r1;
	SLLNodePtr<T> r2;
	r1 = head;
	r2 = head->next;
	std::map<T,bool> hasAlready;
	hasAlready[r1->elem] = true;
	while(r2 != nullptr){
		if(hasAlready.count(r2->elem) > 0){
			r1->next = r2->next;
			r2->next = nullptr;
			delete r2;
			r2 = r1->next;
		}else {
			hasAlready[r2->elem] = true;
			r1 = r2;
			r2 = r2->next;	
		}
	}
}

template<class T>
SLLNodePtr<T> kthToLast(int k, SLLNodePtr<T> head){
	auto n1 = head;
	auto n2 = head;
	for(int i = 0; i < k && n1 != nullptr; i++){
		n1 = n1->next;
	}
	if(n1 == nullptr) return n2;
	while(n1->next != nullptr){
		n1 = n1->next;
		n2 = n2->next;
	}
	return n2;
}

template<class T>
void removeSLLNode(SLLNodePtr<T> node){
	auto next = node->next;
	node->next = next->next;
	node->elem = next->elem;
	next->next = nullptr;
	delete next;
}

template<class T>
SLLNodePtr<T> sumReverseOrder(SLLNodePtr<T> head1, SLLNodePtr<T> head2, bool carry){
	if(head1 == nullptr && head2 == nullptr) return nullptr;
	SLLNodePtr<T> returnSLLNode = new SLLNode<T>();
	T value1 = 0;
	T value2 = 0;
	if(head1 != nullptr){
		value1 = head1->elem;
	}
	if(head2 != nullptr){
		value2 = head2->elem;
	}

	T value = value1 + value2 + (carry ? 1 : 0);		
	carry = value / 10;
	value = value % 10;
	auto next1 = (head1 == nullptr) ? head1 : head1->next;	
	auto next2 = (head2 == nullptr) ? head2 : head2->next;	
	returnSLLNode->elem = value;
	returnSLLNode->next = sumReverseOrder(next1,next2, carry);
	return returnSLLNode;
}

template<class T>
int sizeOfList(SLLNodePtr<T> head){
	int counter;
	for(counter = 0; head != nullptr; head = head->next, counter++);
	return counter;
}

void swap(int & a, int & b){
	auto c = a;
	a = b;
	b = c;
}

template<class T>
void swap(SLLNodePtr<T> & a, SLLNodePtr<T> & b){
	auto c = a;
	a = b;
	b = c;
}

template<class T>
SLLNodePtr<T> sumDirectOrder(int n1ToEnd, int n2ToEnd, SLLNodePtr<T> head1, SLLNodePtr<T> head2, bool & carry);

template<class T>
SLLNodePtr<T> sumDirectOrder(SLLNodePtr<T> head1, SLLNodePtr<T> head2){
	int n1 = sizeOfList(head1);		
	int n2 = sizeOfList(head2);
	if(n1 < n2){
		swap(n1,n2);
		swap(head1,head2);
	}
	bool carry;
	auto retSLLNode = sumDirectOrder(n1,n2, head1,head2, carry);
	if(carry){
		auto auxval = retSLLNode;
		retSLLNode = new SLLNode<T>();
		retSLLNode->elem = carry;
		retSLLNode->next = auxval;
	}
	return retSLLNode;
}


template<class T>
SLLNodePtr<T> sumDirectOrder(int n1ToEnd, int n2ToEnd, SLLNodePtr<T> head1, SLLNodePtr<T> head2, bool & carry){
	if(head1 == nullptr && head2 == nullptr) return nullptr;
	if(n1ToEnd > n2ToEnd){
		auto nextSLLNode = sumDirectOrder(n1ToEnd-1,n2ToEnd,head1->next,head2, carry);
		auto val = head1->elem + (carry? 1 : 0);
		carry = val >= 10;
		val = val % 10;
		auto currentSLLNode = new SLLNode<T>();
		currentSLLNode->elem = val;
		currentSLLNode->next = nextSLLNode;
		return currentSLLNode;
	} else{
		auto nextSLLNode = sumDirectOrder(n1ToEnd-1,n2ToEnd-1,head1->next, head2->next, carry);	
		auto currentSLLNode = new SLLNode<T>();
		auto val = head1->elem + head2->elem + (carry ? 1 : 0);
		carry = val >= 10;
		val = val % 10;
		currentSLLNode->elem = val;
		currentSLLNode->next = nextSLLNode;
		return currentSLLNode;
	}
}


template<class T>
bool isPalindrome(SLLNodePtr<T> head,SLLNodePtr<T> & valToCompare, int  & size, int  & counter){
	if(head == nullptr) return true;
	size++;
	bool retValue = isPalindrome(head->next,valToCompare, size, counter);
	if(counter > size/2) return retValue;
	retValue = retValue && (valToCompare->elem == head->elem);
	valToCompare = valToCompare->next;
	counter++;
	return retValue;
}

template<class T>
bool isPalindrome(SLLNodePtr<T> head){
	SLLNodePtr<T> valToCompare = head;
	int size = 0;
	int counter = 0;
	return isPalindrome(head,valToCompare,size, counter);
}

//Detecting the intersection.
//First we must equal the amount remaining for each one
template<class T>
SLLNodePtr<T> intersect(SLLNodePtr<T> head1, SLLNodePtr<T> head2){
	auto n1 = sizeOfList(head1);
	auto n2 = sizeOfList(head2);
	if(n1 == 0 || n2 == 0) return nullptr;
	if(n1 < n2){
		swap(n1,n2);
		swap(head1,head2);
	}
	while(n1 > n2){
		head1 = head1->next;
		n1--;	
	}
	while(head1 != head2){
		head1 = head1->next;
		head2 = head2->next;
	}
	return head1;
}

template<class T>
SLLNodePtr<T> readSLLNode(){
	SLLNodePtr<T> head;	
	string a;
	stringstream ss;
	getline(std::cin,a);
	ss << a;
	T val;
	ss >> val;
	head = new SLLNode<T>(val);
	while(ss >> val){
		SLLNodePtr<T> auxval;
		auxval = head;
		head = new SLLNode<T>(val);	
		head->next = auxval;
	}
	return head;
}

template<class T>
SLLNodePtr<T> detectLoop(SLLNodePtr<T> head){
	if(head == nullptr) return nullptr;
	auto r1 = head;
	auto r2 = head;
	while(r1 == head || r1 != r2){
		r2 = r2->next;
		if(r2 == nullptr) return nullptr;
		r2 = r2->next;
		r1 = r1->next;
		std::cout << r2->elem << " " << r1->elem << endl;
	}
	while(r1->next != r2){
		r1 = r1->next;
	}
	return r1;
}

template<class T>
SLLNodePtr<T> readLinkedList(istream & stream);

template<>
SLLNodePtr<int> readLinkedList(istream & stream){
	string line;
	getline(stream,line);
	stringstream ss;
	ss.str(line);
	SLLNodePtr<int> ptr = nullptr;
	int data;
	while(ss>>data){
		auto next = ptr;	
		ptr = new SLLNode<int>(data);
		ptr->next = next;
	}
	return ptr;	
}

template<class T>
void partitionList(SLLNodePtr<T> & ptr, T compare){
	// separating in two lists. auxlist is the list with values < compare and ptr is a list with values >=
	if(ptr == nullptr) return;
	auto auxList = ptr;
	auxList = nullptr;
	auto auxPointer = auxList;
	while(ptr != nullptr && ptr->elem < compare){
		auxPointer = auxList;	
		auxList = ptr;
		ptr = ptr->next;
		auxList->next = auxPointer;
	}
	if(ptr == nullptr) return;
	auto pivot1 = ptr->next;
	auto pivot2 = ptr;
	while(pivot1 != nullptr){
		if(pivot1->elem < compare){
			pivot2->next = pivot1->next;
			pivot1->next = auxList;
			auxList = pivot1;
			pivot1 = pivot2->next;
			continue;
		}
		pivot1 = pivot1->next;
		pivot2 = pivot2->next;
	}
	// Merging the lists
		
	if(auxList == nullptr) return ;	
	pivot1 = auxList->next;
	pivot2 = auxList;
	while(pivot1 !=nullptr){
		pivot1 = pivot1->next;
		pivot2 = pivot2->next;
	}
	pivot2->next = ptr;
	ptr = auxList;
	return ;
}

template<class T>
SLLNodePtr<T> reverse(SLLNodePtr<T> head){
	if(head){
		auto r1 = head;
		decltype(r1) r2;
		while(r1->next){
			r2 = r1->next;
			r1->next = r2->next;
			r2->next = head;
			head = r2;
		}
	}
	return head;
}

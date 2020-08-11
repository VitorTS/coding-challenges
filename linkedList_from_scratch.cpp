/* 	my own implementation of LinkedList 
	based only on the conceptual definition of the data structure 
*/

//Deletion − Deletes an element at the beginning of the list.
//TODO

//reverse - Creates  backwards version of the list
//TODO

//Search − Searches an element using the given key.
//TODO

//Delete − Deletes an element using the given key.
//TODO

//Insert Last − Adds an element at the end of the list.
//TODO

//Delete Last − Deletes an element from the end of the list.
//TODO

//Insert After − Adds an element after an item of the list.
//TODO

#include <iostream>
#include <memory>

template <typename T>
struct Node{
	Node(T v, std::shared_ptr<Node<T>> n) : val(v), next(n) {};
	T val;
	std::shared_ptr<Node<T>> next;
};

template <typename T>
using Link = std::shared_ptr<Node<T>>;

template <typename T>
class LinkedList{
	
private:
	Link<T> head;
public:
	void add(T val){
		Link<T> temp = std::make_shared<Node<T>>(val, nullptr);
		
		if(head == nullptr){
			head = std::move(temp);
		}else{
			end()->next = std::move(temp);
		}
	}
	
	Link<T> end(){
		Link<T> interator = head;
		
		while(interator->next != nullptr){
			interator == interator->next;
		}
		
		return interator;
	}
	
	Link<T> search(T val){
		Link<T> interator = head;
		
		if(!interator) return interator;
		
		while(interator != nullptr){
			if(interator->val == val){
				return interator;
			}
			
			interator = interator->next;
		}
		
		Link<T> emptyLink = nullptr; //empty pointer for not found
		return emptyLink; 
	}
};

int main(){
	int val = 12;

	LinkedList<int> list{};

	std::cout << "Adding " << val << " to list" << "\n";

	list.add(1);
	list.add(val);
	
	std::cout << "Searching for " << val << "\n";

	Link<int> result = list.search(val);

	if(result){
		std::cout << "Found" << "\n";
	}else{
		std::cout << "Not found" << "\n";
	}
	
}
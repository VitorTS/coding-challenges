/* 	my own implementation of LinkedList 
	based only on the conceptual definition of the data structure 
*/

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
    Link<T> tail;
public:
	void add(T val){
		Link<T> temp = std::make_shared<Node<T>>(val, nullptr);
		
		if(!head){
			head = temp;
 		}
        if(tail){
            tail->next = temp;
        }
        
        tail = temp;
	}

	void addFront(T val){
		Link<T> temp = std::make_shared<Node<T>>(val, head);

        if(!head){ //adding in front of empty or single item list
            tail = temp;
        }

		head = temp;
	}

	void addAfter(T val, T searchVal){
		Link<T> iterator = head;
		
		while(iterator){
			if(iterator->val == searchVal){
				Link<T> temp = std::make_shared<Node<T>>(val, iterator->next);

                if(!iterator->next){ //adding after last element
                    tail = temp;
                }

				iterator->next = temp;

				return;
			}

			iterator = iterator->next;
		}
	}
	
	bool remove(T searchVal){
		Link<T> iterator = head;
		
		if(!head){
			return false;
		}

		if(head->val == searchVal){
			head = head->next;

			if(!head){ //deleted the last element
				tail = nullptr;
			}

			return true;
		}

		while(iterator->next){
			if(iterator->next->val == searchVal){ //deleted the last element
				if(iterator->next){
					tail = iterator;
				}
				
				iterator = iterator->next;
				return true;
			}

			iterator = iterator->next;
		}

		return false;
	}
	
	Link<T> end(){
        return tail;
	}
	
	Link<T> search(T val){
		Link<T> iterator = head;

		while(iterator){
			if(iterator->val == val){
				return iterator;
			}
			
			iterator = iterator->next;
		}
		
		Link<T> emptyLink = nullptr; //empty pointer for not found
		return emptyLink; 
	}

	void print(){
		std::cout << "[";

		Link<T> iterator = head;

		while(iterator){
			std::cout << iterator->val;
			if(iterator->next) std::cout << ", ";
			iterator = iterator->next;
		}

		std::cout << "]\n";
	}
	
	void reverse(){
		Link<T> iterator = head;

		Link<T> prev = nullptr;
		Link<T> temp;
		while(iterator){
			temp = iterator->next;
			iterator->next = prev;
			prev = iterator;
			iterator = temp;
		}
		
		head = prev;
	}
	
};

int main(){
	LinkedList<int> list{};

	std::cout << "Adding " << 1 << " to list" << "\n";
	list.add(1);
	list.print();

	std::cout << "Adding " << 99 << " to the front of the list" << "\n";
	list.addFront(99);
	list.print();

    std::cout << "list tail: " << list.end()->val << "\n";

	std::cout << "Adding " << 3 << " to list" << "\n";
	list.add(3);
	list.print();

	std::cout << "Adding " << 1981 << " after " << 1 << " to list" << "\n";
	list.addAfter(1981, 1);
	list.print();

	std::cout << "removing " << 99 << " from the list" << "\n";
	list.remove(99);
	list.print();
	
	std::cout << "removing " << 3 << " from the list" << "\n";
	list.remove(3);
	list.print();

    std::cout << "list tail: " << list.end()->val << "\n";

	std::cout << "reversing the list" << "\n";
	list.reverse();
	list.print();

	int searchVal = 12;
	std::cout << "Searching for " << searchVal << "\n";

	Link<int> result = list.search(searchVal);

	if(result){
		std::cout << "Found" << "\n";
	}else{
		std::cout << "Not found" << "\n";
	}
	
}
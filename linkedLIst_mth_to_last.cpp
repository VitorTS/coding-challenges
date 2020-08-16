/* 
Given a singly linked list find the mth-to-last element of the list.
 Define mth to last such that when M = 0 the last element of the list is returned.
*/

/*
    My solution:
    Iterate through the list
    Count the number of iterations
    create a second pointer that "lags behind" starting its own iteration after M cycles
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
    Link<T> mth_to_last(int m){
        Link<T> iterator = head;
        Link<T> mth;

        int i = 1;
        while(iterator){
            if(i - m > 0){
                if(!mth){
                    mth = head;
                }else{
                    mth = mth->next;
                }
            }
            i++;

            iterator = iterator->next;
        }

        return mth;
    }

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
	
};

int main(){
	LinkedList<int> list{};

	std::cout << "Filling the list with numbers 1 to 10 " << "\n";
	list.add(1);
	list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(6);
    list.add(7);
    list.add(8);
    list.add(9);
    list.add(10);

    std::cout << "First before last " << list.mth_to_last(1)->val << "\n";
    
    std::cout << "Fifth before last " << list.mth_to_last(5)->val << "\n";

    std::cout << "zeroth before last " << list.mth_to_last(0)->val << "\n";

    std::cout << "11th before last " << list.mth_to_last(11) << "\n";
}
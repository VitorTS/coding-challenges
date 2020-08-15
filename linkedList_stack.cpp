/* 	my own implementation of Stack using a linkedList 
*/

#include <iostream>
#include <memory>

/*
push() − Pushing an element on the stack.

pop() − Removing an element from the stack.

peek() − get the top data element of the stack, without removing it.
*/

template <typename T>
struct Node{
	Node(T v, std::shared_ptr<Node<T>> n) : val(v), next(n) {};
	T val;
	std::shared_ptr<Node<T>> next;
};

template <typename T>
using Link = std::shared_ptr<Node<T>>;

template <typename T>
class Stack{
	
private:
	Link<T> top;
public:
	void push(T val){
		Link<T> temp = std::make_shared<Node<T>>(val, nullptr);
        temp->next = top;
		top = temp;
	}

	Link<T> pop(){
        if(!top){
            return top; //nullptr for not found, because with smart pointer we never have nullptr links 
        };

        Link<T> temp = top;
        top = top->next;

        return temp;
	}
	
	Link<T> peek(){
        return top;
	}

	void print(){
		std::cout << "[";

		Link<T> interator = top;

		while(interator){
			std::cout << interator->val;
			if(interator->next) std::cout << ", ";
			interator = interator->next;
		}

		std::cout << "]\n";
	}
	
};

int main(){
	Stack<int> stack{};

	std::cout << "Adding " << 12 << " and " << 7 << " to the stack" << "\n";
	stack.push(12);
    stack.push(7);
	stack.print();

    std::cout << "Peeking the top of the stack: " << stack.peek()->val << "\n";

    Link<int> popped = stack.pop();
    std::cout << "Popping the stack, got value : " << popped->val << "\n";
	
}
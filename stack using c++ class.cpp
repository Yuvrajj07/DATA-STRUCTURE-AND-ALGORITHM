# include <bits/stdc++.h>
# include <stack>
using namespace std;
class Stack{
	public:
	int *arr;
	int size;
	int top;
	
	// THIS IS CONSTRUCTOR OF THE STACK :
	
	Stack(int CAPACITY){
		this -> size = CAPACITY;  		// IT IS DEFINING THE VALUE  OF SIZE 
		arr=new int[size];
		top=-1;
	}
	void push(int element){
		if (top==size-1){
			cout<<"stack overflow"<<endl;
				}
		else {
			top++;
			arr[top]=element;
			}
		}
	void pop(){
			if (top==-1){
				cout<<"stack under flow"<<endl;
			}
			else {
				top--;
			}
		}
	int peek() {
			if (top>=0){
				return arr[top];
			}
			else{
				cout<<"empty string "<<endl;
				}
	}
	
	bool isEmpty() {
			if (top==-1) return true;
			else return false;
	}
};
int main () {
	
	Stack st(10);									// creating element of the stack 
	st.push(22);									// pushing elements in the stack 
	st.push(420);
	cout<<"SIZE OF STACK IS : "<<st.size<<endl;	    // IT WILL RETURN THE SIZE OF THE STACK 
	if (st.isEmpty()){							// IT WILL TELL WEATHER THE STACK IS EMPTY OR NOT 
		cout<<"THE STACK IS EMPTY "<<endl;
	}
	else {
		cout<<"STACK IS NOT EMPTY "<<endl;
	}
	cout<<st.peek()<<endl;							// IT WILL RETURN THE TOP ELEMENT OF THE Stack
	st.pop();										// IT WILL POP THE ELEMENT OF THE STACK 
	cout<<"AFTER POPING THE SIZE OF THE STACK WILL BE ---> "<<st.size<<endl;
	
}

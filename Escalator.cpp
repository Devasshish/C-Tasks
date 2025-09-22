#include <iostream>
using namespace std;
// stack class
class Stack{
private:
    int arr[100]; 
    int top;
    int capacity;

public:
	//constructor
    Stack(int size){
        capacity=size;
        top=-1;
    }
	//push
    void push(int value) {
        if(isFull()){
            cout<<"Stack is full!\n";
        }
		else{
            arr[++top]=value;
            cout<<value<<" pushed.\n";
        }
    }
	//pop
    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty!\n";
        } 
		else{
            cout<<arr[top--]<<" popped.\n";
        }
    }
	//top element
    void topElement(){
        if(isEmpty()){
            cout<<"No top element, stack is empty.\n";
        } 
		else{
            cout<<"Top element: "<<arr[top]<<endl;
        }
    }
	//empty checking
    bool isEmpty(){
        return (top==-1);
    }
	//stack full
    bool isFull(){
        return (top==capacity-1);
    }
};

int main(){
    int n,choice,value;
    //input stack size
    cout<<"Enter stack size (max 100): ";
    cin>>n;
    Stack s(n);
    do{
    	cout<<"\n1. Push\n2. Pop\n3. Show Top\n4. Check Empty\n5. Check Full\n6. Exit\n";
        cout<<"Choice: ";
        cin>>choice;
        //case checking
        switch(choice){
            case 1:
                cout<<"Enter value: ";
                cin>>value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.topElement();
                break;
            case 4:
                cout<<(s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
                break;
            case 5:
                cout<<(s.isFull() ? "Stack is full\n" : "Stack is not full\n");
                break;
            case 6:
                cout<<"Goodbye!\n";
                break;
            default:
                cout<<"Invalid choice!\n";
        }
    }while(choice!=6);
    return 0;
}


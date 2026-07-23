#include <iostream>
using namespace std;

class Stack {
  int *arr;
  int size;
  int top; 
  
public:  
  Stack(int ssize) {
      size=ssize;
      arr=new int[size];
      top=-1;
  }
  ~Stack(){ delete[] arr; }
  
  bool isEmpty() { return (top==-1); }
  bool isFull() { return (top==size-1) ; }
  
  void push(int value) {
      if(!isFull()) arr[++top]=value;
      else cout<<"Stack is Full";
  }
  
  int pop() { return arr[top--]; }
  int peek() { return arr[top]; }
    
};

int main() {
    Stack s(3);
    s.push(3);
    s.push(7);
    s.push(20);
    
    if(s.isEmpty()) cout<<"Your stack is empty"<<endl;
    else {
        int value=s.pop();
        cout<< " popped value is : "<<value<<endl;
    }
    if(!s.isEmpty()) cout<<s.peek()<<endl;

    return 0;
}

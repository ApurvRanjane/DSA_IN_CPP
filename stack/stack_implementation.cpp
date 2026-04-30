#include<iostream>
using namespace std;

class stack{
    public:
    int* arr;
    int top;    
    int size;

    stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    void push(int data){
        if(top==size-1){
            cout<<"Stack overflow"<<endl;
         
        }
        else{
        top++;
        arr[top]=data;
        }
    }

    void pop(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
            
        }
        else{
            top--;
        }
    }

    int peek(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top==-1;
    }

};

int main(){
    stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout<<"Top element is: "<<s.peek()<<endl;
    s.pop();    
    cout<<"Top element is: "<<s.peek()<<endl;
    s.pop();    
   cout<<"stack is empty: "<<s.isEmpty()<<endl;
    s.pop();    
    s.pop();    
    s.pop();    
    cout<<"stack is empty: "<<s.isEmpty()<<endl;
    s.pop();    
    return 0;
}       
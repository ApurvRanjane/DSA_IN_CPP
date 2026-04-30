#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class stack{
    Node* top;

    public:
        stack(){
            top=nullptr;
        }
        
        void push(int x){
            Node* newNode = new Node();
            newNode -> data = x;
            newNode -> next = top;
            top = newNode;
            cout <<x<< "Pushed into stack\n";
        }

        void pop(){
            if(top == nullptr){
                cout<< "stack Underflow!!!\n";
                return;
            }
            Node* temp = top;
            cout << temp->data<<"popped from stack\n";
            top = top ->next;
            delete(temp);
        }

        int peekElement(){
            if(top == nullptr){
                cout<<"Stack is empty!!\n";
                return -1;
            }
            else{
                return top->data;
            }
        }

        bool is_Empty(){
            if(top == nullptr){
                return true;
            }
            else{
                return false;
            }
        }
};

int main(){
    stack s;
    s.push(45);
    s.push(18);
    s.push(79);
    int peek=s.peekElement();
    cout<<"Top of the stack: "<<peek<<endl;
    s.is_Empty();
    s.pop();
    s.pop();
     peek=s.peekElement();
    cout<<"Top of the stack: "<<peek<<endl;
}
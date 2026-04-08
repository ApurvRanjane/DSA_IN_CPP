#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with value" << value << endl;
    }
};

void insertNode(Node* &tail,int element,int d){
    // empty list
    if(tail==NULL){
        Node* newNode=new Node(d);
        tail=newNode;
        newNode->next=newNode;
    }
    else{
        // non empty list
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        // element found -> curr is representing element node
        Node* temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void deleteNode(Node* &tail,int value){
    // empty list
    if(tail==NULL){
        cout<<"List is empty, please check again"<<endl;
        return;
    }
    else{
        // non empty
        Node* prev=tail;
        Node* curr=prev->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;

        // 1 node linked list
        if(curr==prev){
            tail=NULL;
        }
        // >=2 node linked list
        else if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}

void print(Node* tail){
    Node* temp=tail;
   do{
    cout<<tail->data<<" ";
    tail=tail->next;
   }while(tail!=temp);
   cout<<endl;
}



int main(){
    Node* tail=NULL;

    insertNode(tail,5,3);
    insertNode(tail,3,5);
    insertNode(tail,5,7);
    insertNode(tail,7,9);   
      
   print(tail);
   return 0;
      
}


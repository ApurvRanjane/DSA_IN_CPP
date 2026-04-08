#include<iostream>
#include<map>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    // Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //Destructor
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;

        }
        cout<<"Memory is free for node with value"<<value<<endl;
    }
};

// Insert at Head
void insertAtHead(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

// Insert at Tail
void insertAtTail(Node* &tail,int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

// Insert at Position
void insertAtPosition(Node* &head, Node* &tail, int position, int data){

    // Insert at start
    if(position == 1){
        insertAtHead(head,data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    // Insert at end
    if(temp->next == NULL){
        insertAtTail(tail,data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

//Deletion of element in lInkedlIST
void deleteElement(int position,Node *&head){
    if(position==1){
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{ Node *curr=head;
    Node *prev=NULL;
    int cnt=1;
    while(cnt<position){
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
}
   
}

// Print Linked List
void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool detectLoop(Node* head){
    if(head==NULL){
        return false;
    }
   map<Node*,bool> visited;
   Node* temp=head;
   while(temp!=NULL){
       if(visited[temp]==true){
            cout<<"Loop is present at element: "<<temp->data<<endl;
           return true;
       }
       visited[temp]=true;
       temp=temp->next;
   }
   return false;

}

Node* floydDetectLoop(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

        if(slow==fast){
            cout<<"Loop is present at element: "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* intersection=floydDetectLoop(head);
    Node* slow=head;

    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

void removeLoop(Node* head){
    if(head==NULL){
        return;
    }
    Node* startOfLoop=getStartingNode(head);
    Node* temp=startOfLoop;

    while(temp->next!=startOfLoop){
        temp=temp->next;
    }
    temp->next=NULL;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    // Insert at tail
    insertAtTail(tail,12);
    insertAtTail(tail,14);
    insertAtTail(tail,15);
    insertAtTail(tail,20);

    // cout<<"Linked List:"<<endl;
    // print(head);

    // // Insert at head
    // insertAtHead(head,5);
    // cout<<"After inserting at head:"<<endl;
    // print(head);

    // // Insert at position
    // insertAtPosition(head,tail,3,50);
    // cout<<"After inserting at position 3:"<<endl;
    // print(head);

    // // Deletion of element in linked list
    // deleteElement(1,head);
    // cout<<"After deletion of element at position 1:"<<endl;
    // print(head);

    // deleteElement(5,head);
    // cout<<"After deletion of element at position 1:"<<endl;
    // print(head);

    // // Detect loop in linked list
    tail->next=head->next;
    floydDetectLoop(head);
    Node*loop=getStartingNode(head);
    cout<<"Starting node of loop is: "<<loop->data<<endl;
    removeLoop(head);
    print(head);
    // detectLoop(head);
    deleteElement(1,head);
    print(head);
    


    return 0;
}
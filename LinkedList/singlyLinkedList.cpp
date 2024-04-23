#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    //destructor
    ~Node(){
        int value=this->data;
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }

};

void insertAtHead(Node* &head,int d){
    //new node create
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

void insertAtPosition(Node* &tail,Node* &head,int pos,int d){
    Node* temp=head;
    int cnt=1;
    //insert at start
    if(pos==1){
        insertAtHead(head,d);
        return;
    }

    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }

    //insert at last position
    if(temp->next==NULL){
        insertAtTail(tail,d);
        return;
    }

    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}

void deleteNode(int pos,Node* &head,Node*tail){

    //deleting first or start node
    if(pos==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    
    else{

        //deleting any middle node
        Node* curr=head;
        Node* prev=NULL;

        int count=1;
        while(count<pos){ 
            prev=curr;    
            curr=curr->next;
            count++;
        }  
        // if(curr->next==NULL){
        //     prev->next = curr->next;
        //     curr->prev = NULL;
        //     curr->next = NULL;
        //     tail = prev;
        //     delete curr;
        //     return;
        // }  
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }

}

void print(Node* &head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

    Node* node1=new Node(10);  

    //head pointed to node1
    Node* head=node1;
    Node* tail=node1;
    print(head);

    // insertAtHead(head,12);
    insertAtTail(tail,12);
    print(head);

    // insertAtHead(head,15);
    insertAtTail(tail,15);  
    print(head);

    // insertAtPosition(head,3,22);
    // insertAtPosition(head,1,23);
    // print(head);

    insertAtPosition(tail,head,4,22);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    deleteNode(4,head,tail);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    return 0;
}

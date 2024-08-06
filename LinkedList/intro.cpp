#include<iostream>
using namespace std;

class Node{

    public:

    int data;
    Node* next;

    Node(int value){
        data=value;
        next=NULL;
    }    

};

/*CREATE A NODE

int main(){

    Node *Head;
    Head=new Node(4);

    cout<<Head->data<<endl;
    cout<<Head->next<<endl;

}

*/

/*INSERT A NODE AT BEGINNING:

int main(){
    Node *head;
    head=NULL;
    int arr[]={32,33,12,9};
    for(int i=0;i<4;i++){

        if(head == NULL){
            head=new Node(arr[i]);
        }else{
            Node *temp;
            temp=new Node(arr[i]);
            temp->next=head;
            head=temp;
        }
    } 

//print the values

    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

*/

//insert at end

// int main(){
//     Node *head;
//     head=NULL;

//     int arr[]={2,3,5,12,33};

    //way 1;

    // for(int i=0;i<5;i++){
    //     if(head==NULL){
    //         head=new Node(arr[i]);
    //     }else{
    //         Node* tail=head;
    //         while(tail->next!=NULL){
    //             tail=tail->next;
    //         }
    //         Node* temp;
    //         temp=new Node(arr[i]);

    //         tail->next=temp;
    //     }
    // }

    //way 2:

    // for(int i=0;i<5;i++){
    //     if(head==NULL){
    //         head=new Node(arr[i]);
    //     }else{
    //         Node* tail=head;
    //         while(tail->next!=NULL){
    //             tail=tail->next;
    //         }
    //         tail->next=new Node(arr[i]);
    //     }
    // }

    //way 3

    // Node *tail=NULL;

    // for(int i=0;i<5;i++){
    //     if(head==NULL){
    //         head=new Node(arr[i]);
    //         tail=head;
    //     }else{

    //         tail->next=new Node(arr[i]);
    //         tail=tail->next;
    //     }
    // }

    // Node *temp = head;
    // while(temp!=NULL){
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }

    //using recursion:

/*    Node* createLinkedList(int arr[],int index,int size){

        if(index==size){
            return NULL;
        }

        Node* temp;
        temp=new Node(arr[index]);
        temp->next=createLinkedList(arr,index+1,size);

        return temp;
    }

    int main(){
        Node* Head;
        Head=NULL;

        int arr[]={2,3,4,5,6};

        Head=createLinkedList(arr,0,5);

        //print the answer:

        Node* temp;
        temp=Head;

        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        } 
    }
    */

   // creating a linkedlist from end using recursion

/*    Node* createLinkedList(int arr[],int index,int size,Node *prev){

        if(index==size){
            return prev;
        }

        Node* temp;
        temp=new Node(arr[index]);
        temp->next=prev;

        return createLinkedList(arr,index+1,size,temp);

    }

    int main(){
        Node* Head;
        Head=NULL;

        int arr[]={2,3,4,5,6};

        Head=createLinkedList(arr,0,5,NULL);

        //print the answer:

        Node* temp;
        temp=Head;

        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        } 
    }
    */

   //adding a node at middle

   Node* createLinkedList(int arr[],int index,int size){

        if(index==size){
            return NULL;
        }

        Node* temp;
        temp=new Node(arr[index]);
        temp->next=createLinkedList(arr,index+1,size);

        return temp;
    }

   int main(){
        Node* Head;
        Head=NULL;

        int arr[]={2,3,5,6,7};

        Head=createLinkedList(arr,0,5);

        //insert node at particular position
        int x=2; //position
        int value=4;

        Node *temp=Head;
        x--;

        while(x--){
            temp=temp->next;
        }

        Node *temp2=new Node(value);
        temp2->next=temp->next;
        temp->next=temp2;

        //print the answer:
        temp=Head;

        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        } 
   }

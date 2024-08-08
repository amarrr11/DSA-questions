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

        //Delete the first node
        /*if(Head!=NULL){
            Node *temp=Head;
            Head=Head->next;
            delete temp;
        }*/

        //delete the last node(we need 2 pointers cause the last node after deletion needs to point to null)
        Node *curr=Head;
        Node *prev=NULL:
        while(curr->next!=NULL){
            prev=curr;
            curr=curr->next;
        }
        

        //print the values
        while(Head!=NULL){
            cout<<Head->data<<" ";
            Head=Head->next;
        }
}


   
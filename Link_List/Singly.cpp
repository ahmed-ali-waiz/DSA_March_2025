#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

// insert at head

void insert_At_head(Node* &head, int val){
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

  // insert at position

  void  insert_AT_pos(Node* &head, int val, int pos){

    if(pos==0){
        insert_At_head(head,val);
    }
    else{
        Node* temp = head;
        int cur = 0;
        while(cur!= pos-1){
            temp = temp->next;
            cur++;
        }
        Node * n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }
  }

  // print function
    void print(Node* head){
        Node* temp = head;
        while(temp!= NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    // delete at head

    void delete_AT_Head(Node* &head){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // delete from position

    void delete_From_Pos(Node* &head,int pos){
    Node * temp = head;
    int cur = 0;
    while(cur!= pos-1){
        temp = temp->next;
        cur++;
    }
    Node * toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;

    }

   // insert at last
      
    void insert_At_last(Node* &head, int val){
        Node* n = new Node(val);
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
    }

    // delete from last

    void delete_from_last(Node* &head){
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

int main(){
    Node* head = NULL;

    insert_At_head(head , 1);
    print(head);

    insert_AT_pos(head,4,0);
    print(head);

    insert_AT_pos(head,6,0);
    print(head);

    insert_At_last(head,9);
    print(head);

    // delete_AT_Head(head);
    // print(head);

    // delete_From_Pos(2,head);
    // print(head);

    delete_from_last(head);
    print(head);

    delete_From_Pos(head,2);
    print(head);

    delete_From_Pos(head,1);
    print(head);

}
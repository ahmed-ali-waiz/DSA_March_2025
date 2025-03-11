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

void insert_At_head(Node* &head, int val){
    Node* n = new Node(val);
    n->next = head;
    head = n;
}


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
    void print(Node* head){
        Node* temp = head;
        while(temp!= NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void delete_AT_Head(Node* &head){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void delete_From_Pos(int pos,Node* &head){
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        temp->next = pos->next;
        delete ;
    }

    void insert_At_last(Node* &head, int val){
        Node* n = new Node(val);
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
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

    delete_AT_Head(head);
    print(head);

    delete_From_Pos(2,head);
    print(head);

}
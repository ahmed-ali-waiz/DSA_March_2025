#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node*next;
    Node*prev;

    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkList{
    public:
    Node* head;
    Node* tail;

    LinkList(){
        head = tail = NULL;
    }

    //   insert at start

    void insert_at_start(int val){
        Node* n = new Node(val);
        if(head == NULL){
            head = tail = n;
            head->prev = NULL;
            return;
        }
        else{
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

      // insert at last

    void insert_at_last(int val){
        Node* n = new Node(val);
        if(head == NULL){
            head = tail = n;
            head->prev = NULL;
            head->next = NULL;
        }
        else{
            tail->next = n;
            n->prev = tail;
            tail = n;
            n->next = NULL;
        }
    }

     // insert at position

    void insert_at_position(int pos, int val){
        Node* n = new Node(val);
        if(pos == 0){
            insert_at_start(val);
            return;
        }
        else{
            Node* temp = head;
            int curr = 0;
            while(curr!= pos-1){
                temp = temp->next;
                curr++;
            }
            n->next = temp->next;
            temp->next = n;
            n->prev = temp;
            if(n->next!= NULL){
                n->next->prev = n;
        }
            return;
        }
    }

    //   update at position

    void update_at_position(int val, int pos){
        Node* temp = head;
        int curr = 0;
        while(curr!= pos){
            temp = temp->next;
            curr++;
        }
        temp->val = val;
    }


    // Display function

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" <-> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    // lenght function

    int length(){
        Node* temp = head;
        int len = 0;
        while(temp!= NULL){
            temp = temp->next;
            len++;
        }
        return len;
    }


      // delete from start

    void delete_from_start(){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }

     // delete from last

    void delete_from_last(){
        if (tail == NULL)
        {
            cout << "list is empty";
            return;
        }

        Node *temp = tail;

        if (tail->prev == NULL)
        {
            head = tail = NULL;
        }
        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
    }

    // delete from position

    void delete_from_position(int pos){
      if(pos == 0){
        delete_from_start();
        return;
      }

      Node* temp = head;
      int curr = 0;
      while(curr!= pos-1){
        temp = temp->next;
        curr++;
      }
      Node* to_del = temp->next;
      temp->next = to_del->next;
      to_del->prev = temp;
      delete to_del;
    }
};

int main(){
    LinkList ll;
    ll.insert_at_start(1);
    ll.insert_at_start(2);
    ll.display();

    ll.insert_at_last(3);
    ll.insert_at_last(4);
    ll.display();

    ll.insert_at_position(3,12);
    ll.display();

    ll.update_at_position(13,3);
    ll.display();

    cout<<ll.length()<<endl;

    ll.delete_from_start();
    ll.display();

    ll.delete_from_last();
    ll.display();

    ll.delete_from_position(1);
    ll.display();
    
}
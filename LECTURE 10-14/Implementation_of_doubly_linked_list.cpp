#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor
     ~Node()
     {
        int val = this->data;
        if(next!=NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for node with data "<<val<<endl;
     }
};

void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int getLength(Node *head)
{
    int len = 0;
    while(head!=NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

void insertAtHead(Node *&tail, Node *&head, int val)
{
    // empty list
    if(head == NULL)
    {
        Node *temp = new Node(val);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(val);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
   
}

void insertAtTail(Node *&tail, Node *&head, int data)
{
    if(tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else{
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    
}
void insertAtPosition(Node *&tail, Node *&head, int pos, int data)
{
    // insert at start
    if(pos == 1)
    {
        insertAtHead(tail, head, data);
        return;
    }

    Node *temp = head;
    int count = 1;
    
    while(count < (pos-1))
    {
        count++;
        temp = temp->next;
    }

    // insert at last
    if(temp->next == NULL)
    {
        insertAtTail(tail, head, data);
        return;
    }
    Node *nodeToinsert = new Node(data);
    nodeToinsert->next = temp->next;
    temp->next->prev = nodeToinsert;
    temp->next = nodeToinsert;
    nodeToinsert->prev = temp;
}
void deleteNode(int pos, Node *&head)
{
    //deleting first node
    if(pos == 1)
    {
        Node *temp = head;

        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        
        // free memory
        delete temp;
    }
    else
    {
        // Delete any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int count = 1;
        while(count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;

    }
}
int main()
{
   
    Node *head = NULL;
    Node *tail = NULL;

    print(head);
    cout<<(getLength(head))<<endl;

    insertAtHead(tail, head, 11);
    print(head);

    insertAtHead(tail, head, 12);
    print(head);

    insertAtHead(tail, head, 15);
    print(head);

    insertAtHead(tail, head, 20);
    print(head);

    insertAtTail(tail, head, 30);
    print(head);

    insertAtTail(tail, head, 40);
    print(head);

    insertAtPosition(tail, head, 2, 1);
    print(head);  

    insertAtPosition(tail, head, 1, 100);
    print(head);

    insertAtPosition(tail, head, 9, 200);
    print(head);

    deleteNode(1, head);
    print(head);

    deleteNode(2, head);
    print(head);

    deleteNode(7, head);
    print(head);
    return 0;
}
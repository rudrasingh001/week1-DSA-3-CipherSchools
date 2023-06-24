#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, Node *&tail, int d)
{
    // create new node
    Node *temp = new Node(d);
    if(head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail = head;
    temp->next = head;
    head = temp;
}

void insertAtLast(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if(tail == NULL)
    {
        tail = temp;
        head = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}
void insertAtMiddle(Node *head, int pos, int data)
{
    Node *temp = new Node(data);
    int count = 0;
    while(head!=NULL)
    {
        count++;
        if(count==pos-1)
        {
            temp->next = head->next;
            head->next = temp;
            break;
        }
        head = head->next;
    }
}
void print(Node *&head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, -5);
    insertAtLast(head, tail, 10);
    insertAtLast(head, tail, 20);
    insertAtLast(head, tail, 30);
    insertAtLast(head, tail, 40);
    print(head);
    cout<<endl;
    insertAtMiddle(head, 3, 25);
    print(head);
    return 0;
}
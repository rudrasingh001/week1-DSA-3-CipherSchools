// q3: insert at bottom
void insertAtBottom(stack<int> &s,int x){
    if(!s.empty()){
        s.push(x);
    }
    else{
        int temp =s.top();
        s.pop();
        insertAtBottom(s,x);
        s.push(temp);
    }
}

void reverse(stack<int> &s){
    if(!s.empty()){
        return;
    }
    else{
        int temp =s.top();
        s.pop();
        reverse(s);
        insertAtBottom(s,temp);
    }
}
void sortedInsert(stack<int> &s,int x)
{
    if(s.empty() || s.top()<x)
    {
        s.push(x);
        return;
    }
    else{
        int temp = s.top();
        s.pop();
        sortedInsert(s,x);
        s.push(temp);
    }
}
void SortedStack :: sort()
{
    if(!s.empty()){
        int x = s.top();
        s.pop();
        sort();
        sortedInsert(s,x);
    }
}

// q4 LRU Cache
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    int value;
    Node *prev;
    Node *next;
    Node (int k,int v){
        key=k;
        value=v;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache{
    public: 
    unordered_map<int,Node*> m;
    int capacity,count;
    Node *head,*tail;

    LRUCache(int c){
        capacity=c;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        head->prev=NULL;
        tail->next=NULL;
        count=0;
    }
    void deleteNode(Node *node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void addToHead(Node *node){
        node->next=head->next;
        node->next->prev=node;
        node->prev=head;
        head->next=node;
    }
    int get(int key){
        if(m[key]!=NULL){
            Node *node=m[key];
            int result=node->value;
            deleteNode(node);
            addToHead(node);
            cout<<"Got the value: "<<result<<" for the key"<<endl;
            return result;
        }
        cout<<"Did not got the value for the key"<<endl;
        return -1;
    }
    void set(int key,int value){
        cout<<"Going to set the (key,value) (: "<<key<<","<<value<<")"<<endl;
        if(m[key]!=NULL){
            Node *node=m[key];
            int result=node->value;
            deleteNode(node);
            addToHead(node);
        }
        else{
            Node *node=new Node(key,value);
            m[key]=node;
            if(count<capacity){
                count++;
                addToHead(node);
            }
            else{
                m.erase(tail->prev->key);
                deleteNode(tail->prev);
                addToHead(node);
            }
        }
    }
};

int main(){
    LRUCache cache(2);
    cache.set(1,10);
    cache.set(2,20);
    cout<<"Value for the key: 1 is "<<cache.get(1)<<endl;
    cache.set(3,30);
    cout<<"Value for the key: 2 is "<<cache.get(2)<<endl;
    cache.set(4,40);
    cout<<"Value for the key: 1 is "<<cache.get(1)<<endl;
    cout<<"Value for the key: 3 is "<<cache.get(3)<<endl;
    cout<<"Value for the key: 4 is "<<cache.get(4)<<endl;
    return 0;
}
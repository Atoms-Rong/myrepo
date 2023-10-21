#include <iostream>

using namespace std;

template<class T>
class LPQ{
private:
    struct Node{
        T data;
        Node* next;
    };
    Node *head;
    Node *tail;
public:
    LPQ(){
        head = tail = NULL;
    }
    ~LPQ(){
        Node *p = head;
        for(Node *i = head->next; i; i = i->next){
            delete p;
            p = i;   
        }
    }
    void insert(const T &dt){
        Node *t = new Node;
        t->data = dt;
        t->next = NULL;
        if(head == NULL){
            head = tail = t;
        }
        else{
            if(t->data <= head->data){
                t->next = head;
                head = t;
            }
            else if(t->data >= tail->data){
                tail = tail->next = t;
            }
            else{
                Node *p = head;
                for(Node *i = head->next; i; i = i->next){
                    if(t->data <= i->data){
                        p->next = t;
                        t->next = i;
                        break;
                    }
                    p = p->next;
                }
            }
        }
    }
    void pop(){
        if(head == NULL) return;
        Node* nh = head->next;
        delete head;
        head = nh;
    }
    T front(){
        return head->data;
    }
    bool empty(){
        return head == NULL;
    }
    void print(){
        for(Node *i = head; i; i = i->next){
            cout << i->data << " ";
        }
        cout << endl;
    }

};

int main(){
    LPQ<int> lpq;
    cout << "input\ni means insert\np means pop\no means print the queue\nf means print the front element\nb means break" << endl;
    while(1){
        char op;
        cin >> op;
        if(op == 'i'){
            int t;
            cin >> t;
            lpq.insert(t);
        }
        else if(op == 'p'){
            lpq.pop();
        }
        else if(op == 'o'){
            lpq.print();
        }
        else if(op == 'f'){
            cout << lpq.front() << endl;
        }
        else if(op == 'b'){
            break;
        }
    }
    return 0;
}
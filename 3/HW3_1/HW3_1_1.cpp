#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template<class T>
class Stack{
private:
    T *data;
    int t;
    int maxSize;
    const int addtion = 100;
    void overflow(){
        T *newarr = new T[maxSize + addtion];
        if(newarr == NULL){
            cout << "MLE" << endl;
            exit(1);
        }
        for(int i = 0;i < t; ++i){
            newarr[i] = data[i];
        }
        maxSize = maxSize + addtion;
        delete []data;
        data = newarr;
    }
public:
    Stack(int sz):t(-1), maxSize(sz){
        data = new T[maxSize];
        assert(data != NULL);
    }
    ~Stack(){
        delete []data;
    }
    void push(const T& x){
        if(full()){
            overflow();
        }
        else 
            data[++t] = x;
    }
    void pop(){
        if(!empty()) --t;
    }
    T top(){
        if(!empty()) return data[t];
        return T(0);
    }
    bool empty() const{
        return t == -1;
    }
    bool full() const{
        return t == maxSize - 1;
    }
    size_t size() const{
        return t + 1;
    } 
    void clear(){
        t = -1;
    }

};

int main(){
    vector<int> a, b;
    int n;
    cin >> n;
    for(int i = 0;i < n; ++i){
        int t;
        cin >> t;
        a.push_back(t);
    }
    for(int i = 0;i < n; ++i){
        int t;
        cin >> t;
        b.push_back(t);
    }
    Stack<int> m(100);
    int pa = 0, pb = 0;
    while(1){
        if(pa < n){
            m.push(a[pa++]);
        }
        while(pb < n && m.top() == b[pb]){
            m.pop();
            ++pb;
        }
        if(pb == pa && pa == n && m.empty()){
            cout << "Yes" << endl;
            break;
        }
        else if(pa == n && !m.empty() && m.top() != b[pb]){
            cout << "No" << endl;
            break;
        }
    }
    return 0;
}
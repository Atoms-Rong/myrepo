#include <iostream>
#include <string>
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
    void print(){
        for(int i = 0; i <= t; ++i){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

Stack<int> st(10);

void permutation(int m, int k){
    if(k == 0 || m == 0 || m < k){
        if(k == 0){
            st.print();
        }
        return;
    }
    st.push(m);
    permutation(m - 1, k - 1);
    st.pop();
    permutation(m - 1 , k); 
}

int main(){
    int m, k;
    cin >> m >> k;
    permutation(m, k);
    return 0;
}
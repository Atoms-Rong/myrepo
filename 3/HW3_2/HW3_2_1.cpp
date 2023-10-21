#include <iostream>
#include <stack>

using namespace std;

int ackerman1(int m, int n){
    if(m == 0) return n + 1;
    if(n == 0) return ackerman1(m - 1, 1);
    return ackerman1(m - 1, ackerman1(m, n - 1));
}

int ackerman2(int m, int n){
    stack<int> st;
    st.push(m);
    st.push(n);
    while(st.size() > 1){
        int tn = st.top();
        st.pop();
        int tm = st.top();
        st.pop();
        if(tm == 0) {
            st.push(tn + 1);
        }
        else if(tn == 0){
            st.push(tm -1);
            st.push(1);
        }
        else{
            st.push(tm - 1);
            st.push(tm);
            st.push(tn - 1);
        }
    }
    return st.top();
}

int main(){
    int m, n;
    cin >> m >> n;
    cout << ackerman1(m, n) << " " << ackerman2(m, n) << endl;
    return 0;
}
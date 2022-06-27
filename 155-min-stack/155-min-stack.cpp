class MinStack {
public:
    //brute force     
    stack < pair < int, int >> st;
    MinStack() { }
    void push(int val) {
        int mini;
        if(st.empty()) mini = val;
        else mini = min(st.top().second, val);
        st.push({val,mini});
    }    
    void pop() { st.pop(); }    
    int top() { return st.top().first; }    
    int getMin() {  return st.top().second; }
    
    //optimal
    // stack<int>st,minSt;    
    // void push(int val) {
    //     st.push(val);
    //     if(!minSt.size() || val<=minSt.top())
    //         minSt.push(val);
    //     else if(val>minSt.top())
    //         minSt.push(minSt.top());
    // }    
    // void pop() {
    //     st.pop();
    //     minSt.pop();
    // }    
    // int top() { return st.top(); }
    // int getMin() { return minSt.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
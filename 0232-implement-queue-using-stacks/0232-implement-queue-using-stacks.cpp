class MyQueue {
public:
    //brute force
    // stack < int > input, output;  
    // MyQueue() {}
    // void push(int data) {
    //     while (!input.empty()) {
    //         output.push(input.top());
    //         input.pop();
    //     }
    //     input.push(data);
    //     while (!output.empty()) {
    //         input.push(output.top());
    //         output.pop();
    //     }
    // }
    // int pop() {
    //     int val = input.top();
    //     input.pop();
    //     return val;
    // }
    // int peek() {
    //     return input.top();
    // }
    // bool empty() {
    //     return input.empty() && output.empty();
    // }
    
    //better - push in O(1) 
    stack<int> input, output;
    MyQueue() {}
    void push(int x) {
        input.push(x);
    }    
    int pop() {
        if(output.empty()){
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
        }
        int x=output.top();
        output.pop();
        return x;
    }    
    int peek() {
        if (output.empty()){
            while (input.size()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top(); 
    }    
    bool empty() {
        return input.empty() && output.empty();
    }
};
/*
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
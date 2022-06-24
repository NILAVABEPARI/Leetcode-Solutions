// using 2 queues

// class MyStack {
// public:
//     /** Initialize your data structure here. */
//     queue<int> q1;
//     queue<int> q2;
//     MyStack() {}    
//     /** Push element x onto stack. */
//     void push(int x) {
//         q2.push(x);
//         while(!q1.empty()){
//             q2.push(q1.front());    q1.pop();
//         }
//         swap(q1, q2);
//     }    
//     /** Removes the element on top of the stack and returns that element. */
//     int pop() {
//         int result = q1.front();
//         q1.pop();
//         return result;
//     }    
//     /** Get the top element. */
//     int top() {
//         return q1.front();
//     }    
//     /** Returns whether the stack is empty. */
//     bool empty() {
//         return q1.empty();
//     }
// };

    
// using 1 queue
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() {}    
    /** Push element x onto stack. */
    void push(int x) {
        int s=q.size();
        q.push(x);
        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int result = q.front();
        q.pop();
        return result;
    }    
    /** Get the top element. */
    int top() {
        return q.front();
    }    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};
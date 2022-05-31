class SeatManager {
public:
    priority_queue<int>pq;
    SeatManager(int n) {
        for(int i=0;i<n;i++)
            pq.push(-i-1);
    }    
    int reserve() {
        int i=-pq.top();
        pq.pop();
        return i;
        
    }    
    void unreserve(int seatNumber) {
        pq.push(-seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
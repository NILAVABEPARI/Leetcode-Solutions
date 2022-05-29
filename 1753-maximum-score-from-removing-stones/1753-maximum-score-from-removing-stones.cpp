class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int cnt=0;
        priority_queue<int>pq;
        pq.push(a); pq.push(b); pq.push(c);
        while(1){
            int x=pq.top(); pq.pop();
            int y=pq.top(); pq.pop();
            if(y==0) return cnt;
            x--;y--;
            pq.push(x); pq.push(y);
            cnt++;
        }
        return cnt;
    }
};
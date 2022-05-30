class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0,n=heights.size();
        for(i;i<n-1;i++){
            if(heights[i+1]<=heights[i]) continue;
            else{
                if(ladders==0)
                    bricks-=heights[i+1]-heights[i];                
                else if(pq.size()==ladders){
                    int d1=pq.top();
                    int d2=heights[i+1]-heights[i];
                    if(d1<d2){
                        pq.pop();
                        bricks-=d1;
                        pq.push(d2);
                    }
                    else bricks-=d2;                
                }  
                else pq.push(heights[i+1]-heights[i]);
            }
            if(bricks<0) break;
        }       
        return i;
    }
};
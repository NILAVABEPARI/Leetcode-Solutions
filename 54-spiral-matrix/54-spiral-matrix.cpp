class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int top=0,bottom=n-1,l=0,r=m-1;
        vector<int>ans;
        while(top<=bottom && l<=r){
            int i=l;
            while(i<=r){
                ans.push_back(matrix[top][i]);
                //cout<<matrix[top][i]<<" ";
                i++;
            }
            top++;
            i=top;
            while(i<=bottom){
                ans.push_back(matrix[i][r]);
                //cout<<matrix[i][r]<<" ";
                i++;
            }
            r--;
            i=r;
            if(top<=bottom){      
                while(i>=l){
                    ans.push_back(matrix[bottom][i]);
                    //cout<<matrix[bottom][i]<<" ";
                    i--;
                }
                bottom--;
            }
            i=bottom;
            if(l<=r){                 
                while(i>=top){
                    ans.push_back(matrix[i][l]);
                    //cout<<matrix[i][l]<<" ";
                    i--;
                }
                l++;    
            }
        }
        return ans;
    }
};
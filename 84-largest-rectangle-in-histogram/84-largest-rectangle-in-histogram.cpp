class Solution {
public:
    //brute force - TLE - TC->O(N^2), SC->O(1)
    // int largestRectangleArea(vector<int> &height) {
    //     int maxArea = 0, n =height.size();
    //     for (int i = 0; i < n; i++) {
    //         int minHeight = INT_MAX;
    //         for (int j = i; j < n; j++) {
    //             minHeight = min(minHeight, height[j]);
    //             maxArea = max(maxArea, minHeight * (j - i + 1));
    //         }
    //     }
    //     return maxArea;
    // }
    
    //better - TC->O(N), SC->O(3N)
    // int largestRectangleArea(vector<int> &heights) {
    //     int n = heights.size();
    //     stack < int > st;
    //     int leftsmall[n], rightsmall[n];
    //     for (int i = 0; i < n; i++) {
    //         while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();            
    //         if (st.empty())
    //             leftsmall[i] = 0;
    //         else leftsmall[i] = st.top() + 1;
    //         st.push(i);
    //     }
    //     // clear the stack to be re-used
    //     while (!st.empty()) st.pop();
    //     for (int i = n - 1; i >= 0; i--) {
    //         while (!st.empty() && heights[st.top()] >= heights[i])  st.pop();
    //         if (st.empty())
    //             rightsmall[i] = n - 1;
    //         else rightsmall[i] = st.top() - 1;
    //         st.push(i);
    //     }
    //     int maxA = 0;
    //     for (int i = 0; i < n; i++) 
    //         maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
    //     return maxA;
    // }
    
    
    //optimized
    int largestRectangleArea(vector<int> &heights){
        stack < int > st;
        int maxA = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
      return maxA;
    }    
};       
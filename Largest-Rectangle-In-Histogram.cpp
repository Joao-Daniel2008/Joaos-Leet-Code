class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int l = heights.size();
        stack<int> stack;
        int max = 0;
        int current_bar;
        for(int i = 0; i <= l; i++){
            if(i == l){
                current_bar = 0;
            } else{
                current_bar = heights[i];
            }
            while(!stack.empty() && current_bar < heights[stack.top()]){
                int ID = stack.top();
                stack.pop();
                int height = heights[ID];
                int width;
                if(!stack.empty()){
                    width = i - stack.top() - 1;
                } else {
                    width = i;
                }
                int area = height * width;
                max = std::max(max, area);
            }
            stack.push(i);
        }
        return max;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater=0;
        int left=0 , right= height.size()-1;
        while(left<right){
            int width = right-left;
            int minh = min(height[left],height[right]);
            int area = width * minh;
            maxWater = max(maxWater,area);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater;
        
    }
};
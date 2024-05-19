class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int max=0;
        int area=0;
        while(r>l){
            int minHeight=((height[l]>height[r])?height[r]:height[l]);
            area = (r-l )*minHeight ;
            max=(max>area)?max:area;
            if(height[l]>height[r]){
                r--;
            }else{
                l++;
            }
        }
        return max;
    }
};
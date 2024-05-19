class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int max=0;
        int area=0;
        while(r>l){
            int minHeight=0;
            if(height[l]>height[r]){
                minHeight=height[r--];
            }else{
                minHeight=height[l++];
            }
            area = (r-l+1 )*minHeight ;
            max=(max>area)?max:area;
            
        }
        return max;
    }
};
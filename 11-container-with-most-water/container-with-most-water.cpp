class Solution {
public:
    int maxArea(vector<int>& height) {
        //-----brute force----------will show TLE
        // int n=height.size();
        // int maxi_area=0;
        // for(int i=0;i<n;i++){
        //     int area=0;
        //     for(int j=0;j<n;j++){
        //         area= min(height[i],height[j])*abs(j-i);
        //         maxi_area=max(area,maxi_area);
        //     }
        // }
        // return maxi_area;


        //OPTIMAL--------
        int n=height.size();
        int l=0;
        int r=n-1;
        // int max_h=0;
        int max_area=0;
        while(l<r){
            //as we'll take minimum height
            int h=min(height[l],height[r]);
            int w=r-l;
            max_area=max(h*w,max_area);
            if(height[l]<height[r]){
                l++;
            }
            else r--;
        }
        return max_area;
    }
};
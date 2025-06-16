class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int maxDist = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                maxDist = max(maxDist, j - i);
                j++; // try to go further to increase distance
            } else {
                i++; // nums1[i] too big, move i forward
            }
        }

        return maxDist;
    }
};


// class Solution {
// public:
//     // int BS(vector<int> temp, int size, int &tg ){
//     //     int low=0;
//     //     int high=size-1;
        

//     //     while(low<=high){
//     //         int mid=low+(high-low)/2;
//     //         if(temp[mid]==tg) return mid;
//     //         else if(tg>temp[mid]) low=mid+1;
//     //         else high=mid-1;
//     //     }
//     //     return -1;
//     // }
//     // int maxDistance(vector<int>& nums1, vector<int>& nums2) {
//     //     int dist=0;
//     //     int i=0,j=0;

//     //     vector<int> v1=nums1;
//     //     vector<int> v2=nums2;

//     //     sort(v1.begin(),v1.end());
//     //     sort(v2.begin(),v2.end());
        
//     //     int n1=BS(nums1,nums1.size(),nums1[0]);
//     //     int n2=BS(nums1,nums1.size(),nums1[nums1.size()-1]);

//     //     int m1=BS(nums2,nums2.size(),nums2[0]);
//     //     int m2=BS(nums2,nums2.size(),nums2[nums2.size()-1]);

//     //     int ans=max(m2-n1,n2-m1);
//     //     return ans;
    
//     }
// };
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        if(m > n)
        {
            // Lets a have case where always nums1 is smaller or equal to nums2
            // for simplicity.
            return findMedianSortedArrays(nums2,nums1);
        }
        int start =0, end = m-1;
        int PX =0 , PY =0;
        double ans;
        int minleftX, minleftY , maxrightX, maxrightY;
        while(1)
        {
            // lets do partition on nums1
            PX = (start + end+1)/2;
            PY = ((m+n+1)/2) - PX;

            cout<< start << " "<< end <<endl;

           // return 0.0;
            
            minleftX = PX == 0 ? INT_MIN : nums1[PX-1];
            minleftY = PY == 0 ? INT_MIN : nums2[PY-1];

            maxrightX = PX == m ? INT_MAX : nums1[PX];
            maxrightY  = PY == n ? INT_MAX : nums2[PY];

           // cout << minleftX << " " << maxrightY << " " << minleftY <<" " << maxrightX<<endl;
            if(minleftX <= maxrightY &&
                 minleftY <= maxrightX)
                break;
            else if(minleftX > maxrightY)
                end = PX-1;
            else
                start = PX+1;
        }
        if((m+n) % 2 == 0)
        {
            ans = (double)(max(minleftX,minleftY) + min(maxrightX,maxrightY))/2;
        }
        else
            ans = max(minleftX,minleftY);
        return ans;
    }
};

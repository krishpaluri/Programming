class Solution {
public:
    void swap(int &a,int &b)
    {
        int temp = a;
        a= b;
        b = temp;
    }

    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i=m-1,j=n-1,k;
        int len1 = a.size(), len2 = b.size();
        k = len1-1;
        while(j>=0)
        {
            //pick max among the elements
            int ai = i<0 ? INT_MIN:a[i];
            if(ai > b[j])
            {
                a[k] = ai;
                i--;
            }
            else
            {
                a[k] = b[j];
                j--;
            }
            k--;

        }

    }
};

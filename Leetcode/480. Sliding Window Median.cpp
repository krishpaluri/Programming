class Solution {
public:
    int n = 0;
    multiset<double> ms;
    multiset<double> :: iterator iter;


    void addNum(int num) {
        if(n == 0) {
            ms.insert(num);
            iter = ms.begin();
            n++;
            return;
        }
        n++;
        ms.insert(num);
        // if size is even
        if(n % 2 == 0) {
            // so element is added to left side so shift iter to left
            if(num < *iter) {
                iter = prev(iter);
            }
            //if added to right side median will itr and next(iter)
        } else {
            //if odd if element is added to right side shift iter to right
            if(num >= *iter) {
                iter = next(iter);
            }
        }

    }

    void delNum(int num) {
        n--;

        bool ismedianerased = false;
        multiset<double> :: iterator it,pit,nit;
        it = ms.find(num);;
        if(n == 0)
        {
            ms.erase(it);
            return;
        }
        pit = prev(iter);
        nit = next(iter);
        int median = *iter;

        if(it == iter)
        {
            ismedianerased = true;
        }
        ms.erase(it);


        // if size is even

        if(n % 2 == 0) {

            if(ismedianerased)
            {
                iter = pit;
                cout<<*iter;
                return;
            }
            // so element is erased to left side so shift iter to right
            if( ismedianerased || num > median) {
                iter = prev(iter);
            }
            //if added to right side median will itr and next(iter)
        } else {
            if(ismedianerased)
            {
                iter = nit;
                cout<<*iter;
                return;
            }
            //if odd if element is erased to left side shift iter to
            if(ismedianerased || num <= median) {
                iter = next(iter);
            }
        }

    }


    double getmedian() {
        if(n % 2 == 1) {
            return *iter;
        } else {
            return (double)(*iter+*next(iter)) / 2.0;
        }

    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        int i,j;
        vector<double> ans;
        for(i=0;i<k;i++)
        {
            addNum(nums[i]);
        }
        ans.push_back(getmedian());
        j=i;
        i=1;
        while(j<nums.size())
        {
            delNum(nums[i-1]);
            addNum(nums[j]);
            ans.push_back(getmedian());
            i++;
            j++;
        }
        return ans;
    }

};

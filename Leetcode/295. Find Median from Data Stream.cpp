class MedianFinder {
public:
    /** initialize your data structure here. */
    int n = 0;
    multiset<int> ms;
    multiset<int> :: iterator iter;

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

    double findMedian() {
        if(n % 2 == 1) {
            return *iter;
        } else {
            cout<<*iter <<*next(iter)<<endl;
            return (double)(*iter+*next(iter)) / 2.0;
        }
    }
};

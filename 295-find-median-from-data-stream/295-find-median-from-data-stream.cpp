class MedianFinder {
public:
    priority_queue<int>mini;
    priority_queue<int,vector<int>,greater<int>>maxi;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mini.size()==0) {
            mini.push(num);
        }
        else if(maxi.size()==mini.size()) {
            if(num>maxi.top()) {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(num);
            }
            else {
                mini.push(num);
            }
        }
        else {
            if(num<mini.top()) {
                maxi.push(mini.top());
                mini.pop();
                mini.push(num);
            }
            else {
                maxi.push(num);
            }
            
        }
    }
    
    double findMedian() {
        double ans;
    if(maxi.size()==mini.size()) {
        ans = (maxi.top() + mini.top()) / (double)2;
    }       
    else {
        ans = mini.top();
    }
    return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
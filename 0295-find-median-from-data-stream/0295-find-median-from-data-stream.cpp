class MedianFinder {
public:
    priority_queue<int>maxi;
    priority_queue<int, vector<int>, greater<int>>mini;
    MedianFinder() {
        
    }
    
    void addNum(int x) {
        //cout<<"u";
        if(maxi.size()==0) {
            maxi.push(x);
        }
        else if(mini.size()==0){
            if(x<maxi.top()) {
                int c = maxi.top();
                maxi.pop();
                maxi.push(x);
                mini.push(c);
            }
            else mini.push(x);
        }
        else if(mini.size()==maxi.size()) {
            if(x>mini.top()) {
                int c = mini.top();
                mini.pop();
                mini.push(x);
                maxi.push(c);
            }
            else {
                maxi.push(x);
            }
        }
        else {
            int c = maxi.top();
            if(x<c) {
                int u = maxi.top();
                maxi.pop();
                maxi.push(x);
                mini.push(u);
            }
            else {
                mini.push(x);
            }
        }
    }
    
    double findMedian() {
        //cout<<"a";
        double ans = 0;
        if(mini.size()==maxi.size()) {
            ans = ((double)mini.top() + (double)maxi.top())/2.0;
        }
        else {
            ans = (double)maxi.top();
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
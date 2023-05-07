class FrequencyTracker {
public:
    vector<int>a;
    unordered_map<int,int>m;
    FrequencyTracker() {
        a.resize(1e5+6,0);
    }
    
    void add(int x) {
        m[a[x]]--;
        m[a[x]+1]++;
        a[x]++;
    }
    
    void deleteOne(int x) {
        if(!a[x]) return;
        m[a[x]]--;
        m[a[x]-1]++;
        a[x]--;
    }
    
    bool hasFrequency(int x) {
        if(m[x]) return 1;
        return 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
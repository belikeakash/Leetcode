class Solution {
public:
    vector<int>ans;
    void merge(int left, int mid, int right, vector<pair<int,int>>&array) {
        int subArrayOne = mid - left + 1;
        int subArrayTwo = right - mid;
  
    // Create temp arrays
        vector<pair<int,int>>leftArray(subArrayOne);
        vector<pair<int,int>>rightArray(subArrayTwo);
         
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
    for(auto x:leftArray) {
        int cx = lower_bound(rightArray.begin(),rightArray.end(),x) - rightArray.begin();
        ans[x.second]+=cx;
    }
    int indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    }
    void mergeSort(int s, int e, vector<pair<int,int>>&a) {
        if(s>=e) return;
        int mid = (s+e)/2;
        mergeSort(s,mid,a);
        mergeSort(mid+1,e,a);
        merge(s,mid,e,a);
    }
    vector<int> countSmaller(vector<int>& b) {
        
        int n = b.size();
        ans.resize(n,0);
        vector<pair<int,int>>a;
        for(int i=0;i<n;i++) {
            a.push_back({b[i],i});
        }
        mergeSort(0,n-1,a);
        return ans;
    }
};
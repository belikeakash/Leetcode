class Solution {
public:
    int countNodes(vector<int>& a1, vector<int>& a2, int root) {
        if(root==-1) return 0;
        return 1 + countNodes(a1,a2,a1[root]) + countNodes(a1,a2,a2[root]);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& a1, vector<int>& a2) {
        int root = -1;
        int edges = 0;
        vector<int>in(n,0);
        for(int i=0;i<n;i++) {
            if(a1[i]!=-1) {
                edges++;
                in[a1[i]]++;
                if(in[a1[i]]>1) return 0;
            }
            if(a2[i]!=-1) {
                edges++;
                in[a2[i]]++;
                if(in[a2[i]]>1) return 0;
            }
        }
        if(edges!=n-1) return 0;
        int c = 0;
        for(int i=0;i<n;i++) {
            if(in[i]==0) {
                c++;
                if(c>1) return 0;
                root = i;
            }
        }
        if(root==-1) return 0;
        return n==countNodes(a1,a2,root);
    }
};
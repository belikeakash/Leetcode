class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s = "";
        if(a==b) {
            for(int i=0;i<a;i++) s+="ab";
        }
        else if(a>b) {
            while(a!=b && b!=0) {
                a=a-2;
                b=b-1;
                s+="aab";
            }
            if(b==0) {
                for(int i=0;i<a;i++) s+="a";
            }
            else for(int i=0;i<a;i++) s+="ab";
        }
        else {
            while(a!=b && a!=0) {
                a=a-1;
                b=b-2;
                s+="bba";
            }
            if(a==0) {
                for(int i=0;i<b;i++) s+="b";
            }
            else for(int i=0;i<a;i++) s+="ba";
        }
        return s;
    }
};
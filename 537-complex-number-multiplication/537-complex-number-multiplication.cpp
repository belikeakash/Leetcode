class Solution {
public:
    string complexNumberMultiply(string s1, string s2) {
        int i = 0;
        string b1 = "";
        while(s1[i]!='+') {
            b1+=s1[i];
            i++;
        }
        i++;
        int n1 = stoi(b1);
        string c1 = "";
        while(s1[i]!='i') {
            c1+=s1[i];
            i++;
        }
        int n3 = stoi(c1);
        i = 0;
        string b2 = "";
        while(s2[i]!='+') {
            b2+=s2[i];
            i++;
        }
        i++;
        string c4="";
        while(s2[i]!='i') {
            c4+=s2[i];
            i++;
        }
        int n4 = stoi(c4);
        // cout<<b1<<" "<<b2<<endl;
        // cout<<c1<<" "<<c4<<endl;
        int n2 = stoi(b2);
         cout<<n1<<" "<<n2<<endl;
        cout<<n3<<" "<<n4<<endl;
        int p1 = n1*n2 + -(n3*n4);
        int p2 = n1*n4 + n2*n3;
        cout<<p1<<" "<<p2<<endl;
       string d1 = to_string(p1) + "+" + to_string(p2) + "i";
        // string d2 = to_string(p1) + "+" + to_string(p2) = "i";
        return d1;
    }
};
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void sortInsert(stack<int>&s, int temp) {
    if(s.size()==0) {
        s.push(temp);
        return;
    }
    if(temp>s.top()) {
        s.push(temp);
        return;
    }
    int x = s.top();
    s.pop();
    sortInsert(s, temp);
    s.push(x);
}
void SortedStack :: sort()
{
   if(s.size()>0) {
        int temp = s.top();
        s.pop();
        sort();
        sortInsert(s,temp);
        return;
   }
}
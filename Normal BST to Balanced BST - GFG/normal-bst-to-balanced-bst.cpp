// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* insert(struct Node* node, int key){
	if (node == NULL) return new Node(key);
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);
	return node;
}

void preOrder(Node* node)
{
	if (node == NULL)return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

int height(struct Node* node) 
{
  if (node==NULL) return 0;
  else
  {
      int lDepth = height(node->left);
      int rDepth = height(node->right);
      if (lDepth > rDepth) return(lDepth+1);
      else return(rDepth+1);
  }
return 2;
} 
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* buildBalancedTree(Node* root);

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        struct Node *root = NULL;
        int n, temp;
        string tree;
        getline(cin,tree);
        root = buildTree(tree);
        // cout<<height(root)<<endl;
        root = buildBalancedTree(root);
        cout<<height(root)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/
// Your are required to complete this function
// function should return root of the modified BST
void func(Node* root, vector<int>&v) {
    if(root==NULL) return;
    func(root->left,v);
    v.push_back(root->data);
    func(root->right,v);
}
// Node* g1(vector<int>a, int &i) {
//     if(i>=a.size()) return NULL;
//     Node* root = new Node(a[i]);
//     i++;
//     root->left = g1(a,i);
//     return root;
// }
// Node* g2(vector<int>a, int &i) {
//     if(i>=a.size()) return NULL;
//     Node* root = new Node(a[i]);
//     i++;
//     root->right = g2(a,i);
//     return root;
// }
Node* func(vector<int>a, int s, int e) {
    if(s>e) return NULL;
    int x = (s+e)/2;
    Node* root = new Node(a[x]);
    // cout<<root->data<<" ";
    root->left = func(a,s,x-1);
    root->right = func(a,x+1,e);
    return root;
}
Node* buildBalancedTree(Node* root)
{
	vector<int>v;
	func(root,v);
	int n = v.size();
// 	vector<int>a1,a2;
// 	for(int i=0;i<n/2;i++) a1.push_back(v[i]);
// 	reverse(a1.begin(),a1.end());
// 	for(int i=n/2+1;i<n;i++) a2.push_back(v[i]);
	Node* p = func(v,0,v.size()-1);
	
	return p;
}

// heap is complete binary tree
class TreeNode{
    public: 
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left,TreeNode* right):val(x),left(left),right(right){}
};

void inorder(TreeNode *root, vector<int> &result){
    if(root==NULL) return;
    inorder(root->left);
    result.push_back(root->val); // add the current node's value to our
    inorder(root->right);// traversal list and then recursively traverse its children
}
vector<int> inorder(TreeNode* root){
    vector<int> result;     // initialize an empty array of integers as output
    inorder(root, result);      // call helper function with initial parameters (the input subtree
    return result;
}

vector<int> preorder(TreeNode* root){
    if(root==NULL)  return {};
    vector<int> result;
    stack <TreeNode*> s;   // create a stack for storing nodes during recursion
    s.push(root);
    TreeNode *temp=root;
    while(true){
        temp=s.top();
        while(temp!=NULL && temp->left!=NULL){
            result.push_back(temp->val);
            s.push(temp);
            temp=temp->left;
        }
        if(s.empty()){
            break;
        }
        temp=s.top();
        s,pop();
        temp=temp->right;
    }
    return result;
}
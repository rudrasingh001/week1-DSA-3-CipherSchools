// Q3(Construct Binnary Tree form Inorder &preorder | Inorder & postorder)
int find(vector<int> inOrder, int start, int end, int x)
{
    for (int i = start; i <= end; i++)
    {
        if (inOrder[i] == x)
        {
            return i;
        }
    }
    return -1;
}

TreeNode *buildTree(const vector<int> &preOrder, const vector<int> &inOrder, int start, int end, int &curr)
{
    if (start > end)
        return NULL;
    TreeNode *newNode = new TreeNode(preOrder[curr]);
    curr++;
    if (start == end)
        return newNode;
    else
    {
        int idx = find(inOrder, start, end, newNode->val);
        newNode->left = buildTree(preOrder, inOrder, start, idx - 1, curr);
        newNode->right = buildTree(preOrder, inOrder, idx + 1, end, curr);
    }
    return newNode;
}

TreeNode *buildTree(const vector<int> &preOrder, const vector<int> &inOrder)
{
    int curr = 0;
    return buildTree(preOrder, inOrder, 0, inOrder.size() - 1, curr);
}

// Q4(Serialize & Deserialize)
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        string s = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node == NULL)
                s.append("#,");
            else
                s.append(to_string(node->val) + ',');
            if (node != NULL)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ','); // this will store the number in string format
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#")
            {
                node->left = NULL;
            }
            else
            {
                TreeNode *left = new TreeNode(stoi(str));
                node->left = left;
                q.push(left);
            }
            getline(s, str, ',');
            if (str == "#")
            {
                node->right = NULL;
            }
            else
            {
                TreeNode *right = new TreeNode(stoi(str));
                node->right = right;
                q.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// Q3(root to leaf problem)
bool isLeaf(TreeNode *root)
{
    return (root != NULL && root->left == NULL && root->right == NULL);
}
void rootToLeafPath(TreeNode *root, vector<vector<int>> &paths, vector<int> &pathSoFar)
{
    if (root == NULL)
        return;
    pathSoFar.push_back(root->val);
    if (isLeaf(root))
    {
        paths.push_back(pathSoFar);
        return;
    }
    else
    {
        rootToLeafPath(root->left, paths, pathSoFar);
        rootToLeafPath(root->right, paths, pathSoFar);
    }
    pathSoFar.pop_back();
}
vector<vector<int>> rootToLeaf(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<vector<int>> paths;
    vector<int> pathSoFar;

    rootToLeafPath(root, paths, pathSoFar);
    return paths;
}

// Q4(print ancestors of node in binary tree)
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
bool printAncestors(struct node *root, int target)
{
    if (root == NULL)
        return false;

    if (root->data == target)
        return true;

    if (printAncestors(root->left, target) ||
        printAncestors(root->right, target))
    {
        cout << root->data << " ";
        return true;
    }

    return false;
}

struct node *newnode(int data)
{
    struct node *node = (struct node *)
        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}


// Q5(find LCA(least common ancestor) of binary tree)
class Solution
{
public:
    bool findAncestors(TreeNode *root, TreeNode *target, vector<TreeNode *> &ancestors)
    {
        if (root == NULL)
            return false;

        if (root == target)
        {
            ancestors.push_back(target);
            return true;
        }

        if (findAncestors(root->left, target, ancestors) || findAncestors(root->right, target, ancestors))
        {
            ancestors.push_back(root);
            return true;
        }

        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> ancestorP, ancestorQ;
        findAncestors(root, p, ancestorP);
        findAncestors(root, q, ancestorQ);

        TreeNode *lca = NULL;
        int i = ancestorP.size() - 1, j = ancestorQ.size() - 1;
        while (i >= 0 && j >= 0 && ancestorP[i] == ancestorQ[j])
        {
            lca = ancestorP[i];
            i--;
            j--;
        }

        return lca;
    }
};
// Q6 binary tree to doubly linked list
struct node
{
    int data;
    node *left;
    node *right;
};

void BinaryTree2DoubleLinkedList(node *root, node **head)
{
    if (root == NULL)
        return;
    static node *prev = NULL;
    BinaryTree2DoubleLinkedList(root->left, head);
    if (prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BinaryTree2DoubleLinkedList(root->right, head);
}

node *newNode(int data)
{
    node *new_node = new node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}
void printList(node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->right;
    }
}

// Q7 populate next pointer
void populateRandomPointer(TreeNode *root)
{
    if (root == NULL || isLeaf)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *prev;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            root = q.front();
            q.pop();
            if (i == 0)
            {
                prev = root;
            }
            else
            {
                prev->random = root;
                prev = root;
            }
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
    }
}
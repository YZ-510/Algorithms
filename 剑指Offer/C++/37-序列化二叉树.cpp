/*
请实现两个函数，分别用来序列化和反序列化二叉树
*/ 

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
	// 把二叉树分解成 3 个部分：根节点、左子树和右子树 
	// 根据前序遍历的顺序来序列化二叉树，碰到 nullptr 指针时用 '#' 代替，节点之间的数值用 ',' 隔开。 
    char* Serialize(TreeNode *root) {    
        if(root == nullptr)
            return nullptr;
        string str;
        Serialize(root, str);
        char *res = new char[str.length() + 1];
        int i;
        for(i = 0; i < str.length(); i++)
            res[i] = str[i];
        res[i] = '\0';
        
        return res;
    }
    
    void Serialize(TreeNode *root, string& str)
    {
        if(root == nullptr)
        {
            str += '#';
            return;
        }
        string r = to_string(root->val);
        str += r;
        str += ',';
        Serialize(root->left, str);
        Serialize(root->right, str);
    }
    
    TreeNode* Deserialize(char *str) {
        if(str == nullptr)
            return nullptr;
        TreeNode *res = Deserialize(&str);
        
        return res;
    }
    
    // 递归函数的参数为 char **，这样才能保证每次递归后指向字符串的指针会随着递归的进行而进行移动。
	// 由于递归时会不断的向后读取字符串，所以一定要用 **str，以保证递归后指针 str 指向未被读取的字符。
	// 这里涉及到写的问题，每次写的时候还要更新原指针的指向，所以就要用二级指针，或者用一级指针的引用。
	// *str 是指向字符 str 的指针，因为指针要往后移，要指向下一个字符，也就是说过程中要改变指针，所以应该传这个指针的地址，二级指针。 
    TreeNode* Deserialize(char **str)
    {
        if(**str == '#')
        {
            ++(*str);
            return nullptr;
        }
        int num = 0;
        while(**str != '\0' && **str != ',')
        {
            num = num * 10 + ((**str) - '0');
            ++(*str);
        }
        TreeNode *root = new TreeNode(num);
        if(**str == '\0')
            return root;
        else
            (*str)++;
        root->left = Deserialize(str);
        root->right = Deserialize(str);
        
        return root;
    }
};

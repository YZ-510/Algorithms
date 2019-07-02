/*
��ʵ�������������ֱ��������л��ͷ����л�������
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
	// �Ѷ������ֽ�� 3 �����֣����ڵ㡢�������������� 
	// ����ǰ�������˳�������л������������� nullptr ָ��ʱ�� '#' ���棬�ڵ�֮�����ֵ�� ',' ������ 
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
    
    // �ݹ麯���Ĳ���Ϊ char **���������ܱ�֤ÿ�εݹ��ָ���ַ�����ָ������ŵݹ�Ľ��ж������ƶ���
	// ���ڵݹ�ʱ�᲻�ϵ�����ȡ�ַ���������һ��Ҫ�� **str���Ա�֤�ݹ��ָ�� str ָ��δ����ȡ���ַ���
	// �����漰��д�����⣬ÿ��д��ʱ��Ҫ����ԭָ���ָ�����Ծ�Ҫ�ö���ָ�룬������һ��ָ������á�
	// *str ��ָ���ַ� str ��ָ�룬��Ϊָ��Ҫ�����ƣ�Ҫָ����һ���ַ���Ҳ����˵������Ҫ�ı�ָ�룬����Ӧ�ô����ָ��ĵ�ַ������ָ�롣 
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

// ˫ָ�룬��һ��ָ��ָ������ĵ�һ�����֣���ֻ����ƶ����ڶ���ָ��ָ����������һ�����飬��ֻ��ǰ�ƶ���
// ������ָ������֮ǰ�������һ��ָ��ָ���������ż�������ҵڶ���ָ��ָ����������������򽻻����������֡� 
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.empty())
            return;
        
        int pBegin = 0;
        int pEnd = array.size() - 1;
        
        while(pBegin < pEnd)
        {
            // ����ƶ� pBegin��ֱ����ָ��ż��
            while(pBegin < pEnd && (array[pBegin] & 0x1) != 0)
                pBegin++;
            
            // ��ǰ�ƶ� pEnd��ֱ����ָ������
            while(pBegin < pEnd && (array[pEnd] & 0x1) == 0)
                pEnd--;
            
            if(pBegin < pEnd)
            {
                int temp = array[pBegin];
                array[pBegin] = array[pEnd];
                array[pEnd] = temp;
            }
        }
    }
};

/*
// ��֤������������ż����ż��֮������λ�ò���
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.empty())
            return;
        
        int length = array.size();
        vector<int> temp;
        for(int i = 0; i < length; i++)
        {
            if((array[i] & 0x1) != 0)
                temp.push_back(array[i]);
        }
        for(int i = 0; i < length; i++)
        {
            if((array[i] & 0x1) == 0)
                temp.push_back(array[i]);
        }
        
        array = temp;
    }
};
*/ 

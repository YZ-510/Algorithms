// 双指针，第一个指针指向数组的第一个数字，它只向后移动；第二个指针指向数组的最后一个数组，它只向前移动。
// 在两个指针相遇之前，如果第一个指针指向的数字是偶数，并且第二个指针指向的数字是奇数，则交换这两个数字。 
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.empty())
            return;
        
        int pBegin = 0;
        int pEnd = array.size() - 1;
        
        while(pBegin < pEnd)
        {
            // 向后移动 pBegin，直到它指向偶数
            while(pBegin < pEnd && (array[pBegin] & 0x1) != 0)
                pBegin++;
            
            // 向前移动 pEnd，直到它指向奇数
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
// 保证奇数和奇数，偶数和偶数之间的相对位置不变
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

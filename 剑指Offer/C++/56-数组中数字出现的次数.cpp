/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
要求时间复杂度是 O(n)，空间复杂度是 O(1)。 
*/ 

/*
异或运算的性质：任何一个数字异或它自己都等于 0。
从头到尾依次异或数组中的每个数字，那么最终的结果就是两个只出现一次的数字的异或结果，因为那些成对出现两次的数字全部在异或中抵消了。
由于这两个数字肯定不一样，异或的结果肯定不为 0，在这个结果数字的二进制表示中至少有一位为 1。
在结果数字中找到第一个为 1 的位的位置，记为第 n 位。以第 n 位是不是 1 为标准把原数组中的数字分为两个子数组，
那么出现了两次的数字肯定被分配到同一个子数组，因为两个相同的数字的任意一位都是相同的。
把原数组分成两个子数组，使得每个子数组包含一个只出现一次的数字，而其他数字都出现了两次。
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.empty())
            return;
        
        int length = data.size();
        int resultExclusiveOR = 0;
        for(int i = 0; i < length; ++i)
            resultExclusiveOR ^= data[i];
        
        unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);
        
        *num1 = *num2 = 0;
        for(int j = 0; j < length; ++j)
        {
            if(IsBit1(data[j], indexOf1))
                *num1 ^= data[j];
            else
                *num2 ^= data[j];
        }
    }
    
    // 在整数 num 的二进制表示中找到最右边是 1 的位 
    unsigned int FindFirstBitIs1(int num)
    {
        int indexBit = 0;
        while(((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
        {
            num = num >> 1;
            ++indexBit;
        }
        
        return indexBit;
    }
    
    // 判断在 num 的二进制表示中从右边数起的 indexBit 位是不是 1 
    bool IsBit1(int num, unsigned int indexBit)
    {
        num = num >> indexBit;
        return (num & 1);
    }
};

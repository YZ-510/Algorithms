/*
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/

//���Ȱ� n �� 1 �������㣬�ж� n �����λ�ǲ���Ϊ 1�����Ű� 1 ����һλ�õ� 2��
//�ٺ� n �������㣬�����ж� n �ĵʹ�λ�ǲ��� 1�������������ƣ�ÿ�ζ����ж� n ������һλ�ǲ��� 1�� 
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         unsigned int flag = 1;
         while(flag)
         {
             if(n & flag)
                 count++;
             
             flag = flag << 1;
         }
         
         return count;
     }
};


//��һ��������ȥ 1���ٺ�ԭ�����������㣬��Ѹ������Ķ����Ʊ�ʾ�����ұߵ� 1 ��� 0��
//һ�������Ķ����Ʊ�ʾ���ж��ٸ� 1���Ϳ��Խ��ж��ٴ������Ĳ�����
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         
         while(n)
         {
             ++count;
             n = (n - 1) & n;
         }
         
         return count;
     }
};

/*
����һ�� double ���͵ĸ����� base �� int ���͵����� exponent��
�� base �� exponent �η���
*/

class Solution {
public:
    double Power(double base, int exponent) {
    if(base < 0.0 && exponent < 0)
        return 0.0;
    
    unsigned int absExponent = (unsigned int)(exponent);
    if(exponent < 0)
        absExponent = (unsigned int)(-exponent);
    
    double result = PowerWithUnsignedExponent(base, absExponent);
    if(exponent < 0)
        result = 1.0 / result;
    
    return result;
    }
    
    double PowerWithUnsignedExponent(double base, unsigned int exponent)
    {
        if(exponent == 0)
            return 1;
        if(exponent == 1)
            return base;
        
        double result = PowerWithUnsignedExponent(base, exponent >> 1);
        result *= result;
        if(exponent & 0x1 == 1)
            result *= base;
        
        return result;
    }
};

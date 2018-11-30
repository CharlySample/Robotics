#include <iostream>
#include <armadillo>
#include <cmath>

int sign(double x)
{
        int sign;
        if(x>0)
                sign = 1;
        else if(x<0)
                sign = -1;
        else
                sign = 0;
        return sign;
}

int neuroput(int n)
{
        int output=0;
        if(n>0)
                output = 1;
        else if(n<0)
                output = 0;
        else
                output = 0;
        return output;
}

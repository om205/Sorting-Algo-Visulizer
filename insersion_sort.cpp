#include"sorting.h"
void sortby::insersion(std::vector<int>& v)
{
    int l = v.size(),temp;
    for(int i=0;i<l;++i)
    {
        for(int j=i-1;j>=0;--j)
        {
            if(v[j]<=v[j+1]) continue;
            temp = v[j];
            v[j] = v[j+1];
            v[j+1] = temp;
        }
    }
}
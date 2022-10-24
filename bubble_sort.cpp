#include"sorting.h"
void sortby::bubble(std::vector<int>& v)
{
    int l = v.size(),temp;
    for(int i=0;i<l;++i)
    {
        for(int j=1;j<l-i;++j)
        {
            if(v[j-1]<=v[j]) continue;
            temp = v[j]; v[j] = v[j-1]; v[j-1] = temp;
        }
    }
}
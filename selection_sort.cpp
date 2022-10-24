#include"sorting.h"
void sortby::selection(std::vector<int>& v)
{
    int l = v.size(),temp;
    for(int i=0;i<l;++i)
    {
        int min = i;
        for(int j=i+1;j<l;++j)
        if(v[j]<v[min]) min = j;
        temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}
#include"sorting.h"
void sortby::count(std::vector<int>& v)
{
    int min=__INT_MAX__,max =-__INT_MAX__;
    for(int i:v) 
    {
        if(i>max) max = i;
        if(i<min) min = i;
    }
    int n = ((max-min)>0?max-min:-(max-min))+1;
    std::vector<int> cnt(n,0);
    for(int i:v)
    ++cnt[i-min];
    int index = 0;
    for(int i=0;i<n;++i)
    while(cnt[i]-->0)
    v[index++] = i+min;
}
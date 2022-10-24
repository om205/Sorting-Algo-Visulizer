#include"sorting.h"
void mearge_function(std::vector<int> &v,int i,int j,int m)
{
    std::vector<int> a(m-i+1),b(j-m);
    for(int p=i;p<=m;++p) a[p-i] = v[p];
    for(int p=m+1;p<=j;++p) b[p-m-1] = v[p];
    int p1=0,p2=0;
    // int (*min)(int&,int&) = [](int& a,int& b){return a<b?a:b;};
    for(int p=i;p<=j;++p)
    {
        if(p1>m-i) v[p] = b[p2++];
        else if(p2>=j-m) v[p] = a[p1++];
        else v[p] = a[p1]<b[p2]?a[p1++]:b[p2++];
    }
}

void meargeSort(std::vector<int> &v,int start,int end)
{
    int mid = (end+start)/2;
    if(start<mid) meargeSort(v,start,mid);
    if(end>mid+1) meargeSort(v,mid+1,end);
    mearge_function(v,start,end,mid);
}


void sortby::mearge(std::vector<int>& v)
{
    meargeSort(v,0,v.size()-1);
}
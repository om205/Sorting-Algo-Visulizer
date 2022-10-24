#include"sorting.h"

void swap(int&a,int&b)
{
    int temp = a;
    a=b; b=temp;
}

void quickSortPass(std::vector<int>& v,int x,int i)
{
    bool front = true;
    int st = x,end = i;
    if(st>=end) return;
    while(x!=i)
    {
        if(front) 
        while(v[x]<=v[i] && x!=i) i--;
        else 
        while(v[x]>=v[i] && x!=i) i++;
        if(x==i) break;
        swap(v[x],v[i]);
        swap(x,i); front = !front;
    }
    if(x>st && x<=end) quickSortPass(v,st,x-1);
    if(x>=st && x<end) quickSortPass(v,x+1,end);
}

void sortby::quick(std::vector<int>& v)
{
    int l = v.size()-1;
    int x = 0;
    quickSortPass(v,x,l);
}
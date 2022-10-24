#include"sorting.h"

void adjust(std::vector<int>&v,int curr,int end)
{
    int l_child = curr*2+1,r_child = l_child+1;
    if(l_child > end)return;
    else if(l_child == end) r_child = l_child;
    int priority = v[l_child]>v[r_child]? l_child : r_child;
    if(v[curr]>v[priority]) return;
    int temp = v[curr];
    v[curr] = v[priority];
    v[priority] = temp;
    adjust(v,priority,end);
}

void insert(std::vector<int>&v,int& start,int& end)
{
    adjust(v,start--,end);
}

void remove(std::vector<int>&v,int root,int& end)
{
    int temp = v[root];
    v[root] = v[end];
    v[end] = temp;
    adjust(v,root,--end);
}

void sortby::heap(std::vector<int>& v)
{
    int start = v.size()-1, end = start;
    while(start>=0)
    insert(v,start,end);
    while(end>0)
    remove(v,0,end);
}
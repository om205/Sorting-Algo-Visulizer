#include<bits/stdc++.h>
#include"sorting.h"

void sort(std::vector<int>& v)
{
    if(v.size()<1e3)
    sortby::selection(v);
    // else sort::mearge(v);
}
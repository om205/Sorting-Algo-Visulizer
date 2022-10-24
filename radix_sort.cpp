#include"sorting.h"

inline int abs(int a)
{
    return a<0?a*-1:a;
}

void swap_adv(std::vector<int>(**a)[10],std::vector<int>(**b)[10])
{
    std::vector<int>(*temp)[10] = *a;
    *a = *b; *b = temp;
    for(auto&it:(*temp))
    it.resize(0);
}

inline int pow(int x,int n)
{
    int ans = 1;
    while(n--)
    ans*=x;
    return ans;
}

void sortby::radix(std::vector<int>& v)
{
    int max = 0,temp;
    for(int i:v)
    if((temp = abs(i))>max) max=temp;
    int no_of_dig = 1,digit;
    while((max = max/10)!=0)
    no_of_dig++;
    std::vector<int> dig[10],dig1[10];
    int x = 0,base;
    for(int i:v)
    {
        base = pow(10,x);
        digit = (i/base)%10;
        digit = (digit + 10)%10;
        dig[digit].push_back(i);
    }
    std::vector<int> (*src)[10] = &dig,(*tar)[10] = &dig1;
    while(++x<no_of_dig)
    {
        for(auto it:(*src))
        for(auto itr:it)
        {
            base = pow(10,x);
            digit = (itr/base)%10;
            digit = (digit + 10)%10;
            (*tar)[digit].push_back(itr);
        }
        swap_adv(&src,&tar);
    }
    int index = 0;
    for(auto it:(*src))
    for(auto itr:it)
    if(itr<0) v[index++] = itr;
    for(auto it:(*src))
    for(auto itr:it)
    if(itr>=0) v[index++] = itr;
}
#include<iostream>
#include"sorting.h"
using namespace std;
int main()
{
    vector<int> arr = {4655,132,58,0,-645};
    // vector<int> arr = {5,6,4,8,1}; 
    sortby::heap(arr);
    for(int i:arr) cout<<i<<' ';
    cout<<endl;
    return 0;
}
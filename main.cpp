#include<iostream>
#include<time.h>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<chrono>
#include"sorting.h"
using namespace std;
using namespace std::chrono;

vector<int> v,cpy;

void inputArray()
{
    cout<<"\t\tEnter the total number of elements in the first line and then enter space seperated values\n";
    int n; cin>>n;
    v.resize(n);
    for(int& i:v)
    cin>>i;
    ::cpy = ::v;
}
void input();
void generateInput(int n=10,int min=1,int max=100)
{
    ofstream fout;
    fout.open("input.txt");
    int range = max-min;
    srand(time(0));
    fout<<n<<'\n';
    for(int i=0;i<n;++i)
    {
        int random = (rand()%10000)/1e4*range;
        fout<<random+min<<' ';
    }
    fout<<'\n';
    fout.close();
    input();
}

void print(vector<int>& v)
{
    cout<<'\n';
    for(int i:v)
    cout<<i<<' ';
    cout<<"\n\n";
}

void input()
{
    ifstream fin;
    fin.open("input.txt"); 
    int n;
    fin>>n;
    v.resize(n);
    for(int i=0;i<n;++i)
    fin>>v[i];
    cpy = v;
    print(v);
    fin.close();
}

void run(void (*sort)(vector<int>&))
{
    auto start = high_resolution_clock::now();
    sort(v);
    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    print(v);
    cout << "\nTime for sorting the vector is "<< diff.count() << " s\n";
    ::v = ::cpy;
}

void menu()
{
    cout<<"\n\t1-Bubble Sort\t2-Selection Sort\t3-Insersion Sort\t4-Quick Sort\t\t5-Mearge Sort\n\t6-Count Sort\t7-Radix Sort\t\t8-Heap Sort\t\t9-Change Input\t\t10-Generate Input\n\t11-View Input\t0-EXIT\n";
    int choice; cin>>choice;
    switch (choice)
    {
    case 1:
        run(sortby::bubble);
        break;
    case 2:
        run(sortby::selection);
        break;
    case 3:
        run(sortby::insersion);
        break;
    case 4:
        run(sortby::quick);
        break;
    case 5:
        run(sortby::mearge);
        break;
    case 6:
        run(sortby::count);
        break;
    case 7:
        run(sortby::radix);
        break;
    case 8:
        run(sortby::heap);
        break;
    case 9:
        inputArray();
        break;
    case 10:
        cout<<"\nEnter the length of input and range as: n min max \n";
        int n,min,max;
        cin>>n>>min>>max;
        generateInput(n,min,max);
        break;
    case 11:
        print(v);
        break;
    case 0:
        exit(0);
    }
}



int main()
{
    cout<<"\n\t\t\t\t\t\t**WELCOME OM**\n\n";
    inputArray();
    while(1) menu();
    return 0;
}
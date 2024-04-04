#include <mutex>
#include <shared_mutex>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

shared_mutex m; //c++17 开始支持 
//g++ -dM -E -x c++  /dev/null | grep plus 查看编译器默认编译标准
int counter = 0;

void write_counter()
{
    // shared_lock<mutex> lk(m);
    unique_lock<shared_mutex> lk(m);
    counter +=1 ;
}

void read_counter()
{
    shared_lock<shared_mutex> lk(m);
    int val = counter;
    // cout << counter << endl;
}

int main()
{
    vector<thread> v;
    for(int i=0;i< 12000;i++)
    {
        thread tr1(write_counter);
        thread tr2(read_counter);
        v.push_back(move(tr1));
        v.push_back(move(tr2));
    }
    for(auto &&it: v)
        it.join();
    cout << counter << endl;
    return 0;
}
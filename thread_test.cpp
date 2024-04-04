// 题目：子线程循环 10 次，接着主线程循环 100 次，接着又回到子线程循环 10 次，接着再回到主线程又循环 100 次，如此循环50次，试写出代码
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

using namespace std;

mutex mtx;
condition_variable cv;
int flag = 10;

void solve1(int num)
{
    for(int i=0; i<50;i++)
    {
        unique_lock<mutex> lk(mtx);
        cv.wait(lk, [&]{return flag==num;}); // num==10 的时候才跑子线程
        for(int j=0;j<num;j++)
        {
            cout << j << ' ';
        }
        flag = (num == 10)?100:10;
        cout << endl;
        cv.notify_one();
    }
}

int main()
{
    thread child(solve1, 10);
    solve1(100);
    child.join();

    return 0;
}
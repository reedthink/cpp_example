#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <vector>

using namespace std;

mutex mtx;
condition_variable cv;
int flag = 10;

// 题目1：子线程循环 10 次，接着主线程循环 100 次，接着又回到子线程循环 10 次，接着再回到主线程又循环 100 次，如此循环50次，试写出代码

void func1(int num)
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

void solve1()
{
    thread child(func1, 10);
    func1(100);
    child.join();
}
// 题目2：写一个程序，开启3个线程，这3个线程的ID分别为A、B、C，每个线程将自己的ID在屏幕上打印10遍，要求输出结果必须按ABC的顺序显示；如：ABCABC….依次递推。

const int loop = 10;

void func2(int id)
{
    for(int i=0;i<loop;i++)
    {
        unique_lock<mutex> lk(mtx);
        cv.wait(lk, [&]{return id == flag%3;});// 阻塞, 等总打印数符合要求的时候才继续
        flag +=1;
        cout << static_cast<char>(id + 'A') << " thread id: " << this_thread::get_id() << endl;
        cv.notify_all();
    }
}

void solve2()
{
    vector<thread> v;
    flag = 0;
    for (int i=0 ; i<3 ; i++)
    {
        thread tr(func2, i);
        v.push_back(move(tr));
        // tr.detach();/
        // tr.join();//等单次循环跑完才执行下一次，所以线程被复用了。。
    }
    for(auto &it: v)
        it.join();
    cout << this_thread::get_id() << endl;
}

int main()
{
    // solve1();
    solve2();
    return 0;
}
#include <future>
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

//有四个线程1、2、3、4。线程1的功能就是输出1，线程2的功能就是输出2，以此类推.........现在有四个文件ABCD。初始都为空。现要让四个文件呈如下格式：
// A：1 2 3 4 1 2....
// B：2 3 4 1 2 3....
// C：3 4 1 2 3 4....

// D：4 1 2 3 4 1....

void func3(int print_num, int offset)
{
    for(int i=0;i<loop;i++)
    {
        unique_lock<mutex> lk(mtx);
        cv.wait(lk, [&]{return print_num == flag%4;});// 阻塞, 等总打印数符合要求的时候才继续
        flag +=1;
        cout << (print_num+offset)%4+1 << " thread id: " << this_thread::get_id() << endl;
        cv.notify_all();
    }
}

void solve3()
{
    vector<thread> v;
    flag = 0;
    for(int i=0; i<4; i++)
    {
        //设置offset区分文件abcd
        v.emplace_back([i]{func3(i,0);});
    }
    for(auto &&it: v)
    {
        it.join();
    }
}

/*
问题4
1）有一int型全局变量g_Flag初始值为0

2） 在主线程中启动线程1，打印“this is thread1”，并将g_Flag设置为1

3） 在主线程中启动线程2，打印“this is thread2”，并将g_Flag设置为2

4） 线程1需要在线程2退出后才能退出 

5） 主线程在检测到g_Flag从1变为2，或者从2变为1的时候退出
*/
// int g_Flag = 0;

atomic<int> g_Flag(0);

void func4_1(future<int> fut)
{
    printf("this is thread1\n");
    g_Flag = 1;
    //通过get或者wait实现阻塞
    fut.wait();
    // fut.get();
    printf("thread 1 exit\n");
}

void func4_2(promise<int> prom)
{
    g_Flag = 2;
    printf("this is thread2\n");
    prom.set_value_at_thread_exit(0);
    printf("thread 2 exit\n");
}

void solve4()
{
    // cout << thread::hardware_concurrency() << endl;
    promise<int> prom;
    auto fut = prom.get_future();
    thread t1{func4_1, move(fut)};
    thread t2{func4_2, move(prom)};

    t1.detach();
    t2.detach();
    //朴实无华的阻塞
    while(g_Flag.load()==0) // load读取才能保证不会脏读
    {
        ;
        // cout << g_Flag.load() << endl;
    }
    cout << "main exit" << endl;

    //稍等片刻，给子线程输出的机会
    this_thread::sleep_for(1000ms);
}

int main()
{
    // solve1();
    // solve2();
    // solve3();
    solve4();
    return 0;
}
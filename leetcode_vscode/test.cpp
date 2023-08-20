#include <iostream>
using namespace std;
#include <cstring>

//对象的初始化和清理

class Person {
public:
    // 1、构造函数
    //没有返回值，不用谢void
    //函数名与类名相同
    //构造函数可以有参数，可以发生重载
    //创建对象的时候，构造函数会自动调用，而且只调用一次
    Person() {
        cout << "Preson 构造函数的使用" << endl;
    }
    // 2、析构函数 进行清理的操作
    //没有返回值，不写void
    //函数名和类名相同 在名称前加~
    //析构函数不可以有参数的，所以不可以发生重载
    //对象在销毁前，会自动调用析构函数，而且只会调用一次
    ~Person() {
        cout << "Person 的析构函数的调用" << endl;
    }
};

//构造和析构都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构
void test01() {
    Person person; //在栈上的数据，test01执行完毕后，就会自动释放
}
int main() {
    test01(); //构造析构都会被调用

    Person p; //但此时只会调用构造函数，也就是其到下一行没有得到释放，
              //只有main()执行完就会执行析构函数

    system("pause");

    return 0;
}

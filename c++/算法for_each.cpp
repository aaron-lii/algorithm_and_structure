#include <iostream>
#include <algorithm>
#include <vector>

/*
 * for_each(iterator begin, iterator end, _func);
 * 参数：（起始迭代器， 结束迭代器， 函数或函数对象）
 * 底层：for循环遍历起始到结束，对每个迭代器解引用后调用函数
 */

using namespace std;

//for_each调用的普通函数
void print_val(const int &val){
    cout << val << " ";
}

//for_each调用的仿函数
class print_val2{
public:
    void operator()(const int &val){
        cout << val << " ";
    }
};

// 创建容器，用for_each遍历容器
void test01(){
    vector<int> v;
    for(int i = 10; i >0 ; i--){
        v.emplace_back(i);
    }

    for_each(v.begin(), v.end(), print_val);
    cout << endl;
    for_each(v.begin(), v.end(), print_val2());
}

int main() {
    test01();
}

#include <iostream>
#include <algorithm>
#include <vector>

/*
 * transform(iterator begin1, iterator end1, iterator begin2, _func);
 * 功能：将源容器值搬运到目标容器，并对值做func运算
 * 参数：（源容器起始迭代器，源容器结束迭代器，目标容器起始迭代器，函数或函数对象）
 * 注意：目标容器要初始化大小为源容器大小
 * 底层：for循环遍历源容器迭代器，解引用后调用func函数，将函数return的值直接等号赋值给目标容器迭代器
 */

using namespace std;

// 对于每个搬运的值乘以2
int trans(int val){
    return val * 2;
}

// 打印vector值
void print_val(const vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void test01(){
    vector<int> v1;
    for(int i = 0; i < 10; i++){
        v1.emplace_back(i);
    }

    vector<int> v2;
    //此处要用resize，开启空间并置初值为 0
    //如果用reserve，只是申请内存，并没有开放赋值，无法往里拷贝
    v2.resize(v1.size());

    transform(v1.begin(), v1.end(), v2.begin(), trans);
    print_val(v1);
    print_val(v2);
}

int main() {
    test01();
}

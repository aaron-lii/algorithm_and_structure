#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
 * 其他数据类型衍生可以参考find相关
 *
 * count(iterator begin, iterator end, val)
 * 功能：统计元素出现次数
 * 参数：（开始迭代器， 结束迭代器， 值）
 * 底层：调用的count_if，for循环遍历迭代器，判断函数为相等，自定义数据类型可以重载等号，有个变量n在计数
 *
 * count_if(iterator begin, iterator end, _pred)
 * 功能：按照条件统计元素出现次数
 * 参数：（开始迭代器， 结束迭代器， 谓词）
 * 底层：for循环遍历迭代器，符合仿函数true的，变量n++，最后返回计数n
 */


// count的例子
void test01(){
    vector<string> v1;
    v1 = {"aa", "bb", "aa", "cc", "dd", "aa"};
    cout << count(v1.begin(), v1.end(), "b") << endl;
}

// 用于count_if的判断方法
bool less_five(const int &val){
    return val < 5;
}
// count_if的例子
void test02(){
    vector<int> v1;
    v1 = {1, 3, 5, 7, 6, 4, 2, 8, 9};
    cout << count_if(v1.begin(), v1.end(), less_five) << endl;
}


int main() {
    test02();
}

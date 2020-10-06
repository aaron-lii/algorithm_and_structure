#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

/*
 * accumulate(iterator begin, iterator end, val)
 * 功能：区间内元素总和
 * 参数：（起始迭代器， 结束迭代器，初始值）
 * 底层：for循环全都加起来
 *
 * fill(iterator begin, iterator end, val)
 * 功能：容器填充
 * 参数：（起始迭代器， 结束迭代器， 值）
 * 底层：for循环等号赋值为val
 */

void test01(){
    vector<int> v1;
    v1 = {1, 3 ,5 ,5 ,5 ,6 ,0 ,8};
    cout << accumulate(v1.begin(), v1.end(), 1) << endl;

    fill(v1.begin(), v1.end(), 100);
    for(int i: v1){
        cout << i << " ";
    }
    cout << endl;
}


int main() {
    test01();
}
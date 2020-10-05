#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * merge(iterator begin1, iterator end1, iterator begin2, iterator end2, iterator target)
 * 功能：将两个有序容器合并，并存储到另一个容器中
 * 参数：（1容器起始迭代器， 1容器结束迭代器， 2容器起始迭代器， 2容器结束迭代器， 目标容器迭代器）
 * 底层：三个迭代器（指针）前两个容器迭代器比较，较小的解引用等号赋值给目标容器迭代器
 */

void test01(){
    vector<int> v1;
    vector<int> v2;
    v1 = {1, 3 ,5 ,4 ,2 ,6 ,0 ,8};
    v2 = {22, 0, -5, 6, 3, 9};
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    vector<int> v3;
    v3.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    for(int i: v3){
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    test01();
}
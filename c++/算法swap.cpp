#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
 * swap(container c1, container c2)
 * 功能：替换两个容器中的元素
 * 参数：（容器1， 容器2）
 * 注意：只能相同元素类型的同种容器
 * 底层：调用容器自带swap函数，设置的容量也会互换
 */


void test01(){
    vector<int> v1;
    vector<string> v2;
    vector<int> v3;
    v1 = {1, 3 ,5 ,5 ,5 ,6 ,0 ,8};
    v2 = {"aaa", "bbb", "ccc"};
    v3 = {1, 2, 1};
    v3.reserve(6);

    swap(v1, v3);
    for(int i: v1){
        cout << i << " ";
    }
    cout << v1.capacity() << endl;
    cout << endl;
    for(int i: v3){
        cout << i << " ";
    }
    cout << v3.capacity() << endl;
    cout << endl;

}


int main() {
    test01();
}
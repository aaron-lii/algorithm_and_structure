#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * replace(iterator begin, iterator end, oldvalue, newvalue)
 * 功能：将区域内旧元素替换为新元素
 * 参数：（开始迭代器， 结束迭代器， 旧元素， 新元素）
 * 底层：for循环遍历，用等号判断是否为旧元素，用等号替换为新元素
 *
 * replace_if(iterator begin, iterator end, _pred, newvalue)
 * 功能：将区域内符合条件的元素替换为新元素
 * 参数：（开始迭代器， 结束迭代器， 谓词， 新元素）
 * 底层：for循环遍历，如果谓词函数为true，用等号替换为新元素
 */

// replace例子
void test01(){
    vector<int> v1;
    v1 = {1, 3 ,5 ,5 ,5 ,6 ,0 ,8};
    sort(v1.begin(), v1.end());

    replace(v1.begin(), v1.end(), 5, 555);
    for(int i: v1){
        cout << i << " ";
    }
    cout << endl;
}

// replace_if例子
bool greater4(int val){
    return val > 4;
}

void test02(){
    vector<int> v1;
    v1 = {1, 2, 3, 4, 5, 6};
    replace_if(v1.begin(), v1.end(), greater4, 555);
    for(int i: v1){
        cout << i << " ";
    }
    cout << endl;
}


int main() {
    test02();
}
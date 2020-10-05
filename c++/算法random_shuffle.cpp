#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

/*
 * random_shuffle(iterator begin, iterator end)
 * 功能：随机调整范围内元素顺序
 * 参数：（起始迭代器， 结束迭代器）
 * 底层：for循环遍历范围内迭代器，借助rand选择前i个中某个元素与第i个元素交换
 */

void test01(){
    // 随机数种子，防止每次结果都一样
    srand((unsigned int)time(NULL));

    vector<int> v;
    v = {1, 3 ,5 ,4 ,2 ,6 ,0 ,8};
    random_shuffle(v.begin(), v.end());
    for(int i: v){
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    test01();
}
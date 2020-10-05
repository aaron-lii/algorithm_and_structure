#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * 自定义类型请参考find相关
 *
 * sort(iterator begin, iterator end, _pred)
 * 功能：默认升序排序，自定义请修改pred
 * 参数：（起始迭代器，结束迭代器，谓词）
 * 底层：introsort(内省排序)+insertion_sort(插入排序)
 *
 *     迭代器结束-起始大于预设值才会进入introsort的while迭代，默认16
 *     introsort的while迭代中，选择first，end，first+(first+end)/2中间大小的作为快排比较的数
 *     进行一轮快排，返回小数组和大数组的分割位置
 *     分割位置+end进行递归快排（introsort中）
 *     end=分割位置，迭代回introsort这步
 *
 *     上述递归中，深度如果超过了 lg(n)*2,则对剩下部分进行__partial_sort
 *     __partial_sort类似堆排序，构建一个大顶堆，然后不断弹出第一个元素到队尾
 *
 *     introsort结束，队列大致有序，进行最终插入排序
 */

void test01(){
    vector<int> v;
    v = {1, 3 ,5 ,4 ,2 ,6 ,0 ,8};
    // 默认排序
    sort(v.begin(), v.end());
    for(int i : v){
        cout << i << " ";
    }
    cout << endl;

    // 系统自带降序函数
    sort(v.begin(), v.end(), greater<int>());
    for(int i : v){
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    test01();
}
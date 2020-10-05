#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * copy(iterator begin, iterator end, iterator target)
 * 功能：容器内指定范围元素拷贝到另一个容器中
 * 注意：新容器要提前resize大小
 *     暂时看例如二维数组，拷贝的也是值，不是地址
 */

void test01(){
    vector<int> v1;
    v1 = {1, 3 ,5 ,4 ,2 ,6 ,0 ,8};
    vector<int> v2;
    v2.resize(v1.size());

    copy(v1.begin(), v1.end()-2, v2.begin());
    for(int i : v2){
        cout << i << " ";
    }
    cout << endl;
}


int main() {
    test01();
}
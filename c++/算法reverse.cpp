#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * reverse(iterator begin, iterator end)
 * 功能：翻转容器
 * 底层：while循环，首尾swap对调，然后往中间缩
 */

void test01(){
    vector<int> v1;
    v1 = {1, 3 ,5 ,4 ,2 ,6 ,0 ,8};
    reverse(v1.begin(), v1.end() - 1);
    for(int i : v1){
        cout << i << " ";
    }
    cout << endl;

}

int main() {
    test01();
}
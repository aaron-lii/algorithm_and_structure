#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
 * find(iterator begin, iterator end, val)
 * 功能：查找容器中有没有这个值，找到返回位置的迭代器，找不到返回结束迭代器end()
 * 参数：（起始迭代器， 结束迭代器， 值）
 * 注意：自定义数据类型重载等号时，参数记得加const
 * 底层：调用的是find_if，val是否相等是用等号判断的，因此自定义数据类型要重载等号
 */

/*
 * find_if(iterator begin, iterator end, _pred)
 * 功能：按照条件查找，找到返回位置迭代器，找不到返回结束迭代器、
 * 参数：（起始迭代器， 结束迭代器， 函数或谓词（bool类型的仿函数））
 * 底层：遍历容器中迭代器，如果当前迭代器传入pred函数返回真，则返回当前迭代器，否则迭代器++
 */

/*
 * binary_search(iterator begin, iterator end, val)
 * 功能：二分查找，查到返回true，否则false
 * 注意：不要在无序序列中使用，不会报错但是结果可能不对
 * 底层：必须是升序的有序序列，底层二分查找的逻辑是升序的，中间数是通过总长度向右位移1得到的,类似__half = __len >> 1
 */

 
// 用于自定义数据类型测试
class Person{
public:
    Person(){
        name = "";
        age = 0;
    }
    Person(string n, int a){
        name = n;
        age = a;
    }

    // 重载等号，用于find比较,这里不加const会报错
    // 这里写的是名字相同就true
    bool operator==(const Person &p2){
        return this->name == p2.name;
    }

    // 输出个人信息
    void print_info(){
        cout << name << " " << age << endl;
    }

    int get_age()const{
        return age;
    }

private:
    string name;
    int age;
};

// find的例子
void test01(){
    // 默认数据类型的查找
    vector<int> v1;
    for(int i = 0; i < 10; i++){
        v1.emplace_back(i);
    }

    // vector<int>::iterator it1 = find(v1.begin(), v1.end(), 6);
    auto t1 = find(v1.begin(), v1.end(), 6);
    auto t2 = find(v1.begin(), v1.end(), 18);
    cout << *t1 << endl;
    if(t2 == v1.end()){
        cout << "t2 not exist" << endl;
    }

    // 自定义数据类型的查找
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);

    vector<Person> v2;
    v2 = {p1, p2, p3};

    auto tp = find(v2.begin(), v2.end(), Person("bbb", 50));
    if(tp != v2.end()){
        tp->print_info();
    }else{
        cout << "tp not exist" << endl;
    }
}


// 用于find_if的条件判断
class Greater_val{
public:
    int val;
    Person p;

    Greater_val(int val){
        this->val = val;
    }
    Greater_val(Person p){
        this->p = p;
    }

    bool operator()(const int &num)const{
        return num > val;
    }

//    bool operator()(Person &p2){
//        return p.get_age() < p2.get_age();
//    }

    // 如果形参加了const，get_age函数也要是const函数
    bool operator()(const Person &p2)const{
        return p.get_age() < p2.get_age();
    }
};

// find_if的例子
void test02(){
    // 默认数据类型的查找
    vector<int> v1;
    for(int i = 0; i < 10; i++){
        v1.emplace_back(i);
    }

    auto t1 = find_if(v1.begin(), v1.end(), Greater_val(6));
    if(t1 != v1.end()){
        cout << *t1 << endl;
    }else{
        cout << "t1 not exist" << endl;
    }

    // 自定义数据类型
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    vector<Person> v2;
    v2 = {p1, p2, p3};

    auto tp = find_if(v2.begin(), v2.end(), Greater_val(Person("ddd", 15)));
    if(tp != v2.end()){
        tp->print_info();
    }else{
        cout << "tp not exist" << endl;
    }
}


// 二分查找
void test03(){
    vector<int> v1;
    for(int i = 10; i > 1; i--){
        v1.emplace_back(i);
    }

    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << endl;
    }

    if(binary_search(v1.begin(), v1.end(), 3)){
        cout << "yes!" << endl;
    }else{
        cout << "no!" << endl;
    }
}

int main() {
    test03();
}

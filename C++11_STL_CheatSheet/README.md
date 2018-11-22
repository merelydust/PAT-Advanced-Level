# C++11 STL Cheat Sheet

collected by merelydust for AC٩(˃̶͈̀௰˂̶͈́)و

## 目录 Table of Conetents



## 1.容器 Container

容器是类模版 充分发挥想象力～

### 1.0 所有容器都有的成员函数

* .size() return int

* .empty() return bool

* 两对迭代器 容器类名::iterator it & 容器类名::reverse_iterator rit

  ![STLimg/iterator.png)

* ![ContainerwithIt](/Users/shadow/Desktop/code/C:C++/PAT-Advanced-Level/C++11STL_CheatSheet/STLimg/ContainerwithIt.jpeg)

![ListIt](/Users/shadow/Desktop/code/C:C++/PAT-Advanced-Level/C++11STL_CheatSheet/STLimg/ListIt.jpeg)

STL的sort函数需要随机访问迭代器的支持 所以不适用list 只能使用list的成员函数.sort()

* .erase(pos, howManytoErase)

### 1.1 顺序容器 Sequence Containers

#### 1.1.0 所有顺序容器都有的成员函数

* .front() 返回第一个元素的引用 .back() 返回最后一个元素的引用
* .push_back(element) 增 .pop_back(element) 删

#### 1.1.1 动态数组 vector

#include <vector>

* vector<type> v;

* v.insert(iterator, val); v.erase(iterator start, iterator end)   v.clear()

  remove函数返回值是空，erase返回指向下一个元素的迭代器

  //如果只有一个参数 只删除该迭代器指向的参数 区别于string

* v.swap(vector<type> &v2) v内容与另一个同类型的v2互换

#### 1.1.2 双向链表 list

#include <list>

![ListMFuncs](/Users/shadow/Desktop/code/C:C++/PAT-Advanced-Level/C++11STL_CheatSheet/STLimg/ListMFuncs.jpeg)

#### 1.1.3 双向队列 deque

#include <deque>

deque也是可变长数组，适用于vector的操作都适用于它。比起vector，它在头尾增删元素的性能更好，有两个vector没有的成员函数: 

.push_front(val) & .pop_front(val)

#### 1.1.4 字符串 string

* 赋值可以接收char数组

* .substr(startPos, len) 如果省略len参数或者len>原字符串长度 则子串取到原串末尾

* s1.swap(s2) 交换两个字符串内容

* s1.find_first_of(s2) 寻找s1中第一次出现s2中任一字符的位置 s1.find_first_not_of(s2) 寻找第一个s2没有的字符

  .find_last_of .find_last_not_of 从后往前找

* s1.replace(被替换的子串首，被替换的子串尾， 去替换的字符串， 去替换的字符串首，去替换的字符串尾)

* .erase(pos, len) .insert(pos, len)

### 1.2 关联容器 Associative Containers

不能修改元素值或map的关键字。

#### 1.2.0 所有关联容器都有的成员函数

* .find(val)

* .lower_bound(val)  // 返回最大位置it [begin, it)中所有元素都比val小

  // 找到的是另一个区间的下限 所以[begin, it)这个区间的元素都小于val

  // 为了这个区间尽可能长 返回最大的it upper_bound以此类推

  .upper_bound(val) // 返回最小位置it [it, end)中所有元素都比val大

* .count(val) // how many elements.value == val

* .insert(val)

#### 1.2.1 集合 set

#include <set>

.insert(val) 返回bool true插入成功 false val已经在集合中

#### 1.2.2 字典 map

#include <map>

It->first 访问关键字 it->second 访问值

### 1.3 容器适配器 Container adaptors

#### 1.3.0 所有容器适配器都有的成员函数

* .push(val)
* .top() // 返回stack顶部 或 queue队头元素的引用
* .pop()

#### 1.3.1 stack

#include <stack>

#### 1.3.2 queue

访问和删除只能在队头 增加只能在队尾

#include <queue>

#### 1.3.3 priority_queue

#include <queue>

队头元素总是最大的 内部并非完全有序 

可以自定义cmp函数 cmp返回false的时候交换位置(wanted condition return false)

## 2. 算法 Algorithm

### 2.0 头文件

<algorithm> <numeric>

### 2.1 不改变原序列的算法

![NotChangeOrder](/Users/shadow/Desktop/code/C:C++/PAT-Advanced-Level/C++11STL_CheatSheet/STLimg/NotChangeOrder.jpeg)

### 2.2 改变元素值的算法

![ChangeVal](/Users/shadow/Desktop/code/C:C++/PAT-Advanced-Level/C++11STL_CheatSheet/STLimg/ChangeVal.jpeg)

### 2.3 删除元素的算法

![DeleteVal](/Users/shadow/Desktop/code/C:C++/PAT-Advanced-Level/C++11STL_CheatSheet/STLimg/DeleteVal.jpeg)

### 2.4 改变顺序的算法

#### 2.4.1 变序算法

![changeOrder](/Users/shadow/Desktop/code/C:C++/PAT-Advanced-Level/C++11STL_CheatSheet/STLimg/changeOrder.jpeg)

#### 2.4.2 排序算法

![Sort](/Users/shadow/Desktop/code/C:C++/PAT-Advanced-Level/C++11STL_CheatSheet/STLimg/Sort.jpeg)

### 2.5 操作有序区间的算法

![OperateOrdered](/Users/shadow/Desktop/code/C:C++/PAT-Advanced-Level/C++11STL_CheatSheet/STLimg/OperateOrdered.jpeg)

## 3. STL实现树和图

### 3.1 树的实现

#### 3.1.1 树的建立

#### 3.1.2 树的遍历

#### 3.1.3 增删查改

#### 3.1.4 应用例题

### 3.2 图的实现

#### 3.2.1 图的建立

#### 3.2.2 图的遍历

- BFS 广度优先
- DFS 深度优先

#### 3.2.3 增删查改

#### 3.2.4 应用例题



## 3. 参考资料 References

- 1. 郭炜《新标准C++程序设计》












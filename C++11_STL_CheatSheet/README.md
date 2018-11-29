# C++11 STL Cheat Sheet

collected by merelydust for AC٩(˃̶͈̀௰˂̶͈́)و

Table of Contents
=================

   * [C  11 STL Cheat Sheet](#c11-stl-cheat-sheet)
      * [目录 Table of Conetents](#目录-table-of-conetents)
      * [1.容器 Container](#1容器-container)
         * [1.0 所有容器都有的成员函数](#10-所有容器都有的成员函数)
         * [1.1 顺序容器 Sequence Containers](#11-顺序容器-sequence-containers)
            * [1.1.0 所有顺序容器都有的成员函数](#110-所有顺序容器都有的成员函数)
            * [1.1.1 动态数组 vector](#111-动态数组-vector)
            * [1.1.2 双向链表 list](#112-双向链表-list)
            * [1.1.3 双向队列 deque](#113-双向队列-deque)
            * [1.1.4 字符串 string](#114-字符串-string)
         * [1.2 关联容器 Associative Containers](#12-关联容器-associative-containers)
            * [1.2.0 所有关联容器都有的成员函数](#120-所有关联容器都有的成员函数)
            * [1.2.1 集合 set](#121-集合-set)
            * [1.2.2 映射 map](#122-映射-map)
         * [1.3 容器适配器 Container adaptors](#13-容器适配器-container-adaptors)
            * [1.3.0 所有容器适配器都有的成员函数](#130-所有容器适配器都有的成员函数)
            * [1.3.1 stack](#131-stack)
            * [1.3.2 queue](#132-queue)
            * [1.3.3 priority_queue](#133-priority_queue)
      * [2. 算法 Algorithm](#2-算法-algorithm)
         * [2.0 头文件](#20-头文件)
         * [2.1 不改变原序列的算法](#21-不改变原序列的算法)
         * [2.2 改变元素值的算法](#22-改变元素值的算法)
         * [2.3 删除元素的算法](#23-删除元素的算法)
         * [2.4 改变顺序的算法](#24-改变顺序的算法)
            * [2.4.1 变序算法](#241-变序算法)
            * [2.4.2 排序算法](#242-排序算法)
         * [2.5 操作有序区间的算法](#25-操作有序区间的算法)
      * [3. 树和图的实现](#3-树和图的实现)
         * [3.1 树的实现](#31-树的实现)
            * [3.1.1 树的建立](#311-树的建立)
            * [3.1.2 树的遍历](#312-树的遍历)
            * [3.1.3 增删查改](#313-增删查改)
               * [3.1.3.1 查改](#3131-查改)
               * [3.1.3.2 插入增加](#3132-插入增加)
         * [3.2 图的实现](#32-图的实现)
            * [3.2.1 图的建立](#321-图的建立)
            * [3.2.2 图的遍历](#322-图的遍历)
      * [3. 参考资料 References](#3-参

## 1.容器 Container

容器是类模版 充分发挥想象力！(●°u°●)​ 」

### 1.0 所有容器都有的成员函数

* .size() return int

* .empty() return bool

* 两对迭代器 容器类名::iterator it & 容器类名::reverse_iterator rit

  ![https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/iterator.png]

* ![ContainerwithIt](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/ContainerwithIt.jpeg)

![ListIt](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/ListIt.jpeg)

STL的sort函数需要随机访问迭代器的支持 所以不适用list 只能使用list的成员函数.sort()

* .erase(pos, howManytoErase)

### 1.1 顺序容器 Sequence Containers

#### 1.1.0 所有顺序容器都有的成员函数

* .front() 返回第一个元素的引用 .back() 返回最后一个元素的引用
* .push_back(element) 增 .pop_back(element) 删

#### 1.1.1 动态数组 vector

#include &lt;vector&gt;

* vector&lt;type&gt; v;

* v.insert(iterator, val); v.erase(iterator start, iterator end)   v.clear()

  remove函数返回值是空，erase返回指向下一个元素的迭代器

  //如果只有一个参数 只删除该迭代器指向的参数 区别于string

* v.swap(vector&lt;type&gt; &v2) v内容与另一个同类型的v2互换

* vector1 == vector2 表明两个序列完全相同（数字和顺序）

#### 1.1.2 双向链表 list

#include &lt;list&gt;

![ListMFuncs](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/ListMFuncs.jpeg)

#### 1.1.3 双向队列 deque

#include &lt;deque&gt;

deque也是可变长数组，适用于vector的操作都适用于它。比起vector，它在头尾增删元素的性能更好，有两个vector没有的成员函数: 

.push_front(val) & .pop_front(val)

#### 1.1.4 字符串 string

* 赋值可以接收char数组

* .substr(startPos, len) 如果省略len参数或者len&gt;原字符串长度 则子串取到原串末尾

* s1.swap(s2) 交换两个字符串内容

* s1.find_first_of(s2) 寻找s1中第一次出现s2中任一字符的位置 s1.find_first_not_of(s2) 寻找第一个s2没有的字符

  .find_last_of .find_last_not_of 从后往前找

* s1.replace(pos, len, str2) 把s1从pos开始 长度为len的子串 替换成s2

* .erase(pos, len) .insert(pos, len)

### 1.2 关联容器 Associative Containers

不能修改元素值或map的关键字。

#### 1.2.0 所有关联容器都有的成员函数

* .find(val)

* .lower_bound(val)  // 返回最大位置it [begin, it)中所有元素都比val小 (返回第一个>=val的位置)

  // 找到的是另一个区间的下限 所以[begin, it)这个区间的元素都小于val

  // 为了这个区间尽可能长 返回最大的it upper_bound以此类推

  .upper_bound(val) // 返回最小位置it [it, end)中所有元素都比val大 (返回第一个>val的位置)

  // 如果没有找到val元素 则返回val应该在的位置 

  // 如果想要下标而不是地址 令返回值减去数组首地址即可

* .count(val) // how many elements.value == val

* .insert(val)

#### 1.2.1 集合 set

#include &lt;set&gt;

.insert(val) 返回bool true插入成功 false val已经在集合中

#### 1.2.2 映射 map

#include &lt;map&gt; // 包含了&lt;utility&gt;头文件 -> pair

通过关键字访问/通过迭代器访问

it-&gt;first 访问关键字 it-&gt;second 访问值

- .find(key) 返回iterator

- .erase(key) .erase(it) .erase(it1, it2) .clear()

- typedef pair<string, int> PAIR;

  bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
    return lhs.second < rhs.second;
  }

  struct CmpByValue {
    bool operator()(const PAIR& lhs, const PAIR& rhs) {
  ​    return lhs.second < rhs.second;
    }
  };

- multimap的插入和遍历

  multimap<string, string> mulMap;

  mulMap.insert(make_pair("鲁迅", "朝花夕拾"));

  typedef multimap<string, string>::iterator multiMapItor;

  pair<multiMapItor, multiMapItor> pos = mulMap.equal_range(key);

  while(pos.first != pos.second)

  ​    {

  ​        cout << pos.first->second << endl;

  ​        ++pos.first;

  ​    }

### 1.3 容器适配器 Container adaptors

#### 1.3.0 所有容器适配器都有的成员函数

* .push(val)
* .top() // 返回stack顶部 或 queue队头元素的引用
* .pop() 
* .front() .back() // 使用前必须先判断容器是否为空 否则会出现错误

#### 1.3.1 stack

#include &lt;stack&gt;

#### 1.3.2 queue

访问和删除只能在队头 增加只能在队尾

#include &lt;queue&gt;

#### 1.3.3 priority_queue

#include &lt;queue&gt;

* 队头元素总是最大的 内部并非完全有序 

* 只能用.top()访问堆顶元素

* 可以自定义cmp函数 cmp返回false的时候交换位置(wanted condition return false)

* 元素优先级设置方法

  * 基本数据类型

    默认最大的放前面 可以加入参数greater &lt;type&gt;()

  * 结构体 

    struct fruit { // 方法一 不用在申明容器时加入cmp参数

    ​	string name; int price;

    ​	friend bool operator < (fruit f1, fruit f2) {

    ​		return f1.price < f2.price; // 价格高的优先

    ​		return f1.price > f2.price; // 价格低的优先

    ​	}

    };

    struct cmp { // 方法二 申明容器时加入cmp参数

    ​	bool operator () (fruit f1, fruit f2) {

    ​		return f1.price > f2.price; // 价格低的优先

    ​	}	

    }; priority_queue&lt;fruit, vector&lt;fruit&gt;, cmp&gt; //第二个参数是承载底层数据结构堆的容器

    其他数据类型或stl容器 也可以通过同样的方式定义优先级

## 2. 算法 Algorithm

### 2.0 头文件

&lt;algorithm&gt; &lt;numeric&gt;

### 2.1 不改变原序列的算法

![NotChangeOrder](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/NotChangeOrder.jpeg)

* max(a, max(b,c)); // 三个元素最大值
* next_permutation(it1, it2) //给出一个序列在全排列中的下一个序列 // 231的下一个序列是312 // 到达全排列最后一个时返回false

### 2.2 改变元素值的算法

![ChangeVal](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/ChangeVal.jpeg)

* swap(x, y);
* fill(arr, arr+5, 233); // 填充的数据类型更灵活
* abs()整型 vs fabs()浮点型(#include &lt;cmath&gt;)

### 2.3 删除元素的算法

![DeleteVal](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/DeleteVal.jpeg)

### 2.4 改变顺序的算法

#### 2.4.1 变序算法

![changeOrder](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/changeOrder.jpeg)

* reverse(it1, it2) //将数组指针或迭代器[it1, it2)直接的元素反转 string的子串也可以

#### 2.4.2 排序算法

![Sort](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/Sort.jpeg)

### 2.5 操作有序区间的算法

![OperateOrdered](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/OperateOrdered.jpeg)

对于集合A，B（可以使用数组、list、vector、set）

merge() //归并两个序列，元素总个数不变，只是将两个有序序列归并为一个有序序列。
set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(tosave, tosave.begin())) //将集合A，B的并保存到tosave中
set_difference()//实现求集合A，B的差（即A—B）
set_symmetric_difference()//实现求集合A，B的对称差（即(A-B)并(B-A))
set_intersection()//实现求集合A，B交集

## 3. 树和图的实现

### 3.1 树的实现

#### 3.1.1 树的建立

二叉树的创建就是二叉树节点的插入过程

```c++
Node* create(int data[], int n) {
	node* root = NULL; // 新建空节点root
	for (int i = 0; i < n; ++i) {
		insert(root, data[i]);
	}
	return root;
}
```

* 完全二叉树中的任何一个编号为x（从1开始）的节点x, 其左孩子编号为2x，右孩子编号为2x+1

  所以可以通过一个大小为2^k的数组存储 k为完全二叉树的最大高度。

  判断某个节点是否为叶节点为：该节点（记下标为root）的左子节点的编号root*2大于节点总个数

  判断某个节点是否为空节点：该节点下表root大于总及节点个数n

* 二叉树的静态实现（用结构体数组/静态链表代替链表）

* 对于一般的树，指针域存放所有**直系**子节点的地址/下标，用数组模拟树

  ```c++
  struct node {
      type data;
      vector<int> child; // 新建节点时 .clear()
  }nodes[maxn];
  ```


#### 3.1.2 树的遍历

DFS：先序遍历 中序遍历 后序遍历（这个名字是针对root被访问的顺序）

BFS：层序遍历

Void layerOrder(node* root) {

​	queue<node*> Q; // 使用node\*才能对原node做更改

​	Q.push(root);

​	while(!Q.empty()) {

​		node* fro = Q.front(); // 另存队首元素

​		Q.pop(); // 弹出队首元素

​		printf("%d ", fro->data); // 访问队首元素

​		if (fro->left != NULL) Q.push(fro->left); // 左子树非空

​		if (fro->right != NULL) Q.push(fro->right); // 右子树非空

​	}

}

当题目要求取得节点的层次，就需要在node结构体中增加layer成员。根节点的layer为0或1。之后每个节点入队前都把他的节点记为当前节点fro的layer+1。

**应用例题**

* 给定一颗二叉树的先序遍历和中序遍历序列，重建这颗二叉树

  ![preOrderAndinOrder](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/preOrderAndinOrder.png)

  // 当前先序序列区间为[preL, preR] 中序序列区间为[inL, inR] 返回根节点位置

  ```c++
  // 当前先序序列区间为[preL, preR] 中序序列区间为[inL, inR] 返回根节点位置
  node* createTree(preL, preR, inL, inR) {
      if (preL > preR) return; // 序列为空时 返回
      node* root = new node;
      root->data = preSeq[preL];
      int k; // root在中序序列中的位置
      for (k = inL; k <= inR; ++k) {
          if (inSeq[k] == root->data) break;
      }
      int numLeft = k - inL; // 左子树节点个数 (用右子树容易错= =)
      // 左子树先序区间为[preL+1, preL+numLeft] 中序区间为[inL, k-1]
      root->left = createTree(preL+1, preL+numLeft, intL, k-1);
      // 右子树先序区间为[preL+numLeft+1, preR] 中序区间为[k+1, inR]
      root->right = create(preL+1+numLeft, preR, k+1, inR);
      return root;
  }
  ```


#### 3.1.3 增删查改

##### 3.1.3.1 查改

void search(node* root, int oldV, int newV) { // 修改指针指向的内容不需要加引用	

​	if (root == NULL) return;

​	if (root->data == oldV) root->data = newV;

​	search(root->left, oldV, newV);

​	search(root->right, oldV, newV);

}

##### 3.1.3.2 插入增加

插入位置就是查找失败的位置

void insert(node*& root, int x) { // 注意使用引用 否则插入不会成功

​	if (root == NULL) {

​		root = createNode(x); return 0; // 新建节点务必让他左右子树为NULL

​	}

​	if (x应该插在左子树) insert(root->left, x); // 往左子树搜索 递归式

​	else insert(root->right, x);

}

### 3.2 图的实现

#### 3.2.1 图的建立

一般用queue实现

#### 3.2.2 图的遍历

- BFS 广度优先 (可以看作树的层序遍历)

  - 模版1：（遍历/标记每一个点 -> 块状广搜标记式）

  void BFS(x, y, z...) {

  ​	queue&lt;type&gt; q; type Node;

  ​	q.push(startNode); inq标记start已经入队

  ​	while (!q.empty()) {

  ​		访问/另存队首元素top;

  ​		将队首元素出队pop; // 当一个node被弹出 意味着这一块都要被标记好了

  ​		通过规则（如方向）得到下一个点的坐标x,y,z...

  ​		judge函数判断是否是需要访问的点（越界/节点值非所求/节点已经入队了 返回false）

  ​		if true 将坐标值赋给临时Node Node入队(传入副本)

  ​		 -> 将top的下一层未曾入队的节点全部入队 并标记为已经入队		

  ​	}

  }

  （循环枚举每一个点 

  if(节点值是所求 && !inq) 传入BFS函数做标记）



  * 模版2：（找到起点到终点的最短路径 -> 外扩式广搜）

    ```c++
    int BFS() { // 返回最小步数 即到终点的层数
        queue<node> q; q.push(S); inq[S.x][S.y]=true;
        while (!q.empty()) {
            node fro = q.front();
            q.pop(); // 当一个node被弹出 意味着通过它能访问到的下一层要被处理了
            if (fro.x == T.x && fro.y == T.y) return fro.step; // 已经到达终点
            for (int i = 0; i < 4; ++i) {
                int newX = fro.x + X[i]; int newY = fro.y + Y[i];
                if (test(newX, newY)) {
                    Node.x = newX; Node.y = newY; Node.step = fro.step+1;
                    q.push(Node); inq[newX][newY] = true;
                }
            }
        }
        return -1; // 无法到达终点
    }
    ```

- DFS 深度优先 (可以看作树的先根遍历)

  给出一组东西，所求是一个满足某种条件的序列：

  建两个vector 分别存储临时序列和最优序列 index指向当前一组东西里被处理的那个

  如果对序列元素有要求的话 函数参数还需要nowSelect 记录选了几个了

  void DFS(int index, int nowSelect...) {

  ​	如果当前状态已经符合条件 用临时解更新最优解

  ​	否则 对于每一件东西都有选与不选两个分支

  ​	tmp.push_back(东西[index]); // 把这个东西加入临时序列tmp

  ​        DFS(index, nowK+1...); // 选了第index个东西的分支

  ​        tmp.pop_back(); // 选的分支结束后把刚加进去的东西pop掉

  ​        DFS(index+1, nowK...); // 不选的分支 如果东西的索引是逆序的 就是index-1 具体情况具体分析

  }

## 3. 参考资料 References

- 1. 郭炜《新标准C++程序设计》
- 2. 晴神《算法笔记》












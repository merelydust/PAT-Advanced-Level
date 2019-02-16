# C++11 STL Cheat Sheet

collected by github@merelydust for AC٩(˃̶͈̀௰˂̶͈́)و

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
      * [3. 参考资料 References](#3-参考资料)

## 1.容器 Container

容器是类模版 充分发挥想象力！(●°u°●)​ 」

### 1.0 所有容器都有的成员函数

* .size() return int

* .empty() return bool

* 两对迭代器 容器类名::iterator it & 容器类名::reverse_iterator rit

  ![iterator](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/iterator.png)

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

* v.insert(iterator, val); 

* v.erase(iterator start, iterator end)   // 如果只有一个参数 只删除该迭代器指向的参数

  remove函数返回值是空，erase返回指向下一个元素的迭代器

* v.clear()
* v.swap(vector&lt;type&gt; &v2) // v内容与另一个同类型的v2互换
* vector1 == vector2 // 表明两个序列完全相同（数字和顺序）

#### 1.1.2 双向链表 list

#include &lt;list&gt;

![ListMFuncs](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/ListMFuncs.jpeg)

#### 1.1.3 双向队列 deque

#include &lt;deque&gt;

deque也是可变长数组，适用于vector的操作都适用于它。比起vector，它在头尾增删元素的性能更好，有两个vector没有的成员函数: 

.push_front(val) & .pop_front(val)

#### 1.1.4 字符串 string

* 赋值可以接收char数组

* .substr(startPos, len) // 如果省略len参数或者len&gt;原字符串长度 则子串取到原串末尾

* s1.swap(s2) // 交换两个字符串内容

* s1.find(pos, s2) // 从pos位开始寻找

* s1.find_first_of(s2) // 寻找s1中第一次出现s2中任一字符的位置 s1.find_first_not_of(s2) 寻找第一个s2没有的字符

  .find_last_of .find_last_not_of // 从后往前找

* s1.replace(pos, len, str2) // 把s1从pos开始 长度为len的子串 替换成s2

  s1.replace(it1, it2, str2)

* 删除单个字符 .erase(it)

  删除字符区间 .erase(it1, it2) 或 .erase(pos, len)

* 插入字符 .insert(pos, string) 或 .insert(it1, it2, it3)

### 1.2 关联容器 Associative Containers

不能修改元素值或map的关键字。

#### 1.2.0 所有关联容器都有的成员函数

* .find(val)

* .lower_bound(val) 

* .upper_bound(val) 

* 如果没有找到val元素 则返回val应该在的位置 

  如果想要下标而不是地址 令返回值减去数组首地址即可

* .count(val) // how many elements.value == val

* .insert(val)

#### 1.2.1 集合 set

#include &lt;set&gt;

.insert(val) // return 插入成功 ? true : false

#### 1.2.2 映射 map

#include &lt;map&gt; // 包含了&lt;utility&gt;头文件 -> pair

通过关键字访问/通过迭代器访问

it-&gt;first 访问关键字 it-&gt;second 访问值

- .find(key) 返回iterator

- .erase(key) .erase(it) .erase(it1, it2) .clear()

- multimap的插入和遍历

  ```c++
  multimap<string, string> mulMap;
  multimap.insert(make_pair("鲁迅", "朝花夕拾"));
  typedef multimap<string, string>::iterator multiMapItor;
  pair<multiMapItor, multiMapItor> pos = mulMap.equal_range(key);
  while (pos.first != pos.second) {
      cout << pos.first->second << endl;
      ++pos.first;
  }
  ```



### 1.3 容器适配器 Container adaptors

#### 1.3.0 所有容器适配器都有的成员函数

* .push(val)
* .top() // 返回stack顶部 或 queue队头元素的引用
* .pop()  // **没有返回值**
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

  * 结构体 （其他数据类型或stl容器 也可以通过同样的方式定义优先级）

    ```c++
    struct fruit { // 方法一 不用在申明容器时加入cmp参数
    
    	string name; int price;
    
    	friend bool operator < (fruit f1, fruit f2) {
    
    		return f1.price < f2.price; // 价格高的优先
    
    		return f1.price > f2.price; // 价格低的优先
    
    	}
    
    };
    
    
    struct cmp { // 方法二 申明容器时加入cmp参数
    
    	bool operator () (fruit f1, fruit f2) {
    
    		return f1.price > f2.price; // 价格低的优先
    
    	}	
    
    }; 
    priority_queue<fruit, vector<fruit>, cmp> //第二个参数是承载底层数据结构堆的容器
    ```


## 2. 算法 Algorithm

### 2.0 头文件

&lt;algorithm&gt; &lt;numeric&gt;

### 2.1 不改变原序列的算法

![NotChangeOrder](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/NotChangeOrder.jpeg)

* max(a, max(b,c)); // 三个元素最大值

### 2.2 改变元素值的算法

![ChangeVal](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/ChangeVal.jpeg)

* swap(x, y);
* fill(arr, arr+5, 233); // 填充的数据类型更灵活
* abs()整型 vs fabs()浮点型(后者要#include &lt;cmath&gt;)

### 2.3 删除元素的算法

![DeleteVal](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/DeleteVal.jpeg)

* unique函数

  unique是 c++标准模板库STL中十分实用的函数之一，使用此函数需要

  ```
  #include <algorithm>
  ```

  该函数的作用是“去除”容器或者数组中相邻元素的重复出现的元素，注意 
  (1) 这里的去除并非真正意义的erase，而是将重复的元素放到容器的末尾，返回值是去重之后的尾地址。 
  (2) unique针对的是相邻元素，所以对于顺序顺序错乱的数组成员，或者容器成员，需要先进行排序，可以调用std::sort()函数

  ```c++
  #include <iostream>
  #include <algorithm>
  using namespace std;
  int main(void)
  {
      int a[8] = {2, 2, 2, 4, 4, 6, 7, 8};
      int c;
  
      //sort(a, a + 8);  对于无序的数组需要先排序
  
      c = (unique(a, a + 8) - a ); // 无重复子序列的末位
  
      cout<< "c = " << c << endl;
  
      //打印去重后的数组成员
      for (int i = 0; i < c; i++)
          cout<< "a = [" << i << "] = " << a[i] << endl;
  
      return 0;
  }
  ```


### 2.4 改变顺序的算法

#### 2.4.1 变序算法

![changeOrder](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/changeOrder.jpeg)

* reverse(it1, it2) //将数组指针或迭代器[it1, it2)直接的元素反转 string的子串也可以

* next_permutation(it1, it2) 

  给出一个序列在全排列中的下一个序列，如231的下一个序列是312，到达全排列最后一个时返回false

#### 2.4.2 排序算法

![Sort](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/Sort.jpeg)

* 堆的STL实现代码

  **堆是一棵完全二叉树 所以用数组模拟很方便*

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {4, 5, 1, 3, 2};
    // 把nums数组变成堆结构
    make_heap(nums.begin(), nums.end());
    cout << "initial max value : " << nums.front() << endl;
    // 弹出堆顶/最大值
    pop_heap(nums.begin(), nums.end()); // stl会把堆顶放到数组末尾同时调整元素顺序维持堆结构
    nums.pop_back(); // 用vector的方法弹出末尾
    cout << "after pop, the max value : " << nums.front() << endl;
    // 放入新元素
    nums.push_back(6); // 用vector的方法加在末尾
    push_heap(nums.begin(), nums.end()); // stl会调整好新元素的位置维持堆结构
}
```



* 手写堆

  ```c++
  const int maxn = 100;
  int heap[maxn], n = 10; // heap为堆 n为元素个数
  
  // 弹出堆顶并用末尾元素覆盖堆顶位置后要向下调整 即把节点从上往下挪
  // 向下调整的对象是非叶子节点 将节点v与它的左右孩子（如果有的话）比较，如果有孩子权值大于v，则与v交换位置。交换完毕后继续让v和新孩子比较，直到节点v的孩子都比v小/不存在
  // 将heap数组在[low, high]范围内向下调整，low是欲调节的数组下标，high是堆的最后一个元素的数组下标
  void downAdjust(int low, int high) {
      int i = low, j = i * 2; // i为欲调整节点j是两个孩子中较大那个的下标 初始为左孩子下标
      while (j <= high) { // 存在孩子节点
          // 如果存在右孩子 且右孩子比左孩子大
          if (j+1 <= high && heap[j+1] > heap[j]) {
              j = j + 1; // 让j存储右孩子下标
          }
          if (heap[j] > heap[i]) {
          swap(heap[j], heap[i]);
          i = j; // 保持i为欲调整节点
          j = i * 2; // j是i的左孩子
      } 
          else break; // 孩子权值都比欲调整节点i小
      }
  }
  
  // 建堆
  // 序列元素个数为n 完全二叉树叶子节点个数位n/2，所以数组下标[1, n/2]范围内都是非叶子节点。于是可以从n/2号位开始倒着枚举节点，对每个遍历到的i都进行向下调整。
  // 为啥要倒着枚举？因为每次调整完一个节点，这个位置的节点就会变成它所在子树的最大值。倒着枚举从树的视角来看就是从级别低的root向终极root走，最终可以保证每个节点都是以其为根节点的子树中值最大的。
  void createHeap() {
      for (int i = n / 2; i >= 1; --i) {
          downAdjust(i, n); // 共有n个元素
      }
  }
  
  // 删除堆中最大元素也就是堆顶元素 保持堆结构
  void deleteTop() {
      heap[1] = heap[n--]; // 用最后一个元素覆盖堆顶元素 然后让元素个素减一
      downAdjust(1, n); // 向下调整堆顶元素
  }
  
  // 添加元素
  // 将元素放在数组最后 进行向上调整操作
  // 把欲比较节点与父节点做比较 如果权值比父节点大 就交换其与父节点 反复比较 知道到达堆顶或父节点较大
  // heap数组在[low, high]范围内向上调整
  // high是欲调整节点下标，low设为堆顶下标1
  void upAdjust(int low, int high) {
      int i = high, j = i / 2; // i为欲调整节点 j为其父亲
      while (j >= low) { // 父亲在[low, high]范围内
          if (heap[j] < heap[i]) {
              swap(heap[j], heap[i]);
              i = j; j = i / 2;
          }
          else break;
      }
  }
  // 开始添加元素
  void insert(int x) {
      heap[++n] = x;
      upAdjust(1, n);
  }
  
  // 堆排序
  // 建堆后 将堆的最后一个元素替换到堆顶 进行向下调整(最大的就到最后了)
  // 如此重复 直到堆中只有一个元素(上一步实际上是在不断删除堆顶)
  // 具体实现时 可以倒着遍历数组 假设当前访问到i号位置 那么将堆顶元素和i号元素交换 接着在[1, i-1]范围内对堆顶元素进行向下调整
  void heapSort() {
      for (int i = n; i > 1; --i) {
          swap(heap[i], heap[1]);
          downAdjust(heap[1]);
      }
  }
  ```


### 2.5 操作有序区间的算法

![OperateOrdered](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/OperateOrdered.jpeg)

```c++
// 对于集合A、B（可以是数组、list、vector、set）
merge(); //归并两个序列，元素总个数不变，只是将两个有序序列归并为一个有序序列。
//将集合A，B的并集保存到tosave中
set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(tosave, tosave.begin())); 
set_difference(); //实现求集合A，B的差（即A—B）
set_symmetric_difference(); //实现求集合A，B的对称差（即(A-B)并(B-A))
set_intersection(); //实现求集合A，B交集
```



## 3. 树和图的实现

### 3.1 树的实现

#### 3.1.1 树的建立

二叉树的创建就是二叉树节点的插入过程

```c++
struct node {
    int data; // data可以是任意数据类型 这里以int为例
    node* left;
    node* right;
    node() {
        left = right = NULL; // 任何节点的左右子树都初始化为空
    }
};

node* newNode(int val) { // 生成一个值为val的新节点
    node* Node = new node;
    Node->data = v;
    return Node;
}

void insert(node*& root, int val) { // 注意使用引用 否则插入不会成功
	if (root == NULL) {
		root = newNode(val);
	}
	if (val应该插在左子树) insert(root->left, val); // 往左子树搜索 递归式
	else insert(root->right, val);
}

node* create(int data[], int n) {
	node* root = NULL; // 新建空节点root
	for (int i = 0; i < n; ++i) {
		insert(root, data[i]);
	}
	return root;
}
```



* 完全二叉树中的任何一个编号为x（**从1开始**）的节点x, 其左孩子编号为2x，右孩子编号为2x+1

  所以可以通过一个大小为2^k的数组存储（k是完全二叉树的最大高度）。

  要明确一点，**指针**是地址，用数组建树时候，**数组索引**就是地址。

  指针去动态分配的空间寻找存储的数据，数组索引去你划定的结构体数组里寻找存储的数据。

  * 二叉树的静态实现（用结构体数组/静态链表代替链表）

  ```c++
  struct node {
      int data;
      int left; // 左子树根节点的地址
      int right; // 右子树根节点的地址
  }nodes[maxn];
  
  nodes[index].data;// 访问节点存储的数据 index就是地址
  ptrNode->data;// 与上面等价
  ```

* 判断某个节点是否为叶节点为：该节点（记下标为root）的左子节点的编号root*2大于节点总个数

  判断某个节点是否为空节点：该节点下标root大于总及节点个数n

* 对于一般的树，指针域存放所有**直系**子节点的地址/下标，用数组存放树

  ```c++
  struct node {
      type data;
      vector<int> child; // 新建节点时 .clear()
  }nodes[maxn];
  ```


#### 3.1.2 树的遍历

DFS：先序遍历 中序遍历 后序遍历（这个名字是针对root被访问的顺序）

BFS：层序遍历

```c++
void layerOrder(node* root) {
    queue<node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        node* fro = Q.front(); // 另存队首元素
        Q.pop(); // 弹出队首元素
        printf("%d ", fro->data); // 访问队首元素
		if (fro->left != NULL) Q.push(fro->left); // 左子树非空
		if (fro->right != NULL) Q.push(fro->right); // 右子树非空
    }
}
```



* 当题目要求取得节点的层次，可以在node结构体中增加layer成员。根节点的layer为0或1。之后每个节点入队前都把他的节点记为当前节点fro的layer+1。

* 如何把给定序列填充到二叉查找树里？

  因为中序遍历树是从小到大的顺序，所以先把序列从小到大排序，再中序遍历树，过程中把序列里的值填进去即可。

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
      root->right = createTree(preL+1+numLeft, preR, k+1, inR);
      return root;
  }
  ```


#### 3.1.3 增删查改

##### 3.1.3.1 查改

```c++
void search(node* root, int oldV, int newV) { // 修改指针指向的内容不需要加引用	

	if (root == NULL) return;

	if (root->data == oldV) root->data = newV;

	search(root->left, oldV, newV);

	search(root->right, oldV, newV);

}
```



##### 3.1.3.2 插入增加

插入位置就是查找失败的位置

```c++
void insert(node*& root, int x) { // 注意使用引用 否则插入不会成功
	if (root == NULL) {
		root = newNode(x);
	}
	if (x应该插在左子树) insert(root->left, x); // 往左子树搜索 递归式
	else insert(root->right, x);
}
```

* AVL的旋转

  * 左旋右旋

    (从图形上看，左旋就是左边下降，右旋就是右边下降)

  ![AVLRotation](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/AVLRotation.png)

  **注意 上图中的树是平衡的 只是为了演示左旋右旋*

  * 针对LL型失衡树和LR型失衡树的措施

  ![LL](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/LL.png)

  ![LR](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/LR.png)

  * 总结：

  ![RotationSum](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/RotationSum.png)

  ![AVLInsertCode](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/AVLInsertCode.png)

* 哈夫曼树

  叶子节点的带权路径长度(WPL): 叶子节点的权值*其路径长度(从根节点出发到达该节点经过的边数)

  带权路径长度最小的树叫做哈夫曼树，又称最优二叉树。哈夫曼树可以不唯一，但其WPL值唯一。

  用优先队列或堆实现。先将所有元素压入优先队列，每次取出两个最小的，合并，再压回优先队列，直到队列中只剩下一个元素。

  构建思想：反复选择最小的两个元素，合并，直到只剩下一个元素。

  哈夫曼编码：出现频次越小，对应节点权值越小。

### 3.2 图的实现

#### 3.2.1 图的建立

* 邻接矩阵，二维数组实现，所需空间较大，一般只适用于1000以下的节点。

* 用vector数组Adj[N]实现邻接表，其中N为顶点个数。

  如果是有向图，节点a增加一条到节点b的边，只需要Adj[a].push_back(b);

  如果是无向图，还需要增加一行Adj[b].push_back(a)。

  如果需要同时存放编号和边权值，则建立结构体node

  ```c++
  struct node {
      int v; // 节点
      int w; // 边权
  }
  ```

  这样邻接表中的元素就是node类型的。

  * 注意区分点权和边权。

#### 3.2.2 图的遍历

- BFS 广度优先 (可以看作树的层序遍历)

  * 遍历模版

    ```c++
    BFS(u) { // 遍历u所在连通块
        queue<type> Q; 
        Q.push(u); inq[u] = true;
        while (!Q.empty()) {
            type fro = Q.front(); Q.pop();
            for (从u可以直接到达的所有子节点v) 「
                if (!inq[v]) {
                    Q.push(v); inq[v] = true;
                }
        }
    }
    
    BFSTraverse(G) {
        for (G的所有顶点u) {
            if (!inq[u]) BFS(u); // 遍历u所在的连通块
        }
    }
    ```

  * 邻接矩阵版

    ```c++
    int n, G[maxn][maxn];
    bool inq[maxn] = {false};
    
    void BFS(int u) { // 以int为例
        queue<int> Q; 
        Q.push(u); inq[u] = true;
        while (!Q.empty()) { // 遍历整个连通块
            int fro = Q.front; Q.pop();
            for (int v = 0; v < n; ++v) {
                if (G[fro][v] && !inq[v]) { // 假定G[u][v]=1代表连通 为0代表不连通
                    Q.push(v); inq[v] = true;
                }
            }
        }
    }
    
    void BFSTraverse() {
        for (int u = 0; u < n; ++u) {
            if (!inq[u]) BFS(u);
        } 
    }
    ```

  * 邻接表版

    ```c++
    const int maxn
    vector<int> Adj[maxn]; // 存放从u出发可以直接到达的v
    bool inq[maxn] = {false};
    
    void BFS(int u) {
        queue<int> Q;
        Q.push(u); inq[u] = true;
        while (!Q.empty()) {
            int fro = Q.front; Q.pop();
            for (int i = 0; i < Adj[fro].size(); ++i) {
                int v = Adj[fro][i];
                if (!inq[v]) {
                    Q.push(v); inq[v] = true;
                }
            }
        }
    }
    
    void BFSTraverse() {
        for (int u = 0; u < n; ++u) { // 枚举所有顶点
            if (!inq[u]) { // 是一个新的连通块
                BFS(u);
            }
        }
    }
    ```


  - 题型模版1：（遍历/标记每一个点 -> 块状标记式）

    ```c++
    void BFS(坐标/序号...) }{
        queue<type> Q; 
        Q.push(startNode); inq[startNode] = true;
        while (!Q.empty()) {
            type fro = Q.front();
            Q.pop(); //当这个node被弹出 意味着它所处的整个连通块都将被标记
            通过规则（如枚举方向或子节点）得到下一个点;
            judge函数判断是否是需要访问的点; // 越界/节点值非所求/节点已经入队了 返回false
            if (judge) 将这个点入队并标记已经入队inq[node]=true; 
            // 入队是传入副本 如果要改变对象则选择让对象的编号入队
            // 如果参数不是type型比如坐标 则建立临时节点tmp 将参数赋予tmp tmp入队
            // 这一轮会将fro直系连接的下一层全部入队
        }
    }
    
    void BFSTraverse() {
        循环枚举每一个点;
        if(两点连通 && !inq) 传入BFS函数标记所处的整个连通块;
    }
    ```


  * 题型模版2：（找到起点到终点的最短路径 -> 外扩式）

    ```c++
    int BFS() { // 返回最小步数 即到终点的层数
        queue<node> q; q.push(S); inq[S.x][S.y]=true;
        while (!q.empty()) {
            node fro = q.front();
            q.pop(); // 当一个node被弹出 意味着通过它能访问到的下一层要被处理了
            if (fro.x == T.x && fro.y == T.y) return fro.step; // 已经到达终点
            for (int i = 0; i < 4; ++i) {
                int newX = fro.x + X[i]; int newY = fro.y + Y[i];
                if (judge(newX, newY)) {
                    Node.x = newX; Node.y = newY; Node.step = fro.step+1;
                    q.push(Node); inq[newX][newY] = true;
                }
            }
        }
        return -1; // 无法到达终点
    }
    ```

- DFS 深度优先 (可以看作树的先根遍历)

  * 遍历模版

    ```c++
    DFS(u) { // 访问顶点u
        vis[u] = true; // 设置u已经被访问
        for (从u出发能直接到达的所有顶点v) {
            if (!vis[v]) DFS(v);
    }
    
    DFSTraverse(G) { // 遍历图G
        for (G的所有顶点u) {
            if (!vis[u]) DFS(u);
        }
    }
    // 如果给的图是一个连通图，则一次DFS就能完成遍历。
    ```

    * 邻接矩阵版

    ```c++
    const int maxn = 1000; int n; // 实际总节点数n
    bool vis[maxn] = {false};
    // 二位数组 邻接矩阵 G[maxn][maxn]
    void DFS(int u, int depth) { // u为当前访问节点 深度为depth 不需要深度不加也行
        vis[u] = true;
        // 这里可以操作u / max(maxDepth, depth)取得最大深度
        // 枚举从u出发能直接到达的分支顶点
        // 如果图中存在环 即两个已经被访问过的v中间还有一条边(u->v1, u->v2, v1-v2)
        // 为了不重复计算(u->v1 v1->u) 使用完一条边权后就要将其归0 G[u][v] = G[v][u] = 0
        // 把vis[i]的判断放在累积边权之后 就能包括环的边即已经访问过的两个节点之间的边了
        for (int v = 0; v < n; ++v) {
            if (!vis[v] && G[u][v]) { 
                DFS(v, depth+1);
            }
        }
    }
    
    void DFSTraverse() { // 遍历图
        for (int u = 0; u < n; ++u) { // 对每个顶点u
            if (!vis[u]) DFS(u, 1); // 遍历u以及u所在的连通块 1表示第一层
        }
    }
    ```

  * 邻接表版

    ```c++
    vector<int> Adj;
    int n;
    bool vis[maxn] = {false};
    
    void DFS(int u, int depth) {
        vis[u] = true;
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = Adj[u][i];
            if (!vis[v]) DFS(v, depth+1);
        }
    }
    
    void DFSTraverse() {
        for (int u = 0; u < n; ++u) {
            if (!vis[u]) DFS(u, 1);
        }
    }
    ```

  * 题型模版

  ```c++
  // 给出一组东西，所求是一个满足某种条件的序列
  // 建两个vector 分别存储临时序列tmp和最优序列ans;
  // 如果对序列元素个数有要求的话 函数参数还需要nowSelect 记录选了几个了
  void DFS(int index, int nowSelect...) { // 变量index指向当前被处理的对象
      if (当前状态已符合条件/到达递归出口) 临时解更新最优解/进行某种计算;
      else {
          // 对于每一件东西都有选与不选两个分支/分支数量是固定的 枚举递归; 
          tmp.push_back(当前这个东西); DFS(index, nowSelect+1...); // 选了第index个东西的分支
          tmp.pop_back(); // 选的分支结束后把刚加进去的东西pop掉
          DFS(index+1, nowK...); // 不选的分支 如果东西的索引是逆序的 就是index-1 具体情况具体分析
          // 如果是完全背包问题 index可以不变
      }
  }
  
  // 总结： 分支数量是给定的 DFS枚举递归写更简洁 如一般的树 枚举节点的孩子集合
  for(int i=0; i<node.children.size(); ++i) {
      DFS(node.children[index][i]...)
  }
  ```

* 最短路径算法

  * Dijkstra算法

    Dijsstra解决的是单源最短路问题，即给定起点s，求s到其他顶点的最短距路。

    **策略**

    设置集合S存放已被访问的点，然后执行n次下面的步骤:

    1. 从未访问的点中选择与起点s距离最短的点u，访问并加入集合S
    2. 让u作为中节点，优化起点s与所有能从u到达的顶点v的最短距离。

    **具体实现**

    ```c++
    // 伪代码
    // G为图 一般设置为全局变量 数组d为起点到各点最短路径长度 s为起点
    void Dijkstra(G, d[], s) {
        初始化;
        for (循环n次) {
            u = 使d[u]最小且还未被访问的顶点编号;
            标记u已经被访问;
            for (从u出发能到达的所有顶点v) {
                if (v未被访问 && 以u为中介点能使s到v的最短距离d[v]更优) {
                    优化d[v];
                }
        }
    }
    ```

    写出具体函数前 先定义maxn为最大顶点数和 INF表示不连通

    ```c++
    const int maxn = 1000;
    const int INF = 10 << 9;
    ```

    **邻接矩阵版**

    适用于点数不大(一两千)的情况

    ```c++
    void Dijkstra(int s) { // s为起点
        fill(d, d + maxn, INF); // fill函数将整个d数组赋值为INF 这里不能用memset
        d[s] = 0; // 到自身的距离为0
        for (int i = 0 ; i < n; ++i) {
            int u = -1, MIN = INF; // u使d[u]最小 MIN存放该最小的d[u]
            for (int j = 0; j < n; ++j) { // 找到未访问的节点中d[]最小的
                if (!vis[j] && d[j] < MIN) {
                    u = j; MIN = d[u];
                }
            }
            if (u == -1) return; // 找不到说明剩下的节点和s连通不了
            vis[u] = true;
            for (int v = 0; v < n; ++v) {
                // v未被访问 && u能到达v && 以u为中节点可以使d[v]更优
                if (!vis[v] && G[u][v] != INF && d[u]+G[u][v] < d[v]) { 
                    d[v] = d[u] + G[u][v];
                }
            }
        }
    }
    ```

    **邻接表版**

    只有更新最短距离的for循环跟邻接矩阵不一样

    ```c++
    struct node {
        int v, dis; // v为边的目标顶点 dis为边权
    };
    vector<node> Adj[maxn];
    
    for (int j = 0; j < Adj[u].size(); ++j) {
        int v = Adj[u][j].v; // 通过邻接表直接获得u能到达的顶点v
        if (!vis[v] && d[u]+Adj[u][j].dis < d[v]) {
            d[v] = d[u]+Adj[u].dis;
        }
    }
    ```

    用pre保存所有能使v产生最短路径的前驱节点

    ![Dijkstra](https://github.com/merelydust/PAT-Advanced-Level/blob/master/C%2B%2B11_STL_CheatSheet/STLimg/Dijkstra.png)


## 3. 参考资料 References

- 1. 郭炜《新标准C++程序设计》
- 2. 晴神《算法笔记》












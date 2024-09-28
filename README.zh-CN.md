# C++ 数据结构与算法

[![C++ Build](https://github.com/MasonCodingHere/cpp-algorithms/actions/workflows/ci.yml/badge.svg)](https://github.com/MasonCodingHere/cpp-algorithms/actions/workflows/ci.yml)

> Read this in other languages: 🇬🇧[_English_](README.md)

本仓库包含了多种基于 C++ 的算法与数据结构。

每种算法和数据结构都有自己的 README，包含相关说明和链接，以便进一步阅读 (还有 YouTube 视频) 。

*☝注意：本项目仅用于学习和研究，**不是**用于生产环境。*

## 数据结构

数据结构是在计算机中组织和存储数据的一种特殊方式，使得数据可以高效地被访问和修改。更确切地说，数据结构是数据值的集合，表示数据之间的关系，也包括了作用在数据上的函数或操作。

`B` - 初学者， `A` - 进阶

* `B` [链表](data-structures/linked-list)
* `B` [双链表](data-structures/doubly-linked-list)

## 算法

算法是如何解决一类问题的明确规范。算法是一组精确定义操作序列的规则。

`B` - 初学者， `A` - 进阶

## 如何使用本仓库

1. 克隆本仓库至本地。

```bash
git clone https://github.com/MasonCodingHere/cpp-algorithms.git
```

2. 进入仓库目录，选择你感兴趣的数据结构或算法，以链表为例。

```bash
cd cpp-algorithms/data-structures/linked-list
```
3. 构建

```bash
./build.sh
```


## 有用的信息

### 大O符号

大O符号中指定的算法的增长顺序。

![Big O graphs](./assets/big-o-graph.png)

> 源: [Big O Cheat Sheet](http://bigocheatsheet.com/).

以下是一些最常用的 大O标记法 列表以及它们与不同大小输入数据的性能比较。

| 大O标记法      | 计算10个元素                 | 计算100个元素                 | 计算1000个元素                  |
| -------------- | ---------------------------- | ----------------------------- | ------------------------------- |
| **O(1)**       | 1                            | 1                             | 1                               |
| **O(log N)**   | 3                            | 6                             | 9                               |
| **O(N)**       | 10                           | 100                           | 1000                            |
| **O(N log N)** | 30                           | 600                           | 9000                            |
| **O(N^2)**     | 100                          | 10000                         | 1000000                         |
| **O(2^N)**     | 1024                         | 1.26e+29                      | 1.07e+301                       |
| **O(N!)**      | 3628800                      | 9.3e+157                      | 4.02e+2567                      |

### 数据结构操作的复杂性

| 数据结构       |  连接  |  查找  |  插入  |  删除  | 备注 |
| -------------- | :----: | :----: | :----: | :----: | ---- |
| **数组**       |   1    |   n    |   n    |   n    |      |
| **栈**         |   n    |   n    |   1    |   1    |      |
| **队列**       |   n    |   n    |   1    |   1    |      |
| **链表**       |   n    |   n    |   1    |   1    |      |
| **哈希表**     |   -    |   n    |   n    |   n    | 在完全哈希函数情况下，复杂度是 O(1） |
| **二分查找树** |   n    |   n    |   n    |   n    | 在平衡树情况下，复杂度是 O(log(n)) |
| **B 树**       | log(n) | log(n) | log(n) | log(n) |      |
| **红黑树**     | log(n) | log(n) | log(n) | log(n) |      |
| **AVL 树**     | log(n) | log(n) | log(n) | log(n) |      |
| **布隆过滤器** |   -    |   1    |   1    | - | 存在一定概率的判断错误（误判成存在） |

### 数组排序算法的复杂性

| 名称                  | 最优      | 平均      | 最坏          | 内存      | 稳定      | 备注                  |
| --------------------- | :-------: | :-------: | :-----------: | :-------: | :-------: | --------------------- |
| **冒泡排序**          | n         | n^2       | n^2           | 1         | Yes       |                       |
| **插入排序**          | n         | n^2       | n^2           | 1         | Yes       |                       |
| **选择排序**          | n^2       | n^2       | n^2           | 1         | No        |                       |
| **堆排序**            | n log(n)  | n log(n)  | n log(n)      | 1         | No        |                       |
| **归并排序**          | n log(n)  | n log(n)  | n log(n)      | n         | Yes       |                       |
| **快速排序**          | n log(n)  | n log(n)  | n^2           | log(n)    | No        | 在 in-place 版本下，内存复杂度通常是 O(log(n)) |
| **希尔排序**          | n log(n)  | 取决于差距序列   | n (log(n))^2  | 1         | No        |  |
| **计数排序**          | n + r     | n + r     | n + r         | n + r     | Yes       | r - 数组里最大的数    |
| **基数排序**          | n * k     | n * k     | n * k         | n + k     | Yes       | k - 最长 key 的升序   |


## 参考
1. [trekhleb的javascript-algorithms仓库](https://github.com/trekhleb/javascript-algorithms)
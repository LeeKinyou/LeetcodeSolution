# LeetCode Solution

个人 LeetCode 刷题题解仓库，记录算法学习历程。代码按算法主题分类整理，方便查阅与复习。

## 项目结构

```
├── cpp/              # C++ 题解，按算法主题分类
│   ├── array/        # 数组相关题目
│   ├── binary_search # 二分查找
│   ├── bit/          # 位运算
│   ├── design/       # 设计类题目
│   ├── dp/           # 动态规划
│   ├── graph/        # 图论
│   ├── math/         # 数学相关
│   ├── sorting/      # 排序算法
│   ├── string/       # 字符串处理
│   ├── tree/         # 树与二叉树
│   ├── two_pointers/ # 双指针
│   └── utils/        # 通用工具函数
└── java/             # Java 题解，按题目系列分类
    ├── LCR/          # 剑指 Offer (专项突击版)
    └── mainstation/  # LeetCode 主站题目
```

## 环境说明

- **C++**: 使用 C++17 标准，基于 `iostream` 和 STL 标准库
- **Java**: 基于 JUnit 5 单元测试，每个题目包含 `Solution` 类和对应的 `AnswerTest` 测试类

## 使用方式

### C++

直接编译运行对应文件即可：

```bash
g++ -std=c++17 cpp/array/2011_finalValueAfterOperations.cpp -o solution && ./solution
```

### Java

使用 Maven 或 IDE 运行单元测试：

```bash
mvn test -Dtest=java/LCR/LCR012/AnswerTest
```

## 工具函数

`cpp/utils/utils.cpp` 包含一些常用的工具函数和模板，如输入输出优化、常用数据结构定义等。

## 作者

Lee Kinyou

## License

本项目仅供学习交流使用。

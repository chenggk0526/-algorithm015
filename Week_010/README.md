学习笔记
一、做题方法
1、4件套：
    （1）与面试官确认题目意思
    （2）想出所有可能解决的方法，列出时间复杂度与空间复杂度
    （3）确定最优解决防范
    （4）写代码，测试
2、五毒神掌：
    （1）第一遍：不要死磕，看代码学习
    （2）第二遍：自己写
    （3）第三遍：24h后
    （4）第四遍：一周后
    （5）第五遍：面试前


二、第一周：
1、数组：增、删数据时间复杂度o(n)。
2、链表：
    （1）每一个元素一般是class，两个成员变量，val与next（指针）。
    （2）增、删操作为o(1)
    （3）查询为o(n)。
3、跳表：只能用于元素有序的情况
    （1）跳表如何加速查询：主要思想为：对于一维有序的数据结构，可通过升维进行查询加速
    （2）跳表的索引因为元素的增、删可能出现不连续，同时其维护成本较高，增、删时间复杂度o(logn)
4、栈与队列：
    （1）栈：先进后出
    （2）队列：先进先出
    （3）两者增、删皆为o(1),查询为o(n)
    （4）如果在工程中需要使用stack，推荐直接使用deque。
5、priority queue
    （1）插入o(1)
    （2）取出o(logn)，按照元素的优先级取出
    （3）底层具体实现结构较为多样及复杂：heap、bst、treap


三、第二周
1、哈希表，也叫散列表，查询、插入、删除都是o(1)
2、树、二叉树、二叉搜索树的实现和特性
    （1）二叉树遍历：前序：根左右；中序：左根右；后序：左右根
    （2）图与数的差别：关键在于形成环没有，有环则为图。
    （3）二叉搜索树：左子树上所有结点的值均小于它的根节点的值，右子树上所有结点的值均大于它的根节点的值；其中序遍历是升序排列
        a 查询：o(logn)
        b 插入：查询到最后，将其添加至该节点
        c 删除：如果在叶子节点，删除即可，如果是根节点，则删除该节点，找到第一个大于其的节点，将其充当为新的根节点。
3、堆和二叉堆的实现和特性
    （1）堆：可以迅速找到一堆数中的最大值或最小值的数据结构
    （2）二叉堆：通过完全二叉树来实现（不是二叉搜索树）
        a 完全二叉树：根与每一层都是满的，出来最后一层可能不满之外，跟二叉搜索树没有关系。
        b 工程中直接调用priority_queue
        c 实现过程中的技术处理：交换时，可以先将交换的值往下拉，最后再将插入的值更新至其该在的位置。减少了每次比较时的赋值。


四、第三周
1、递归：数的面试题解法一般都是递归
    （1）模板
        void recursion(int level, int param) { 
        // recursion terminator
        if (level > MAX_LEVEL) { 
            // process result 
            return ; 
        }

        // process current logic 
        process(level, param);

        // drill down 
        recursion(level + 1, param);

        // reverse the current level status if needed
        }
    （2）节点的意义
    （3）自相似性
    （4）思维要点：
        a 不要人肉递归
        b 找到最近最简方法，将其拆解成可重复解决的问题（重复子问题）
        c 数学归纳法思维
2、分治：
    int divide_conquer(Problem *problem, int params) {
    // recursion terminator
    if (problem == nullptr) {
        process_result
        return return_result;
    } 

    // process current problem
    subproblems = split_problem(problem, data)
    subresult1 = divide_conquer(subproblem[0], p1)
    subresult2 = divide_conquer(subproblem[1], p1)
    subresult3 = divide_conquer(subproblem[2], p1)
    ...

    // merge
    result = process_result(subresult1, subresult2, subresult3)
    // revert the current level status
    
    return 0;
    }


五、第四周
1、贪心算法：是一种在每一步选择中都采取当前状态下最好或最优（即最有利）的选择，从而希望导致结构是全局最好或最优的算法
    （1）与回溯、DP的区别：当下做局部最优判断；回溯：能够回退；DP：最优判断+回退
    （2）适用场景：问题能够分解成子问题来解决，子问题的最优解能够地推到最终问题的最优解，这种子问题的最优解成为最优子结构
2、二分查找
    （1）使用前提：
        a 目标函数单调性（单调递增或递减）
        b 存在上下界
        c 能够通过索引访问
    （2）模板
        int binarySearch(const vector<int>& nums, int target) {
            int left = 0, right = (int)nums.size()-1;
            
            while (left <= right) {
                int mid = left + (right - left)/ 2;
                if (nums[mid] == target) return mid;
                else if (nums[mid] < target) left = mid + 1;
                else right = mid - 1;
            }
            
            return -1;
        }


六、第六周
1、动态规划：动态规划和递归或者分治没有根本上的区别（关键看有无最优的子结构）
    （1）三者共性：找到重复子问题
    （2）差异性：最优子结构、中途可以淘汰次优解
    （3）思维习惯：
        a 自顶向下：递归或分治和记忆化
        b 自底向上：for loop
        c 动态规划初期可用递归或分治的思维，高手或终极形态为自底向上。
    （4）关键点：
        a 最优子结构 opt[n] = best_of(opt[n-1], opt[n-2],...)
        b 储存中间状态：opt[i]
        c 递归公式（状态转移方程或者DP方程）Fib: opt[i] = opt[n-1] + opt[n-2]


七、第七周
1、字典树
    （1）优点：最大限度地减少无谓的字符串比较，查询效率比哈希高
    （2）核心思想：空间换时间，利用字符去的公共前缀来降低查询时间的开销以达到提高效率的目的
2、并查集
    （1）适用场景：组团、配对问题；group or not？
    （2）基本操作：
        a makeSet(s)：建立一个新的并查集，其中包含S个单元素集合
        b unionSet(x, y): 把元素x和元素y所在的集合合并，要求x和Y所在的集合不相交，如果相交则不合并
        c find(x): 找到元素x所在的集合的代表，该操作也可以用于判断两个元素是否位于同一个集合，只要将它们各自的代表比较一下就可以了
    （3）代码模板
            class UnionFind {
            public:
                UnionFind(vector<vector<char>>& grid) {
                    count = 0;
                    int m = grid.size();
                    int n = grid[0].size();
                    for (int i = 0; i < m; ++i) {
                        for (int j = 0; j < n; ++j) {
                            if (grid[i][j] == '1') {
                                parent.push_back(i * n + j);
                                ++count;
                            }
                            else {
                                parent.push_back(-1);
                            }
                            rank.push_back(0);
                        }
                    }
                }
                int find(int i) {
                    if (parent[i] != i) {
                        parent[i] = find(parent[i]);
                    }
                    return parent[i];
                }
                void unite(int x, int y) {
                    int rootx = find(x);
                    int rooty = find(y);
                    if (rootx != rooty) {
                        if (rank[rootx] < rank[rooty]) {
                            swap(rootx, rooty);
                        }
                        parent[rooty] = rootx;
                        if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
                        --count;
                    }
                }
                int getCount() const {
                    return count;
                }
            private:
                vector<int> parent;
                vector<int> rank;
                int count;
            };

3、高级搜索
    （1）朴素搜索
    （2）优化方式：不重复、剪枝
    （3）搜索方向：DFS、BFS
    （4）双向搜索
    （5）启发式搜索：是一种告知搜索方法的方法，它提供了一种明智的方法来猜测哪个邻居结点会导向一个目标
4、AVL树和红黑树的实现和特性
    （1）balance factor = {-1, 0, 1}
    （2）通过旋转操作来进行平衡：左旋、右旋、左右旋、右左旋
    （3）总结
        a 平衡二叉搜索树
        b 每个结点存balance factor = {-1, 0, 1}
        c 四种旋转操作
        d 不足：结点需要存储额外信息，且调整次数频繁
5、红黑树：是一种近似平衡的二叉搜索树，它能够确保任何一个结点的左右子树的高度差小于两倍。具体来说，红黑树是满足如下条件的二叉搜索树：
    （1）每个结点要么是红色、要么是黑色
    （2）根结点是黑色
    （3）每个叶结点（NIL、空结点）是黑色的
    （4）不能有相邻接的两个红色结点
    （5）从任一结点到其每个叶子的所有路径都包含相同数目的黑色结点
    关键性质：从根到叶子的最长的可能路径不多于最短的可能路径的两倍长


八、第八周
1、位运算：
    （1）运算符：
        左移  <<
        右移  >>
        按位或  |
        按位与  &
        按位取反  ~
        按位异或 ^
    （2）异或：相同为0， 不同为1
        x ^ 0 = x;
        x ^ 1s = ~x //(1s = ~0)
        x ^ (~x) = 1s
        x ^ x = 0
        c = a ^ b => a ^ c = b, b ^ c = a // 交换两个数
        a ^ b ^ c = a ^ (b ^ c) = (a ^ b) ^ c
    （3）指定位置的位运算
        将x最右边的n位清零： x & (~0 << n)
        获取x的第n位值（0或者1）： （x >> n） & 1
        获取x的第n位幂值： x & (1 << n)
        仅将第n位置为0 ： x & (~(1 << n))
        仅将第n位置为1 ： x | (1 << n)
        将x最高位至第n位（含）清零： x & ((1 << n) - 1)
    （4）实战要点
        判断奇偶：x & 1
        x >> 1 -> x / 2
        清零最低位的1：x = x & (x - 1)
        得到最低位的1：x & -x
        x & ~x = 0

2、布隆过滤器：一个很长的二进制向量和一系列随机映射函数。
    （1）布隆过滤器可以用于检查一个元素是否在一个集合中
    （2）优点：空间效率和查询时间都远远超过一般的算法
    （3）缺点：有一定的误识别率和删除困难

3、LRU Cache
    （1）两个要素：大小、替换策略
    （2）hash table + double LinkedList
    （3）查询、修改、更新 o(1)

4、初级排序和高级排序
    （1）比较类排序、非比较类排序
    （2）初级排序（o(n^2)）
        a 选择排序
        b 插入排序
        c 冒泡排序：循环嵌套，每次查看相邻元素如果逆序，则交换
    （3）高级排序
        a 快速排序：数组取标杆pivot，将小元素放pivot左边，大元素放右侧，然后依次对左右两边的子数组进行快排，以达到整个序列有序
        b 归并排序-分治：分为两个n / 2 的子序列，分别对子序列进行归并排序，merge
        c 堆排序：数组元素依次建立小顶堆，依次取堆顶元素并删除。堆插入o(logn)，取最大/最小o(1)
    （4）特殊排序
        a 计数排序
        b 桶排序
        c 基数排序


九、第九周
1、高级动态规划：状态转移方程遇到一维解决不了的时候，进行升维


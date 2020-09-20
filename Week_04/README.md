学习笔记 Week 04
搜索遍历搜索
	* 
每个节点都要访问一次
	* 
每个节点仅访问一次

深度优先搜索 (DFS， Depth First Search)
代码模板:
//C/C++
//递归写法：
map<int, int> visited;

void dfs(Node* root) {
  // terminator
  if (!root) return ;

  if (visited.count(root->val)) {
    // already visited
    return ;
  }

  visited[root->val] = 1;

  // process current node here. 
  // ...
  for (int i = 0; i < root->children.size(); ++i) {
    dfs(root->children[i]);
  }
  return ;
}

//C/C++
//非递归写法：
void dfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  stack<Node*> stackNode;
  stackNode.push(root);

  while (!stackNode.empty()) {
    Node* node = stackNode.top();
    stackNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;


    for (int i = node->children.size() - 1; i >= 0; --i) {
        stackNode.push(node->children[i]);
    }
  }

  return ;
}广度优先搜索 (BFS, Breadth First Search)
一层一层的往下遍历
代码模板:
// C/C++
void bfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  queue<Node*> queueNode;
  queueNode.push(root);

  while (!queueNode.empty()) {
    Node* node = queueNode.top();
    queueNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;

    for (int i = 0; i < node->children.size(); ++i) {
        queueNode.push(node->children[i]);
    }
  }

  return ;
}优先级优先搜索
启发搜索贪心算法
在每一步选择中都采取在当前状态下最好活最优的选择，从而希望到时结果是全局最好或最优的算法适用场景
一旦一个问题可以使用贪心算法，那么贪心算法一般是解决这个问题的最好办法
	* 
解决一些最优化的问题

		* 
最小生成树
		* 
哈夫曼编码
	* 
用作辅助算法
	* 
解决一些结果要求不特别精确的问题
	* 
能分解成子问题的问题，子问题的最优解能递推到最终问题的最优解(子问题最优解被称为最优子结构)

与动态规划的区别
	* 
贪心

		* 
对每个子问题的解决方案都做出选择
		* 
不能回退
	* 
动态规划

		* 
保存以前的运算结果，并根据以前的结果对当前进行选择
		* 
有回退功能

二分查找
代码模板：

C/C++

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


前提条件
	* 
目标函数单调性(单调递增或递减)
	* 
存在上下界
	* 
能够通过索引访问


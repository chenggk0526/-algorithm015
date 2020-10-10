动态规划
1、动态规划将一个复杂问题分解为简单子问题，递归求解，采用分治 + 最优子结构，与其说是动态规划，更贴切的是动态递推。
2、分治、回溯、递归，本质上没有多大的差别(关键看有无最优子结构)
3、共性: 找到重复子问题
4、差异性: 最优子结构、中途可以淘汰次优解
5、两种思维模式：动态规划有自顶向下(递归)、自底向上(循环)两种解法，初期可采用递归加记忆化搜索方式，但高手或终极形态使用自底向上循环的思维方式。
6、动态规划关键点：最优子结构、储存中间状态、递归公式（状态转移方程或DP方程）

递归模板
// C/C++
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

分治模板
C/C++
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


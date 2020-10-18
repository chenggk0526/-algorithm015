学习笔记
1、字典树		
（1）优点：最大限度地减少无谓的字符串比较，查找效率比哈希表高。	   
（2）基本性质：
	a. 结点本身不存在完整单词；	
	b. 从根结点到某一结点，路径上经过的字符连接起来，为该结点对应的字符串；	
	c. 每个结点所有的子结点路径代表的字符都不相同。	
（3）核心思想：	
	空间换时间，利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的。
（4）代码模板：
//C/C++
class Trie {
    struct TrieNode {
        map<char, TrieNode*>child_table;
        int end;
        TrieNode(): end(0) {}
    };
        
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->child_table.count(word[i]) == 0)
                curr->child_table[word[i]] = new TrieNode();
                
            curr = curr->child_table[word[i]];                
        }
        curr->end = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word, 1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix, 0);
    }
private:
    TrieNode* root;
    bool find(string s, int exact_match) {
        TrieNode *curr = root;
        for (int i = 0; i < s.size(); i++) {
            if (curr->child_table.count(s[i]) == 0)
                return false;
            else
                curr = curr->child_table[s[i]];
        }
        
        if (exact_match)
            return (curr->end) ? true : false;
        else
            return true;
    }
};


2、并查集
（1）适用场景：
	a. 组团、配对问题
	b.Group or not?
（2）基本操作：
	a. makeSet(s): 建立一个新的并查集，其中包含S个单元素集合。
	b. unionSet(x, y): 把元素x和元素y所在的集合合并，要求x和y所在的集合不相交，如果相交则不合并。
	c. find(x): 找到元素x所在的集合的代表，该操作也可以用于判断两个元素是否位于同一个集合，只要将他们各自的代表比较一下就可以了
（3）重点操作：
	a.初始化
	b.查询、合并
	c.路径压缩
（4）代码模板：
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

//递归
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
（1）初级搜索：
	a.朴素搜索
	b.优化方式：不重复（fibonacci)、剪枝（生成括号问题）
	c.搜索方向：DFS、BFS
（2）高级搜索：双向搜索、启发式搜索

4、AVL树和红黑树的实现和特性
（1）AVL
	a.  平衡二叉搜索树
	b.  balance factor = {-1,0,1}
	c.  通过旋转操作来进行平衡（左旋、右旋、左右旋、右左旋）
	d. 不足：结点需要存储额外信息、且调整次数频繁
（2）红黑树：红黑树是一种近似平衡的二叉搜索树，它能确保任何一个结点的左右子树的高度差小于两倍。具体来说，红黑树是满足如下条件的二叉搜索树：
	a. 每个结点要么是红色，要么是黑色
	b. 根结点是黑色
	c. 每个叶结点（NIL结点、空结点）是黑色的
	d. 不能有相邻接的两个红色结点
	e. 从任一结点到其每个叶子的所有路径都包含相同数目的黑色结点。
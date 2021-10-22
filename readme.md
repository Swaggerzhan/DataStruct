### 二叉树的前中后序遍历



递归法的遍历过于简单，这里就不在讨论了，这里要讲的是迭代法，模拟了栈的运行方式后也是非常的简单又容易记住。



前序遍历，前序遍历的顺序是 中 -> 左 -> 右，所以我们只要想法将这个过程用栈实现出来即可，也就是遇到节点就将其推进栈中，然后再通过起左右节点判断是否再推进栈中。一开始我们假定栈中已经有一个root节点了。

* 1. 从栈中取出一个节点
* 2. 输出这个节点，判断是否有右节点，有的话，推入栈

* 3. 判断是否有左节点，有的话，推入栈

先推右的原因是栈是反向的，这样一来出栈的顺序就成了先左后右，也就是 中 -> 左 -> 右前序遍历了。

```c++
vector<int> preorder(TreeNode* root) {
  if ( !root )
    return {};
  vector<int> res;
  stack<TreeNode*> s;
  s.push(root);
  while ( !s.empty() ){
    TreeNode* node = s.top();
    s.pop();
    res.push_back(node);
    if ( node->right) // 先推右
      s.push(node->right);
    if ( node->left )
      s.push(node->left);
  }
  return res;
}
```



__前序是 中 -> 左 -> 右，而后序是左 -> 右 -> 中，如果我们将前序的方法改变为先推进左，再推右，那么所整个过程就将变为 中->右->左，现在我们再通过一个栈存储，然后输出，就发现变成了后续遍历了。 __

```c++
vector<int> postOrder(TreeNode* root) {
  if (!root)
    return {};
  stack<TreeNode*> tmp_stack;
  stack<TreeNode*> ret_stack;
  tmp_stack.push(root);

  while ( !tmp_stack.empty() ) {
    TreeNode* node = tmp_stack.top();
    tmp_stack.pop();
    ret_stack.push(node);
    if ( node->left )
      tmp_stack.push(node->left);
    if ( node->right )
      tmp_stack.push(node->right);
  }
  vector<int> ret;
  while ( !ret_stack.empty()) {
    TreeNode* node = ret_stack.top();
    ret_stack.pop();
    ret.push_back(node->val);
  }
  return ret;
}
```

最后是中序遍历，中序遍历的主要思想是尽量的将左节点先全部的压入到栈中去，然后再一个个取出，一个个输出，并且输出的同时，还要再判断一下是否有右节点(也就是右子树嘛)。

```c++
vector<int> inOrder(TreeNode* root){
  if ( !root )
    return {};
  vector<int> ret;
  stack<TreeNode*> s;
  TreeNode* node = root;
  while ( !s.empty() || node != nullptr ) {
    while ( node != nullptr) { // 尽量全部压入栈中
      s.push(node);
      node = node->left;
    }
    if ( !s.empty() ){
      TreeNode* tmp = s.top();
      s.pop();
      ret.push_back(tmp->val); // 输出
      node = tmp->right; 			 // 如果发现有右节点，那么我们也需要将右节点压入
    }													 // 这里的右节点其实就是 "右子树"
  }
  return ret;
}
```


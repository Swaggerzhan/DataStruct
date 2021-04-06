//
// Created by swagger on 2021/4/6.
//

#ifndef DATASTRUCT_BINARYTREE_H

#define DATASTRUCT_BINARYTREE_H


#include <iostream>
#include <queue>


using namespace std;

template <typename Key, typename Value>
class BinaryTree{


private:

    /* 将树的节点隐藏在其中 */
    struct Node{
        Key key;
        Value value;
        Node* left;
        Node* right;

        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = nullptr;
        }

        Node(Node* node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    // 树节点的个数
    int count;

    // 树根
    Node* root;


public:

    BinaryTree(){
        count = 0;
        root = nullptr;
    }

    /**
     * 销毁方式可以使用树的后序遍历来进行
     */
    ~BinaryTree(){
        destroy(root);
    }

    bool isEmpty(){ return count == 0;}


    /**
     * 调用了私有insert方法，其中私有insert方法使用了return来保持树的结构
     * @param key
     * @param value
     */
    void insert(Key key, Value value){
        root = insert(root, key, value);
    }


    void preOrder(){ preOrder(root); }
    void inOrder(){ inOrder(root); cout<<endl;}
    void posOrder(){ posOrder(root); }


    /**
     * 给定一个key判断树中是否存在这个节点
     * @param key
     * @return
     */
    bool contain(Key key){
        return contain(root, key);
    }

    /**
     * 给定一个key，返回树中这个key对应的value
     * 由于这个节点可能不存在，所以直接返回value的指针，当然也可以先使用contain判断是否存在再取值
     * @param key
     * @return
     */
    Value* search(Key key){
        return search(root, key);
    }


    /**
     * 层序遍历可以使用队列来实现
     */
    void levelOrder(){
        if (root == nullptr)
            return;
        queue<Node*> q;
        q.push(root);
        while ( !q.empty() ){
            Node* node = q.front();
            q.pop();
            cout << node->key << " ";
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);

        }

        cout << endl;
    }


    Key min(){
        assert(count != 0);
        Node* node =  min(root);
        return node->key;
    }



    Key max(){
        assert(count != 0);
        Node* node = max(root);
        return node->key;
    }


    /**
     * 删除最小的元素
     */
    void removeMin(){
        assert( count != 0);
        root = removeMin(root);
    }

    void removeMax(){
        assert( count != 0);
        root = removeMax(root);
    }

    /*
     * 删除所指向的key节点
     *
     */
    void remove(Key key){
        assert( count != 0);
        root = remove(root, key);
    }

private:

    Node* remove(Node* node, Key key){
        if (node == nullptr)
            return nullptr;

        if (key < node->key ){
            node->left = remove(node->left, key);
            return node;
        }else if (key > node->key){
            node->right = remove(node->right, key);
            return node;
        }else {
            /* 如果既不小于也没有大于，那就是找到所要删除的节点了 */
            if ( node->left == nullptr ){
                // 左节点没有东西的情况下很简单，只需要将右节点接上即可
                Node* rightNode = node->right;
                delete node;
                count --;
                return rightNode;
            }
            if ( node->right == nullptr ){
                // 同上
                Node *leftNode = node->left;
                delete leftNode;
                count --;
                return leftNode;
            }
            /* 这种情况就是左右都有节点的情况
             * 可以将右节点的最小值最为新节点
             * 也可以将左节点的最大值作为新节点
             * */
            Node* successor = new Node(min(node->right));
            //这里多复制了一份，所以需要++，在后面的remove中会--掉，保持平衡
            count ++;
            /* 将node的右边节点最小节点删除，返回给新的替代node的节点 */
            successor->right = removeMin(node->right);
            /* 接上left */
            successor->left = node->left;

            delete node;
            count --;

            return successor;

        }
    }



    Node* removeMax(Node* node){

        if (node->right == nullptr){
            Node* nodeLeft = node->left;
            delete node;
            count --;
            return nodeLeft;
        }
        node->right = removeMax(node->right);
        return node;
        /* 类似removeMin */
    }


    Node* removeMin(Node* node){
        if (node->left == nullptr){
            Node* nodeRight = node->right;
            delete node;
            count --;
            // 将右节点返回给上层递归，即使nodeRight是nullptr也满足
            return nodeRight;
        }

        node->left = removeMin(node->left);
        // 如果当前节点并不是需要删除的节点，就将当前的结果返回给上层递归
        // 因为我们需要维护上层递归来达到"接上树"的目的
        return node;
    }

    Node* max(Node* node){
        if (node->right == nullptr)
            return node;
        return max(node->right);
    }

    Node* min(Node* node){
        if (node->left == nullptr)
            return node;
        return min(node->left);
    }

    void destroy(Node* node){

        if (node != nullptr ){
            destroy(node->left);
            destroy(node->right);
            delete node;
            count --;
        }

    }

    Value* search(Node* node, Key key){

        /* search的方法和contain相似 */
        if ( node == nullptr )
            return nullptr;
        else if (node->key == key)
            return &(node->value);
        else if (key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);

    }


    bool contain(Node* node, Key key){
        /* 这种和insert方法是有些许不同的
         * contain不需要将最底层的递归结果返回给上层，所以可以直接return
         * */
        if (node == nullptr )
            return false;
        else if (node->key == key)
            return true;
        else if (key < node->key )
            return contain(node->left, key);
        else
            return contain(node->right, key);

    }

    void preOrder(Node* node){
        if (node != nullptr){
            cout << node->key << endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(Node* node){
        if (node != nullptr ){
            inOrder(node->left);
            cout << node->key << " ";
            inOrder(node->right);
        }

    }

    void posOrder(Node* node){
        if (node != nullptr ){
            posOrder(node->left);
            posOrder(node->right);
            cout << node->key << endl;
        }
    }


    /**
     * 这是个分而治之的过程，将根节点的插入问题转换成左节点或右节点的插入问题
     * return是为了保持整颗树的完整
     * @param node
     * @param key
     * @param value
     * @return
     */
    Node* insert(Node* node, Key key, Value value){

        if ( node == nullptr ){
            node = new Node(key, value);
            count ++;
        }


        /* 如果节点小于当前的节点，就往左边的树中插入 */
        if (key < node->key)
            /* 插入后需要将当前节点返回给上层调用的节点的左节点处 */
            node->left = insert(node->left, key, value);
        else if (key > node->key)
            node->right = insert(node->right, key, value);

        return node;

    }

};



#endif //DATASTRUCT_BINARYTREE_H

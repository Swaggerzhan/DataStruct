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

private:

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

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
    void inOrder(){ inOrder(root); }
    void posOrder(){ posOrder(root); }

private:

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
            cout << node->key << endl;
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

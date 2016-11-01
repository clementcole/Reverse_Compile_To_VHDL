#ifndef TREE_META_H
#define TREE_META_H
/*1353899646907*/
#include <cstddef>
#include <vector>
using namespace std;

template<class T>
class TreeNode {

private:

    T* data;
    TreeNode<T>* parent;
    vector< TreeNode<T>* > children;

public:

    TreeNode(TreeNode<T>* parent, T data);
    ~TreeNode();

    T& getData() const;
    void setData(const T& data);
    void addChild(const T& data);
    void removeChild(const size_t& indx);
    TreeNode<T>* findChild(const T& data) const;
    TreeNode<T>* getChild(const size_t& indx) const;
    TreeNode<T>* getParent() const;
    int getNumChildren() const;

};

template<class T>
TreeNode<T>::TreeNode(TreeNode<T>* parent, T data) : parent(parent) {
    this->data = new T(data);
}

template<class T>
TreeNode<T>::~TreeNode() {
    delete data;
    for(TreeNode<T>* childNode : children)
        delete childNode;
}

template<class T>
T& TreeNode<T>::getData() const {
    return *this->data;
}

template<class T>
void TreeNode<T>::setData(const T& data) {
    *this->data = data;
}

template<class T>
void TreeNode<T>::addChild(const T& data) {
    children.push_back(new TreeNode<T>(this, data));
}

template<class T>
void TreeNode<T>::removeChild(const size_t& indx) {
    children.erase(children.begin()+indx);
}

template<class T>
TreeNode<T>* TreeNode<T>::findChild(const T& data) const {
    for(int i=0; i<children.size(); i++)
        if(children[i]->getData() == data)
            return children[i];
    return NULL;
}

template<class T>
TreeNode<T>* TreeNode<T>::getChild(const size_t& indx) const {
    return children[indx];
}

template<class T>
TreeNode<T>* TreeNode<T>::getParent() const {
    return parent;
}

template<class T>
int TreeNode<T>::getNumChildren() const {
    return children.size();
}


#endif
// Clase nodo
#include <string>
template<class T> class BST;
template<class T>
class NodeT
{
    friend class BST<T>; // clase amiga
    friend class BSTAnimales; // clase amiga
    private:
        T data;
        NodeT<T> *left, *right;
    public:
        NodeT() {left = right = nullptr;};
        NodeT(T d) {data = d; left = right= nullptr;};
};
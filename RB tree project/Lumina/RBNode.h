#include "Criminal.h"
#include "Header.h"
using namespace std;


struct RBNode
{
    int key;       // key
    RBNode* p;     // pointer to parent
    RBNode* left;  // pointer to left child
    RBNode* right; // pointer to right child
    enum color { RED, BLACK };
    color col;
    Criminal criminal;
    static RBNode* Nil; // sentinel leaf node

    RBNode(Criminal cr, RBNode* l = Nil, RBNode* r = Nil, RBNode* parent = Nil, color c = RBNode::BLACK) :
        criminal(cr), key(cr.getID()), p(parent), left(l), right(r), col(c) {}

    RBNode(int x, RBNode* l = Nil, RBNode* r = Nil, RBNode* parent = Nil, color c = RBNode::BLACK) :
        key(x), p(parent), left(l), right(r), col(c) {}


    string toString()
    {
        ostringstream os;
        os << key << ((col == RBNode::RED) ? ":r" : ":b");
        return os.str();
    }

    ~RBNode()
    {
        if (this != Nil)
        {
            if (left != Nil)
                delete left;
            if (right != Nil)
                delete right;
        }
    }

};

struct RBTree
{
    RBNode* root;

    void LeftRotate(RBNode* x)
    {
        // Set y
        RBNode* y = x->right;
        // Turn y's left subtree into x's right subtree
        x->right = y->left;
        if (y->left != RBNode::Nil)
            y->left->p = x;
        // link x's parent to y
        y->p = x->p;
        if (x->p == RBNode::Nil)
            root = y;
        else if (x == x->p->left)
            x->p->left = y;
        else
            x->p->right = y;
        // Put x on y's left
        y->left = x;
        x->p = y;
    }
    /*
    void perform(RBTree* RB,int o)
    {
        list<int> nodeKeys;
        RBNode* rbn;
        int skey;
        switch (o)
        {
        case 1: // Add nodes
            IODialog::getNodeKeys(nodeKeys);
            for (list<int>::iterator it = nodeKeys.begin();
                it != nodeKeys.end(); it++)
                this->RBInsert(this->createNode(*it));
            break;
        case 2: // Delete node
            skey = IODialog::getNodeKey();
            rbn = this->search(this->root, skey);
            if (!this->isNil(rbn)) this->del(rbn);
            else cout << "RB: Node not found" << endl;
            break;
        case 3: // Show tree RB
            this->indentedDisplay();
            break;
        case 4:
            cout << "\nInorder traversal of RB tree yields" << endl << ' ';
            this->inorder();
            cout << endl;
            break;
        case 5: // Exit
            delete this;
            cout << "Bye!" << endl;
            exit(0);
        }
    }

    void startProcessing()
    {
        int o;
        while (true)
        {
            o = IODialog::getTreeOperation();
            perform(this, o);
        }
    }


    /**
     * RightRotate(y) also assumes that y is the right child of
     * an RBNode x
     */

    void RightRotate(RBNode* y)
    {
        // Set x
        RBNode* x = y->left;
        // Turn x's right subtree into y's left subtree
        y->left = x->right;
        if (x->right != RBNode::Nil)
            x->right->p = y;
        // link y's parent to x
        x->p = y->p;
        if (y->p == RBNode::Nil)
            root = x;
        else if (y == y->p->left)
            y->p->left = x;
        else
            y->p->right = x;
        // Put y on x's right
        x->right = y;
        y->p = x;
    }

    RBTree()
    {
        root = RBNode::Nil;
    }
    ~RBTree()
    {
        delete root;
    }

    static RBNode* createNode(Criminal criminal)
    {
        return new RBNode(criminal);
    }

    static bool isNil(RBNode* n)
    {
        return (n == RBNode::Nil);
    }

    static RBNode* search(RBNode* w, int key)
    {
        if (isNil(w) || w->key == key)
            return w;
        return search((key < w->key) ? w->left : w->right, key);
    }

    /**
     * maximum(w) returns the node with maximum key in the
     * RB-tree with root node w
     */
    RBNode* maximum(RBNode* w)
    {
        RBNode* x = w;
        while (!isNil(x->right))
            x = x->right;
        return x;
    }

    /**
     * minimum(w) returns the node with minimum key in the
     * RB-tree with root node w
     */
    RBNode* minimum(RBNode* w)
    {
        RBNode* x = w;
        while (!isNil(x->left))
            x = x->left;
        return x;
    }

    /**
     * successor(w) returns the successor of node w in the
     * RB-tree to which node w belongs
     */
    RBNode* successor(RBNode* w)
    {
        if (isNil(w)) return w;
        RBNode* x = w;
        if (!isNil(x->right))
            return minimum(x->right);
        RBNode* y = x->p;
        while (!isNil(y) && x == y->right)
        {
            x = y;
            y = x->p;
        }
        return y;
    }

    RBNode* predecessor(RBNode* w)
    {
        if (isNil(w)) return w;
        RBNode* x = w;
        if (!isNil(x->left))
            return maximum(x->left);
        RBNode* y = x->p;
        while (!isNil(y) && x == y->left)
        {
            x = y;
            y = x->p;
        }
        return y;
    }


    /**
     * RBInsert(z) inserts node z in this RB-tree
     */
    void RBInsert(RBNode* z)
    {
        // insert like in a binary search tree
        RBNode* y = RBNode::Nil;
        RBNode* x = root;
        while (!isNil(x))
        {
            y = x;
            x = (z->key < x->key) ? x->left : x->right;
        }
        z->p = y;
        if (isNil(y))
            root = z;
        else if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
        z->left = z->right = RBNode::Nil;
        z->col = RBNode::RED;
        RBInsertFixup(z);
    }

    RBNode* del(RBNode* z)
    {
        RBNode* y = (isNil(z->left) || isNil(z->right)) ? z : successor(z);
        RBNode* x = !isNil(y->left) ? y->left : y->right;
        x->p = y->p;
        if (isNil(y->p))
        {
            root = x;
        }
        else
        {
            if (y == y->p->left)
                y->p->left = x;
            else
                y->p->right = x;
        }
        if (y != z)
        {
            z->key = y->key;
            // copy y's satellite data into z
        }
        if (y->col == RBNode::BLACK)
            RBDeleteFixup(x);
        return y;
    }

    void RBDeleteFixup(RBNode* x)
    {
        RBNode* w;
        while ((x != root) && (x->col == RBNode::BLACK))
        {
            if (x == x->p->left)
            {
                w = x->p->right;
                if (w->col == RBNode::RED)
                {
                    w->col = RBNode::BLACK;
                    x->p->col = RBNode::RED;
                    LeftRotate(x->p);
                    w = x->p->right;
                }
                if ((w->left->col == RBNode::BLACK) && (w->right->col == RBNode::BLACK))
                {
                    w->col = RBNode::RED;
                    x = x->p;
                }
                else
                {
                    if (w->right->col == RBNode::BLACK)
                    {
                        w->left->col = RBNode::BLACK;
                        w->col = RBNode::RED;
                        RightRotate(w);
                        w = x->p->right;
                    }
                    w->col = x->p->col;
                    x->p->col = RBNode::BLACK;
                    w->right->col = RBNode::BLACK;
                    LeftRotate(x->p);
                    x = root;
                }
            }
            else
            {
                // same as 'then' clause with 'right' and 'left' exchanged
                w = x->p->left;
                if (w->col == RBNode::RED)
                {
                    w->col = RBNode::BLACK;
                    x->p->col = RBNode::RED;
                    RightRotate(x->p);
                    w = x->p->left;
                }
                if ((w->left->col == RBNode::BLACK) && (w->right->col == RBNode::BLACK))
                {
                    w->col = RBNode::RED;
                    x = x->p;
                }
                else
                {
                    if (w->left->col == RBNode::BLACK)
                    {
                        w->right->col = RBNode::BLACK;
                        w->col = RBNode::RED;
                        LeftRotate(w);
                        w = x->p->left;
                    }
                    w->col = x->p->col;
                    x->p->col = RBNode::BLACK;
                    w->left->col = RBNode::BLACK;
                    RightRotate(x->p);
                    x = root;
                }
            }
        }
        x->col = RBNode::BLACK;
    }

    void RBInsertFixup(RBNode* z)
    {
        while (z->p->col == RBNode::RED)
            if (z->p == z->p->p->left)
            {
                RBNode* y = z->p->p->right;
                if (y->col == RBNode::RED)
                {
                    z->p->col = RBNode::BLACK;
                    y->col = RBNode::BLACK;
                    z->p->p->col = RBNode::RED;
                }
                else
                {
                    if (z == z->p->right)
                    {
                        z = z->p;
                        LeftRotate(z);
                    }
                    z->p->col = RBNode::BLACK;
                    z->p->p->col = RBNode::RED;
                    RightRotate(z->p->p);
                }
            }
            else
            {
                /* same as 'then' clause,
                 * with 'left' and 'right' exchanged */
                RBNode* y = z->p->p->left;
                if (y->col == RBNode::RED)
                {
                    z->p->col = RBNode::BLACK;
                    y->col = RBNode::BLACK;
                    z->p->p->col = RBNode::RED;
                }
                else
                {
                    if (z == z->p->left)
                    {
                        z = z->p;
                        RightRotate(z);
                    }
                    z->p->col = RBNode::BLACK;
                    z->p->p->col = RBNode::RED;
                    LeftRotate(z->p->p);
                }
            }
        root->col = RBNode::BLACK;
    }

    void inorder(RBNode* T)
    {
        if (!isNil(T))
        {
            inorder(T->left);
            cout << T->toString() << ' ';
            inorder(T->right);
        }
    }

    void inorder()
    {
        if (isNil(root))
        {
            cout << "empty";
        }
        else
            inorder(root);
    }

    void display(RBNode* w, int indent)
    {
        if (!isNil(w))
        {
            display(w->right, indent + 2);
            for (int i = 0; i < indent; i++) cout << ' ';
            cout << w->toString() << '\n';
            display(w->left, indent + 2);
        }
    }

    void indentedDisplay()
    {
        if (isNil(root))
            cout << "The RB tree is empty" << endl;
        else
        {
            cout << "The RB tree is" << endl;
            display(root, 0);
        }
    }

    // auxiliary method
    int bh(RBNode* x)
    {
        return (isNil(x) ? 0 : countBlacks(x->left));
    }

    // auxiliary method
    int countBlacks(RBNode* x)
    {
        if (isNil(x)) return 1;
        int n = countBlacks(x->left);
        return ((x->col == RBNode::RED) ? n : n + 1);
    }

    /**
     * Compute the black-height of this red-black tree
     */
    int bh()
    {
        int nr = 0;
        RBNode* x = root;
        while (!isNil(x->right))
        {
            if (x->BLACK)
            {
                nr++;
            }
            x = x->right;

        }
        if (x->BLACK)
        {
            nr++;
        }
        return nr;
    }

    // compute the depth of the tree with root *x
    int depth(RBNode* x)
    {
        if (isNil(x))
        {
            return -1;
        }
        else
        {
            int lDepth = depth(x->left);
            int rDepth = depth(x->right);
            return (lDepth < rDepth ? rDepth : lDepth) + 1;
        }
    }

    /**
     * Compute the depth of this red-black tree
     */
    int depth()
    {
        return depth(root);
    }

    /* return the maximum key of black nodes.
     * If the tree is empty, return -1000 */
    int maxBlackKey()
    {
        int nr = 0;
        RBNode* x = root;
        if (isNil(root))
        {
            return -1000;
        }

        while (!isNil(x->right))
        {
            if (x->col == x->BLACK)
            {
                nr = x->key;
            }
            x = x->right;

        }
        if (x->col == x->BLACK)
        {
            nr = x->key;
        }

        return nr;
    }

    /* return the maximum key of red nodes.
     * If the tree has no red nodes, return -1000 */

    int maxRedKey()
    {
        int nr = 0;
        RBNode* x = root;
        bool areNoduriRosii = false;

        while (!isNil(x->right))
        {
            if (x->col == x->RED)
            {
                areNoduriRosii = true;
                nr = x->key;
            }
            x = x->right;

        }
        if (x->col == x->RED)
        {
            areNoduriRosii = true;
            nr = x->key;
        }
        if (areNoduriRosii == true)
            return nr;

        x = root->right;

        while (!isNil(x->left))
        {
            if (x->col == x->RED)
            {
                areNoduriRosii = true;
                nr = x->key;
            }
            x = x->left;

        }
        if (x->col == x->RED)
        {
            areNoduriRosii = true;
            nr = x->key;
        }
        if (areNoduriRosii == true)
            return nr;



        x = root->left;

        while (!isNil(x->right))
        {
            if (x->col == x->RED)
            {
                areNoduriRosii = true;
                nr = x->key;
            }
            x = x->right;

        }
        if (x->col == x->RED)
        {
            areNoduriRosii = true;
            nr = x->key;
        }
        if (areNoduriRosii == true)
            return nr;

        x = root->left;

        while (!isNil(x->left))
        {
            if (x->col == x->RED)
            {
                areNoduriRosii = true;
                nr = x->key;
            }
            x = x->left;

        }
        if (x->col == x->RED)
        {
            areNoduriRosii = true;
            nr = x->key;
        }
        if (areNoduriRosii == true)
            return nr;


        return -1000;
    }
};

#ifndef AVL_NODE_H
#define AVL_NODE_H

#include "abstractnode.h"

class AVL_node : public AbstractNode
{
public:
    explicit AVL_node(int val);

protected:
    char height;
};

#endif // AVL_NODE_H

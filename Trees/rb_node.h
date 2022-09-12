#ifndef RB_NODE_H
#define RB_NODE_H

#include "abstractnode.h"

class RB_node : public AbstractNode
{
public:
    explicit RB_node(int val);

protected:
    bool color;

};

#endif // RB_NODE_H

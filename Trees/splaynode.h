#ifndef SPLAYNODE_H
#define SPLAYNODE_H

#include "abstractnode.h"

class SplayNode : public AbstractNode
{
public:
    SplayNode();

    explicit SplayNode(int val);
};

#endif // SPLAYNODE_H

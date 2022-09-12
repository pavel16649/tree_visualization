#ifndef ABSTRACTNODE_H
#define ABSTRACTNODE_H


class AbstractNode
{
public:
    explicit AbstractNode(int val);

    AbstractNode();

protected:
    AbstractNode* left;

    AbstractNode* right;

    int value;
};

#endif // ABSTRACTNODE_H

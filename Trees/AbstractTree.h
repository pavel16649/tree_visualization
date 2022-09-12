#pragma once
class AbstractTree
{
//protected:

	//int maxRecursive(const node* current) const;

	//int minRecursive(const node* current) const;

public:
	//virtual void erase(int value) = 0;

	virtual bool insert(int value) = 0;

	//virtual void clear() = 0;
	
	virtual void print() const = 0;

	//int min() const;

	//int max() const;
};

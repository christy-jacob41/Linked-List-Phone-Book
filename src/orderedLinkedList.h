/*
 * orderedLinkedList.h
 *
 * Store the DataType values in sorted order. This ordering
 * is determined by the comparison operators of the DataType
 * class.
 *
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_

#include <cstddef>

#include "linkedList.h"

template<class DataType>
class orderedLinkedList
{
	public:
		typedef linkedList<DataType>              		unorderedLinkedList;
		typedef std::bidirectional_iterator_tag			iterator_category;
		typedef std::ptrdiff_t 					     	difference_type;
		typedef std::size_t						      	size_type;
		typedef typename unorderedLinkedList::iterator  iterator;
		typedef const iterator	  	               		const_iterator;
	private:
		// we are making use of the DoubleLinkedList class
		unorderedLinkedList list;
	public:
		// default constructor
		orderedLinkedList();
		// copy constructor
		orderedLinkedList(const orderedLinkedList &other);
		// assignment operator
		const orderedLinkedList& operator=(const orderedLinkedList &other);
		// destructor
		virtual ~orderedLinkedList();
		// iterators
		iterator begin()
		{
			return list.begin();
		}

		iterator end()
		{
			return list.end();
		}

		const_iterator begin() const
		{
			return list.begin();
		}

		const_iterator end() const
		{
			return list.end();
		}

		// number of items in the list
		virtual std::size_t size() const;
		// is the list empty (true) or does it have entries (false)
		virtual bool empty() const;
		// print the items in the list
		virtual void print() const;
		// display the contents of the list to the ostream&
		virtual void print(std::ostream &out) const;
		// display debug information on the passed in ostream
		virtual void debug(std::ostream &out) const;
		// find the element and return an interator for it
		virtual iterator find(const DataType &existingItem);
		// remove the node equal to currentItem
		virtual bool erase(const DataType &currentItem);
		// remove the node by address existingNode
		virtual iterator erase(iterator iter);
		// insert the new item into the list (in sorted order)
		// a duplicate entry will be ignored
		virtual void insert(const DataType &newItem);
		// get the last entry
		iterator back()
		{
		   return list.back();
		}

		const_iterator back() const
		{
		   return list.back();
		}
};

// Your implementation code goes here
//default constructor
template<class DataType>
orderedLinkedList<DataType>::orderedLinkedList()
{
	linkedList<DataType> newList;
	list = newList;
}

template<class DataType>
orderedLinkedList<DataType>::orderedLinkedList(const orderedLinkedList &other)
: list(other)
{
}

template<class DataType>
const orderedLinkedList<DataType>& orderedLinkedList<DataType>::operator=(const orderedLinkedList &other)
{
	list = other;

	return list;
}
template<class DataType>
orderedLinkedList<DataType>::~orderedLinkedList()
{
}
// number of items in the list
template<class DataType>
std::size_t orderedLinkedList<DataType>::size() const
{
	return list.size();
}
// is the list empty (true) or does it have entries (false)
template<class DataType>
bool orderedLinkedList<DataType>::empty() const
{
	return list.empty();
}
// print the items in the list
template<class DataType>
void orderedLinkedList<DataType>::print() const
{
	list.print();
}
// display the contents of the list to the ostream&
template<class DataType>
void orderedLinkedList<DataType>::print(std::ostream &out) const
{
	list.print(out);
}
// display debug information on the passed in ostream
template<class DataType>
void orderedLinkedList<DataType>::debug(std::ostream &out) const
{
	list.debug(out);
}
// find the element and return an interator for it
template<class DataType>
typename orderedLinkedList<DataType>::iterator orderedLinkedList<DataType>::find(const DataType &existingItem)
{
	return list.find(existingItem);
}
// remove the node equal to currentItem
template<class DataType>
bool orderedLinkedList<DataType>::erase(const DataType &currentItem)
{
	return list.erase(currentItem);
}
// remove the node by address existingNode
template<class DataType>
typename orderedLinkedList<DataType>::iterator orderedLinkedList<DataType>::erase(iterator iter)
{
	return list.erase(iter);
}
// insert the new item into the list (in sorted order)
// a duplicate entry will be ignored
template<class DataType>
void orderedLinkedList<DataType>::insert(const DataType &newItem)
{
	orderedLinkedList<DataType>::iterator iter = find(newItem);
	int count = static_cast<int>(size());
	if(iter==end())
	{
		if(count == 0)
		{
			list.push_front(newItem);
		}
		else
		{
			orderedLinkedList<DataType>::iterator tempIter = begin();
			DataType tempData = *(tempIter);
			while(tempData<newItem)
			{
				tempIter++;
				if((tempIter)!=end())
				{
					tempData = *(tempIter);
				}
				else
				{
					break;
				}
			}
			if(count>1)
			{
				tempIter--;
			}
			if(newItem>*(back()))
			{
				list.push_back(newItem);
			}
			else if(newItem<*(begin()))
			{
				list.push_front(newItem);
			}
			else
			{
				list.insert_after(tempIter, newItem);
			}

		}
	}
}
// get the last entry

#endif /* ORDEREDLINKEDLIST_H_ */

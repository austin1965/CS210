// Begin Guard
#ifndef ITEMSOLD_H
#define ITEMSOLD_H

// Dependencies
#include "PythonWrapper.h"

/*
 * Class used to represent items sold and their frequencies of being sold.
 */
class ItemSold {
private:
	// Member variables
	string m_itemName = "";
	int m_numSold = -1;

public:

	// Accessors
	string getItemName() {
		return this->m_itemName;
	}

	int getNumSold() {
		return this->m_numSold;
	}

	// Mutators
	void setItemName(string t_itemName) {
		this->m_itemName = t_itemName;
	}

	void setNumSold(int t_numSold) {
		this->m_numSold = t_numSold;
	}

};

// End Guard
#endif // !ITEMSOLD_H


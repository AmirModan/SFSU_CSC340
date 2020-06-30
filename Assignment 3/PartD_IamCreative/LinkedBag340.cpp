//	LinkedBag340.cpp
//	Created by: CSC340

#include<iostream>
#include<ctime>     
#include"LinkedBag.h"




/**
 * removeSecondNode340()
 * Removes the second node in a bag.
 * 
 * @return remove(node->getItem()), the outcome of the remove operation.
 */
template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {
    Node<ItemType>* node = headPtr->getNext();
    if (remove(node->getItem())) {
        return true;
    } else {
        return false;
    }
    
}


/**
 * addEnd340()
 * Adds a node at the end of a bag.
 *
 * @param item, a constant reference to an item that will be added.
 * @return true, the outcome of the add operation.
 */
template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& item) {
    Node<ItemType>* currentPtr = headPtr;

    while (currentPtr->getNext() != nullptr) {
        currentPtr = currentPtr->getNext();
    }

    Node<ItemType>* newNode = new Node<ItemType>();
    newNode->setItem(item);
    currentPtr->setNext(newNode);
    itemCount++;
    return true;
}


/**
 * getCurrentSize340Iterative()
 * Gets the current size of a bag iteratively.
 *
 * @return num, the size of the bag.
 */
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    int num = 0;
    Node<ItemType>* currentPtr = headPtr;

    while (currentPtr != nullptr) {
        currentPtr = currentPtr->getNext();
        num++;
    }
    return num;
}


/**
 * getCurrentSize340Recursive()
 * Gets the current size of a bag recursively.
 *
 * @return getCurrentSize340RecursiveHelper(currentPtr)
 * , the size of the bag given by the helper.
 */
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
    static Node<ItemType>* currentPtr = headPtr;

    if (currentPtr == nullptr) {
        currentPtr = headPtr;
        return 0;
    }
    currentPtr = currentPtr->getNext();
    return getCurrentSize340RecursiveHelper(currentPtr);
    

}

/**
 * getCurrentSize340RecursiveHelper()
 * Helps get the current size of a bag recursively.
 *
 * @return getCurrentSize340Recursive() + num, the size of the current recursive cycle.
 */
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>*) const {
    int num = 0;
    Node<ItemType>* currentPtr = headPtr;
    if (currentPtr == nullptr) {
        currentPtr = headPtr;
        return 0;
    }
    currentPtr = currentPtr->getNext();
    num++;
    return getCurrentSize340Recursive() + num;
}


/**
 * getCurrentSize340RecursiveNoHelper()
 * Gets the current size of a bag recursively without the use of a helper.
 *
 * @return getCurrentSize340RecursiveNoHelper(currentPtr) + num
 * , the size of the current recursive cycle.
 */
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    int num = 0;
    static Node<ItemType>* currentPtr = headPtr;

    if (currentPtr == nullptr) {
        currentPtr = headPtr;
        return 0;
    }
    currentPtr = currentPtr->getNext();
    num++;
    return getCurrentSize340RecursiveNoHelper() + num;
    
}


/**
 * getFrequencyOf340Recursive()
 * Gets the frequency of an item in a bag recursively.
 *
 * @param item, a constant reference to an item whose frequency will be determined
 * @return getFrequencyOf340RecursiveHelper(currentPtr, item)
 * , the frequency of the item given by the helper.
 */
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& item) const {
    static Node<ItemType>* currentPtr = headPtr;

    if (currentPtr == nullptr) {
        currentPtr = headPtr;
        return 0;
    }
        return getFrequencyOf340RecursiveHelper(currentPtr, item);

}

 
/**
 * getFrequencyOf340RecursiveHelper()
 * Helps get the frequency of an item in a bag recursively.
 *
 * @param item, a constant reference to an item whose frequency will be determined.
 * @return getFrequencyOf340Recursive(item) + num, the frequency of the current recursive cycle.
 */
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>*, const ItemType& item) const {
    int num = 0;
    static Node<ItemType>* currentPtr = headPtr;

    if (currentPtr == nullptr) {
        currentPtr = headPtr;
        return 0;
    } else if (currentPtr->getItem() == item) {
        currentPtr = currentPtr->getNext();
        num++;
        return getFrequencyOf340Recursive(item) + num;
    } else {
        currentPtr = currentPtr->getNext();
        return getFrequencyOf340Recursive(item) + num;
    }

}


/**
 * getFrequencyOf340RecursiveNoHelper()
 * Gets the frequency of an item in a bag recursively without the use of a helper.
 *
 * @param item, a constant reference to an item whose frequency will be determined.
 * @return getFrequencyOf340RecursiveNoHelper(item) + num, the frequency of the current recursive cycle.
 */
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& item) const {
    int num = 0;
    static Node<ItemType>* currentPtr = headPtr;

    if (currentPtr == nullptr) {
        currentPtr = headPtr;
        return 0;
    } else if (currentPtr->getItem() == item) {
        num++;
        currentPtr = currentPtr->getNext();
        return getFrequencyOf340RecursiveNoHelper(item) + num;
    } else {
        currentPtr = currentPtr->getNext();
        return getFrequencyOf340RecursiveNoHelper(item) + num;
    }

}

  
/**
 * removeRandom340()
 * Removes a random item in a bag
 *
 * @return item, the item which is removed.
 */
template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {

    int size = getCurrentSize340Iterative();
    srand(time(0));
    int random = (rand() % size) + 1;

    ItemType item;
    Node<ItemType>* randomNode1 = headPtr;
    for (int i = 0; i < random - 2; i++) {
        randomNode1 = randomNode1->getNext();
    }
    Node<ItemType>* randomNode2 = randomNode1;
    item = randomNode2->getItem();
    remove(item);
    return item;
}


/**
 * removeAllOccurrences()
 * Removes all occurrences of an item in a bag.
 *
 * @param item, the item to be removed.
 * @return item, the item which is removed.
 */
template<typename ItemType>
ItemType LinkedBag<ItemType>::removeAllOccurrences(const ItemType& item) {

    Node<ItemType>* currentPtr = headPtr;

    while (currentPtr != nullptr) {
        if (currentPtr->getItem() == item) {
            remove(currentPtr->getItem());
            currentPtr = currentPtr->getNext();
        }
        else {
            currentPtr = currentPtr->getNext();
        }
    }
    return item;
}
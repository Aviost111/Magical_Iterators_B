// LinkedList.cpp
#include "LinkedList.hpp"

namespace ariel {
// Node constructor initializes data with the given shared pointer and next with nullptr
    Node::Node(std::shared_ptr<int> value) : data(std::move(value)), next(nullptr), index(0) {}

// Getter for data, returns the shared pointer to the int
    std::shared_ptr<int> Node::getData() const {
        return this->data;
    }

// Getter for the next node, returns a shared pointer to the next node
    std::shared_ptr <Node> Node::getNext() const {
        return this->next;
    }

// Setter for the next node, takes a shared pointer to a Node
    void Node::setNext(std::shared_ptr <Node> newNext) {
        this->next = std::move(newNext);
    }

    int Node::getIndex() const {
        return this->index;
    }

    void Node::setIndex(const int index) {
        this->index = index;
    }

// Destructor for LinkedList, cleans up the list
    LinkedList::~LinkedList() {
        while (this->head) {
            std::shared_ptr <Node> temp = std::move(this->head);
            this->head = std::move(temp->next);
        }
    }

// Insert function that takes a shared pointer to an int and inserts it into the list
    void LinkedList::insert(const std::shared_ptr<int> &value) {
        std::shared_ptr <Node> newNode = std::make_shared<Node>(value);

        // If the list is empty or the value is smaller than the head's data
        if (!this->head || *value < *this->head->data) {
            newNode->setNext(std::move(this->head));
            this->head = std::move(newNode);
        } else {
            std::shared_ptr <Node> current = this->head;
            // Find the position to insert the new node
            while (current->getNext() && *value > *current->getNext()->data) {
                current = current->getNext();
            }
            newNode->setNext(std::move(current->next));
            current->setNext(std::move(newNode));
        }
        updateIndexes();
    }

// Display function to print the list
    void LinkedList::display() const {
        std::shared_ptr <Node> current = this->head;
        while (current) {
            std::cout << *current->getData() << " ";
            current = current->getNext();
        }
        std::cout << std::endl;
    }

    void LinkedList::updateIndexes() {
        std::shared_ptr <Node> current = this->head;
        int currentIndex = 1;

        while (current) {
            current->setIndex(currentIndex);
            currentIndex++;
            current = current->getNext();
        }
    }

    void LinkedList::remove(int value) {
        if (!this->head) {
            return; // List is empty, nothing to remove
        }

        // If the head node contains the value to be removed
        if (*this->head->getData() == value) {
            this->head = std::move(this->head->next);
            updateIndexes();
            return;
        }

        std::shared_ptr <Node> current = this->head;
        while (current->getNext() && *current->getNext()->getData() != value) {
            current = current->getNext();
        }

        // If the value was found in the list
        if (current->getNext()) {
            current->setNext(std::move(current->getNext()->next));
            updateIndexes();
        }
    }

    std::shared_ptr <Node> LinkedList::getHead() {
        return this->head;
    }

    void LinkedList::insert(const std::shared_ptr<int> &value, int location) {
        std::shared_ptr <Node> newNode = std::make_shared<Node>(value);

        // If the list is empty or the location is 1, insert at the beginning
        if (!this->head || location == 1) {
            newNode->setNext(std::move(this->head));
            this->head = std::move(newNode);
            updateIndexes();
            return;
        } else {
            std::shared_ptr <Node> current = this->head;
            int currentIndex = 1;

            // Traverse the list to find the position to insert the new node
            while (current && currentIndex < location - 1) {
                current = current->getNext();
                currentIndex++;
            }

            // Insert the new node at the found position
            if (current) {
                newNode->setNext(std::move(current->getNext()));
                current->setNext(std::move(newNode));
            } else {
                // Insert at the end
                current = this->head;
                while (current->getNext()) {
                    current = current->getNext();
                }
                current->setNext(std::move(newNode));
            }
        }

        updateIndexes();
    }

}
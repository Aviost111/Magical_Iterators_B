// LinkedList.hpp
#ifndef MAGICITERATOR_LINKEDLIST_HPP
#define MAGICITERATOR_LINKEDLIST_HPP

#include <iostream>
#include <memory>

namespace ariel {
    class Node {
    private:
        std::shared_ptr<int> data; // Shared pointer to store the data
        std::shared_ptr <Node> next; // Shared pointer to the next node in the list
        int index;
    public:
        int getIndex() const;

        void setIndex(int index);

        // Constructor that takes a shared pointer to an int as its parameter
        Node(std::shared_ptr<int> value);

        Node(const Node &other) = default;

        Node &operator=(const Node &other) = default;

        Node(Node &&other) = default;

        Node &operator=(Node &&other) = default;

        ~Node() = default;

        // Getter for the data, returns a shared pointer to the int
        std::shared_ptr<int> getData() const;

        // Getter for the next node, returns a shared pointer to the next node
        std::shared_ptr <Node> getNext() const;

        // Setter for the next node, takes a shared pointer to a Node
        void setNext(std::shared_ptr <Node> newNext);

        //why friend class LinkedList
        friend class LinkedList;
    };

    class LinkedList {
    private:
        std::shared_ptr <Node> head; // Shared pointer to the head of the list

    public:
        // Default constructor initializes the head to nullptr
        LinkedList() : head(nullptr) {}

        // Destructor to clean up the list
        ~LinkedList();

        LinkedList(const LinkedList &) = default;

        LinkedList &operator=(const LinkedList &) = default;

        LinkedList(LinkedList &&) = default;

        LinkedList &operator=(LinkedList &&) = default;

        // Insert function that takes a shared pointer to an int and inserts it into the list
        void insert(const std::shared_ptr<int> &value);

        void insert(const std::shared_ptr<int> &value, int location);

        // Display function to print the list
        void display() const;

        void updateIndexes();

        // Remove function that takes an int and removes the first occurrence of the value from the list
        void remove(int value);

        std::shared_ptr <Node> getHead();
    };
}
#endif //MAGICITERATOR_LINKEDLIST_HPP

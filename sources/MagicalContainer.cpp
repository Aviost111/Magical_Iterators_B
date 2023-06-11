#include "MagicalContainer.hpp"

using namespace std;
namespace ariel {


    int MagicalContainer::size() const {
        return int(this->elements.size());
    }

    bool MagicalContainer::isPrime(int number) {
        // Handle special cases
        if (number <= 1) {
            return false;
        }

        // Check divisibility from 2 to the square root of the number
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                return false;  // Number is divisible, hence not prime
            }
        }

        return true;  // Number is prime
    }

    void MagicalContainer::addElement(int element) {
        if (std::find(elements.begin(), elements.end(), element) == elements.end()) {
            // Allocate memory for the new element and create a shared_ptr
            shared_ptr<int> pointer = make_shared<int>(element);
            ascending.insert(pointer);
            if (!this->size()) {
                cross.insert(pointer);
            } else {
                updateCross();
            }
            if (isPrime(element)) {
                prime.insert(pointer);
            }
            // Find the position to insert the element
            auto insertPos = std::lower_bound(elements.begin(), elements.end(), element);

            // Insert the element at the found position
            elements.insert(insertPos, element);
        }
    }

    void MagicalContainer::removeElement(int element) {
        if (std::find(elements.begin(), elements.end(), element) == elements.end()) {
            throw runtime_error("doesn't exist");
        }
        auto it = find(this->elements.begin(), this->elements.end(), element);
        elements.erase(it);
        prime.remove(element);
        ascending.remove(element);
        cross.remove(element);
    }

    MagicalContainer::MagicalContainer() = default;

    MagicalContainer::~MagicalContainer() = default;

    vector<int> MagicalContainer::getElements() {
        return this->elements;
    }

//    int MagicalContainer::findcrosslocation(int element) const {
//        int high = int(elements.size());
//        int low  =1;
//        int loc=1;
//        if(high==1){
//            if(elements.at(0)>element){
//                return 1;
//            } else{
//                return 2;
//            }
//        }
//        auto itB = elements.begin();
//        auto itE = elements.end();
//        itE--;
//        while(high>low){
//            if(*itB>element){
//                return loc;
//            }
//            loc++;
//            itB++;
//            low++;
//            if(*itE<element){
//                return loc;
//            }
//            loc++;
//            itE--; // Decrement itE instead of incrementing it
//            high--;
//        }
//
//        return loc;
//    }

    void MagicalContainer::updateCross() {
        // Create a vector of shared pointers to the elements in the ascending list
        vector <shared_ptr<int>> asc;
        shared_ptr <Node> temp = ascending.getHead();
        while (temp) {
            asc.push_back(temp->getData());
            temp = temp->getNext();
        }

        // Clear the cross linked list
        cross = LinkedList();

        // Insert the elements from the asc vector into the cross linked list
        if (!asc.empty()) {
            cross.insert(asc.at(0));
            unsigned long j = 1;
            for (int i = 1; i < asc.size(); ++i) {
                if (i % 2 != 0) {
                    cross.insert(asc.at(asc.size() - j), i + 1);
                } else {
                    cross.insert(asc.at(j), i + 1);
                    j++;
                }
            }
        }
    }

//    template<typename Iterator1, typename Iterator2>
//    bool operator==(const Iterator1& it1, const Iterator2& it2) {
//        if (typeid(it1) != typeid(it2)) {
//            throw std::runtime_error("Can't compare iterators of different types!");
//        }
//        // Perform the actual comparison between the iterators
//        // ...
//    }

}

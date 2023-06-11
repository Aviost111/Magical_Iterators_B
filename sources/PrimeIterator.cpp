#include "MagicalContainer.hpp"

#include <iostream>

using namespace std;

namespace ariel {
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &cont)
            : container(cont), element(cont.prime.getHead()) {}

    std::weak_ptr <Node> MagicalContainer::PrimeIterator::getElement() const {
        return element;
    }

    //done
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
        if (&this->container != &other.container) {
            throw runtime_error("Can't compare iterators with different containers!");
        }
        auto thisElement = element.lock();
        auto otherElement = other.getElement().lock();

        // If both pointers are null, they are equal, so return false
        if (!thisElement && !otherElement) {
            return true;
        }

        // If this pointer is null and the other one isn't, the null is considered bigger, so return false
        if ((!thisElement && otherElement) || (thisElement && !otherElement)) {
            return false;
        }
        return (this->element.lock()->getIndex() == other.getElement().lock()->getIndex());
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
        if (&this->container != &other.container) {
            throw runtime_error("Can't compare iterators with different containers!");
        }
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
        if (&this->container != &other.container) {
            throw runtime_error("Can't compare iterators with different containers!");
        }
        return (!((*this < other) || (*this == other)));
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
        if (&this->container != &other.container) {
            throw runtime_error("Can't compare iterators with different containers!");
        }
        auto thisElement = element.lock();
        auto otherElement = other.getElement().lock();

        // If both pointers are null, they are equal, so return false
        if (!thisElement && !otherElement) {
            return false;
        }

        // If this pointer is null and the other one isn't, the null is considered bigger, so return false
        if (!thisElement && otherElement) {
            return false;
        }

        // If this pointer isn't null and the other one is, the null is considered bigger, so return true
        if (thisElement && !otherElement) {
            return true;
        }
        return (element.lock()->getIndex() < other.getElement().lock()->getIndex());
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        return *element.lock()->getData();
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
        if (!element.lock()) {
            throw runtime_error("Cant go more");
        }
        element = element.lock()->getNext();
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
        return MagicalContainer::PrimeIterator(this->container);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
        MagicalContainer::PrimeIterator temp(this->container);
        temp.setElementNull();
        return temp;
    }

    void MagicalContainer::PrimeIterator::setElementNull() {
        this->element.reset();
    }

    // Copy constructor
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
            : container(other.container), element(other.element) {
    }

// Copy assignment operator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
        if (&this->container != &other.container) {
            throw runtime_error("Iterators with different containers!");
        }
        if (this != &other) {
            container = other.container;
            element = other.element;
        }
        return *this;
    }

    // Move assignment operator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other)

    noexcept {
    if (this != &other) {
    container = other.container;
    element = std::move(other.element);
    other.

    setElementNull();
}
return *this;
}


}

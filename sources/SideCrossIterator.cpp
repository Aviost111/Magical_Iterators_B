#include "MagicalContainer.hpp"
#include <iostream>

using namespace std;

namespace ariel {
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &cont)
            : container(cont), element(cont.cross.getHead()) {}

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
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
        return element.lock() == other.element.lock();
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
        if (&this->container != &other.container) {
            throw runtime_error("Can't compare iterators with different containers!");
        }
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {
        if (&this->container != &other.container) {
            throw runtime_error("Can't compare iterators with different containers!");
        }
        return (!((*this < other) || (*this == other)));
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {
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

    int MagicalContainer::SideCrossIterator::operator*() const {
        return *element.lock()->getData();
    }

    std::weak_ptr <Node> MagicalContainer::SideCrossIterator::getElement() const {
        return element;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
        if (!element.lock()) {
            throw runtime_error("Cant go more");
        }
        element = element.lock()->getNext();
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
        return MagicalContainer::SideCrossIterator(this->container);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
        MagicalContainer::SideCrossIterator temp(this->container);
        temp.setElementNull();
        return temp;
    }

    void MagicalContainer::SideCrossIterator::setElementNull() {
        this->element.reset();
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
            : container(other.container), element(other.element) {
    }

    MagicalContainer::SideCrossIterator &
    MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
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
    MagicalContainer::SideCrossIterator &
    MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other)

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

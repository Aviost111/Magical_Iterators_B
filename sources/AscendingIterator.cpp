#include "MagicalContainer.hpp"
#include <iostream>

using namespace std;

namespace ariel {
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &cont)
            : container(cont), element(cont.ascending.getHead()) {}

    std::weak_ptr <Node> MagicalContainer::AscendingIterator::getElement() const {
        return element;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const {
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
        return element.lock()->getIndex() == other.getElement().lock()->getIndex();
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const {
        if (&this->container != &other.container) {
            throw runtime_error("Can't compare iterators with different containers!");
        }
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const {
        if (&this->container != &other.container) {
            throw runtime_error("Can't compare iterators with different containers!");
        }
        return !((*this < other) || (*this == other));
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const {
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

    int MagicalContainer::AscendingIterator::operator*() const {
        return *element.lock()->getData();
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        if (!element.lock()) {
            throw runtime_error("Cant go more");
        }
        element = element.lock()->getNext();
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
        return MagicalContainer::AscendingIterator(this->container);;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
        MagicalContainer::AscendingIterator temp(this->container);
        temp.setElementNull();
        return temp;
    }

    void MagicalContainer::AscendingIterator::setElementNull() {
        this->element.reset();
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
            : container(other.container), element(other.element) {
    }

    MagicalContainer::AscendingIterator &
    MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
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
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other)

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

#include "MagicalContainer.hpp"
#include <iostream>

using namespace std;
namespace ariel {
    MagicalContainer::Base_Iterator::Base_Iterator(MagicalContainer &container)
            : container(container), element(container.ascending.getHead()) {}

    bool MagicalContainer::Base_Iterator::operator==(const MagicalContainer::Base_Iterator &other) const {
        if(typeid(*this)!= typeid(other)){
            throw runtime_error("cant compare different types");
        }
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

    bool MagicalContainer::Base_Iterator::operator!=(const MagicalContainer::Base_Iterator &other) const {
        if(typeid(*this)!= typeid(other)){
            throw runtime_error("cant compare different types");
        }
        if (&this->container != &other.container) {
            throw runtime_error("Can't compare iterators with different containers!");
        }
        return !(*this == other);
    }

    bool MagicalContainer::Base_Iterator::operator<(const MagicalContainer::Base_Iterator &other) const {
        if(typeid(*this)!= typeid(other)){
            throw runtime_error("cant compare different types");
        }
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

    bool MagicalContainer::Base_Iterator::operator>(const MagicalContainer::Base_Iterator &other) const {
        if(typeid(*this)!= typeid(other)){
            throw runtime_error("cant compare different types");
        }
        if (&this->container != &other.container) {
            throw runtime_error("Can't compare iterators with different containers!");
        }
        return !((*this < other) || (*this == other));
    }

    std::weak_ptr<Node> MagicalContainer::Base_Iterator::getElement() const {
        return this->element;
    }

    MagicalContainer::Base_Iterator &
    MagicalContainer::Base_Iterator::operator=(const MagicalContainer::Base_Iterator &other) {
        if(typeid(*this)!= typeid(other)){
            throw runtime_error("cant compare different types");
        }
        if (&this->container != &other.container) {
            throw runtime_error("Iterators with different containers!");
        }
        if (this != &other) {
            Base_Iterator::operator=(other);
            element = other.element;
        }
        return *this;
    }

    MagicalContainer::Base_Iterator &
    MagicalContainer::Base_Iterator::operator=(MagicalContainer::Base_Iterator &&other) noexcept{
        if (this != &other) {
            Base_Iterator::operator=(std::move(other));
            element = std::move(other.element);
            other.

                    setElementNull();
        }
        return *this;
    }

    void MagicalContainer::Base_Iterator::setElementNull() {
        this->element.reset();
    }

//    int MagicalContainer::Base_Iterator::operator*() const {
//        return *element.lock()->getData();
//    }

    MagicalContainer::Base_Iterator &MagicalContainer::Base_Iterator::operator++() {
        if (!element.lock()) {
            throw runtime_error("Cant go more");
        }
        element = element.lock()->getNext();
        return *this;
    }

}
#include "MagicalContainer.hpp"
#include <iostream>

using namespace std;

namespace ariel {
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &cont)
            : Base_Iterator(cont) {
        element = container.cross.getHead();
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
        return MagicalContainer::SideCrossIterator(this->container);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
        MagicalContainer::SideCrossIterator temp(this->container);
        temp.setElementNull();
        return temp;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        return *element.lock()->getData();
    }
}

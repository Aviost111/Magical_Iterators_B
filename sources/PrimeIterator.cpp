#include "MagicalContainer.hpp"

#include <iostream>

using namespace std;

namespace ariel {
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &cont)
            : Base_Iterator(cont) {
        element = cont.prime.getHead();
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
        return MagicalContainer::PrimeIterator(this->container);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
        MagicalContainer::PrimeIterator temp(this->container);
        temp.setElementNull();
        return temp;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        return *element.lock()->getData();
    }

}

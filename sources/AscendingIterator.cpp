
#include "MagicalContainer.hpp"

using namespace std;

namespace ariel {
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &cont)
            : Base_Iterator(cont) {}

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
        return MagicalContainer::AscendingIterator(this->container);;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
        MagicalContainer::AscendingIterator temp(this->container);
        temp.setElementNull();
        return temp;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        return *element.lock()->getData();
    }

}


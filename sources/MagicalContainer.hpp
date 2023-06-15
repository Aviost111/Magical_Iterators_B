#ifndef MAGICITERATOR_MAGICALCONTAINER_HPP
#define MAGICITERATOR_MAGICALCONTAINER_HPP

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include "LinkedList.hpp"

namespace ariel {
    class MagicalContainer {
    private:
        std::vector<int> elements;
        LinkedList prime;
        LinkedList cross;
        LinkedList ascending;

    public:
        MagicalContainer();

        ~MagicalContainer();

        std::vector<int> getElements();

        void addElement(int element);

        int size() const;

        void removeElement(int element);

        static bool isPrime(int number);

        void updateCross();

        MagicalContainer(const MagicalContainer &other) = default;

        // Copy assignment operator
        MagicalContainer &operator=(const MagicalContainer &other) = default;

        // Move constructor
        MagicalContainer(MagicalContainer &&other) noexcept = default;

        // Move assignment operator
        MagicalContainer &operator=(MagicalContainer &&other) noexcept = default;
//
//        class Base_Iterator {
//        private:
//            MagicalContainer &container;
//            std::weak_ptr<Node> element;
//        public:
//            Base_Iterator(const MagicalContainer &container);
//
//            virtual ~Base_Iterator() = default;
//            Base_Iterator(const Base_Iterator &other) = default;
//            Base_Iterator(Base_Iterator &&other) = default;
//
//            Base_Iterator &operator=(const Base_Iterator &other) = delete;
//            Base_Iterator &operator=(Base_Iterator &&other) = delete;
//
//            bool operator==(const Base_Iterator &other) const;
//            bool operator!=(const Base_Iterator &other) const;
//            bool operator<(const Base_Iterator &other) const;
//            bool operator>(const Base_Iterator &other) const;
//        };

        // Ascending Base_Iterator class
        class AscendingIterator {
        private:
            MagicalContainer &container;
            std::weak_ptr<Node> element;

            void setElementNull();

        public:
            explicit AscendingIterator(MagicalContainer &cont);

            AscendingIterator(const AscendingIterator &other);

            AscendingIterator(AscendingIterator &&other) noexcept = default;

            AscendingIterator &operator=(const AscendingIterator &other);

            AscendingIterator &operator=(AscendingIterator &&other) noexcept;

            ~AscendingIterator() = default;

            std::weak_ptr<Node> getElement() const;

            bool operator==(const AscendingIterator &other) const;

            bool operator!=(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other) const;

            bool operator<(const AscendingIterator &other) const;

            int operator*() const;

            AscendingIterator &operator++();

            AscendingIterator begin() const;

            AscendingIterator end() const;
        };

        // SideCross Base_Iterator class
        class SideCrossIterator {
        private:
            MagicalContainer &container;
            std::weak_ptr<Node> element;

            void setElementNull();

        public:
            explicit SideCrossIterator(MagicalContainer &cont);

            SideCrossIterator();

            ~SideCrossIterator() = default;

            SideCrossIterator(const SideCrossIterator &other);

            SideCrossIterator(SideCrossIterator &&other) noexcept = default;

            SideCrossIterator &operator=(const SideCrossIterator &other);

            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;

            bool operator==(const SideCrossIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            int operator*() const;

            std::weak_ptr<Node> getElement() const;

            SideCrossIterator &operator++();

            SideCrossIterator begin() const;

            SideCrossIterator end() const;
        };

        // Prime Base_Iterator class
        class PrimeIterator {
        private:
            MagicalContainer &container;
            std::weak_ptr<Node> element;

            void setElementNull();

        public:
            explicit PrimeIterator(MagicalContainer &cont);

            ~PrimeIterator() = default;

            PrimeIterator(const PrimeIterator &other);

            PrimeIterator(PrimeIterator &&other) noexcept = default;

            PrimeIterator &operator=(const PrimeIterator &other);

            PrimeIterator &operator=(PrimeIterator &&other) noexcept;

            std::weak_ptr<Node> getElement() const;

            bool operator==(const PrimeIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            int operator*() const;

            PrimeIterator &operator++();

            PrimeIterator begin() const;

            PrimeIterator end() const;
        };
    };
}

#endif //MAGICITERATOR_MAGICALCONTAINER_HPP

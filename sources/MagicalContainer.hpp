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

        class Base_Iterator {
        protected:
            MagicalContainer &container;
            std::weak_ptr<Node> element;
            void setElementNull();
        public:
            explicit Base_Iterator(MagicalContainer &container);

            virtual ~Base_Iterator() = default;

            Base_Iterator(const Base_Iterator &other) = default;
            Base_Iterator(Base_Iterator &&other) = default;

            Base_Iterator &operator=(const Base_Iterator &other);
            Base_Iterator &operator=(Base_Iterator &&other) noexcept;

            virtual int operator*() const = 0;

            Base_Iterator &operator++();

            std::weak_ptr<Node> getElement() const;
            bool operator==(const Base_Iterator &other) const;
            bool operator!=(const Base_Iterator &other) const;
            bool operator<(const Base_Iterator &other) const;
            bool operator>(const Base_Iterator &other) const;

//            virtual Base_Iterator begin() const = 0;
//
//            virtual Base_Iterator end() const = 0;
        };

        // Ascending Base_Iterator class
        class AscendingIterator : public Base_Iterator{
        private:

        public:
            explicit AscendingIterator(MagicalContainer &cont);

            ~AscendingIterator() override = default;

            int operator*() const override;

//            AscendingIterator &operator++() override;

            AscendingIterator begin() const;

            AscendingIterator end() const;
        };

        // SideCross Base_Iterator class
        class SideCrossIterator : public Base_Iterator{
        private:

        public:
            explicit SideCrossIterator(MagicalContainer &cont);

            SideCrossIterator()=delete;

            ~SideCrossIterator() override = default;

            int operator*() const override;

            SideCrossIterator begin() const;

            SideCrossIterator end() const;
        };

        // Prime Base_Iterator class
        class PrimeIterator : public Base_Iterator{
        private:

        public:
            explicit PrimeIterator(MagicalContainer &cont);

            ~PrimeIterator() override = default;

            int operator*() const override;

            PrimeIterator begin() const;

            PrimeIterator end() const;
        };
    };
}

#endif //MAGICITERATOR_MAGICALCONTAINER_HPP

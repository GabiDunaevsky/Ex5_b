#pragma GCC diagnostic ignored "-Wextra"
#pragma once
#include <iostream>
#include <stdexcept>
#include <list>
#include <iterator>
#include <set>
#include <cmath>
//I was using chat gpt in the task
// I was consoulting with a friend on the task.

namespace ariel{

class MagicalContainer{
        private:
            std::list<int> elements;
            std::set<int> ascendinElements;
            std::list<int> crossElements;
            std::list<int> primeElements;
            bool inFront;
            

        public:
            MagicalContainer();
            MagicalContainer(const MagicalContainer& other);
            ~MagicalContainer();
            MagicalContainer& operator=(MagicalContainer&&) = delete;
            MagicalContainer(MagicalContainer&&) = delete;
            MagicalContainer& operator=(const MagicalContainer&) = delete;
            void addElement(int element);
            void removeElement(int element);
            int size() const;
            bool isPrime(int number);
            
    
class AscendingIterator{
        private:
            std::set<int>::iterator itAscending;
            std::set<int>::iterator endIterator;
            std::set<int>::iterator beginIterator;
     
        public:
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator& other);
            AscendingIterator& operator=(AscendingIterator&&) = delete;
            AscendingIterator(AscendingIterator&&) = default;
            ~AscendingIterator() = default;
            AscendingIterator& operator++();
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            int operator*() const;
            AscendingIterator begin() const;
            AscendingIterator end() const;
            AscendingIterator& operator=(const AscendingIterator& other);
    };

    class SideCrossIterator{
        private:
            std::list<int>::iterator itCross;
            std::list<int>::iterator endIterator;
            std::list<int>::iterator beginIterator;
            
        public:
            SideCrossIterator(MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator& other);
            SideCrossIterator& operator=(SideCrossIterator&&) = delete;
            ~SideCrossIterator() = default;
            SideCrossIterator(SideCrossIterator&&) = default;
            SideCrossIterator& operator++();
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            int operator*() const;
            SideCrossIterator begin() const;
            SideCrossIterator end() const;
            SideCrossIterator& operator=(const SideCrossIterator& other);
    };

    class PrimeIterator{
    private:
        std::list<int>::iterator itPrime;
        std::list<int>::iterator endIterator;
        std::list<int>::iterator beginIterator;
       
    public:
        PrimeIterator(MagicalContainer &container);
        PrimeIterator(const PrimeIterator& other);
        PrimeIterator& operator=(PrimeIterator&&) = delete;
        ~PrimeIterator() = default;
        PrimeIterator(PrimeIterator&&) = default;
        PrimeIterator& operator++();
        bool operator>(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        int operator*() const;
        PrimeIterator begin() const;
        PrimeIterator end() const;
        PrimeIterator& operator=(const PrimeIterator& other);
    };

    };
}
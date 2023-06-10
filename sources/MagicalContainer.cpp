#include "MagicalContainer.hpp"
namespace ariel{
    /*sources:
        https://cplusplus.com/reference/iterator/distance/
        https://www.jdoodle.com/cpp-programming-online/
    */

    MagicalContainer::MagicalContainer(){
        this->inFront = true;
    }
    MagicalContainer::MagicalContainer(const MagicalContainer& other){
        this->inFront = other.inFront;
    }
    MagicalContainer::~MagicalContainer(){
        this->elements.clear();
        this->ascendinElements.clear();
        this->primeElements.clear();
        this->crossElements.clear();
    }
    // took this function from https://www.geeksforgeeks.org/c-program-to-check-prime-number/
    bool MagicalContainer::isPrime(int number){
        if (number <= 1)
            return false;
        for (int i = 2; i <= sqrt(number); i++)
            if (number % i == 0)
                return false;
        return true;
    }

    void MagicalContainer::addElement(int element){
        this->elements.push_back(element);
        this->ascendinElements.insert(element);
        if(isPrime(element)){
            this->primeElements.push_back(element);
        } 
        this->crossElements.clear();
        std::list<int>::iterator startIter = this->elements.begin();
        std::list<int>::reverse_iterator endIter = this->elements.rbegin();
        size_t i = 0;
        while(i < this->elements.size()/2){
            this->crossElements.push_back(*startIter);
            this->crossElements.push_back(*endIter);
            startIter++;
            endIter++;
            ++i;
    }
        if (this->elements.size() % 2 == 1) {
            this->crossElements.push_back(*startIter);
        }
    }

    void MagicalContainer::removeElement(int element){
        int numberOfElements = this->ascendinElements.count(element);
        if(numberOfElements == 0){
            throw std::runtime_error("End of iterator");
        }
        this->elements.remove(element);
        this->ascendinElements.erase(element);
        this->primeElements.remove(element);
        this->crossElements.remove(element);
    }

    int MagicalContainer::size() const{
        return this->elements.size();
    }

     MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container){
        this->itAscending = container.ascendinElements.begin();
        this->endIterator = container.ascendinElements.end();
        this->beginIterator = container.ascendinElements.begin();
    }
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other){
        this->itAscending = other.itAscending;
        this->beginIterator = other.beginIterator;
        this->endIterator = other.endIterator;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
        if(this->itAscending == this->endIterator){
            throw std::runtime_error("End of iterator");
        }
        this->itAscending++;
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
        int dist1 = std::distance(this->beginIterator,this->itAscending);
        int dist2 = std::distance(other.beginIterator,other.itAscending);
        return dist1 == dist2;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{
        int dist1 = std::distance(this->beginIterator,this->itAscending);
        int dist2 = std::distance(other.beginIterator,other.itAscending);
        return dist1 > dist2;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{
        int dist1 = std::distance(this->beginIterator,this->itAscending);
        int dist2 = std::distance(other.beginIterator,other.itAscending);
        return dist1 < dist2;;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{
        return !(*this == other);
    }

    int MagicalContainer::AscendingIterator::operator*() const{
        return *(this->itAscending);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const{
        MagicalContainer::AscendingIterator acIter(*this);
        acIter.itAscending = this->beginIterator;
        return acIter;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const{
        MagicalContainer::AscendingIterator acIter(*this);
        acIter.itAscending = this->endIterator;
        return acIter;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){
        if(this->beginIterator != other.beginIterator){
            throw std::runtime_error("Point to different containers");
        }
        return *this;
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container){
        this->itCross = container.crossElements.begin();
        this->beginIterator = container.crossElements.begin();
        this->endIterator = container.crossElements.end();
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other){
         this->itCross = other.itCross;
        this->beginIterator = other.beginIterator;
        this->endIterator = other.endIterator;
    }
    
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){
        if(this->itCross == this->endIterator){
            throw std::runtime_error("End of iterator");
        }
        this->itCross++;
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{
        int dist1 = std::distance(this->beginIterator,this->itCross);
        int dist2 = std::distance(other.beginIterator,other.itCross);
        return dist1 == dist2;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{
        int dist1 = std::distance(this->beginIterator,this->itCross);
        int dist2 = std::distance(other.beginIterator,other.itCross);
        return dist1 > dist2;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{
        int dist1 = std::distance(this->beginIterator,this->itCross);
        int dist2 = std::distance(other.beginIterator,other.itCross);
        return dist1 < dist2;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{
        return !(*this == other);
    }

    int MagicalContainer::SideCrossIterator::operator*() const{
        return (*this->itCross);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const{
        MagicalContainer::SideCrossIterator scIter(*this);
        scIter.itCross = this->beginIterator;
        return scIter;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const{
        MagicalContainer::SideCrossIterator scIter(*this);
        scIter.itCross = this->endIterator;
        return scIter;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
        if(this->beginIterator != other.beginIterator){
            throw std::runtime_error("Point to different containers");
        }
        return *this;
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container){
        this->itPrime = container.primeElements.begin();
        this->beginIterator = container.primeElements.begin();
        this->endIterator = container.primeElements.end();
    }
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other){
        this->itPrime = other.itPrime;
        this->beginIterator = other.beginIterator;
        this->endIterator = other.endIterator;
    }


    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){
        if(this->itPrime == this->endIterator){
            throw std::runtime_error("End of iterator");
        }
        this->itPrime++;
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{
        int dist1 = std::distance(this->beginIterator,this->itPrime);
        int dist2 = std::distance(other.beginIterator,other.itPrime);
        return dist1 == dist2;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{
        int dist1 = std::distance(this->beginIterator,this->itPrime);
        int dist2 = std::distance(other.beginIterator,other.itPrime);
        return dist1 > dist2;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{
        int dist1 = std::distance(this->beginIterator,this->itPrime);
        int dist2 = std::distance(other.beginIterator,other.itPrime);
        return dist1 < dist2;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const{
        return !(*this == other);
    }

    int MagicalContainer::PrimeIterator::operator*() const{
        return (*this->itPrime);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const{
        MagicalContainer::PrimeIterator prIter(*this);
        prIter.itPrime = this->beginIterator;
        return prIter;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const{
        MagicalContainer::PrimeIterator prIter(*this);
        prIter.itPrime = this->endIterator;
        return prIter;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){
        if(this->beginIterator != other.beginIterator){
            throw std::runtime_error("Point to different containers");
        }
        return *this;
    } 
}

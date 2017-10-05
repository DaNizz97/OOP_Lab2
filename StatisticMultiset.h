//
// Created by DNS on 24.09.2017.
//

#ifndef LAB2_STATISTICMULTISET_H
#define LAB2_STATISTICMULTISET_H

#include <vector>
#include <limits>
#include <set>
#include <list>
#include <fstream>
typedef unsigned long long int ulli;

template <class T>
class StatisticMultiset {
private:
    T max, min;
    mutable float average;
    std::vector<int> dataSet;
public:
    StatisticMultiset(){
        max = std::numeric_limits<T>::min();
        min = std::numeric_limits<T>::max();
        average = 0;
    };
    // Добавляет число в набор.
    void AddNum( T num );
    void AddNum( const std::vector<T>& numbers );
    void AddNumsFromFile( const char* filename );
    void AddNums( const StatisticMultiset& a_stat_set );
    // Максимальное число в наборе.
    T getMax() const;
    // Минимальное число в наборе.
    T getMin() const;
    // Среднее арифметическое всего набора.
    float getAvg() const;
    // Кол-во чисел в наборе меньше заданного порога.
    int getCountUnder(float threshold) const;
    // Кол-во чисел в наборе больше заданного порога.
    int getCountAbove(float threshold) const;
    // Returned set's size
    ulli getSize() const;


};

template <class T>
void StatisticMultiset<T>::AddNum(T num) {
    dataSet.push_back(num);
    if(num > max){
        max = num;
    }
    if(num < min){
        min = num;
    }
    average = average + num;
}
template <class T>
float StatisticMultiset<T>::getAvg() const{
    if (!dataSet.empty()){
        average = average/dataSet.size();
    }
    return average;
}

template <class T>
T StatisticMultiset<T>::getMin() const{
    return min;
}

template <class T>
T StatisticMultiset<T>::getMax() const{
    return max;
}
template <class T>
int StatisticMultiset<T>::getCountUnder(float threshold) const{
    int count = 0;
    for (int i : dataSet) {
        if(i < threshold){
            count++;
        }
    }
    return count;
}
template <class T>
int StatisticMultiset<T>::getCountAbove(float threshold) const{
    int count = 0;
    for (int i : dataSet) {
        if(i > threshold){
            count++;
        }
    }
    return count;
}

template <class T>
void StatisticMultiset<T>::AddNum(const std::vector<T> &numbers) {
    for (int number : numbers) {
        dataSet.push_back(number);
        if(number > max){
            max = number;
        }
        if(number < min){
            min = number;
        }
        average+= number;
    }
}

void StatisticMultiset<T>::AddNum(const std::vector<T> &numbers) {
    for (int number : numbers) {
        dataSet.push_back(number);
        if(number > max){
            max = number;
        }
        if(number < min){
            min = number;
        }
        average+= number;
    }
}

template <class T>
void StatisticMultiset<T>::AddNumsFromFile(const char *filename) {
    std::ifstream fin(filename);
    T number;
    while(!fin.eof()){
        fin >> number;
        dataSet.push_back(number);
    }
}
template <class T>
ulli StatisticMultiset<T>::getSize() const {
    return dataSet.size();
}

template <class T>
void StatisticMultiset<T>::AddNums(const StatisticMultiset &a_stat_set) {
    T number;
    for (int i = 0; i < a_stat_set.getSize(); ++i) {
        number = a_stat_set.dataSet[i];
        this->dataSet.push_back(number);
        if(number > max){
            max = number;
        }
        if(number < min){
            min = number;
        }
        average+= number;
    }
}
#endif //LAB2_STATISTICMULTISET_H

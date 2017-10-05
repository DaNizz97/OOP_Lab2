#include <iostream>
#include "StatisticMultiset.h"
using namespace std;

int main() {
    StatisticMultiset<int> first,second;
    for(int i = 0; i < 10; i++) {
        first.AddNum(i);
    }
    second.AddNum(111);
    vector<int> vet = {10,11,12,13,14};
    first.AddNum(vet);
    first.AddNums(second);
    cout <<"Minimum: " << first.getMin() << "\nMaximum: "<< first.getMax() << "\nAverage: " << first.getAvg();
    cout << endl << first.getCountAbove(1) << " ----- " << first.getCountUnder(5);
    cout << "\nSize: " << first.getSize();
    return 0;
}
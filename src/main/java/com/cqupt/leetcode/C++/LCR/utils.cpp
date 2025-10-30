#include <bits/stdc++.h>

template<typename T>
void printVector(const std::vector<T>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

template void printVector<int>(const std::vector<int>&);
template void printVector<double>(const std::vector<double>&);
template void printVector<std::string>(const std::vector<std::string>&);
#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <map>
#include <memory>

template <typename T, typename Key>
T* searchInMap(const std::map<Key, std::unique_ptr<T>>& container, const Key& key) {
    auto it = container.find(key);
    if (it != container.end()) {
        return it->second.get();
    }
    return nullptr;
}

template <typename Container, typename Compare>
void sortContainer(Container& container, Compare comp) {
    std::sort(container.begin(), container.end(), comp);
}

class InvalidInputException : public std::runtime_error {
public:
    explicit InvalidInputException(const std::string& msg) 
        : std::runtime_error(msg) {}
};

class DuplicateIdException : public std::runtime_error {
public:
    explicit DuplicateIdException(const std::string& msg) 
        : std::runtime_error(msg) {}
};

class NotFoundException : public std::runtime_error {
public:
    explicit NotFoundException(const std::string& msg) 
        : std::runtime_error(msg) {}
};

#endif // UTILITIES_H
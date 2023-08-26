///////////////////////////////////////////////////
// Workshop 10 : searchNlist.h
// Student Name: Rong-Yuan, Wen
// Student ID  : 114556228
// Email       : rwen1@myseneca.ca
// Section     : NGG
///////////////////////////////////////////////////
#ifndef SEARCH_NLIST_H
#define SEARCH_NLIST_H
#include <iostream>
#include "Collection.h"
namespace sdds {
    // Function template to search for a key in an array and add matches to a Collection
    template <typename T, typename U>
    // T - template type 1 : "Collection" and the type of object stored in the array.
    // U - template type 2 : The type of the "key" value. It must be comparable to an object of type 'T'
    bool search(Collection<T>& collection, T* arr, int numOfElements, const U& key) {
        bool result = false;
        for (int i = 0; i < numOfElements; ++i) {
            if (arr[i] == key) {  // use '==' operator to correspond relative type 
                collection.add(arr[i]); // revoke the template function 'add' from Collection template class
                result = true;
            }
        }
        return result;
    }

    // Function template to list all elements of an array
    template <typename T>
    void listArrayElements(const char* title, const T* arr, int numElements) {
        std::cout << title << std::endl;
        for (int i = 0; i < numElements; ++i) {
            // use customize '<<' operator from abstract base class 'ReadWrite', the actual obj will be determined in runtime. 
            std::cout << i + 1 << ": " << arr[i] << std::endl;  
        }
    }
}
#endif // !SEARCH_NLIST_H

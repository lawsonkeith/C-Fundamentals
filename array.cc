#include <array>
#include <vector>
#include <iostream>
#include <iterator>

int main()
{
    // demo of various c++ container classes
    // vectors / arrays (c / c++)
    //
    int c_array[5] = {2,4,6,8,10};
    std::array<int, 5> cpp_array = {1,2,3,4,5};
    std::vector<int> cpp_dynarray(5);
    
    // dyanmic 
    cpp_dynarray[0] = 5;
    cpp_dynarray[1] = 6;
    cpp_dynarray[2] = 7;
    cpp_dynarray[3] = 8;
    cpp_dynarray[4] = 9;
    cpp_dynarray.push_back(10);
    cpp_dynarray.push_back(11);
    cpp_dynarray.push_back(12);
    cpp_dynarray.push_back(13);
    cpp_dynarray.push_back(14);


    auto c_array_begin = std::begin(c_array); // = c_array + 0
    auto c_array_end = std::end(c_array);     // = c_array + 5
    std::cout << std::endl << "#1  " ;
    for(auto i=c_array_begin; i<c_array_end; ++i)
        std::cout << *i << ",";
    //#1    2,4,6,8,10,2,10
        
    auto cpp_array_begin = std::begin(cpp_array); // = cpp_array.begin()
    auto cpp_array_end = std::end(cpp_array);     // = cpp_array.end()
    std::cout << std::endl << "#2  " ;
    for(auto i=cpp_array_begin; i<cpp_array_end; ++i)
        std::cout << *i << ",";
    //#2  1,2,3,4,5,

    auto cpp_dynarray_begin = std::begin(cpp_dynarray); // = cpp_dynarray.begin()
    auto cpp_dynarray_end = std::end(cpp_dynarray);     // = cpp_dynarray.end()
    std::cout << std::endl << "#3  " ;
    for(auto i=cpp_dynarray_begin; i<cpp_dynarray_end; ++i)
        std::cout << *i << ",";
    //#3  5,6,7,8,9,10,11,12,13,14,2,10
    
    //#4  
    std::cout << std::endl << "#4  " << std::endl ;
    //2,10
    std::cout << "   a. " << *c_array_begin << "," << *(c_array_end-1) << std::endl ;
    //1,5
    std::cout << "   b. " << *cpp_array_begin << "," << *(cpp_array_end-1) << std::endl ;
    //5,14
    std::cout << "   c. " << *cpp_dynarray_begin << "," << *(cpp_dynarray_end-1) << std::endl ;
}

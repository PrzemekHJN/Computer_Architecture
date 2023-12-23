/*  
    The program displays the memory contents for different data types and compares binary representations of data, 
    in particular, int, float and double types, defining parameters with different values. 
    It examines the memory contents for maximum and minimum values for different types. To make modifications, 
    change the corresponding variable values in the main function (main).
*/  

#include <iostream>
#include <bitset>
#include <limits>
#include <iomanip>

// defining a template function show_bits, which is used to display the binary representation of data type T
template <typename T>
void show_bits(T tmp)
{
    const int tmpSize = sizeof(T) * 8;
    unsigned char *bytes = reinterpret_cast<unsigned char *>(&tmp);

    std::cout << "Binary representation (" << tmpSize << " bits): ";
    for (int i = tmpSize - 1; i >= 0; i--)
    {
       std::cout << std::bitset<8>(bytes[i]);
    }
    std::cout << "\n";
}

int main()
{
    // Test for type 'int'
    int a = -91;
    show_bits(a);

    int b = 91;
    show_bits(b);

    int c = std::numeric_limits<int>::min();
    show_bits(c);

    int d = std::numeric_limits<int>::max();
    show_bits(d);

    // Test for type 'float'
    float e = -100.0f;
    show_bits(e);

    float f = std::numeric_limits<float>::max();
    show_bits(f);

    // Test for type 'double'
    double g = -100.0;
    show_bits(g);

    double h = std::numeric_limits<double>::max();
    show_bits(h);

    return 0;
}

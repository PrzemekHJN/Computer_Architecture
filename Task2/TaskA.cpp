// Header files
#include <iostream>
#include <emmintrin.h>
#include <immintrin.h>

template <typename T>
/*
Template function which is used to check the address match 
to the limits of a exponentiation (exp 2) for different data types
*/
void checkFitting() 
{
    T tmp; // tmp variable declaration of a given type

    // For loop iterating from 1 to 7
    for (int i = 0; i < 8; ++i) 
    {
        int limit = 1 << i; // Limit calculation as 2 exp i

        // Getting the address of the variable "tmp" and storing its value in the variable address
        long long adress = (long long)&tmp;

        // Print out information about the address and the limit
        std::cout << "Is address: ";
        std::cout << adress;
        std::cout << " fitted to limit 2^" << i << " bytes? ";
        std::cout << std::endl;

        // Is adress fitted to limit
        if (adress % limit) 
        {
            std::cout << "Adress is not fitted to limit 2^" << i << " bytes.";
        }
        else
        {
            std::cout << "Adress is fitted to limit 2^" << i << " bytes.";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    checkFitting<float>(); // Float type example
    checkFitting<int>();   // Int type example
    // Other types as eg. double, __m128i, __m256i, can be added

    return 0;
}

/* 
The memory addresses of the variable tmp usually seem to match the limits of 2 exp i.
For limits that are exponentials of two, addresses are divisible by these limits without rest.
The results may suggest that memory in the computer system.
is organized in a way that facilitates data access for the limits of 2^i.
This is consistent with the idea that many hardware implementations prefer data sizes that are equal to 2^i.
*/
/*
    make-test-patterns
        Author: Keitaro Naruse
        Date:   2021-12-24
        MIT License
*/

// # Solution

#include <iostream>
#include <vector>

int main()
{
    //  Constants
    const int H = 100, W = 100;
    std::cout << H << " " << W << std::endl;

    //  Make Ai
    const int bias_A = 0;
    for( int h = 0; h < H; h ++ ) {
        for( int w = 0; w < W; w ++ ) {
            // std::cout << h * 100 + w + bias_A << " ";
            std::cout << bias_A << " ";
        }
        std::cout << std::endl;
    }

    //  Make Bi
    // const int bias_B = 90001;
    const int bias_B = 100000;
    for( int h = 0; h < H; h ++ ) {
        for( int w = 0; w < W; w ++ ) {
            // std::cout << h * 100 + w + bias_B << " ";
            std::cout << bias_B << " ";
        }
        std::cout << std::endl;
    }

    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}

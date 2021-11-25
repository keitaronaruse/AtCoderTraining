/*
    ABC086A Product
        https://atcoder.jp/contests/abs/tasks/abc086_a
        Author: Keitaro Naruse
        Date:   2021-11-08
        MIT License
*/

#include <iostream>
#include <string>

int main()
{
    int a, b;
    
    //  Read a and b
    std::cin >> a >> b;
    //  Debug
    std::cerr << a << " " << b << std::endl;
    
    //  Check if a*b is even and odd 
    if( 0 == a * b % 2 ) {
        std::cout << "Even" << std::endl;
    }
    else {
        std::cout << "Odd" << std::endl;
    }

    //  Finalize
    std::cerr << "Normally terminated." << std::endl;      
    return( 0 );
}

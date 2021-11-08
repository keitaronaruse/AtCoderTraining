/*
    ABC086A Product
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
    //  Check if a*b is even and odd 
    if( 0 == a * b % 2 ) {
        std::cout << "Even" << std::endl;
    }
    else {
        std::cout << "Odd" << std::endl;
    }
        
    return( 0 );
}

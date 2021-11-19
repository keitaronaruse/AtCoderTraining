/*
    ABC049C - 白昼夢
        https://atcoder.jp/contests/abs/tasks/arc065_a
        Author: Keitaro Naruse
        Date:   2021-11-18, 2021-11-20
        MIT License
*/
//
//  # Programming point
//  - Distinguish dream-erase? from dreamer-* 
//  # My solution
//  - if a string matches with dream-eraser or dream-erase
//    update the string
//  - else if it matches with dream or dreamer
//    update the string
//  - else if it matchers with erase or eraser
//    update the string
//  - else
//    No match -> No
//
#include <iostream>
#include <string>
#include <algorithm>

/*
    match_strings(b, e, b2, e2)
        # return 
        - true if [b, e] matches with [b2, e2]
        - false if not
        - matching length: a shorter string if [b, e] or [b2, e2]
*/
bool match_strings(std::string::iterator b, std::string::iterator e, 
    std::string::iterator b2, std::string::iterator e2 )
{
    //  Loop by b2-e2 word
    while( b2 != e2 ) {
        //  If b-e word is short for matching b2-e2 word
        if( b == e ) {
            //  Not mach
            return( false );
        }

        //  Continue the loop if the characters are same
        if(*b == *b2) {
            b ++;
            b2 ++;
        }
        else {
            //  Not match
            return( false );
        }
    }
    
    //  If it has come to here, all match
    return( true );
}

int main()
{
    //  literals
    std::string dreamer("dreamer"), dream("dream"), eraser("eraser"), erase("erase");

    //  Read S
    std::string S;
    std::cin >> S;
    //  Debug
    std::cerr << S << std::endl;

    //
    std::string::iterator b = S.begin(), e = S.end();
    while(b != e) {
        //  Debug
        std::string s;
        std::copy( b, e, std::back_inserter( s ) );
        std::cerr << s << std::endl;
        if( match_strings( b, e, dreamer.begin(), dreamer.end() ) ) {
            b += dreamer.size();
            //  dreamer is found
            //  Debug 
            std::cerr << "dreamer" << std::endl;
        }
        else if( match_strings( b, e, dream.begin(), dream.end() ) ) {
            b += dream.size();
            //  dream is found
            //  Debug 
            std::cerr << "dream" << std::endl;
        }
        else if( match_strings( b, e, eraser.begin(), eraser.end() ) ) {
            b += eraser.size();
            //  eraser is found
            //  Debug 
            std::cerr << "eraser" << std::endl;
        }
        else if( match_strings( b, e, erase.begin(), erase.end() ) ) {
            b += erase.size();
            //  erase is found
            //  Debug 
            std::cerr << "erase" << std::endl;
        }
        else {
            //  None of the above is found
            std::cout << "NO" << std::endl;
            //  Finalize
            std::cerr << "Normally terminated with no found." << std::endl;
            return( 0 );
        }
    }

    //  If it come here, it is found
    std::cout << "YES" << std::endl;

    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}

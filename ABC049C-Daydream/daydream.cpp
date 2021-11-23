/*
    ABC049C - 白昼夢
        https://atcoder.jp/contests/abs/tasks/arc065_a
        Author: Keitaro Naruse
        Date:   2021-11-18, 2021-11-23
        MIT License
*/
//
//  # Programming point
//  - Distinguish dream-erase? from dreamer-* 
//  # My solution
//  - if a string matches with dream
//    - if the follwoing matches with eraser -> dream-eraser
//    - else if it does with erase -> dream-erase
//    - else if it does with er -> dreamer
//    - else -> continue
//  - else if a string matches with eraser
//  - else if a string matches with erase
//  - else -> No

#include <iostream>
#include <string>
#include <algorithm>

/*
    match_strings(b, e, b2, e2)
        # return 
        - true if [b, e] matches with [b2, e2]
        - false if not
*/
bool match_strings(std::string::iterator b, std::string::iterator e, 
    std::string::iterator b2, std::string::iterator e2 )
{
    // //  Debug
    // std::string be( b, e ), b2e2( b2, e2 );
    // std::cerr << be << " " << b2e2 << std::endl;

    //  If a given sentence is empty, no match
    if( b == e ) {
        return( false );
    }

    while( b2 != e2 ) {
        //  Continue the loop if the characters are same
        if(*b == *b2) {
            b ++;
            b2 ++;
            //  if a given sentence and a word get empty at the same time, match
            if( ( b == e ) && ( b2 == e2 ) ) {
                return( true );
            }
        }
        else {
            return( false );
        }
    }
  
    //  If it has come to here, all match
    return( true );
}

int main()
{
    //  Initialize
    //  literals
    std::string dream("dream"), eraser("eraser"), erase("erase"), er("er"); 

    //  Read S
    std::string S;
    std::cin >> S;
    //  Debug
    std::cerr << S << std::endl;

    //  Main 
    bool isMatched = false;
    std::string::iterator b = S.begin(), e = S.end();
    while( b != e ) {
        isMatched = true;
        //  Match with dream
        if( match_strings( b, e, dream.begin(), dream.end() ) ) {
            b += dream.size();
            //  Match with eraser
            if( match_strings( b, e, eraser.begin(), eraser.end() ) ) {
                b += eraser.size();
            }
            //  Match with erase
            else if( match_strings( b, e, erase.begin(), erase.end() ) ) {
                b += erase.size();
            }
            //  Match with er
            else if( match_strings( b, e, er.begin(), er.end() ) ) {
                b += er.size();
            }
        }
        //  Match with eraser
        else if( match_strings( b, e, eraser.begin(), eraser.end() ) ) {
            b += eraser.size();
        }
        //  Match with erase
        else if( match_strings( b, e, erase.begin(), erase.end() ) ) {
            b += erase.size();
        }
        //  No match
        else {
            isMatched = false;
            break;
        }
    }

    //  Print result
    if( isMatched ) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
    //  Finalize
    std::cerr << "Normally terminated." << std::endl;

    return( 0 );
}

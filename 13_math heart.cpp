#include <iostream>
using namespace std;

int main() {

    string PINK = "\033[95m";
    string RED  = "\033[91m";
    string WHITE = "\033[97m";
    string RESET = "\033[0m";

    cout << "\033[2J\033[H";

    cout << PINK << R"(

 LL          OOOOO       VV       VV   EEEEEEEEE
 LL        OO     OO     VV       VV   EE
 LL       OO       OO     VV     VV    EE
 LL       OO       OO     VV     VV    EEEEEEE
 LL       OO       OO      VV   VV     EE
 LL        OO     OO        VV VV      EE
 LLLLLLLL    OOOOO           VVV       EEEEEEEEE

)" << RESET;

    cout << RED << R"(

             *******             *******
          *************       *************
        *****************   *****************
      *****************************************
     *******************************************
    *********************************************
    *********************************************
     *******************************************
      *****************************************
        *************************************
          *********************************
            *****************************
              *************************
                *********************
                  *****************
                    *************
                      *********
                        *****
                          *

)" << RESET;

    cout << WHITE;
    cout << "              C + +   L O V E   M O D E\n";
    cout << RESET;

    cout << PINK;
    cout << "\n                    <3  <3  <3\n\n";
    cout << RESET;

    return 0;
}
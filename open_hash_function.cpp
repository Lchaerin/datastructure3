#include "open_hash_function.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


int OpenHashFunction::openhashing(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int index,sum=0;
    for(int i=key;i>0;i=i/10){
        sum+=i%10;
    }
    index=sum%index_size;
    return index;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

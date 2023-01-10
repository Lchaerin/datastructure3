#include "closed_hash_function.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;


int ClosedHashFunction::closedhashing(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int hashing=int(pow(key,2));
    int* num=new int[key_size*2];
    int result=0;
    
    for(int i=0;i<key_size*2;i++){
        num[i]=hashing/int(pow(2,(key_size*2-i-1)));
        hashing=hashing%int(pow(2,(key_size*2-i-1)));
    }
    for(int j=0;j<index_size;j++){
        result+=num[key_size-index_size/2+j]*int(pow(2,index_size-j-1));
    }
    return result;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
  
}


/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

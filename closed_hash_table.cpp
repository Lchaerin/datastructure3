#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "closed_hash_function.h"
#include "closed_hash_table.h"

using namespace std;

ClosedHashTable::ClosedHashTable(int table_size, ClosedHashFunction *hf) : table_size(table_size) {
    this->hf = hf;
    this->table = new int[this->table_size];
    this->states = new ClosedTableState[this->table_size];
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    
    for(int i=0;i<table_size;i++){
        this->states[i]=CLOSED_EMPTY;
    }
    
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

ClosedHashTable::~ClosedHashTable() {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    
    /*  Write your codes if you need  */
    
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////

    delete[] this->table;
    delete[] this->states;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
void ClosedHashTable::print_table(ostream &out) {
    for (int i=0; i < this->table_size; i++) {
        out << i << ": ";
        if (this->states[i] == CLOSED_EMPTY)
            out << "empty" << endl;
        else if (this->states[i] == CLOSED_DELETED)
            out << "deleted" << endl;
        else if (this->states[i] == CLOSED_OCCUPIED)
            out << this->table[i] << endl;
        else
            out << "unknown state" << endl;
    }
}

void ClosedHashTable::insert(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int hashed=hf->closedhashing(key);
    if(states[hashed]==CLOSED_EMPTY){
        table[hashed]=key;
        states[hashed]=CLOSED_OCCUPIED;
    }
    else{
        int colli=0;
        while(states[hashed]!=CLOSED_EMPTY){
            colli++;
            int collision=colli*colli+colli+1;
            hashed=hf->closedhashing(key+collision);
        }
        table[hashed]=key;
        states[hashed]=CLOSED_OCCUPIED;
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

void ClosedHashTable::erase(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    for(int i=0;i<table_size;i++){
        if(table[i]==key){
            states[i]=CLOSED_DELETED;
        }
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////


///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

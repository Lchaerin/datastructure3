#include "sort.h"
#include <iostream>
#include <fstream>
#include <string>


sortAlg::sortAlg() {
    arr_size = 0;
    arr = new int[100]; // Each test case will be less than 100 values
}

using namespace std;

void sortAlg::printArray(ofstream &fout) {
    string answer;
    for (int i = 0; i < arr_size - 1; i++)
        answer += to_string(arr[i]) + " ";
    answer += to_string(arr[arr_size - 1]);
    fout << answer << endl;
}

void sortAlg::quickSort(ofstream &fout, int left, int right) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    if (left < right) {
        int piv_index = partition(fout,left,right);
        quickSort(fout, left, piv_index - 1);
        quickSort(fout, piv_index + 1, right);
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

int sortAlg::partition(ofstream &fout,int left, int right){
    int pivot = arr[left];
    int parti = left+1;
    for (int i = left+1; i <= right; i++) {
        if (arr[i] < pivot){
            swap(arr[i], arr[parti]);
            if(arr[i]!=arr[parti]){
            printArray(fout);
            }
            parti++;
            }
    }
    swap(arr[left], arr[parti-1]);
    if (left!=(parti-1)){
        printArray(fout);
        }
    return parti-1;
}

void sortAlg::merge(int left, int mid, int right) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    int* temp=new int[right-left+1];
    int count=0;
    int lp=left;
    int rp=mid+1;
    while((lp<=mid)&&(rp<=right)){
        if(arr[lp]<arr[rp]){
            temp[count]=arr[lp];
            lp++;
        }
        else{
            temp[count]=arr[rp];
            rp++;
        }
        count++;
    }
    if(lp>mid){
        while(rp<=right){
            temp[count]=arr[rp];
            rp++;
            count++;
        }
    }
    else{
        while(lp<=right){
            temp[count]=arr[lp];
            lp++;
            count++;
        }
    }
    for(int i=0;i<right-left+1;i++){
        arr[left+i]=temp[i];
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

void sortAlg::mergeSort(ofstream &fout, int left, int right) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    
    if(left==right)
        return;
    if (left < right) {
        int mid = (left+right)/2;
        mergeSort(fout, left, mid); 
        mergeSort(fout, (mid+1), right);
        merge(left,mid,right);
        printArray(fout);// DO NOT ERASE THIS LINE
    }

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////

}

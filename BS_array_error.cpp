#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <typeinfo>
using namespace std;

int toCheckDucplicateBS(int arr[],int l , int r , int key){
//if found rt -1;
//if not found 1;
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == key)
            return -1;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > key)
            return toCheckDucplicateBS(arr, l, mid - 1, key);

        // Else the element can only be present
        // in right subarray
        return toCheckDucplicateBS(arr, mid + 1, r, key);
    }

    // We reach here when element is not
    // present in array
    return 1;

}
int main(){
    int num=0; // for random number quantity input
    int arrSize=0;


    srand(time(NULL));
    cout << "Enter the number of random numbers you want: " << endl;
    cin >> num;
    int arrRandNumber[num]; // to store random numbers ( may be duplicate number )
    int arrPureNumber[num]; // not duplicate number
    int x=0; // for loop rand generate
    int randNumber = 0; // to store generated random numbers
    int status = NULL ; // to check status 1 or  0
    int indexOfPureArray =0;
    for(x=0; x<=num ; x++){
        randNumber  = (rand()%100)+1;

        arrSize =sizeof(arrPureNumber)/sizeof(arrPureNumber[0]);
        cout<<"Random arr size"<<arrSize<<endl;

        status = toCheckDucplicateBS(arrPureNumber,0,arrSize-1,randNumber);
        if(status ==1){
            cout<<"adding :"<<randNumber<<endl;
            arrPureNumber[indexOfPureArray]=randNumber;
            indexOfPureArray++;
        }else{
            cout<<randNumber <<" is duplicate"<<endl;
        }
    }
    cout<<"All data from Pure Rand array:"<<endl;
    for(x=0; x<=arrSize ; x++ ){
        cout<<arrPureNumber[x]<<" ";
    }


    return 0;
}

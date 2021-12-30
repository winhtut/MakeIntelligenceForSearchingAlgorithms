#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <typeinfo>
using namespace std;

int* ourSort(int arr[],int arrSize){


    int i=0;
    for( i =0 ; i<=arrSize ; i++){
        cout<<"array data:"<<arr[i]<<endl;
    }

    return arr;
}
int main()

{
    //part 1 random generating part
    fstream ob;
    ob.open("test.txt", ios::out);	//opening file in writing mode
    srand(time(NULL));
    int n, t, c,z;
    int error=0;

    cout << "Enter the number of random numbers you want" << endl;
    cin >> n;
    //reuse number of data in our size of array ;
    int arrSize = n;
    int array[arrSize];

    cout << "Random numbers are:" << endl;

    for (c = 1; c <= n; c++)
    {
        t = (rand()%100)+1;
        ob << t <<endl;

    }
    ob.close();	//closing the file

    //part 2 data writint part
    ob.open("test.txt", ios:: in);	//again opening the file but in reading mode

    while (!ob.eof())
    {
        int str;
        ob >> str;	//reading word by word from file and storing in str

        cout << str << "\n";	//printing str
        //cout<<typeid(str).name() <<endl;
        array[error]= str;
        error++;
    }
    cout<<"array data inserted "<<endl;
    cout<<"alll data from array"<<endl;
    for(z=0; z<=arrSize ; z++){
        cout<< z << ":" <<array[z]<<" ";

    }
    ob.close();	//closing the file after use





    //for Sorting
    int* result = ourSort(array,arrSize); //will get sorted data

    int zz=0;
    for(zz=0 ; zz<arrSize ; zz++){
        cout<<" return array data"<<result[zz]<<endl;
    }



    return 0;

}

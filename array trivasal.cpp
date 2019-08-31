#include <iostream>
using namespace std;

// struct isn't a return type
/*struct*/ void reverse_array( float array[], int arraylength )
{
    for (int i = 0; i < (arraylength / 2); i++) {
        float temporary = array[i];                 // temporary wasn't declared
        array[i] = array[(arraylength - 1) - i];
        array[(arraylength - 1) - i] = temporary;
    }
}

int main()
{
    int /*temporary,*/ arraylength;     // unused variable temporary?
    //float array[50];
    /*
    You need to dynamically allocate memory for the array,
    as its size is not know at compile time.
    */
    cout << "Enter the array size: ";
    cin >> arraylength;
    
    float* array = new float[arraylength];

    cout << "Enter the numbers in the array:" << endl;
    for ( int i = 0; i < arraylength; i++ ) {
        cout << "Array[" << i << "] = ";
        cin >> array[i];
    }
    
    reverse_array( array, arraylength );
    
    cout << "The new array order is " << endl;
    for ( int i = 0; i < arraylength; i++ ) { 
        cout << "Array[" << i << "] = " << array[i] << endl;
    }
    
    // free the memory, to prevent memory leaks
    delete[] array;
}

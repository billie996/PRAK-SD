#include <iostream>     
using namespace std;    

void tukar(int *x, int *y) {   
    int temp = *x;         
    *x = *y;               
    *y = temp;               
}

int main() {                   
    int n;                    
    int arr[100];              
    cout << "Masukkan jumlah elemen array: "; 
    cin >> n;                                

    cout << "Masukkan elemen array: ";        
    for (int i = 0; i < n; i++) {             
        cin >> arr[i];                       
    }

    for (int i = 0; i < n-1; i++) {          
        for (int j = i+1; j < n; j++) {       
            if (arr[i] > arr[j]) {            
                tukar(&arr[i], &arr[j]);     
            }
        }
    }

    cout << "Array setelah diurutkan: ";      
    for (int i = 0; i < n; i++) {             
        cout << arr[i] << " ";                
    }

    return 0;                                
}

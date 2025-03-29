#include <iostream>
#include <ctime>

using namespace std;

int find_index(int *a, int size){
    for(int i=0; i<size; i++){
        if(a[i]<0) return i;
    }
    return -1;
}

int main(){
    srand(static_cast<unsigned int>(time(0))); 

    int N1, N2;
    cin >> N1 >> N2;

    int *A = new int[N1]();
    int *B = new int[N2]();
    
    for(int j=0; j<N1; j++){
        A[j] = rand() % 10 - 5;
        cout << A[j] << endl;
    }

    for(int k=0; k<N2; k++){
        B[k] = rand() % 10 - 5;
        cout << B[k] << endl;
    }

    int index_a = find_index(A, N1);
    int index_b = find_index(B, N2);

    cout << "Index A = " << index_a << endl;
    cout << "Index B = " << index_b << endl;

    if (index_a != -1 && index_a != N1 - 1){
        int sum_A = 0;
        int count_A = 0;
        for(int j1 = index_a; j1<N1; j1++){
            sum_A += A[j1];
            count_A += 1;
        }
        float avr_A = float (sum_A)/ count_A;
        cout << "Среднее в массиве А: " << avr_A << endl; 
    } else { 
        cout << "В массиве А нет второй части" << endl;
    }

    if (index_b != -1 && index_b != N2 - 1){
        int sum_B = 0;
        int count_B = 0;
        for(int j2 = index_b; j2<N2; j2++){
            sum_B += B[j2];
            count_B += 1;
        }
        float avr_B = float (sum_B)/ count_B;
        cout << "Среднее в массиве B: " << avr_B << endl; 
    } else { 
        cout << "В массиве B нет второй части" << endl;
    }

    delete[] A;
    delete[] B;

    }

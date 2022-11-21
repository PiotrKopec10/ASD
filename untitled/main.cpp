#include <iostream>
#include <ctime>
#include <math.h>
#include <algorithm>
#include<climits>


using namespace std;


//                                      QS POCZATEK

int Partition(int A[], int p, int r){

    int pivot=A[p];
    int smaller=r+1;

    for (int j = r; j>p ; j--) {
        if (A[j]>pivot){
            smaller--;
            swap(A[smaller],A[j]);
        }
    }
    swap(A[smaller-1],A[p]);
    return smaller-1;
}


void quicksort(int A[],int p, int r){
    if (p<r){
        int q= Partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}

void reverse(int A[], int p, int r)
{
    if(p<r)
    {
        swap(A[p], A[r]);
        reverse(A, p+1, r-1);
    }
}

//                              QS KONIEC



//                          KOPIEC POCZATEK


        void Maxheapify(int A[],int x, int i){

         int  left= 2*i+1;       //wzor na left(i)
         int right= 2*i+2;       // wzor na right(i)
         int largest=i;

            if (left<x && A[left]>A[i]){                //jezeli galazka z lewej jest wieksze od tego co ma na gorze
                largest=left;
            }

            if (right<x && A[right]>A[largest]){        // jezeli galazka z prawej jest wieksze od tego co ma na gorze
                largest=right;
            }

            if (largest != i){
                swap(A[i],A[largest]);
                Maxheapify(A,x,largest);
            }
}

        void Heapbuilder(int A[],int x){

            for (int i =( x/2); i>=0 ; i--) {
                Maxheapify(A,x,i);
            }
}

        void HeapSorting(int A[], int  x){
            Heapbuilder(A,x);
            for (int i = x-1; i >=0 ; i--) {
                swap(A[0],A[i]);
                Maxheapify(A,i,0);
            }

}

    void reverseheap(int A[],int x,int last)
    {
        Heapbuilder(A,x);

        swap(A[x], A[last]);
        reverse(A, x+1, last-1);

    }


//                         KOPIEC KONIEC


//                        SELECTION SORT POCZATEK


void selectionSort(int A[], int size) {
    int i, j, imin;
    for (i = 0; i < size - 1; i++) {
        imin = i;
        for (j = i + 1; j < size; j++)
            if (A[j] < A[imin])
                imin = j;
        swap(A[i], A[imin]);
    }
}


void reverseselection(int A[],int x,int last)
{

    swap(A[x], A[last]);
    reverse(A, x+1, last-1);

}




//                        SELECTION SORT KONIEC





int main() {


    srand(time(0));  // Generuje rozne zestawy cyfr dla randa
    int x = 50000;
    int A[x];
    int B[x];
    int C[x];
    for (int i =0; i <x ; i++) {
        int p=(rand()%999)+1;
        A[i]=p;
        B[i]=p;
        C[i]=p;
    }

    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;

//                      QS POCZATEK

    clock_t startqs=clock();
    quicksort(A,0,x-1);
    clock_t stopqs=clock();
    double timeofqs=(stopqs-startqs);
    cout<<"[QS]Posortowano NIEPOSORTOWANA w czasie: "<<timeofqs<<" ms"<<endl;



    clock_t startqs1=clock();
    quicksort(A,0,x-1);
    clock_t stopqs1=clock();
    double timeofqs1=(stopqs1-startqs1);
    cout<<"[QS]Posortowano POSORTOWANA w czasie: "<<timeofqs1<<" ms"<<endl;



    clock_t startqs2=clock();
    reverse(A,0,x-1);
    quicksort(A,0,x-1);
    clock_t stopqs2=clock();
    double timeofqs2=(stopqs2-startqs2);
    cout<<"[QS]Posortowano POSORTOWANA ODWROTNIE w czasie: "<<timeofqs2<<" ms"<<endl<<endl;


    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;

//                      QS KONIEC




    //              KOPIEC POCZATEK




    clock_t startheap=clock();
    HeapSorting(B,x);
    clock_t stopheap=clock();
    double timeofheap=(stopheap-startheap);
    cout<<"[KOPIEC]Posortowano NIEPOSORTOWANA w czasie: "<<timeofheap<<" ms"<<endl;


    clock_t startheap1=clock();
    HeapSorting(B,x);
    clock_t stopheap1=clock();
    double timeofheap1=(stopheap1-startheap1);
    cout<<"[KOPIEC]Posortowano POSORTOWANA w czasie: "<<timeofheap1<<" ms"<<endl;


    clock_t startheap2=clock();
    reverseheap(B,0,x-1);
    HeapSorting(B,x);
    clock_t stopheap2=clock();
    double timeofheap2=(stopheap2-startheap2);
    cout<<"[KOPIEC]Posortowano POSORTOWANE ODWROTNIE  w czasie: "<<timeofheap2<<" ms"<<endl<<endl;


    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;





    //              KOPIEC KONIEC



    clock_t startselection=clock();
    selectionSort(C,x);
    clock_t stopselection=clock();
    double timeofselection=(stopselection-startselection);

    cout<<"[WYBOR]Posortowano NIEPOSORTOWANA w czasie: "<<timeofselection<<" ms"<<endl;

    clock_t startselection1=clock();
    selectionSort(C,x);
    clock_t stopselection1=clock();
    double timeofselection1=(stopselection1-startselection1);

    cout<<"[WYBOR]Posortowano POSORTOWANA w czasie: "<<timeofselection1<<" ms"<<endl;

    clock_t startselection3=clock();

    reverseselection(C,0,x-1);
    selectionSort(C,x);


    clock_t stopselection3=clock();
    double timeofselection3=(stopselection3-startselection3);



    cout<<"[WYBOR]Posortowano POSORTOWANA ODWROTNIE w czasie: "<<timeofselection3<<"ms"<<endl;




    //                      KONIEC  SELECTION






    return 0;
}


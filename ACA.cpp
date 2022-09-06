#include <iostream>
#include <locale.h>

using namespace std;
void merge(int *,int, int , int );
void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){ //o(1) ("o" sendo utilizado como notação Theta)
        mid=(low+high)/2; //o(1)
        merge_sort(arr,low,mid); //T(n/2)
        merge_sort(arr,mid+1,high); //T(n/2)
        merge(arr,low,high,mid); //o(n)
    }

    /* 
    Relação de Recorrência

    T(n) = o(1) + T(n/2) + T(n/2) + o(n)
         = 2T(n/2) + o(n) + o(1) 
         = 2T(n/2) + n 

    */

}

void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int myarray[30], num;
    cout<<"Informe a quantidade de números da sequência:";
    cin>>num;
    cout<<"Insira os "<<num<<" números da sequência:";
    for (int i = 0; i < num; i++) { cin>>myarray[i];
    }
    merge_sort(myarray, 0, num-1);
    cout<<"Sequência ordenada\n";
    for (int i = 0; i < num; i++)
    {
        cout<<myarray[i]<<"\t";
    }
}
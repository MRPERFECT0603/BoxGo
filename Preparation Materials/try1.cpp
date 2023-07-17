#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int left_arr[n1], right_arr[n2];

    for (i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (left_arr[i] >= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int h[] = {42,38,9,27,14};
    int w[] = {49,39,5,35,26};
    int l[] = {12,10,4,8,6};
    int h_size = sizeof(h) / sizeof(int);
    int hcopy[h_size];
    int wcopy[h_size];
    int lcopy[h_size];
    for(int i=0;i<h_size;i++)
    {
        hcopy[i] = h[i];
    }
    cout << "Given array is \n";
    for (int i = 0; i < h_size; i++)
        cout << hcopy[i] << " ";

    mergeSort(hcopy, 0, h_size - 1);

    cout << "\nSorted array is \n";
    for (int i = 0; i < h_size; i++)
    {
        cout << hcopy[i] << " ";
    }
    cout<<endl;
    for (int i = 0; i < h_size; i++)
    {
        for(int j=0;j<h_size;j++)
        {
            if(hcopy[i]==h[j])
            {
                wcopy[i]=w[j];
                lcopy[i]=l[j];
            }
        }
    }
    for (int i = 0; i < h_size; i++)
    {
        cout << hcopy[i] << " ";
    }
    cout<<endl;
    for (int i = 0; i < h_size; i++)
    {
        cout << wcopy[i] << " ";
    }
    cout<<endl;
    for (int i = 0; i < h_size; i++)
    {
        cout << lcopy[i] << " ";
    }
    return 0;
}

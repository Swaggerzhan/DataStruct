//
// Created by swagger on 2021/4/7.
//

#ifndef DATASTRUCT_MERGESORT_H
#define DATASTRUCT_MERGESORT_H



void __merge(int arr[], int l, int mid, int r){

    int tmp[r - l + 1];
    for (int i=l; i<=r; i++)
        tmp[i-l] = arr[i];

    int i = l, j = mid+1;
    for (int k=l; k<=r; k++){

        if (i > mid){
            arr[k] = tmp[j-l];
            j ++;
        }else if ( j > r){
            arr[k] = tmp[i-l];
            i ++;
        }else if (tmp[i-l] < tmp[j-l]){
            arr[k] = tmp[i-l];
            i ++;
        }else {
            arr[k] = tmp[j-l];
            j ++;
        }
    }
}

/**
 * [l, ....., r]
 * @tparam T
 * @param arr
 * @param l
 * @param r
 */
void __mergeSort(int arr[], int l, int r){

    if ( l >= r)
        return;
    int mid = l + ((r - l) / 2);
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    //if ( arr[mid] > arr[mid+1])
        __merge(arr, l, mid, r);
}




void mergeSort(int arr[], int n){

    __mergeSort(arr, 0, n-1);

}




#endif //DATASTRUCT_MERGESORT_H

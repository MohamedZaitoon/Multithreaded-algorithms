#include <iostream>
#include <fstream>
#include <pthread.h>
#include <ctime>


using namespace std;

int *temp_arr;


//arguments of merge_sort function for threads
struct merge_input{
    int * arr;
    int left;
    int right;
};

void merge(int * arr, int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int it = 0;

    while(i <= mid && j <= right){
        if(arr[i] < arr[j])
            temp_arr[it++] = arr[i++];
        else
            temp_arr[it++] = arr[j++];
    }
    while(i <= mid){
        temp_arr[it++] = arr[i++];
    }

    while(j <= right){
        temp_arr[it++] = arr[j++];
    }

    for(int k = 0; k < it; k++){
        arr[left+k] = temp_arr[k];
    }

}

void* merge_sort(void * args){

    merge_input* mi = (merge_input*) args;
    int left = mi->left;
    int right = mi->right;
    int *arr = mi->arr;
    if(left < right){
        int mid = (right + left)/ 2;
        merge_input left_side = {arr, left, mid};
        merge_input right_side = {arr, mid+1, right};
        pthread_t th1;//,th2 ;

        pthread_create(&th1, NULL, merge_sort, &left_side);
        // pthread_create(&th2, NULL, merge_sort, &right_side); //using two thread leads to overhead on the system, so it take more time
        merge_sort(&right_side);
        


        pthread_join(th1, NULL);
        // pthread_join(th2, NULL);
        merge(arr, left, mid, right);

    }

}
//print array
void print_array(int *arr, int len){
    for(int i =0; i < len; i++){
        printf("%d ", arr[i]);
    }
}

int main() {
    //read input configuration
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    //read input
    int n;
    int *arr;
    cin>>n;
    if(n== 0)return 0;

    arr = new int[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    temp_arr = new int[n];

    //sort
    merge_input input ={arr, 0,n-1};
    pthread_t th ;
    pthread_create(&th, NULL, merge_sort, &input);
    pthread_join(th,NULL);
    //merge_sort(&input);
    print_array(arr, n);


    delete[] arr;
    delete[] temp_arr;
    return 0;
}

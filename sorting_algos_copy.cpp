#include <iostream>

using namespace std;

int* BubbleSort(int arr[],int arr_length){
    int x;
    int y;
    int* arr_pointer=arr;
    for(int i=0;i<arr_length;i++){
        for(int j=0;j<arr_length;j++){
            //ascending
            if(arr[j]>arr[j+1]){
                //swaping
                x=arr[j];
                y=arr[j+1];
                arr[j+1]=x;
                arr[j]=y;
            }
        }
    }
    return arr_pointer;
}

int* InsertionSort(int arr[],int arr_length){
    int x;
    int y;
    int* arr_pointer=arr;
    for(int i=0;i<arr_length;i++){
        for(int j=i;j>=0;j--){
            //ascending
            if(arr[j]>arr[j+1]){ //not sorted
                x=arr[j];
                y=arr[j+1];
                arr[j+1]=x;
                arr[j]=y;
            }
            else{
                break;
            }
        }
    }
    return arr_pointer;
}

int* SelectionSort(int arr[],int arr_length){
    int x;
    int y;
    int* arr_pointer=arr;
    int min;
    int min_index=0;
    for(int i=0;i<arr_length-1;i++){
        min=arr[i];
        for(int j=i;j<arr_length;j++){
            if(arr[j]<min){
                min=arr[j];
                min_index=j;
            }
        }
        //swaping
        x=arr[min_index];
        y=arr[i];
        arr[i]=x;
        arr[min_index]=y;
    }
    return arr_pointer;
}

int* merge(int* left_sorted_pointer,int left_length,int* right_sorted_pointer,int right_length){
    int i=0;
    int j=0;
    int* result_pointer=new int[left_length+right_length];
    // int* result_pointer=result;
    while(i<left_length && j<right_length){
        if(left_sorted_pointer[i]<=right_sorted_pointer[j]){
            result_pointer[i+j]=left_sorted_pointer[i];
            i++;
        }
        else if(left_sorted_pointer[i]>right_sorted_pointer[j]){
            result_pointer[i+j]=right_sorted_pointer[j];
            j++;
        }
    }
    while(i<left_length){
        result_pointer[i+j]=left_sorted_pointer[i];
        i++;
    }
    while(j<right_length){
        result_pointer[i+j]=right_sorted_pointer[j];
        j++;
    }
    return result_pointer;
}

int* MergeSort(int arr[],int arr_length){
    int* arr_pointer=arr;
    if(arr_length<=1){
        return arr_pointer;
    }
    int mid=arr_length/2;
    int* left=new int[mid];
    int* right=new int[arr_length-mid];
    for(int i=0;i<mid;i++){
        left[i]=arr[i];
    }
    for(int i=mid;i<arr_length;i++){
        right[i-mid]=arr[i];
    }
    int* left_sorted_pointer=MergeSort(left,mid);
    int* right_sorted_pointer=MergeSort(right,arr_length-mid);
    return merge(left_sorted_pointer,mid,right_sorted_pointer,arr_length-mid);
}

int Partition(int* arr,int start,int end){
    int x;
    int pivot=arr[end];
    int pIndex=start;
    for(int i=start;i<end;i++){
        if(arr[i]<=pivot){
            //swaping
            x=arr[i];
            arr[i]=arr[pIndex];
            arr[pIndex]=x;
            pIndex++;
        }
    }
    //swaping
    x=arr[pIndex];
    arr[pIndex]=arr[end];
    arr[end]=x;
    return pIndex;
}

void QuickSort(int* arr,int start,int end){
    if(start>=end){
        return;
    }
    int Pindex=Partition(arr,start,end);
    QuickSort(arr,start,Pindex-1);
    QuickSort(arr,Pindex+1,end);
}


int main(){
    int option_selected;
    int num_test_cases;
    cin>>option_selected;
    cin>>num_test_cases;
    int* arr_lengths=new int[num_test_cases];
    int** arr=new int*[num_test_cases];
    for(int i=0;i<num_test_cases;i++){
        cin>>arr_lengths[i];
        arr[i]=new int[arr_lengths[i]];
        for(int j=0;j<arr_lengths[i];j++){
            cin>>arr[i][j];
        }
    }
    if(option_selected==1){
        for(int i=0;i<num_test_cases;i++){
            arr[i]=BubbleSort(arr[i],arr_lengths[i]);
            for(int j=0;j<arr_lengths[i];j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else if(option_selected==2){
        for(int i=0;i<num_test_cases;i++){
            arr[i]=InsertionSort(arr[i],arr_lengths[i]);
            for(int j=0;j<arr_lengths[i];j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else if(option_selected==3){
        for(int i=0;i<num_test_cases;i++){
            arr[i]=SelectionSort(arr[i],arr_lengths[i]);
            for(int j=0;j<arr_lengths[i];j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else if(option_selected==4){
        for(int i=0;i<num_test_cases;i++){
            arr[i]=MergeSort(arr[i],arr_lengths[i]);
            for(int j=0;j<arr_lengths[i];j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else if(option_selected==5){
        for(int i=0;i<num_test_cases;i++){
            QuickSort(arr[i],0,arr_lengths[i]-1);
            for(int j=0;j<arr_lengths[i];j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
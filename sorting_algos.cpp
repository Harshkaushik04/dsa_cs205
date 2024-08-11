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
    // cout<<"hi"<<endl;
    int* arr_pointer=arr;
    if(arr_length<=1){
        // cout<<*arr_pointer<<endl;
        return arr_pointer;
    }
    int mid=arr_length/2;
    // cout<<"new"<<endl;
    int* left=new int[mid];
    int* right=new int[arr_length-mid];
    // cout<<"bye"<<endl;
    for(int i=0;i<mid;i++){
        left[i]=arr[i];
        // cout<<left[i]<<" ";
    }
    // cout<<endl;
    for(int i=mid;i<arr_length;i++){
        right[i-mid]=arr[i];
        // cout<<right[i]<<" ";
    }
    // cout<<endl;
    int* left_sorted_pointer=MergeSort(left,mid);
    int* right_sorted_pointer=MergeSort(right,arr_length-mid);
    return merge(left_sorted_pointer,mid,right_sorted_pointer,arr_length-mid);
}

int* Partition(int* arr,int start,int end){ //returns array in which first length(arr) elements are actual array members which are partitioned and last element is the partition index
    int Pindex;
    int pivot=arr[end];
    bool flag=true;
    int x;
    int y;
    int* final_arr=new int[end-start+2]; //returns array in which first length(arr) elements are actual array members which are partitioned and last element is the partition index
    while(start<end){
        while(arr[start]<pivot){
            start++;
            if(start>=end){
                Pindex=end;
                flag=false;
                break;
            }
        }
        if(flag==false){
            break;
        }
        while(arr[end]>pivot){
            end--;
            if(start>=end){
                Pindex=start;
                flag=false;
                break;
            }
        }
        if(flag==false){
            break;
        }
        //swaping
        x=arr[start];
        y=arr[end];
        arr[start]=y;
        arr[end]=x;
    }
    for(int i=0;i<start-end+1;i++){
        final_arr[i]=arr[i];
    }
    final_arr[start-end+1]=Pindex;
    int* final_arr_pointer=final_arr;

    return final_arr_pointer;
}

int* QuickSort(int* arr,int start,int end){ //end element as pivot
    if(start>=end){
        return arr;
    }
    int* partitioned_arr=new int[start-end+1];
    int Pindex;
    int* final_arr=Partition(arr,start,end);
    for(int i=0;i<start-end+1;i++){
        partitioned_arr[i]=final_arr[i];
    }
    Pindex=final_arr[start-end+1];
    arr=QuickSort(partitioned_arr,start,Pindex-1);
    arr=QuickSort(partitioned_arr,Pindex+1,end);
    return arr;
}

int main(){
    int option_selected;
    int num_test_cases;
    cin>>option_selected;
    cin>>num_test_cases;
    pair<int,int*> arr[num_test_cases]; //length of array, array itself
    for(int i=0;i<num_test_cases;i++){
        cin>>arr[i].first;
        arr[i].second=new int[arr[i].first];
        for(int j=0;j<arr[i].first;j++){
            cin>>(arr[i].second)[j];
        }
    }
    if(option_selected==1){
        for(int i=0;i<num_test_cases;i++){
            arr[i].second=BubbleSort(arr[i].second,arr[i].first);
            for(int j=0;j<arr[i].first;j++){
                cout<<arr[i].second[j]<<" ";
            }
            cout<<endl;
        }
    }
    else if(option_selected==2){
        for(int i=0;i<num_test_cases;i++){
            arr[i].second=InsertionSort(arr[i].second,arr[i].first);
            for(int j=0;j<arr[i].first;j++){
                cout<<arr[i].second[j]<<" ";
            }
            cout<<endl;
        }
    }
    else if(option_selected==3){
        for(int i=0;i<num_test_cases;i++){
            arr[i].second=SelectionSort(arr[i].second,arr[i].first-1);
            for(int j=0;j<arr[i].first;j++){
                cout<<arr[i].second[j]<<" ";
            }
            cout<<endl;
        }
    }
    else if(option_selected==4){
        for(int i=0;i<num_test_cases;i++){
            arr[i].second=MergeSort(arr[i].second,arr[i].first);
            for(int j=0;j<arr[i].first;j++){
                cout<<arr[i].second[j]<<" ";
            }
            cout<<endl;
        }
    }
    else if(option_selected==5){
        for(int i=0;i<num_test_cases;i++){
            arr[i].second=QuickSort(arr[i].second,0,arr[i].first-1);
            for(int j=0;j<arr[i].first;j++){
                cout<<arr[i].second[j]<<" ";
            }
            cout<<endl;
        }
    }
    // int arr[5]={4,2,9,8,6};
    // int arr_length=5;
    // int* sorted_array=BubbleSort(arr,arr_length);
    // for(int i=0;i<arr_length;i++){
    //     cout<<*(sorted_array+i)<<endl;
    // }
    return 0;
}
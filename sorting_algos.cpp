#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int* sorted_array_generator(int num_integers){
    int arr[num_integers];
    int* arr_pointer=arr;
    for(int i=0;i<num_integers;i++){
        arr_pointer[i]=i;
    }
    return arr_pointer;
}

int* unsorted_array_generator(int num_integers,int random_seed){
    mt19937 gen(random_seed);
    int lower_bound = 0;
    int upper_bound = 15000;
    uniform_int_distribution<> dis(lower_bound, upper_bound); 
    int arr[num_integers];
    int* arr_pointer=arr;
    for(int i=0;i<num_integers;i++){
        arr_pointer[i]=dis(gen);
    }
    return arr_pointer;
}
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

// int* Partition(int* arr,int start,int end){ //returns array in which first length(arr) elements are actual array members which are partitioned and last element is the partition index
//     int Pindex;
//     int pivot=arr[end];
//     bool flag=true;
//     int x;
//     int y;
//     int* final_arr=new int[end-start+2]; //returns array in which first length(arr) elements are actual array members which are partitioned and last element is the partition index
//     while(start<end){
//         while(arr[start]<pivot){
//             start++;
//             if(start>=end){
//                 Pindex=end;
//                 flag=false;
//                 break;
//             }
//         }
//         if(flag==false){
//             break;
//         }
//         while(arr[end]>pivot){
//             end--;
//             if(start>=end){
//                 Pindex=start;
//                 flag=false;
//                 break;
//             }
//         }
//         if(flag==false){
//             break;
//         }
//         //swaping
//         x=arr[start];
//         y=arr[end];
//         arr[start]=y;
//         arr[end]=x;
//     }
//     for(int i=0;i<start-end+1;i++){
//         final_arr[i]=arr[i];
//     }
//     final_arr[start-end+1]=Pindex;
//     int* final_arr_pointer=final_arr;

//     return final_arr_pointer;
// }

// int* QuickSort(int* arr,int start,int end){ //end element as pivot
//     if(start>=end){
//         return arr;
//     }
//     int* partitioned_arr=new int[start-end+1];
//     int Pindex;
//     int* final_arr=new int[start-end+2];
//     final_arr=Partition(arr,start,end);
//     for(int i=0;i<start-end+1;i++){
//         partitioned_arr[i]=final_arr[i];
//     }
//     Pindex=final_arr[start-end+1];
//     arr=QuickSort(partitioned_arr,start,Pindex-1);
//     arr=QuickSort(partitioned_arr,Pindex+1,end);
//     return arr;
// }
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
    int* sorted_arr;
    int* unsorted_arr;
    clock_t start;
    clock_t end;
    vector<double> bubble_sort_time={};
    vector<double> insertion_sort_time={};
    vector<double> selection_sort_time={};
    vector<double> merge_sort_time={};
    vector<double> quick_sort_time={};
    double duration;
    int x=9995;
    for(int i=2;i<=x+5;i++){
        cout<<i<<endl;
        int* answer_arr=new int[i];
        sorted_arr=sorted_array_generator(i);
        unsorted_arr=unsorted_array_generator(i,42);
        //unsorted
        start=clock();
        answer_arr=BubbleSort(unsorted_arr,i);
        end=clock();
        duration = double(end - start) / CLOCKS_PER_SEC;
        bubble_sort_time.push_back(duration);
        // start=clock();
        // answer_arr=InsertionSort(unsorted_arr,i);
        // end=clock();
        // duration = double(end - start) / CLOCKS_PER_SEC;
        // insertion_sort_time.push_back(duration);
        // start=clock();
        // answer_arr=SelectionSort(unsorted_arr,i);
        // end=clock();
        // duration = double(end - start) / CLOCKS_PER_SEC;
        // selection_sort_time.push_back(duration);
        // start=clock();
        // answer_arr=MergeSort(unsorted_arr,i);
        // end=clock();
        // duration = double(end - start) / CLOCKS_PER_SEC;
        // merge_sort_time.push_back(duration);
        // start=clock();
        // QuickSort(unsorted_arr,0,i-1);
        // end=clock();
        // duration = double(end - start) / CLOCKS_PER_SEC;
        // quick_sort_time.push_back(duration);
        // delete[] answer_arr;
    }
    cout<<"Bubble sort time:"<<bubble_sort_time[x]<<endl;
    for(int i=2;i<=x+5;i++){
        cout<<i<<endl;
        int* answer_arr=new int[i];
        sorted_arr=sorted_array_generator(i);
        unsorted_arr=unsorted_array_generator(i,42);
        //unsorted
        start=clock();
        answer_arr=InsertionSort(unsorted_arr,i);
        end=clock();
        duration = double(end - start) / CLOCKS_PER_SEC;
        insertion_sort_time.push_back(duration);
    }
    cout<<"insertion sort time:"<<insertion_sort_time[x]<<endl;
    for(int i=2;i<=x+5;i++){
        cout<<i<<endl;
        int* answer_arr=new int[i];
        sorted_arr=sorted_array_generator(i);
        unsorted_arr=unsorted_array_generator(i,42);
        //unsorted
        start=clock();
        answer_arr=SelectionSort(unsorted_arr,i);
        end=clock();
        duration = double(end - start) / CLOCKS_PER_SEC;
        selection_sort_time.push_back(duration);
    }
    cout<<"selection sort time:"<<selection_sort_time[x]<<endl;
    for(int i=2;i<=x+5;i++){
        cout<<i<<endl;
        int* answer_arr=new int[i];
        sorted_arr=sorted_array_generator(i);
        unsorted_arr=unsorted_array_generator(i,42);
        //unsorted
        start=clock();
        answer_arr=MergeSort(unsorted_arr,i);
        end=clock();
        duration = double(end - start) / CLOCKS_PER_SEC;
        merge_sort_time.push_back(duration);
    }
    cout<<"merge sort time:"<<merge_sort_time[x]<<endl;
    for(int i=2;i<=x+5;i++){
        cout<<i<<endl;
        int* answer_arr=new int[i];
        sorted_arr=sorted_array_generator(i);
        unsorted_arr=unsorted_array_generator(i,42);
        //unsorted
        start=clock();
        QuickSort(unsorted_arr,0,i-1);
        end=clock();
        duration = double(end - start) / CLOCKS_PER_SEC;
        quick_sort_time.push_back(duration);
    }
    cout<<"quick sort time:"<<quick_sort_time[x]<<endl;
    return 0;
}
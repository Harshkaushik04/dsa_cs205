#include <iostream>
using namespace std;

void ternary_search(int* arr,int to_search,int start,int end){
    if(end-start>=2){
        int left_pivot=start+(end-start)/3;
        int right_pivot=start+2*(end-start)/3;
        if(to_search==arr[left_pivot]){
            cout<<"Found in index "<<left_pivot<<endl;
            return;
        }
        else if(to_search==arr[right_pivot]){
            cout<<"Found in index "<<right_pivot<<endl;
            return;
        }
        else if(to_search<arr[left_pivot]){
            ternary_search(arr,to_search,start,left_pivot-1);
        }
        else if(to_search<arr[right_pivot]){
            ternary_search(arr,to_search,left_pivot+1,right_pivot-1);
        }
        else if(to_search>arr[right_pivot]){
            ternary_search(arr,to_search,right_pivot+1,end);
        }
        else{
            cout<<"Not present in the given array"<<endl;
            return;
        }
    }
    else if(end-start==1){
        if(arr[start]==to_search){
            cout<<"Found in index "<<start<<endl;
            return;
        }
        else if(arr[end]==to_search){
            cout<<"Found in index "<<end<<endl;
            return;
        }
        else{
            cout<<"Not present in the given array"<<endl;
            return;
        }
    }
    else if(end-start==0){
        if(arr[start]==to_search){
            cout<<"Found in index "<<start<<endl;
            return;
        }
        else{
            cout<<"Not present in the given array"<<endl;
            return;
        }
    }
}



int main(){
    int num_test_cases;
    cin>>num_test_cases;
    int* arr_lengths=new int[num_test_cases];
    int* to_search=new int[num_test_cases];
    int** arr=new int*[num_test_cases];
    for(int i=0;i<num_test_cases;i++){
        cin>>arr_lengths[i];
        arr[i]=new int[arr_lengths[i]];
        for(int j=0;j<arr_lengths[i];j++){
            cin>>arr[i][j];
        }
        cin>>to_search[i];
    }

    for(int i=0;i<num_test_cases;i++){
        ternary_search(arr[i],to_search[i],0,arr_lengths[i]-1);
    }
    return 0;
}
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

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

#include <iostream>
#include <vector>
#include <cstdio>

void plotSingleVector(const std::vector<double>& vector_1) {
    // Open a pipe to GNUplot
    FILE* gnuplotPipe = popen("gnuplot -persistent", "w");
    if (!gnuplotPipe) {
        std::cerr << "Error: Could not open pipe to GNUplot." << std::endl;
        return;
    }

    // Write GNUplot commands to the pipe
    fprintf(gnuplotPipe, "set terminal pngcairo\n");
    fprintf(gnuplotPipe, "set output 'ternary_Search.png'\n");
    fprintf(gnuplotPipe, "set title 'ternary search time'\n");
    fprintf(gnuplotPipe, "set xlabel 'Array Size'\n");
    fprintf(gnuplotPipe, "set ylabel 'Time'\n");
    fprintf(gnuplotPipe, "plot '-' with lines title 'Vector 1'\n");

    // Write vector_1 data to GNUplot
    for (size_t i = 0; i < vector_1.size(); ++i) {
        fprintf(gnuplotPipe, "%zu %f\n", i + 2, vector_1[i]); // x = i + 2
    }
    fprintf(gnuplotPipe, "e\n"); // End of data

    // Close the pipe
    pclose(gnuplotPipe);
}



int main(){
    clock_t start;
    clock_t end;
    double duration;
    vector<double> ternary_search_time;
    int* arr_pointer;
    for(int i=3;i<=500000;i++){
        cout<<i<<endl;
        int arr[i];
        for(int j=0;j<i;j++){
            arr[j]=j;
        }
        arr_pointer=arr;
        // cout<<"i:"<<i<<endl;
        start=clock();
        ternary_search(arr_pointer,arr[0],0,i-1);
        end=clock();
        duration = double(end - start) / CLOCKS_PER_SEC;
        ternary_search_time.push_back(duration);
    }
    plotSingleVector(ternary_search_time);
}
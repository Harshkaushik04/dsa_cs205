#include <iostream>

using namespace std;

int main(){
    int option_selected;
    int num_test_cases;
    pair<int,int*> arr[num_test_cases]; //length of array, array itself
    cin>>option_selected;
    cin>>num_test_cases;
    for(int i=0;i<num_test_cases;i++){
        cin>>arr[i].first;
    }
    return 0;
}
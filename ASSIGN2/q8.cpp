#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int n = 6;
    int arr[6] = {1, 2, 1, 2, 3, 4};
    
    sort(arr, arr + n);

    int j = 0;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] != arr[i+1]) {
            j++;
            arr[j] = arr[i+1];
            
        }
    }
    n = j+1;
    cout<<"no. of unique elements are "<<n<<endl;
}
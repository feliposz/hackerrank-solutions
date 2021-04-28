#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){	
    deque<int> max;
    int i;
    
    for (i = 0; i < k; i++) {
        while (!max.empty() && (arr[i] >= arr[max.back()])) {
            max.pop_back();
        }
        max.push_back(i);
    }
    
    for (; i < n; i++) {
        cout << arr[max.front()] << " ";
        
        while (!max.empty() && (max.front() <= (i - k))) {
            max.pop_front();
        }

        while (!max.empty() && (arr[i] >= arr[max.back()])) {
            max.pop_back();
        }
        
        max.push_back(i);
    }
    
    cout << arr[max.front()] << endl;
}

int main(){
  
    ios::sync_with_stdio(false);
    
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}


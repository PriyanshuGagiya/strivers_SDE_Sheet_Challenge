#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/min-heap_8230863?challengeSlug=striver-sde-challenge&leftPanelTab=1
//using data structure pq
vector<int> minHeap(int n, vector<vector<int>>& q) 
{
    // Write your code here.
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        if(q[i][0])
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        else
        {
            pq.push(q[i][1]);
        }
    }
    return ans;
}
//heap implementation using array
#include <bits/stdc++.h> 

void heapify(vector<int>& arr, int size, int index);

class MinHeap{
    private: 
        vector<int> arr;
        int size;
        int max_size;
    public:
        MinHeap(){
            size = 0;
            max_size = 0;
        }
        void add(int x){
            if(size < max_size){
                arr[size] = x;
                int i = size;
                while(i > 0){
                    if(arr[i] < arr[(i - 1)/2]){
                        swap(arr[i], arr[(i - 1)/2]);
                        i = (i - 1)/2;
                    }
                    else{
                        break;
                    }
                }
                size++;
            }
            else{
                arr.push_back(x);
                max_size++;
                int i = size;
                while(i > 0){
                    if(arr[i] < arr[(i - 1)/2]){
                        swap(arr[i], arr[(i - 1)/2]);
                        i = (i - 1)/2;
                    }
                    else{
                        break;
                    }
                }
                size++;
            }
        }
        void remove(){
            if(size != 0){
                size--;
                // Step 1: put the root node value to the a last index.
                swap(arr[0], arr[size]);
                // Step 2: Heapify the newly formed heap
                heapify(arr, size, 0);
            }
        }
        bool empty(){
            return size == 0;
        }
        int length(){
            return size;
        }
        void print(){
            cout << "printing" << endl;
            for(int i = 0; i < size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        int front(){
            return (size == 0)?(-1):(arr[0]);
        }
};

void heapify(vector<int> &arr, int size, int index){
    // Step 1: Check the Base condition
    if(index >= size) return;

    // Step 2: Point a pointer to the smallest element to the root.
    int smallest = index;
    
    // Step 3: find the index to the right and left child.
    int left = index*2 + 1;
    int right = index*2 + 2;

    // Step 4: Check and update the smallest value.
    if(left < size && arr[smallest] > arr[left])
        smallest = left;
    if(right < size && arr[smallest] > arr[right])
        smallest = right;
    
    // Step 5: Check If the smallest value is updates
    if(smallest != index){
        // Step 6: swap the smallest value and the root value.
        swap(arr[smallest], arr[index]);
        
        // Step 7: Recursively update the updated tree.
        heapify(arr, size, smallest);
    }
}


vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> ans;
    MinHeap mh;
    for(int i = 0; i < n; i++){
        if(q[i][0] == 0){
            mh.add(q[i][1]);
        }
        else{
            ans.push_back(mh.front());
            mh.remove();
        }
    }
    return ans;
}


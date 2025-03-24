#include<iostream>
#include<vector>

void merge(std::vector<int>& vecA, int left, int right, int mid){
    

    //Need to get the size of both sub arrays to copy data
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    //create a sorted vector that will be copied to vecA later
    std::vector<int> leftSortedVec(leftSize);
    std::vector<int> rightSortedVec(rightSize);
    //Copy the data into each sorted sub array

    //Left
    for(int i = 0; i < leftSize; ++i){
        leftSortedVec[i] = vecA[left + i];
        //leftSortedVec.push_back(vecA[left + i]);
    }
    //Right
    for(int i = 0; i < rightSize; ++i){
        rightSortedVec[i] = vecA[mid + i + 1];
        //rightSortedVec.push_back(vecA[mid + i + 1]);
    } //Now have two sorted subarrays

    // Compare and merge
    int i = 0; // i tracks position in the lefts sorted subarray
    int j = 0; // j tracks position in the right sorted subarray
    int k = left; // k tracks position in original vector (where the new sorted values need to be put)
    while(i < leftSize && j < rightSize){
        if(leftSortedVec[i] <= rightSortedVec[j]){
            vecA[k] = leftSortedVec[i];
            ++i;
        }else{
            vecA[k] = rightSortedVec[j];
            ++j;
        }
        ++k;
    }
    // Now need to copy extra elements that were not compared (now in order)
    while(i < leftSize){
        vecA[k] = leftSortedVec[i];
        ++i;
        ++k;
    }
    while(j < rightSize){
        vecA[k] = rightSortedVec[j];
        ++j;
        ++k;
    }

}
//Merge sort on vector of integers
//Originally left is start of vector, right is end of vector (indices)
void merge_sort(std::vector<int>& vecA, int left, int right){
    // if right is greater then nothing has to be sorted
    if(left < right){
        int mid = left + (right - left) / 2;
        
        //merge sort on left sublist
        merge_sort(vecA, left, mid);
        //merge sort on right sublist
        merge_sort(vecA, mid + 1, right);

        merge(vecA, left, right, mid);
    }
}
void merge_sort(std::vector<int>& vecA){
    int left = 0;
    int right = vecA.size() - 1;
    merge_sort(vecA, left, right);
}
void print_vector(std::vector<int>& vecA){
    for(int i = 0; i < vecA.size(); ++i){
        std::cout << vecA[i] << " ";
    }
    std::cout << std::endl;
}
int main(){
std::vector<int> vecA;
    vecA.push_back(5);
    vecA.push_back(4);
    vecA.push_back(3);
    vecA.push_back(2);
    vecA.push_back(1);
    std::cout << "Before merge sort: ";
    print_vector(vecA);
    merge_sort(vecA);
    std::cout << "After merge sort: ";
    print_vector(vecA);

}

#include <iostream>
#include <vector>
#include "mergesort.h"
using namespace std;

void Merge(vector<int>& numbers, int i, int j, int k) {
   int mergedSize;                            // Size of merged partition
   int mergePos;                              // Position to insert merged number
   int leftPos;                               // Position of elements in left partition
   int rightPos;                              // Position of elements in right partition
   //vector<int> mergedNumbers;
 
   mergePos = 0;
   mergedSize = k - i + 1;
   leftPos = i;                               // Initialize left partition position
   rightPos = j + 1;                          // Initialize right partition position
   vector<int>mergedNumbers (mergedSize);       // Dynamically allocates temporary array
                                              // for merged numbers
   
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
      if (numbers.at(leftPos) < numbers.at(rightPos)) {
         mergedNumbers.at(mergePos) = numbers.at(leftPos);
         ++leftPos;
      }
      else {
         mergedNumbers.at(mergePos) = numbers.at(rightPos);
         ++rightPos;
         
      }
      ++mergePos;
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers.at(mergePos) = numbers.at(leftPos);
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers.at(mergePos) = numbers.at(rightPos);
      ++rightPos;
      ++mergePos;
   }
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers.at(i + mergePos) = mergedNumbers.at(mergePos);
   }

} 

void MergeSort(vector<int>& numbers, int i, int k) {
   int j;
   
   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      MergeSort(numbers, i, j);
      MergeSort(numbers, j + 1, k);
      
      // Merge left and right partition in sorted order
      Merge(numbers, i, j, k);
   }
}

int main() {
   vector<int> numbers;// { 10, 2, 78, 4, 45, 32, 7, 11 };
   numbers.push_back(10);
   numbers.push_back(2);
   numbers.push_back(78);
   numbers.push_back(4);
   numbers.push_back(45);
   numbers.push_back(32);
   numbers.push_back(7);
   numbers.push_back(11);

   const int NUMBERS_SIZE = 8;
   int i;
   
   cout << "UNSORTED: ";
   for(i = 0; i < NUMBERS_SIZE; ++i) {
      cout << numbers.at(i) << " ";
   }
   cout << endl;
   
   MergeSort(numbers, 0, NUMBERS_SIZE - 1);
   
   cout << "SORTED: ";
   for(i = 0; i < NUMBERS_SIZE; ++i) {
      cout << numbers.at(i) << " ";
   }
   cout << endl;
   
   
   return 0;
}
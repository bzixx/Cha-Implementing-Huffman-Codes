#pragma once

#include <iostream>
using namespace std;

class MaxIntHeap {
	//Fields
private:
	int mainArray[1000];  //In an actual professinal implementation, we would make this expandable. 
	//int size is located at mainArray[0]

	//HELPER METHODS:
	void reheapifyUp(int targetIndex) {
		//RECURSIVE. 

		//BASE CASES:

			//targetIndex <= 1,
			//val[targetIndex] <= val[parentIndex]

		//RECURSIVE CASES:
		if (targetIndex > 1 && mainArray[targetIndex] > mainArray[targetIndex / 2]) {
			//Swap and recursie up. 
			int tmp{ mainArray[targetIndex] };
			mainArray[targetIndex] = mainArray[targetIndex / 2];
			mainArray[targetIndex / 2] = tmp;
			reheapifyUp(targetIndex / 2);
		}
	}

	void reheapifyDown(int targetIndex) {
		//Look for which for the elements is the biggest, and assign root.
		//If Root is not biggest, swap with child. 
		if (mainArray[1] <= mainArray[2 * 1] || mainArray[1] <= mainArray[(2 * 1) + 1]) {
			if (mainArray[1] <= mainArray[2 * 1]) {
				mainArray[2 * 1] = mainArray[1];
				reheapifyDown(newTarget);
			}

			if (mainArray[1] <= mainArray[(2*1)+1]) {
				mainArray[(2 * 1) + 1] = mainArray[1];
				reheapifyDown(newTarget);

			}
		}
	}


public:
	MaxIntHeap() {
		mainArray[0] = 0;  //Inialize size field. 

	}
	//METHODS

	void printArray() {

		for (int i = 1; i < mainArray[0]+1; i++) {
			cout << mainArray[i] << " ";
		}
		cout << endl << endl;
	}

	bool isEmpty() {
		return mainArray[0] == 0;
	}

	int Peek() {  //Peek Max
		return mainArray[1];  //Note - this will fail if the size is 0;
	}

	void insert(int keyToInsert) {  //In pricipal this is key value pair but we only interact with the key. 
		//Fully fetured heap is operating on pairs. We you have a value and pririty.  Ours shows just priority. The Data filed would need to be added. 

		//0. increase Size.
		mainArray[0]++;

		//1.  Find the right index to maintain the shape constraint. 
		mainArray[mainArray[0]] = keyToInsert;

		//2. ReHeapify Up!  To maintain the ordering constraint. 
		//Are we bigger than aprent, or already at the root?
		reheapifyUp(mainArray[0]);

	}

	int removeMax() {
		//Remove and return the Maximum element. 


		//1. get the max element from index 1, 
		int intToReturn = mainArray[1];

		//2. Maintain the shape constraint (take the element from the very last index and put it at index 1.
		mainArray[1] = mainArray[mainArray[0]];

		//0. reduce size. 
		mainArray[0]--;

		//3. Rehepify Down from the root to maintain the ordering constraint.  Recursively like rehepaify up but in resver. 


		return intToReturn;
	}




};
#pragma once

template<class T>
class ArrayList {
public:

	ArrayList()
	{
		size =10, currentIndx =0;
		arr = new T[size];
	}

	~ArrayList()
	{
		delete[] arr;
		arr = NULL;
	}

	int getSize() {
		return currentIndx;
	}

	int indexOf(T& element) {
		for (int i = 0; i < currentIndx; i++) {
			if (arr[i] == element)
			{
				return i;
			}
		}
		return -1;
	}

	void addElement(T element) {
		if (currentIndx >= size) {
			expand();
		}
		else
		{
			arr[currentIndx] = element;
			currentIndx++;
		}
	}

	bool addElement(int index, T element) {
		if (index >= 0 && index <= currentIndx) {
			if (currentIndx >= size) {
				expand();
			}
			for (int i = currentIndx - 1; i >= 0; i--) {
				if (i < index) {
					break;
				}
				arr[i + 1] = arr[i];
			}
			arr[index] = element;
			currentIndx++;
			return true;
		}
		return false;
	}

	bool removeElement(int index) {
		if (index >= 0 && index <= currentIndx) {
			for (int i = index; i < currentIndx; i++) {
			
				arr[i] = arr[i+1];
			}
			currentIndx--;
			return true;
		}
		return false;
	}

	bool isExist(T element) {
		
		return indexOf(element) > 0 ? true : false;
	}


	bool isEmpty() {
		return currentIndx == 0 ? true : false;
	}

	
	T& operator[](int index)
	{
		return arr[index];
	}
	

private:

	T* arr;
	int size, currentIndx;


	void expand() {
		size *= 2;
		T* newArr = new T[size];
		for (int i = 0; i < currentIndx; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
	}

};	







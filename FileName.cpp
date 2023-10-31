#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

const int arraySize = 25;

int RandomNumberGeneration(int min, int max) {
    return min + (rand() % (max - min + 1));
}

void GenerateArray(int array[], int min, int max, int index = 0) {
    if (index < arraySize) {
        array[index] = RandomNumberGeneration(min, max);
        GenerateArray(array, min, max, index + 1);
    }
}

int CountCorrectElements(int array[], int index = 0) {
    if (index == arraySize) {
        return 0;
    }

    int count = CountCorrectElements(array, index + 1);

    if (array[index] > 0 || index % 2 == 0) {
        count++;
    }

    return count;
}

int SumCorrectElements(int array[], int index = 0) {
    if (index == arraySize) {
        return 0;
    }

    int sum = SumCorrectElements(array, index + 1);

    if (array[index] > 0 || index % 2 == 0) {
        sum += array[index];
    }

    return sum;
}

void ReplaceWithZeros(int array[], int index = 0) {
    if (index < arraySize) {
        if (array[index] > 0 && index % 2 == 0) {
            array[index] = 0;
        }
        ReplaceWithZeros(array, index + 1);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int Array[arraySize];
    GenerateArray(Array, -20, 30);

    for (int i = 0; i < arraySize; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;

    int count = CountCorrectElements(Array);
    int sum = SumCorrectElements(Array);

    cout << "Count of correct elements: " << count << endl;
    cout << "Sum of correct elements: " << sum << endl;

    ReplaceWithZeros(Array);

    for (int i = 0; i < arraySize; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int binarySearch(const vector<int> &arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> numbers;
    int num;

    cout << "Ingrese los numeros (Ingrese '0' para terminar): " << endl;
    while (true) {
        cin >> num;
        if (num == 0)
            break;
        numbers.push_back(num);
    }

    vector<int> insertionSorted = numbers;
    insertionSort(insertionSorted);

    cout << "Ordenado por insercion: ";
    for (size_t i = 0; i < insertionSorted.size(); i++) {
        cout << insertionSorted[i] << " ";
    }
    cout << endl;

    vector<int> bubbleSorted = numbers;
    bubbleSort(bubbleSorted);

    cout << "Ordenado por metodo burbuja: ";
    for (size_t i = 0; i < bubbleSorted.size(); i++) {
        cout << bubbleSorted[i] << " ";
    }
    cout << endl;

    sort(numbers.begin(), numbers.end());
    int target;
    cout << "Ingrese el numero que desea buscar: ";
    cin >> target;
int binaryResult = binarySearch(numbers, target);
if (binaryResult != -1)
    cout << "El numero " << target << " esta en la posicion " << binaryResult + 1 << " en la lista ordenada." << endl;
else
    cout << "El numero " << target << " no se encontro en la lista ordenada." << endl;

    return 0;
}

    #include <iostream>
    #include <Windows.h>
    #include <random>
    using namespace std;

    int main() {
        SetConsoleOutputCP(CP_UTF8);
        random_device rd;
        mt19937_64 rng(rd());
        uniform_int_distribution<int> distrib(1, 30);

        int* arr = new int[5];
        cout << "Початковий масив: ";
        for (int i = 0; i < 5; i++) {
            arr[i] = distrib(rng);
            cout << arr[i] << " ";
        }
        cout << endl;
        int maxLength = 1, Length = 1;
        int startMax = 0, start = 0;
        for (int i = 1; i < 5; ++i) {
            if (arr[i] > arr[i - 1]) {
                ++Length;
                if (Length > maxLength) {
                    maxLength = Length;
                    startMax = start;
                }
            } else {
                Length = 1;
                start = i;
            }
        }
        cout << "Найбільший зростаючий підмасив: ";
        for (int i = startMax; i < startMax + maxLength; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        return 0;
    }

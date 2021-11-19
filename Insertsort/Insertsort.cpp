#include <iostream>
#include <cstdlib>
#include <chrono>
#include <math.h> 

using namespace std;
using namespace std::chrono;


int main() {
    setlocale(LC_ALL, "rus");
    int arr[100];
    cout << "Inser sort" << endl;
    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 199 - 99;
    }
    cout << "Неотсортированный массив: " << endl;
    for (int i = 0; i < 100; i++) {
        cout << arr[i] << " ";
    }
    int l = 0, r = 100;
    for (int i = l + 1; i < r; i++) {
        int j = i;
        while (j > l && arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
    cout << endl << "Отсортированный массив: " << endl;
    for (int i = 0; i < 100; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int max, min, med, x; {
        auto start = chrono::high_resolution_clock::now();
        max = min = arr[0];
        for (int i = 1; i < 100; i++)
        {
            if (max < arr[i]) max = arr[i];
            if (min > arr[i]) min = arr[i];
        }
        cout << "max = " << max << endl;
        cout << "min = " << min << endl;
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float> duration = end - start;
        cout << "Время поиска Min и Max = " << duration.count() * 1000 << "ms." << endl;
    }
    x = (max + min) / 2;
    floor(x);
    med = x;
    int key;
    key = med;
    bool flag = false;
    int lef = 0;
    int rig = 99;
    int mid;

    while ((lef <= rig) && (flag != true)) {
        mid = (lef + rig) / 2;
        if (arr[mid] == key)
            flag = true;
        if (arr[mid] > key)
            rig = mid - 1;
        else
            lef = mid + 1;
    }

    if (flag)
        cout << "Индекс элемента " << key << " в массиве равен: " << mid << endl;
    else
        cout << "Нет такого числа";

    int cou = 0, a;
    cin >> a;
    for (int i = 0; i < 100; i++)
        if (arr[i] < a)
            cou += 1;
    cout << "Количество элементов меньше числа a " << cou << endl;

    int coutn = 0, b;
    cin >> b;
    for (int i = 0; i < 100; i++)
        if (arr[i] > b)
            coutn += 1;
    cout << "Количество элементов больше числа b " << coutn << endl;

    int el1, el2; {
        cout << "Введите индекс элемента массива 1 ";
        cin >> el1;
        cout << endl << "Введите индекс элемента массива 2 ";
        cin >> el2;
        {
            auto start = chrono::high_resolution_clock::now();
            swap(arr[el1], arr[el2]);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<float> duration = end - start;
            cout << "Время обмена = " << duration.count() * 1000 << "ms." << endl;
        }
        cout << endl << arr[el1] << " " << arr[el2] << endl;
    }
    return 0;
}
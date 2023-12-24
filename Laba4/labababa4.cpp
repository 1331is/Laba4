#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <vector>
#include <ctype.h>
#include <stdio.h>

#include <stdlib.h>
// Комментарий для рецензиторов, rbhbkk люблю тебя, функции не хочу использовать, мне лень

int searchSubstring(char text[], char pattern[], int len, int lentask) {
    int n = len; // длина текста
    int m = lentask; // длина подстроки

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == m) // если все символы совпали
            return i; // вернуть индекс начала подстроки
    }

    return -1; // подстрока не найдена
}

int main()
{   
    setlocale(0, "");
    int choose;
    const int size = 200;    // максимальное количиство считываемых символов
    char a[size]{};
    char x[size] = {};
    std::vector<std::string> vect2;
    char vect1[size]{};
    char vect3[size]{};
    int helper;
    int char_size = 0;
    
    while (true) {
        std::cin >> choose;
        if (choose == 1) {
            std::cin >> helper;
            if (helper == 1) {
                std::cin.getline(a, size);
                std::cin.getline(a, size);
                std::cout << "You entered:\n";
                for (int i = 0; a[i] != '\0'; i++) {
                    std::cout << a[i];
                    char_size++;
                }
                std::cout << char_size;
            }
            if (helper == 2) {
                std::ifstream in("text.txt");
                if (in.is_open())
                {
                    std::string b;
                    while (in >> b)
                    {
                        std::cout << "'"<<  b << "'" << std::endl;
                        vect2.push_back(b);
                    }
                }
                in.close();
            }
            for (int i = 0; i < vect2.size(); i++) {
                int l = -1;
                l++;
                for (int j = 0; vect2[i][j] != '\0'; j++) {
                    vect1[l] = vect2[i][j];
                }
            }
            int char_size2 = vect2.size();
        }
        if (choose == 2 and vect2.empty()) {
            bool regiter = true;
            int k = 0;
            for (int i = 0; a[i] != '\0'; i++) {
                if (isspace(a[i]) && isspace(a[i + 1])) {
                    k++;
                    char_size--;
                }
                else {
                    x[i-k] = a[i];
                }
            }
            k = 0;
            for (int i = 0; x[i] != '\0'; i++) {
                if (ispunct(x[i]) && ispunct(x[i+1])) {
                    k++;
                    char_size--;
                }
                else {
                    a[i - k] = x[i];
                }
            }
            for (int i = 0; a[i] != '\0'; i++) {
                if (a[i] == '.') {
                    regiter = true;
                }
                if (isalpha(a[i]) && !regiter) {
                    a[i] = (char) tolower(a[i]);
                }
                if (isalpha(a[i]) && regiter) {
                    a[i] = (char)toupper(a[i]);
                    regiter = false;
                }
            }
            for (int i = 0; i < char_size; i++) {
                std::cout << a[i];
            }
            
            
        }
        if (choose == 2 and !vect2.empty()) {
            bool regiter = true;
            int k = 0;
            for (int i = 0; vect1[i] != '\0'; i++) {
                if (isspace(vect1[i]) && isspace(vect1[i + 1])) {
                    k++;
                    char_size--;
                }
                else {
                    vect3[i - k] = vect1[i];
                }
            }
            k = 0;
            for (int i = 0; vect3[i] != '\0'; i++) {
                if (ispunct(vect3[i]) && ispunct(vect3[i + 1])) {
                    k++;
                    char_size--;
                }
                else {
                    vect1[i - k] = vect3[i];
                }
            }
            for (int i = 0; vect1[i] != '\0'; i++) {
                if (vect1[i] == '.') {
                    regiter = true;
                }
                if (isalpha(vect1[i]) && !regiter) {
                    vect1[i] = (char)tolower(vect1[i]);
                }
                if (isalpha(vect1[i]) && regiter) {
                    vect1[i] = (char)toupper(a[i]);
                    regiter = false;
                }
            }
            for (int i = 0; i < vect2.size(); i++) {
                std::cout << vect1[i];
            }


        }
        if (choose == 3 and vect2.empty()) {
            for (int i = char_size-1; i > -1; i--) {
                std::cout << a[i];
            }
        }
        if (choose == 3 and !vect2.empty()) {
            for (int i = vect2.size() - 1; i > -1; i--) {
                std::cout << a[i];
            }
        }
        if (choose == 4 and vect2.empty()) {
            int count = 0;
            int countmax = 0;
            bool probel = false;
            for (int i = 0; i < char_size; i++) {
                if (isdigit(a[i])) {
                    count++;
                }
                if (isspace(a[i])) {
                    countmax < count ? countmax = count : 1;
                    count = 0;
                }
            }
            for (int i = 0; i < countmax; i++) {
                for (int i = 0; i < char_size - 1; i++) {
                    if (isdigit(a[i]) and i == char_size - 1) {
                        break;
                    }
                    if (isdigit(a[i]) and !isspace(a[i + 1]) || a[i + 1] == NULL) {
                        std::swap(a[i], a[i + 1]);
                    }
                }
            }
            for (int i = 0; i < char_size; i++) {
                std::cout << a[i];
            }
        }
        if (choose == 4 and !vect2.empty()) {
            int count = 0;
            int countmax = 0;
            bool probel = false;
            for (int i = 0; i < vect2.size(); i++) {
                if (isdigit(vect1[i])) {
                    count++;
                }
                if (isspace(vect1[i])) {
                    countmax < count ? countmax = count : 1;
                    count = 0;
                }
            }
            for (int i = 0; i < countmax; i++) {
                for (int i = 0; i < vect2.size() - 1; i++) {
                    if (isdigit(vect1[i]) and i == char_size - 1) {
                        break;
                    }
                    if (isdigit(vect1[i]) and !isspace(vect1[i + 1]) || vect1[i + 1] == NULL) {
                        std::swap(vect1[i], vect1[i + 1]);
                    }
                }
            }
            for (int i = 0; i < vect2.size(); i++) {
                std::cout << vect1[i];
            }
        }
        if (choose == 5 and vect2.empty()) {
            char asd[size]{};
            int pod_str_len = 0;
            for (int i = 0; asd[i] != '\0'; i++) {
                pod_str_len++;
            }
            std::cin.getline(asd, size);
            std::cin.getline(asd, size);
            searchSubstring(a, asd, char_size, pod_str_len);
        }
        if (choose == 5 and !vect2.empty()) {
            if (choose == 5 and vect2.empty()) {
                char asd[size]{};
                int pod_str_len = 0;
                for (int i = 0; asd[i] != '\0'; i++) {
                    pod_str_len++;
                }
                std::cin.getline(asd, size);
                std::cin.getline(asd, size);
                searchSubstring(vect1, asd, vect2.size(), pod_str_len);
            }
        }
    }
}

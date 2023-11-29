#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "SortClass.h"
#include <math.h>
#include <exception>

using namespace std;


SortClass::SortClass(int n, bool genRandom) {
    swapCount = 0;
    if (genRandom) {
        for (int i = 0; i < n; i++)
            array.push_back((rand() % 1000) * 1.0);
    } else {
        for (int i = 0; i < n; i++)
            array.push_back(0.0);
    }
}

SortClass::SortClass(const SortClass &st) {
    swapCount = st.swapCount;
    for (int i = 0; i < st.array.size(); i++)
        array.push_back(st.array[i]);

}


int SortClass::count() {
    return array.size();
}

int SortClass::getSwapCount() {
    return swapCount;
}

void SortClass::clear(bool genRandom) {
    swapCount = 0;
    if (genRandom) {
        //srand(time(0));
        for (int i = 0; i < array.size(); i++)
            array[i] = (rand() % 1000) * 1.0;
    } else {
        for (int i = 0; i < array.size(); i++)
            array[i] = 0.0;
    }
}

bool SortClass::lessthan(int i, int j) {
    return (array[i] < array[j]);
}

void SortClass::swap(int i, int j) {
    float temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    swapCount++;
}

ostream &operator<<(ostream &os, SortClass &s) {
    for (int i = 0; i < s.array.size(); i++) {
        if (!(i % 10))
            os << endl;
        os << s.array[i] << " ";
    }
    return os;
}

istream &operator>>(istream &is, SortClass &s) {
    for (int i = 0; i < s.array.size(); i++) {
        is >> s.array[i];
    }
    return is;
}

/*
For k = 1 to p
    h = list[k]
    for (int j = n; j >= h; j--){
        i = j
        while (i >= h) and (A[i-h] > A[i])
            swap (A[i], A[i-h])
            i = i -h
 */

void ShellSort(SortClass &s, int code) {
    if (code == 0) {
        for (int j = 1; j < s.count(); j++) {
            int i = j;
            while ((i >= 0) && (s.lessthan(i, i - 1))) {
                s.swap(i - 1, i);
                i--;
            }
        }
    } else if (code == 1) {
        int ik = sqrt(s.count());
        vector<int> hlist;
        for (int i = ik; i > 0; i--) {
            hlist.push_back(i * i);
        }
        for (int x = 0; x < hlist.size(); x++) {
            int h = hlist[x];
            for (int j = s.count() - 1; j >= h; j--) {
                int i = j;
                while ((i >= h) && (s.lessthan(i, i - h))) {
                    s.swap(i, i - h);
                    i = i - h;
                }
            }
        }
        for (int j = 1; j < s.count(); j++) {
            int i = j;
            while ((i >= 0) && (s.lessthan(i, i - 1))) {
                s.swap(i - 1, i);
                i--;
            }
        }
    } else if (code == 2) {
        int ik = s.count() + 1;
        ik = log2(ik);
        vector<int> hlist;
        for (int i = ik; i > 0; i--) {
            hlist.push_back(pow(2, i) - 1);
        }
        for (int x = 0; x < hlist.size(); x++) {
            int h = hlist[x];
            for (int j = s.count() - 1; j >= h; j--) {
                int i = j;
                while ((i >= h) && (s.lessthan(i, i - h))) {
                    s.swap(i, i - h);
                    i = i - h;
                }
            }
        }
        for (int j = 1; j < s.count(); j++) {
            int i = j;
            while ((i >= 0) && (s.lessthan(i, i - 1))) {
                s.swap(i - 1, i);
                i--;
            }
        }
    } else if (code == 3) {
        int ik = s.count() * 2;
        ik = ik + 1;
        ik = log2(ik) / log2(3);
        vector<int> hlist;
        for (int i = ik; i > 0; i--) {
            hlist.push_back((pow(3, i) - 1) / 2);
        }
        for (int x = 0; x < hlist.size(); x++) {
            int h = hlist[x];
            for (int j = s.count() - 1; j >= h; j--) {
                int i = j;
                while ((i >= h) && (s.lessthan(i, i - h))) {
                    s.swap(i, i - h);
                    i = i - h;
                }
            }
        }
        for (int j = 1; j < s.count(); j++) {
            int i = j;
            while ((i >= 0) && (s.lessthan(i, i - 1))) {
                s.swap(i - 1, i);
                i--;
            }
        }
    }
    else{
        cerr << "please input a correct code";
        throw  exception();
    }
}
#include <iostream>
#include <vector>
#include <list>


class Bubble_Sort{
public:
    void sort(std::vector<int> &my_vec) {
        for (int i = 0; i < my_vec.size(); ++i) {
            bool is_sorted = true;
            for (int j = 0; j < my_vec.size() - 1; ++j) {
                if (my_vec[j] > my_vec[j + 1]) {
                    int temp = my_vec[j];
                    my_vec[j] = my_vec[j + 1];
                    my_vec[j + 1] = temp;
                    is_sorted = false;
                }
                if (is_sorted) {
                    return;
                }
            }
        }
    }
private:
    void swap_values(std::vector<int> &my_vec, int index_1, int index_2) {
        int temp = my_vec[index_1];
        my_vec[index_1] = my_vec[index_2];
        my_vec[index_2] = temp;
    }
};


class SelectionSort {
public:
    void sort(std::vector<int> &my_vec) {
        for (int i = 0; i < my_vec.size(); ++i) {
            int minimum_index = i;
            for (int j = i; j < my_vec.size(); ++j) {
                if (my_vec[j] < my_vec[minimum_index]) {
                    minimum_index = j;
                }
            }
            swap_values(my_vec, minimum_index, i);
        }
    }
private:
    void swap_values(std::vector<int> &my_vec, int index1, int index2) {
        int temp = my_vec[index1];
        my_vec[index1] = my_vec[index2];
        my_vec[index2] = temp;
    }
};

class InsertionSort {
public:
    void sort(std::vector<int> &vec) {
        for (int i = 1; i < vec.size(); ++i) {
            int current = vec[i];
            int j = i - 1;
            while (j >= 0 && vec[j] > current) {
                vec[j + 1] = vec[j];
                --j;
            }
            vec[j + 1] = current;
        }
    }
};


class mergeSort {
public:
    void sort(std::vector<int> &array) {
        if (array.size() < 2) {
            return;
        }
        int middle = array.size() / 2;
        std::vector<int> left (middle, 0);
        for (int i = 0; i < middle; ++i) {
            left[i] = array[i];
        }

        std::vector<int> right(array.size() - middle, 0);
        for (int i = middle; i < array.size(); i++) {
            right[i - middle] = array[i];
        }

        sort(left);
        sort(right);

        merge(left, right, array);
    }

private:
    void merge(std::vector<int> &left, std::vector<int> &right, std::vector<int> &result) {
        int i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                result[k++] = left[i++];
            }
            else {
                result[k++] = right[j++];
            }
        }
        while (i < left.size()) {
            result[k++] = left[i++];
        }

        while (j < right.size()) {
            result[k++] = right[j++];
        }

    }
};

class QuickSort {
private:
    void swap(std::vector<int> &array, int index1, int index2) {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }
    int partition(std::vector<int> &array, int start, int end) {
        int boundary = start - 1;
        int pivot = array[end];

        for (int i = start; i <= end; ++i) {
            if (array[i] <= pivot) {
                boundary++;
                swap(array, i, boundary);
            }
        }
        return boundary;
    }
public:
    void sort(std::vector<int> &array, int start, int end) {
        if (start >= end) {
            return;
        }
        int boundary = partition(array, start, end);
        // sort left
        sort(array, start, boundary - 1 );
        // sort right
        sort(array, boundary + 1, end);
        // partition
    }

};

class CountingSort {
public:
    void sort(std::vector<int> array, int max) {
        std::vector<int> counts(max + 1, 0);
        for (auto &value : array) {
            counts[value]++;
        }
        int k = 0;
       for (int i = 0; i < counts.size(); ++i) {
          for (int j = 0; j < counts[i]; ++j)
              array[k++] = i;
       }
    }

};

class BucketSort {
public:
    void sort(std::vector<int> array, int no_of_buckets) {
        //std::list<int> x;
        std::list<std::list<int>> buckets(no_of_buckets);
        for (auto &value : array) {

        }

    }
};

class SearchAlgorithms {
public:
    int LinearSearch(std::vector<int> array, int target) {
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] == target)
                return i;
        }
        return -1;
    }

    int BinarySearchRec(std::vector<int> &array, int target) {
        return BinarySearchRec(array, target, 0, array.size() - 1);
    }

    int BinarySearch(std::vector<int> &array, int target) {
        int left = 0;
        int right = array.size();

        while (left <= right) {
            int middle = (left + right) / 2;

            if (array[middle] == target) {
                return middle;
            }

            if (array[middle] > target) {
                right = middle - 1;
            }
            else if(array[middle] < target) {
                left = middle + 1;
            }
        }
        return -1;
    }

    int TernarySearch(std::vector<int> &array, int target) {
        return TernarySearch(array, target, 0, array.size() - 1);
    }


    int ExponentialSearch(std::vector<int> array, int target, int bound) {
        if (array[bound] == target) {
            return bound;
        }
        if (array[bound] < target) {
            ExponentialSearch(array, target, bound*2);
        }
        if (array[bound] > target) {
            return BinarySearchRec(array, target, 0, bound);
        }
        return -1;
    }
private:
   int BinarySearchRec(std::vector<int> &array, int target, int left, int right) {
        if (right < left) {
            return -1;
        }
        int middle = (left + right) / 2;
        if (array[middle] == target) {
            return middle;
        }
        if (target > array[middle]) {
            return BinarySearchRec(array, target, left, middle - 1);
        }
        return BinarySearchRec(array, target, middle + 1, right);
    }

    int TernarySearch(std::vector<int> &array, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        int partition_size = (right - left) / 3;
        int mid1 = left + partition_size;
        int mid2 = right - partition_size;

        if (array[mid1] == target) {
            return mid1;
        }
        if (array[mid2] == target) {
            return mid2;
        }
        if (array[mid1] > target) {
            return TernarySearch(array, target, left, mid1 - 1);
        }
        if (array[mid2] < target) {
            return TernarySearch(array, target, mid2 + 1, right);
        }
        return TernarySearch(array, target, mid1 + 1, mid2 - 1);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;


    return 0;
}

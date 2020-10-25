class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> recond;
        for (int i = 0; i < arr2.size(); ++i) recond[arr2[i]] = i;
        quickSort(recond, arr1, 0, arr1.size() - 1);
        return arr1;
    }

    void quickSort(unordered_map<int, int> &recond, vector<int>& a, int begin, int end) {
        if (end <= begin) return;
        int pivot = partition(recond, a, begin, end);
        quickSort(recond, a, begin, pivot - 1);
        quickSort(recond, a, pivot + 1, end);
    }

    int partition(unordered_map<int, int> &recond, vector<int>& a, int begin, int end) {
        int pivot = end, count = begin;
        for (int i = begin; i < end; i++) {
            if (less(recond, a[i], a[pivot])) swap(a, count++, i); 
        }
        swap(a, pivot, count);
        return count;
    }

    void swap(vector<int>& a, int i, int j) {
        int temp = a[i]; a[i] = a[j]; a[j] = temp; 
    }

    bool less(unordered_map<int, int> &recond, int num1, int num2) {
        if (recond.find(num1) != recond.end() && recond.find(num2) != recond.end()) return recond.at(num1) < recond.at(num2);           
        else if (recond.find(num1) != recond.end()) return true;
        else if (recond.find(num2) != recond.end()) return false;
        else return num1 < num2;
    }
};
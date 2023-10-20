#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

class RandomPermutation {
public:
    RandomPermutation(int n) : n_(n) {
        sequence.resize(n);
        iota(sequence.begin(), sequence.end(), 1);
    }

    int operator()() {
        random_device rd;
        mt19937 g(rd());
        shuffle(sequence.begin(), sequence.end(), g);
        int result = 0;
        for (int i = 0; i < n_; ++i) {
            result += sequence[i] * (i + 1); // Розраховуємо скалярний добуток.
        }
        return result;
    }
private:
    int n_;
    vector<int> sequence;
};
int MaxScalarProduct(int n, int numPermutations, vector<int>& scalarProducts) {
    int maxScalarProduct = 0;
    RandomPermutation permutation(n);
    for (int i = 0; i < numPermutations; ++i) {
        int scalarProduct = permutation();
        scalarProducts.push_back(scalarProduct);
        if (scalarProduct > maxScalarProduct) {
            maxScalarProduct = scalarProduct;
        }
    }
    return maxScalarProduct;
}

double searchMedian(vector<int> x, int n)
{
    double median;
    if (n % 2 == 0)
        median = (double)(x[(n / 2) - 1] + x[n / 2]) / 2;
    else
        median = x[n / 2];
    return median;
}

// Average of the sequence
int GetAverageValue(vector<int> seq){
    int average = 0;
    int sumElements = 0;
    for(int element: seq){
        sumElements += element;
    }
    average = sumElements / seq.size();
    return average;
}

int main(){
    const string path = "/Users/mykhailolapshyn/Desktop/result.txt";
    ofstream out(path);
    srand(static_cast<unsigned int>(time(NULL)));
    int n = 5;
    int numOfPermutation = 6;
    vector<int> scalar_products;
    int max_scalar_product = MaxScalarProduct(n, numOfPermutation, scalar_products);
//    cout << "Max scalar product: " << max_scalar_product << endl;
//    cout << "Median: " << searchMedian(scalar_products, numOfPermutation) << endl;
//    cout << "Arithmetic average: " << GetAverageValue(scalar_products) << endl;
    if(out.is_open()){
        out << "Max scalar product: " << max_scalar_product << '\n';
        out << "Median: " << searchMedian(scalar_products, numOfPermutation) << '\n';
        out << "Arithmetic average: " << GetAverageValue(scalar_products) << '\n';
        out.close();
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#define EXIT_OK 0
#define EXIT_ERROR -100
using namespace std;
class RandomPermutation {
public:
    RandomPermutation(int n) : n_(n) {
        sequence.resize(n);
        iota(sequence.begin(), sequence.end(), 1);
    }
    void generateRandom() {
        random_device rd;
        mt19937 g(rd());
        std::shuffle(sequence.begin(), sequence.end(), g);  // Змішуємо вектор для генерації випадкової перестановки
    }
    int operator()() {
        generateRandom();
        int result = 0;
        for (int i = 0; i < n_; ++i) {
            result += sequence[i] * (i + 1);
        }
        return result;
    }
private:
    int n_;
    vector<int> sequence;
};

int MaxScalarProduct(int n, int numPermutations, vector<int>& scalarProducts) {
    if(n < 0){
        return EXIT_ERROR;
    }
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
    if(!out){
        cout << "Error opening file" << endl;
        return EXIT_FAILURE;
    }
    srand(static_cast<unsigned int>(time(NULL)));
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(5, 50);
    int n = dist(mt);
    int numOfPermutation = dist(mt);
    vector<int> scalar_products;
    int max_scalar_product = MaxScalarProduct(n, numOfPermutation, scalar_products);
    if(out.is_open()){
        out << "Max scalar product: " << max_scalar_product << '\n';
        out << "Median: " << searchMedian(scalar_products, numOfPermutation) << '\n';
        out << "Arithmetic average: " << GetAverageValue(scalar_products) << '\n';
        out.close();
    }
    return EXIT_OK;
}

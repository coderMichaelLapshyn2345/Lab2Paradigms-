#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

class RandomPermutation {
public:
    RandomPermutation(int n) : n_(n) {

        sequence.resize(n);

        // ���������� ������ ����������� ������� �� 1 �� n.
        iota(sequence.begin(), sequence.end(), 1);
    }

    int operator()() {

        // ��������� ����� ���������� �����. ���� ������� � main()
        random_shuffle(sequence.begin(), sequence.end());


        //��������
        /*for(int num: sequence)
        {
            cout << num << " ";
        }
        cout << endl;
        */


        int result = 0;
        for (int i = 0; i < n_; ++i) {
            result += sequence[i] * (i + 1); // ����������� ��������� �������.
        }

        return result;
    }

    /*
    vector<int> getSequence() {
        return sequence;
    }
    */

private:
    int n_;
    vector<int> sequence;
};

int MaxScalarProduct(int n, int numPermutations, vector<int>& scalarProducts) {
    int maxScalarProduct = 0;

    // ��������� ����������� �������� n
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

int main() {

    // �������� � ������ library<Windows.h>
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ������������ ����� ��� ������ ��������� ���������� �������������
    srand(time(NULL));

    int n = 5;                     // ����� �����������
    int numOfPermutation = 6;      // ʳ������ ���������� ������������ ��� ����������.

    vector<int> scalar_products;
    int max_scalar_product = MaxScalarProduct(n, numOfPermutation, scalar_products);

    // ��������
    /*
    cout << endl;
    for(int i: scalar_products)
        cout << i << " ";
    cout << endl;
    */

    //double average = static_cast<double>(accumulate(scalar_products.begin(), scalar_products.end(), 0)) / numOfPermutation;

    cout << "��������� ��������� �������: " << max_scalar_product << endl;
    cout << "������: " << searchMedian(scalar_products, numOfPermutation) << endl;
    //cout << "������ �����������: " << average << endl;


    return 0;
}

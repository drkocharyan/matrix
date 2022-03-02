#include <iostream>
#include <fstream>
#include "linear.cpp"
#include "operator.cpp"

#include "test_runner.h"
#include "linear_test.h"

void runTests() {
    TestRunner tr;
    tr.RunTest(TestLinearLibrary, "Usual matrix test");
    tr.RunTest(TestDiagonalMatrix, "Diagonal matrix test");
    tr.RunTest(TestUnitMatrix, "Unit matrix test");
    tr.RunTest(TestUpperTriangularMatrix, "Upper triangular matrix test");
    tr.RunTest(TestLowerTriangular, "Lower triangular matrix test");
    tr.RunTest(TestSymmetricMatrix, "Symmetric matrix test");
    tr.RunTest(TestVectors, "Vectors test");
}

int main() {
    runTests();
//     All lines below are my practical experience with the library
    Linear::Matrix<int> matrix({{6, 7, 2}, {4, 6, 8}, {90, 13, 3}});
    std::cout << matrix.Track() << '\n';
    Linear::Matrix<int> m2322({1, 2, 3, -7, 5});
    std::cout << m2322.Norm() << '\n' << m2322.Sum() << '\n';
    Linear::Matrix<int> matrixx({{1, 2, 1}, {1, 1, 1}, {1, 1, 1}});
    Linear::LowerTriangular<int> m({{1, 0, 0}, {0, 5, 0}, {0, 0, 9}, {10, 11, 12}});
    std::cout << m << '\n';
    std::cout << matrix - matrixx << '\n';
    std::cout << Linear::Matrix<int>({{1, 4}, {2, 5}, {3, 6}}).dot(Linear::Matrix<int>({{7, 8, 9}, {10, 11, 12}})) << '\n';

    std::cout << matrix * matrixx << '\n';
    Linear::Unit<double> m1(10);
    std::cout << "det: " << m1.Determinant() << '\n';

    Linear::Matrix<int> matrix2(5, 5);
    Linear::Matrix<int> matrix3(10);
    Linear::Matrix<int> matrix4;
    std::cout << matrix2.Size().first << ' ' << matrix2.Size().second << std::endl;
    matrix.Transpose();
    std::cout << matrix4 << '\n';
    std::cout << matrix4.Size().first << ' ' << matrix4.Size().second << std::endl;
    Linear::SymmetricMatrix<int> a({{1, 2, 3}, {2, 5, 6}, {3, 6, 8}});
    std::cout << a << '\n';

    std::cout << (Linear::Matrix<int>({3, 4, 0}) ^ Linear::Matrix<int>({4, 4, 2})) << '\n';

    Linear::Matrix<double> m33 = Linear::FromFile<double>("matrix.txt");

    std::ofstream file2 ("matrix-output.txt");
    file2 << m33;

    m33.toBinary("hello.bin");

    Linear::Matrix<double> m2;
    m2.fromBinary("hello.bin");

    std::cout << m2 << '\n';

    return 0;
}

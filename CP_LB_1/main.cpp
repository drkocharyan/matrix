
#include "clases.h"
#include "class.h"





int main() {

    ifstream  file_1("C:\\Users\\HUAWEI\\CLionProjects\\CP_LB_1\\loadings.txt"), file_2("C:\\Users\\HUAWEI\\CLionProjects\\CP_LB_1\\matrix_1.txt");
    //string b ;//= {'1','2','3','4','5'};
    ofstream file {"output.txt"};
    //b.push_back('a');
   // getline(file,b);
//  int a = get_size(b);
//    cout << a;
down_tr a (file_1);
a.see();
//matrix b;
//cout << a << '\n';
a.transpose();
a.put(file);
//cout << a;
//cout << b;


/*eye m (5,5);
cout<<m;*/
    /*diag m (5, 5, 5);
    cout << m;*/
/* matrix a (file_1);
 matrix b (file_2);
 matrix c;
 c = a * b;
 cout << '\n';
 c.see();
    cout << '\n';
    cout << c;*/
/*vector <double> m;
    double n;
    while(!file_1.eof()){
        file_1>>n;
        m.push_back(n);
    }
    for (auto i : m){
        cout << i << " ";
    }*/


    return 0;
}


// Created by HUAWEI on 14.12.2021.
//

#ifndef CP_LB_1_CLASES_H
#define CP_LB_1_CLASES_H
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>




using namespace std;


vector <double> chunking(string& a){// разбивает числа на строки и наполняет ими вектор
    string check;
    vector <double> res(0);
    for (int i = 0 ; i <  a.size(); ++i){

        if (a[i] != ' '){
            check.push_back(a[i]);
        }
        else if ((a[i] == ' ') || (i == a.size() - 1 )){
            res.push_back(double(check[0])-48);
            if (check.size() > 1){
                for ( int j = 1; j < check.size();++j){
                    res[res.size() - 1] = res[res.size() - 1]* 10 + double(check[j]) - 48;
                }
            }
            check.clear();
        }



    }

    return res;
}


int get_size(string& a){// счиатет сколько чисел в строке
    int n = 0;
    for(auto i : a){
        if (i == ' '){
            ++n;
        }
    }
    ++n;

    return n;
}



class matrix {
private:




public:
    int row = 0, colomn = 0;
    double e = 0.0001;
    vector <vector<double>> table;
    matrix(){

    };
    double det();
    void update();
    double norm_e();
    double norm_max();
    double angl();
    int rang();
    matrix reverse();
    int swapm (int n , int rw_0  );
    void swap(int n, int m);
    matrix transpose();
    void swap();
    void put (ofstream&  file);
    void read_b (string file);
    void write_b (string file);



    explicit matrix (ifstream& file){
        string a; //временный строка

        double number;
        getline(file,a);
        colomn = get_size(a);
        file.seekg(0, ios_base:: beg);
        //cout << colomn << '\n';
        std::string line;


        size_t columns = 0;



        std::vector<std::vector<double>> matrix;

        while (getline(file, line)) {
            size_t i = 0;
            std::vector<double> row;
            std::istringstream ss(line);
            double num;
            while (ss >> num) {
                ++i;
                row.push_back(num);
            }



            table.push_back(row);
        }


        /*while(getline(file, line)) {
            istringstream ss(line);
            vector<double> cpy;
            for (size_t i = 0; i < colomn; ++i) {
                ss >> number;
                //cout << number << ' ';
                cpy.push_back(number);
            }
            table.push_back(cpy);
        }
        row = table.size();*/
    }





/*

        table.push_back(cpy);

        ++row;
        }
        for (int i = 0; i < table.size(); ++i ){
            for (int j = 0; j < table[i].size(); ++j){
                if (table[i] [j] == - 48  ){
                    table [i][j] = 0;
                }
            }
        }

        colomn= get_size(a);
        file.close();

    };
*//*


    matrix(int n, int m, ifstream file){


        try{
            if (!file) throw (ifstream ());
        }
        catch (ifstream()){
            cout << "file didn't open";
            exit (0);
        }



        row = n;
        colomn = m;

        while (!file.eof()){
            string a;
            getline(file,a);
            table.push_back(chunking (a));

        }

        file.close();
    }
*/


    matrix (int n, int m){

        row = n;
        colomn = m;

    }

    void see (){// вывод эоементов матрицы
        for(auto i :table) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << '\n';
        }
    }



    vector <int> shape(){//возвращает размеры матрицы вектором
        vector <int> a = {row, colomn};
        return a;
    }




};

matrix operator + (matrix a,matrix b){
    if ((b.shape()[0] == a.shape()[0]) & (b.shape()[1] == a.shape()[1])) {
        int n = a.shape()[0], m = a.shape()[1];
        matrix c(n,m);
        for (int i = 0; i < n; ++i) {
            vector <double> cpy;
            for (int j = 0; j < m; ++j) {
                cpy.push_back(a.table[i][j] + b.table[i][j]);
            }
            c.table.push_back(cpy);
        }
        return c;
    }
    else{
        cout << "different sizes";
    };
}


matrix operator - (matrix a,matrix b){
    if ((b.shape()[0] == a.shape()[0]) & (b.shape()[1] == a.shape()[1])) {
        int n = a.shape()[0], m = a.shape()[1];
        matrix c(n,m);
        for (int i = 0; i < n; ++i) {
            vector <double> cpy;
            for (int j = 0; j < m; ++j) {
                cpy.push_back(a.table[i][j] - b.table[i][j]);
            }
            c.table.push_back(cpy);
        }
        return c;
    }
    else{
        cout << "different sizes";
    };
}

matrix operator * (double a, matrix b){
    int n = b.shape()[0], m = b.shape()[1];
    matrix c(n,m);
    for (int i = 0; i < n; ++i) {
        vector <double> cpy;
        for (int j = 0; j < m; ++j) {
            cpy.push_back(b.table[i][j] * a);
        }
        c.table.push_back(cpy);
    }
    return c;
}
matrix operator * (matrix a, matrix b){
    int n = a.shape()[0], m = a.shape()[1], k = b.shape()[1];
    cout<< n << ' '<< m << ' '<< k<<'\n';
    matrix c;
    double cpy = 0;
    vector<double>cpy_1 (k,0);


   for (int i = 0; i < n; ++ i){
       vector <double> cpy_2;
       for (int j = 0; j < k; ++j){
           double sum = 0;
           for (int z = 0; z < m; ++z){
            //   cout << i << " "<< j << " "<< z << " "<< a.table[i][z] << " "<<b.table[z][j]<< '\n';
               sum += a.table[i][z]*b.table[z][j];
              // cout << "a * b = " << a.table[i][z] << " * " <<b.table[z][j] << " = ";
              // cout << c.table [i][j] << ' ' << a.table[i][z]*b.table[z][j] << '\n';
           }
           cpy_2.push_back(sum);

       }
        c.table.push_back(cpy_2);
   }
    return c;

}




ostream& operator<<(ostream &out,matrix a){
    a.see();
}

/*matrix operator = (matrix a, matrix b){
    int n = a.shape()[0], m = a.shape()[1];
    matrix c(n,m);
    return c;

}*/

class eye : public matrix {
public:
    eye(int n, int m){
        row = n;
        colomn = m;
        for (int i = 0; i < n; ++i){
            vector<double>  cpy;
            for (int j = 0; j < m; ++j){
                if (i == j){
                    cpy.push_back(1);
                }
                else{
                    cpy.push_back(0);
                }
            }
            table.push_back(cpy) ;
        }

    }

};



class diag : public matrix {
public:
    diag(int n, int value){
        row = n;
        colomn = n;
        if (n)
        for (int i = 0; i < n; ++i){
            vector<double>  cpy;
            for (int j = 0; j < n; ++j){
                if (i == j){
                    cpy.push_back(value);
                }
                else{
                    cpy.push_back(0);
                }
            }
            table.push_back(cpy) ;
        }

    }

};

class up_tr : public matrix {
public:

    explicit up_tr(ifstream &file) {
        string a; //временный строка

        double number;
        getline(file, a);
        colomn = get_size(a);
        file.seekg(0, ios_base::beg);
        //cout << colomn << '\n';
        std::string line;
        while (getline(file, line)) {
            istringstream ss(line);
            vector<double> cpy;
            for (size_t i = 0; i < colomn; ++i) {
                ss >> number;
                cpy.push_back(number);
            }
            table.push_back(cpy);
        }
        row = table.size();
        bool flag = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < colomn; ++j) {
                if (i > j) {
                    if (table[i][j] != 0) {
                        flag = 1;
                    }
                    table[i][j] = 0;
                }
            }
        }
        cout << "matrix is corrected \n";
    }

};
class down_tr : public matrix {
public:

    explicit down_tr(ifstream &file) {
        string a; //временный строка

        double number;
        getline(file, a);
        colomn = get_size(a);
        file.seekg(0, ios_base::beg);
        //cout << colomn << '\n';
        std::string line;
        while (getline(file, line)) {
            istringstream ss(line);
            vector<double> cpy;
            for (size_t i = 0; i < colomn; ++i) {
                ss >> number;
                cpy.push_back(number);
            }
            table.push_back(cpy);
        }
        row = table.size();
        bool flag = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < colomn; ++j) {
                if (i < j) {
                    if (table[i][j] != 0) {
                        flag = 1;
                    }
                    table[i][j] = 0;
                }
            }
        }
        cout << "matrix is corrected "<< '\n';
    }

};






class sim : public matrix{
public:
    explicit sim(ifstream file){

    string a;

    double number;
    getline(file, a);
    colomn = get_size(a);
    file.seekg(0, ios_base::beg);
    //cout << colomn << '\n';
    std::string line;
    while (getline(file, line)) {
        istringstream ss(line);
        vector<double> cpy;
        for (size_t i = 0; i < colomn; ++i) {
            ss >> number;
            cpy.push_back(number);
        }
        table.push_back(cpy);
    }
    row = table.size();
    if (row == colomn) {
        bool flag = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < colomn; ++j) {
                if (table[i][j] != table[j][i]) {
                    flag = 1;
                    table[i][j] = table[j][i];
                }
            }
        }
    }
    else{
        cout <<" matrix is not correct: m != n";
        table.clear();
    }
    }
};






#endif //CP_LB_1_CLASES_H

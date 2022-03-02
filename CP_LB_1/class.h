

#ifndef CP_LB_1_CLASS_H
#define CP_LB_1_CLASS_H
void matrix :: update(){
    for (int i = 0; i < row; ++i ){
        for (int j = 0; j < colomn; ++j) {
            if (table[i][j] - 0 < e) {
                table[i][j] = 0;
            }
        }
    }
}

double matrix:: det(){
    double k;

    for (int i = 0; i < row; ++i){
        for(int j = i + 1; j < row; ++j){
            k = -table[j][i]/table[i][i];
            //cout << table[j][i] << " " << table[i][i] << k << '\n';
            for(int z = 0; z < colomn; ++z){
                table [j][z] += k * table[i][z];
            }
        }
    }

    double res = 0;
    for(int i = 0; i < row; ++i){
        res *= table[i][i];
    }

    return res;
}


double matrix:: norm_e(){
 double res = 1;
 for (auto i : table){
     for(auto j : i ){
         res*= j * j;
     }
 }
 res = sqrt(res);
 return res;
}
double matrix:: norm_max() {
    double res = table[0][0];
    if (colomn * row > 1) {
        cout << "this is only for vectors";
        return -1;
    } else {
        for (auto i : table) {
            for (int j = 0; j < colomn; ++j) {
                if (i[j] * i[j] > res * res) {
                    res = i[j];
                }
            }
        }
    }
    if (res != 0) {
        return res * res / res;
    } else {
    return 0;
}
}


double angl(matrix a, matrix b){
    double res = 0;
    a.update();
    b.update();
    matrix c;
    c = a*b;
    for(auto i : c.table ){
        for(auto j : i){
            res += j;
        }
    }

    res += res/(a.norm_e() + b.norm_e());
    return res;
}
int matrix:: rang (){
    double k;
    //cout << "ok";
    int res = 0;
    for (int i = 0; i < row; ++i){
        for(int j = i + 1; j < row; ++j){
            k = -table[j][i]/table[i][i];
            //cout << table[j][i] << " " << table[i][i] << k << '\n';
            for(int z = 0; z < colomn; ++z){
                table [j][z] += k * table[i][z];
            }
        }
    }
    //cout << "ok";
    bool flag = 1;
    for (int i = 0; i < colomn; ++i){
        //cout << "ok";

        for (int j = 0; j < row; ++j){
            if (table [j][i]!=0){
                flag = 0;
            }
        }
       // cout << "ok";
        if (flag){
            ++res;
        }

        flag = 1;
        //cout << "ok";
    }
    if (res != 0) {
        res = row - res;
    }
    else{
        res = row;
    }
    //cout << "ok";cout << "ok";
    // cout << res;
    return res;
}

int matrix :: swapm (int n, int rw_0){
    //cout << "ok";
    double max = table[rw_0][n];
    vector<double > cpy (colomn);
    int rw_1;

        for (int j = n ; j < row; ++j){
            if (( max < table[j][n])&&(j > rw_0)){
                max = table[j][n];
                rw_1 = j;
                cout << '\n'<<"ok";
            }
    }
        if (rw_0 != rw_1){
        for (int i = 0; i < colomn; ++i){
            cpy [i] = table[rw_1][i];
            table [rw_1][i] = table [rw_0][i];
            table[rw_0][i] = cpy[i];

        }}
        else{rw_1 = rw_0;}

        return rw_1;
}


void matrix:: swap (int n, int m){
    vector <double> cpy(colomn);
    for (int i = 0; i < colomn; ++i){
        cpy [i] = table[n][i];
        table [n][i] = table [m][i];
        table[m][i] = cpy[i];
    }
}
matrix matrix:: reverse(){
    int n;
    double k;
    eye rew(row,row);
   // cout << rew;
   // cout << "ok";
    if ((( rang() == row )||(rang()== colomn)) && (row == colomn)){
    //rew.see();

        for (int i = 0 ; i < colomn; ++i){
           // cout << "o12142\n";
            swapm (i,i);
            //cout<< rew;
            //cout << "ok";
            for (int j = 0; j < row; ++j){
                k = -table[j][i]/table[i][i];
                table[j][i] += k * table[i][i];
                rew.table[j][i] -= k * table[i][i];

            }
            //rew.see();
        }
    }
    else{
        cout << "rang is nom max" << '\n';
    }
    rew.update();
   //rew.see();
    return rew;
}
void matrix :: swap (){
    int cpy = row;
    row = colomn;
    colomn = row;

}

matrix matrix:: transpose(){
    matrix x;
    vector <vector <double>> cpy;

    for (int i = 0; i < row; ++i){
        vector <double> cpy_1;
        for (int j = 0; j < colomn; ++j){
            cpy_1.push_back(table[i][j]);
        }
        cpy.push_back(cpy_1);
    }


    for (int i = 0; i < row ; ++ i){
        vector <double> cpy_1 (colomn,0);
        x.table.push_back(cpy_1);
    }
    x.row = colomn;
    x.colomn = row;
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < colomn; ++j){
            x.table[i][j] = cpy[j][i];
        }
    }
    return x;

    //cout << row << " "<< colomn;

}

void matrix :: put (ofstream&  file){
    for (auto i : table){
        for (auto j : i){
            file << j << " ";
        }
        file << '\n';
    }
}


void matrix:: read_b (string file){
    std::ifstream r(file, std::ios::in | std::ios::binary);
    r.read((char*)&colomn, sizeof(size_t));
    r.read((char*)&row, sizeof(size_t));
    table.resize(row, std::vector<double>(colomn));
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < colomn; ++j) {
            r.read((char*)&table[i][j], sizeof(double));
        }
    }

    r.close();
}


void matrix:: write_b (string file) {
    std::ofstream w(file, std::ios::out | std::ios::binary);

    w.write((char *) &row, sizeof(size_t));
    w.write((char *) &colomn, sizeof(size_t));
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < colomn; ++j) {
            w.write((char *) &table[i][j], sizeof(double));
        }
    }
}






#endif //CP_LB_1_CLASS_H

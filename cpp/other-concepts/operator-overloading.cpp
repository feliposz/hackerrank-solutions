

class Matrix {
public:
    vector<vector<int>> a;
};

Matrix operator+(const Matrix &m1, const Matrix &m2) {
    Matrix r;
    for(int i=0;i<m1.a.size();i++) {
        vector<int> b;
        for(int j=0;j<m1.a[i].size();j++) {
            b.push_back(m1.a[i][j] + m2.a[i][j]);
        }
        r.a.push_back(b);
    }
    return r;    
}



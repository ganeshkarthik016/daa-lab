#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B, int n) {
    vector<vector<int>> C(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}
vector<vector<int>> subtract(vector<vector<int>> A, vector<vector<int>> B, int n) {
    vector<vector<int>> C(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}
vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B, int n) {
    vector<vector<int>> C(n, vector<int>(n));
    if(n==1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int k = n/2;

    vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k)),
                        A21(k, vector<int>(k)), A22(k, vector<int>(k));
    vector<vector<int>> B11(k, vector<int>(k)), B12(k, vector<int>(k)),
                        B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+k];
            A21[i][j] = A[i+k][j];
            A22[i][j] = A[i+k][j+k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+k];
            B21[i][j] = B[i+k][j];
            B22[i][j] = B[i+k][j+k];
        }

    auto M1 = strassen(add(A11,A22,k), add(B11,B22,k), k);
    auto M2 = strassen(add(A21,A22,k), B11, k);
    auto M3 = strassen(A11, subtract(B12,B22,k), k);
    auto M4 = strassen(A22, subtract(B21,B11,k), k);
    auto M5 = strassen(add(A11,A12,k), B22, k);
    auto M6 = strassen(subtract(A21,A11,k), add(B11,B12,k), k);
    auto M7 = strassen(subtract(A12,A22,k), add(B21,B22,k), k);

    auto C11 = add(subtract(add(M1,M4,k),M5,k),M7,k);
    auto C12 = add(M3,M5,k);
    auto C21 = add(M2,M4,k);
    auto C22 = add(subtract(add(M1,M3,k),M2,k),M6,k);

    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++) {
            C[i][j] = C11[i][j];
            C[i][j+k] = C12[i][j];
            C[i+k][j] = C21[i][j];
            C[i+k][j+k] = C22[i][j];
        }

    return C;
}
vector<vector<int>> addMatrices(vector<vector<int>>& A, vector<vector<int>>& B, int size) {
    vector<vector<int>> C(size, vector<int>(size));
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

vector<vector<int>> multiplyRecursive(vector<vector<int>>& A, vector<vector<int>>& B, int size) {
    if(size == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = size / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));
    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));
    for(int i=0;i<newSize;i++){
        for(int j=0;j<newSize;j++){
            A11[i][j]=A[i][j]; A12[i][j]=A[i][j+newSize];
            A21[i][j]=A[i+newSize][j]; A22[i][j]=A[i+newSize][j+newSize];
            B11[i][j]=B[i][j]; B12[i][j]=B[i][j+newSize];
            B21[i][j]=B[i+newSize][j]; B22[i][j]=B[i+newSize][j+newSize];
        }
    }

    auto M1 = multiplyRecursive(A11, B11, newSize);
    auto M2 = multiplyRecursive(A12, B21, newSize);
    auto M3 = multiplyRecursive(A11, B12, newSize);
    auto M4 = multiplyRecursive(A12, B22, newSize);
    auto M5 = multiplyRecursive(A21, B11, newSize);
    auto M6 = multiplyRecursive(A22, B21, newSize);
    auto M7 = multiplyRecursive(A21, B12, newSize);
    auto M8 = multiplyRecursive(A22, B22, newSize);
    vector<vector<int>> C11 = addMatrices(M1, M2, newSize);
    vector<vector<int>> C12 = addMatrices(M3, M4, newSize);
    vector<vector<int>> C21 = addMatrices(M5, M6, newSize);
    vector<vector<int>> C22 = addMatrices(M7, M8, newSize);
    vector<vector<int>> C(size, vector<int>(size));
    for(int i=0;i<newSize;i++){
        for(int j=0;j<newSize;j++){
            C[i][j] = C11[i][j];
            C[i][j+newSize] = C12[i][j];
            C[i+newSize][j] = C21[i][j];
            C[i+newSize][j+newSize] = C22[i][j];
        }
    }

    return C;
}
int main() {

    int n = 16;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            A[i][j] = rand()%10;
            B[i][j] = rand()%10;
        }
    }
    cout<<"A: "<<endl;
     for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<"B: "<<endl;
     for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout<<B[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    auto D= multiplyRecursive(A,B,n);
    auto C = strassen(A,B,n);
    cout<<"Result Matrix by normal multiply:\n";
     for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout<<D[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<"Result Matrix by Strassen:\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
    }
}
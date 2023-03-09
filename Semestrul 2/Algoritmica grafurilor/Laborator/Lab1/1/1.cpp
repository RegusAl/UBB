//#include <iostream>
//#include <fstream>
//
//using  namespace std;
//
//ifstream fin("/home/albert/Documents/UBB/Semestrul 2/Algoritmica grafurilor/Laborator/Lab1/1/fisier.in");
//
//int main() {
//
//    int n; // numarul de noduri
//    fin >> n;
//    int mat[10][10] = {0};
//    int i, j;
//    cout<<"Lista de muchii: "<<endl;
//    cout<<n<<endl;
//    while(fin>>i>>j) {
//        cout << i << " " << j << endl;
//        mat[i][j] = 1;
//        mat[j][i] = 1;
//    }
//
//    cout<<"Matricea de adiacenta: "<<endl;
//    for(int i = 1; i<=n; i++) {
//        for (int j = 1; j<=n; j++) {
//            cout<<mat[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
//
//    fin.close();
//
//    return 0;
//}
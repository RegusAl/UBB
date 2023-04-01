#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream f("labirint_1.txt");
ofstream g("labirint1_rezolvat.txt");

int a[1000][1000];
int n,m,xs,ys,xf,yf;
char s[1000];

void bordare() {
    for(int i=0;i<=n+1;i++)
        a[i][0]=a[i][m+1]=-1;
    for(int i=0;i<=m+1;i++)
        a[0][i]=a[n+1][i]=-1;
}

void lee(int x,int y) {
    if(x==xf&&y==yf) {
        return;
    }
    if(a[x+1][y]==0 || a[x][y]+1 < a[x+1][y]) {
        a[x+1][y] = a[x][y] + 1;
        lee(x+1,y);
    }
    if(a[x-1][y]==0||a[x][y]+1<a[x-1][y]) {
        a[x-1][y]=a[x][y]+1;
        lee(x-1,y);
    }
    if(a[x][y+1]==0||a[x][y]+1<a[x][y+1]) {
        a[x][y+1]=a[x][y]+1;
        lee(x,y+1);
    }
    if(a[x][y-1]==0||a[x][y]+1<a[x][y-1]) {
        a[x][y-1]=a[x][y]+1;
        lee(x,y-1);
    }
}

int main() {
    while(f.getline(s,1005)) {
        n++;
        m=strlen(s);
        for(int i=0;i<strlen(s);i++) {
            if(s[i]=='1')
                a[n][i+1]=-1;
            else if(s[i]==' ')
                a[n][i+1]=0;
            else if(s[i]=='S') {
                a[n][i+1]=1;
                xs=n;
                ys=i+1;
            }
            else {
                xf=n;
                yf=i+1;
            }
        }
    }

    bordare();
    lee(xs,ys);
    cout<<"Lungimea drumului: "<<a[xf][yf]<<'\n';
    int x,y;
    x=xf;
    y=yf;
    while(x!=xs||y!=ys) {
        if(a[x-1][y]+1==a[x][y]) {
            a[x][y]=-2;
            x=x-1;
        }
        else if(a[x+1][y]+1==a[x][y]) {
            a[x][y]=-2;
            x++;
        }
        else if(a[x][y-1]+1==a[x][y]) {
            a[x][y]=-2;
            y--;
        }
        else if(a[x][y+1]+1==a[x][y]) {
            a[x][y]=-2;
            y++;
        }
    }
    a[xf][yf]=-3;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i][j]==1)
                g<<'S';
            else if(a[i][j]==-2)
                g<<'X';
            else if(a[i][j]==-3)
                g<<'F';
            else g<<' ';
        }
        g<<'\n';
    }
    return 0;
}
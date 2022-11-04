#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fifteen = 15;
string vertices[15] = {"Mohave", "Coconino", "Navajo", "Apache", "Greenlee", "Cochise", "Santa Cruz", "Pima", "Pinal", "Graham", "Gila", "Yavapai", "La Paz", "Yuma", "Maricopa"};

int edges[15][15];

void print(){
for(int i = 0 ; i < fifteen; i++){
    for(int j = 0 ; j < fifteen; j++){
      cout << edges[i][j] << "\t";
    }
    cout << endl << endl;
  }
}

int* getNeighbors(int vertex){
  static int neighbors[15];
  int counter = 0;
  cout << "Neighbors at " << vertices[vertex] << ": ";
  for(int i = 0; i < fifteen; i++){
    if(edges[vertex][i] > 0){
      neighbors[counter] = edges[vertex][i];
      counter++;
      cout << edges[vertex][i] << ", ";
    }
  }
  cout << endl << endl;
  return neighbors;
}

int getDistance(int start, int end){
  int total = 0;
  int m = end;
  int counter = 0;
  if(edges[start][m] > 0){
    return edges[start][m];
  }
  while(edges[start][m] == 0 && counter < fifteen * fifteen){
    counter++;
    if(m == fifteen){
      m = -1;
    }
    m+=1;
    if(edges[start][m] == 0){
      m+=1;
    }
    total += edges[start][m];
    start = m;
    m = end;
    if(edges[start][m] > 0){
      total += edges[start][end];
    }
  }
  if(counter >= fifteen * fifteen){
    return INT_MAX;
  }
  return total;
}

int main() {
  edges[0][1]   = edges[1][0]   = 14;
  edges[0][11]  = edges[11][0]  = 14;
  edges[0][12]  = edges[12][0]  = 9;

  edges[1][2]   = edges[2][1]   = 9;
  edges[1][10]  = edges[10][1]  = 17;
  edges[1][11]  = edges[11][1]  = 9;

  edges[2][3]   = edges[3][2]   = 5;
  edges[2][9]   = edges[9][2]   = 20;
  edges[2][10]  = edges[10][2]  = 13;

  edges[3][4]   = edges[4][3]   = 17;
  edges[3][9]   = edges[9][3]   = 19;

  edges[4][5]   = edges[5][4]   = 16;
  edges[4][9]   = edges[9][4]   = 4;

  edges[5][6]   = edges[6][5]   = 8;
  edges[5][7]   = edges[7][5]   = 9;
  edges[5][9]   = edges[9][5]   = 12;

  edges[6][7]   = edges[7][6]   = 6;

  edges[7][8]   = edges[8][7]   = 7;
  edges[7][9]   = edges[9][7]   = 12;
  edges[7][13]  = edges[13][7]  = 23;
  edges[7][14]  = edges[14][7]  = 10;

  edges[8][9]   = edges[9][8]   = 13;
  edges[8][10]  = edges[10][8]  = 5;
  edges[8][14]  = edges[14][8]  = 6;

  edges[9][10]  = edges[10][9]  = 7;

  edges[10][11] = edges[11][10] = 18;
  edges[10][14] = edges[14][10] = 8;

  edges[11][12] = edges[12][11] = 15;
  edges[11][14] = edges[14][11] = 9;

  edges[12][13] = edges[13][12] = 11;
  edges[12][14] = edges[14][12] = 15;

  print();
  for(int i = 0; i < fifteen; i++){
    getNeighbors(i);
  }

  cout << "-------------------------------" << endl << endl;
  cout << "Distance: " << getDistance(0,14) << endl;
  cout << "Distance: " << getDistance(1,3) << endl;

}

/*
    0  1  2  3  4  5  6  7  8  9  10 11 12 13 14

0   0  14 #  #  #  #  #  #  #  #  #  14 9  #  # 
1   14 0  9  #  #  #  #  #  #  #  17 9  #  #  # 
2   #  9  0  5  #  #  #  #  #  20 13 #  #  #  # 
3   #  #  5  0  17 #  #  #  #  19 #  #  #  #  # 
4   #  #  #  17 0  16 #  #  #  4  #  #  #  #  # 
5   #  #  #  #  16 0  8  9  #  12 #  #  #  #  # 
6   #  #  #  #  #  8  0  6  #  #  #  #  #  #  # 
7   #  #  #  #  #  9  6  0  7  12 #  #  #  23 10 
8   #  #  #  #  #  #  #  7  0  13 5  #  #  #  6 
9   #  #  20 19 4  12 #  12 13 0  7  #  #  #  # 
10  #  17 13 #  #  #  #  #  5  7  0  18 #  #  8 
11  14 9  #  #  #  #  #  #  #  #  18 0  15 #  9 
12  9  #  #  #  #  #  #  #  #  #  #  15 0  11 15 
13  #  #  #  #  #  #  #  23 #  #  #  #  11 0  # 
14  #  #  #  #  #  #  #  10 6  #  8  9  15 #  0 
*/
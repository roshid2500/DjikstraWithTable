#include <iostream>
#include "Matrix.h"
#include <climits>
#include <float.h>
/*
  Constructor to make adj matrix
*/
Matrix::Matrix(std::string fileName){
  //open file
  std::ifstream myfile;
  myfile.open(fileName, std::fstream::in);
  std::string val;
  unsigned int cur = 0;

  //set size of mat
  myfile >> val;
  this->size = stoi(val);

  std::vector<double> vec;
  //fill out the adj matrix
  while(myfile >> val){
    //reached the end of a vector
    if(cur == this->size){
      this->adjacencyMatrix.push_back(vec);
      vec.clear();
      cur = 0;
    }
    vec.push_back(stoi(val));
    cur++;
  }
  this->adjacencyMatrix.push_back(vec);

//close the file
myfile.close();
}


/*
  Simply prints out the adj matrix and its size
*/
void Matrix::prettyPrint(){
  //size of mat adj
  std::cout << "Size " << this->adjacencyMatrix.size() << std::endl;

  //print adj mat
  for(unsigned int i = 0; i < this->size; i++){
    for(unsigned int j = 0; j < this->adjacencyMatrix.at(i).size(); j++){
      std::cout << this->adjacencyMatrix.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }
}





/*
  Peforms djikstra's algorihtm on (start,dest).
  Prints a table of the process and final answer in the end
*/
void Matrix::djikstras(unsigned int start, unsigned int dest){
  if(start == dest) //base case: do nothing
    return;


  //print out the header of the table
  std::cout << "STEP";
  for(unsigned i = 0; i < this->size; i++){
    std::cout << "    p(" << i << ")";
  }
  std::cout << "    visited"<< std::endl;

  //min path array
  double total[this->size];
  //keep track of nodes visited
  bool visited[this->size];

  //initialize the path and visited arrays to infinity and univisted
  for(unsigned int i = 0; i < this->size;i++){
    total[i] = LDBL_MAX;
    visited[i] = false;
  }

  //distance to self is 0
  total[start] = 0;

  //use to keep track of nodes visited so far
  std::string visitedSoFar = "";

  //Loop through the rows minus the starting position
  for(unsigned int i = 0; i < this->size; i++){
    std::vector<std::string> order(this->size);
    std::vector<int> isInf(this->size);
    double minVal = LDBL_MAX;
    int min = -1;

    std::cout << i << "   ";

    //get an unvisited node that has the smallest edge weight to current node (i)
    for(unsigned int v = 0; v < this->size; v++){
      if(!visited[v] && total[v] <= minVal){
        minVal = total[v];
        min =  v;
      }
    }

    //visiting the min nodes
    visited[min] = true;

    //check paths to various nodes and rewrite min paths
    for(unsigned int j = 0; j < this->size; j++){
      //if true, then path to node 'j' is new min
      if(!visited[j] && this->adjacencyMatrix[min][j] != -1 && this->adjacencyMatrix[min][j] + total[min] < total[j]
                  && total[min] != (double) LDBL_MAX){
         total[j] = total[min] + this->adjacencyMatrix[min][j];
         //keep track of new paths
         order[j] = std::to_string(i) + "(" + std::to_string((int)total[j]) + ")";
      }
    }

    //space between nodes in table
    std::string space = "   ";

    //print out the new steps
    for(unsigned k = 0; k < order.size(); k++){
      space = "   ";
      //starting node should always be 0 to itself
      if(i == start && k == start){
        std::cout << "    0    ";
        continue;
      }
      //lower the spacing if path is double digits
      // if(total[k] != (double)LDBL_MAX && total[k] > 9 && order[k] != "")
      //   space = "  ";
      //
      // //lower the spacing if path is triple digits
      // if(total[k] != (double)LDBL_MAX && total[k] > 99 && order[k] != "")
      //   space = "  ";

      //print either inf, nothing, or the value
      if(total[k] == (double) LDBL_MAX)
        std:: cout << space << "inf--";
      else if(order[k] == "" && total[k] != LDBL_MAX)
        std::cout << space << "-----";
      else
        std::cout << space << order[k];
    }

    //print out nodes visited so far in the table
    visitedSoFar += std::to_string(i) + ",";
    //print out each step
    std::cout << "   " << visitedSoFar << "\n";

    //clear the new smallest paths vector for the next set
    order.clear();
  }

  std::cout << "\nshortest path is " << total[dest] << std::endl;
}

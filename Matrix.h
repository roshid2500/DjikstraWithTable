#ifndef MATRIX_H
#define MATRIX_H
#include <fstream>
#include <string>
#include <vector>
#include <list>

class Matrix{
  std::vector<std::vector<double>> adjacencyMatrix;
  unsigned int size;
public:
  Matrix(std::string fileName);
  unsigned int getSize() { return this->size; }
  void djikstras(unsigned int start, unsigned int dest);
  void prettyPrint();
};

#endif

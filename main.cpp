#include <iostream>
#include "SpreadSheet.h"
#include "Cell.h"

int main() {

  SpreadSheet mySpreadSheet(4, 4);
  int size = 4;
  Cell* c = new Cell[size];
  for(int i = 0; i < size; ++i) {
    c[i].setString("A");
  }

  mySpreadSheet.setCellAt(0, 0, "4");
  mySpreadSheet.setCellAt(2, 1, c);

  std::cout << "Cell info: " << mySpreadSheet.getCellAt(2, 1).toString() << std::endl;
  mySpreadSheet.addRow(2);
  mySpreadSheet.setCellAt(5, 1, "Hello");
  std::cout << "Cell info: " << mySpreadSheet.getCellAt(5, 1).toString() << std::endl;
  mySpreadSheet.addColumn(2);
  mySpreadSheet.setCellAt(5, 5, "Bye");
  std::cout << "Cell info: " << mySpreadSheet.getCellAt(5, 5).toString() << std::endl;
  
  return 0;
}

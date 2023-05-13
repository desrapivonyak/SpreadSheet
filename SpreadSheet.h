#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <string>
#include "Cell.h"

class SpreadSheet{
public:
  SpreadSheet(int, int);
  ~SpreadSheet();
  void setCellAt(int, int, std::string);
  void setCellAt(int, int, Cell*);
  Cell getCellAt(int, int);
  void addRow(int);
  void addColumn(int);
private:
  Cell** m_cells;
  int m_rows;
  int m_columns;
};

#endif
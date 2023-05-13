#include "SpreadSheet.h"
#include <stdexcept>

SpreadSheet::SpreadSheet(int rows, int columns) {
  
  this->m_rows = rows;
  this->m_columns =columns;
  this->m_cells = new Cell*[rows];
  for (int i = 0; i < rows; ++i) {
    m_cells[i] = new Cell[columns];
  }
  
  for (int i = 0; i < rows; ++i) {
    for(int j = 0; j < columns; ++j) {
      m_cells[i][j].setString("0");
    }
  }
}

void SpreadSheet::setCellAt(int row, int column, Cell* cell){
  if(row < 0 || row > m_rows || column < 0 || column > m_columns) {
    throw std::out_of_range("Out of range.");
  }
  this->m_cells[row][column] = cell->toString();
}

void SpreadSheet::setCellAt(int row, int column, std::string str){
  if(row < 0 || row > m_rows || column < 0 || column > m_columns) {
    throw std::out_of_range("Out of range.");
  }
  Cell c {str};
  this->m_cells[row][column] = c.toString();
}

Cell SpreadSheet::getCellAt(int row, int column) {
  if(row < 0 || row > m_rows || column < 0 || column > m_columns) {
    throw std::out_of_range("Out of range.");
  }
  return m_cells[row][column];
}

void SpreadSheet::addRow(int n) {
  if(n < 0) {
    throw std::out_of_range("Out of range.");
  }
  Cell** tempCells = new Cell*[m_rows + n];
  for (int i = 0; i < m_rows + n; ++i) {
      tempCells[i] = new Cell[m_columns];
  }
  for (int i = 0; i < m_rows; ++i) {
    for (int j = 0; j < m_columns; ++j) {
      tempCells[i][j] = m_cells[i][j];
    }
  }
  m_cells = tempCells;
  m_rows += n;
}

void SpreadSheet::addColumn(int n) {
  if(n < 0) {
    throw std::out_of_range("Out of range.");
  }
  Cell** tempCells = new Cell*[m_rows];
  for (int i = 0; i < m_rows; ++i) {
    tempCells[i] = new Cell[m_columns + n];
  }
  for (int i = 0; i < m_rows; ++i) {
    for (int j = 0; j < m_columns; ++j) {
      tempCells[i][j] = m_cells[i][j];
    }
  }
  m_cells = tempCells;
  m_columns += n;
}

SpreadSheet::~SpreadSheet() {
  for (int i = 0; i < m_rows; ++i) {
    delete[] m_cells[i];
  }
  delete[] m_cells;
}
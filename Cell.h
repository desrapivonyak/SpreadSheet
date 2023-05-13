#ifndef CELL_H
#define CELL_H

#include <string>

class Cell{

public:
  Cell(const std::string&);
  Cell() = default;
  ~Cell() = default;

  int toInt();
  void setInt(int);

  double toDouble();
  void setDouble(double);

  std::string toString();
  void setString(std::string);
private:
  std::string m_value;
};
#endif
#include "Cell.h"

Cell::Cell(const std::string& str) {this->m_value = str;};

int Cell::toInt() {
  return std::stoi(this->m_value);
}

void Cell::setInt(int num) {
  this->m_value = std::to_string(num);
}

double Cell::toDouble() {
  return std::stod(this->m_value);
}
void Cell::setDouble(double d) {
  this->m_value = std::to_string(d);
}

std::string Cell::toString() {
  return this->m_value;
}

void Cell::setString(std::string str) {
  this->m_value = str;
}
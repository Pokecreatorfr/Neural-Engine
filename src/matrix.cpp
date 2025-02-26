#include <iostream>
#include <matrix/matrix.hpp>
#include <matrix/matrixOperations.hpp>

Matrix::Matrix(uint32_t cols, uint32_t rows, float init_val)
{
    this->rows = rows;
    this->cols = cols;
    this->data = std::vector<float>(rows * cols);
    for (uint32_t i = 0; i < rows * cols; i++)
    {
        this->data[i] = init_val;
    }
}

Matrix::~Matrix()
{
}

uint32_t Matrix::get_rows()
{
    return this->rows;
}

uint32_t Matrix::get_cols()
{
    return this->cols;
}

float Matrix::get(uint32_t col, uint32_t row)
{
    return this->data[row * this->cols + col];
}

void Matrix::set(uint32_t col, uint32_t row, float val)
{
    this->data[row * this->cols + col] = val;
}

void Matrix::set_data(std::vector<float> data)
{
    if (data.size() != this->rows * this->cols)
    {
        throw std::invalid_argument("Data size does not match matrix dimensions");
    }
    this->data = data;
}

void Matrix::function_on_elements(void (*func)(float &))
{
    for (uint32_t i = 0; i < this->rows; i++)
    {
        for (uint32_t j = 0; j < this->cols; j++)
        {
            func(this->data[i * this->cols + j]);
        }
    }
}

void Matrix::print()
{
    for (uint32_t i = 0; i < this->cols; i++)
    {
        for (uint32_t j = 0; j < this->rows; j++)
        {
            std::cout << this->data[j * this->cols + i] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::operator+(Matrix &b)
{
    return add(*this, b);
}

Matrix Matrix::operator-(Matrix &b)
{
    return subtract(*this, b);
}

Matrix Matrix::operator*(Matrix &b)
{
    return multiply(*this, b);
}

Matrix Matrix::operator~()
{
    return transpose(*this);
}

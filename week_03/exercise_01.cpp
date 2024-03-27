#include <iostream>
#include <fstream>
#include <sstream>

bool isDigit(const char ch)
{
    return (ch >= '0' && ch <= '9');
}

int convertCharToDigit(const char ch)
{
    if (isDigit(ch))
        return ch - '0';
    return -1;
}

unsigned convertStrToUnsigned(const char* str)
{
    if (!str)
        return 0;

    unsigned result = 0;
    while (*str)
    {
        int digit = convertCharToDigit(*str);
        if (digit == -1)
            return result;
        (result *= 10) += digit;
        str++;
    }
    return result;
}

namespace GlobalConstants
{
    constexpr int MAX_COLLS = 100;
    constexpr int MAX_ROWS = 100;
    constexpr int MAX_BUFFER_SIZE = 1024;
    constexpr char COLL_SEP = '|';
    constexpr char CELL_SEP = ',';
}

struct Row
{
    int colls[GlobalConstants::MAX_COLLS];    
};

struct Matrix
{
    Row rows[GlobalConstants::MAX_ROWS];
    size_t currentRows = 0;
    size_t currentColls = 0;
};

size_t parseRow(const char* row, Row& rowToReturn)
{
    std::stringstream ss(row);

    size_t currentColumnsCount = 0;
    char buff[GlobalConstants::MAX_BUFFER_SIZE];
    while (!ss.eof())
    {
        ss.getline(buff, GlobalConstants::MAX_BUFFER_SIZE, GlobalConstants::CELL_SEP);
        rowToReturn.colls[currentColumnsCount++] = convertStrToUnsigned(buff);
    }
    return currentColumnsCount;
}

Matrix parseFromFile(std::ifstream& ifs)
{
    Matrix result;
    char buff[GlobalConstants::MAX_BUFFER_SIZE];
    while (!ifs.eof())
    {
        ifs.getline(buff, GlobalConstants::MAX_BUFFER_SIZE, GlobalConstants::COLL_SEP);
        result.currentColls = parseRow(buff, result.rows[result.currentRows++]);
    }
    return result;
}

Matrix parseFromFile(const char* fileName)
{
    if (!fileName)
        return {};

    std::ifstream ifs(fileName);

    if (!ifs.is_open())
        return {};

    return parseFromFile(ifs);
}

void writeToFile(const char* fileName, Matrix& mtx)
{
    if (!fileName)
        return;

    std::ofstream ofs(fileName);
    if (!ofs.is_open())
        return;

    for (size_t i = 0; i < mtx.currentRows; i++)
    {
        for (size_t j = 0; j < mtx.currentColls; j++)
        {
            ofs << mtx.rows[i].colls[j];
            if (j != mtx.currentColls - 1)
                ofs << GlobalConstants::CELL_SEP;
        }
        if (i != mtx.currentRows - 1)
            ofs << GlobalConstants::COLL_SEP;
    }

    ofs.close();
}

int multRowAndColl(Matrix& mtx1, Matrix& mtx2, size_t currentRow, size_t currentColl)
{
    int result = 0;
    for (size_t i = 0; i < mtx1.currentColls; i++)
    {
        result += (mtx1.rows[currentRow].colls[i]) * (mtx2.rows[i].colls[currentColl]);
    }
    return result;
}

Matrix multiplication(Matrix& mtx1, Matrix& mtx2)
{
    Matrix result;

    result.currentRows = mtx1.currentRows;
    result.currentColls = mtx2.currentColls;

    for (size_t i = 0; i < result.currentRows; i++)
    {
        for (size_t j = 0; j < result.currentColls; j++)
        {
            result.rows[i].colls[j] = multRowAndColl(mtx1, mtx2, i, j);
        }
    }

    return result;
}

int main()
{
    Matrix mtx1 = parseFromFile("fst.txt");
    Matrix mtx2 = parseFromFile("snd.txt");
    Matrix res = multiplication(mtx1, mtx2);
    writeToFile("result.txt", res);
}

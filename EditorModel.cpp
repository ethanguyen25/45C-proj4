// EditorModel.cpp
//
// ICS 45C Spring 2020
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"

#include <iostream>
#include <string>
#include <vector>

EditorModel::EditorModel()
    :lineNumber{1}, columnNumber{1}, numOfLines{1}, emVector{""}
{
}


int EditorModel::cursorLine() const
{
    return lineNumber;
}


int EditorModel::cursorColumn() const
{
    return columnNumber;
}


int EditorModel::lineCount() const
{
    return numOfLines;
}


const std::string& EditorModel::line(int lineNumber) const
{
    return emVector.at(lineNumber-1);
}


const std::string& EditorModel::currentErrorMessage() const
{
    return errorMsg;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    errorMsg = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    errorMsg = "";
}

// ADDED FUNCTIONS

void EditorModel::moveCursorRight()
{
    unsigned int end = emVector.at(lineNumber-1).length();
    if (lineNumber == numOfLines or numOfLines == 1)
    {
        if (columnNumber <= end)
        {
            columnNumber += 1;
        }
        else
        {
            throw EditorException ("Already at end");
        }
    }
    else
    {
        if (columnNumber <= end)
        {
            columnNumber += 1;
        }
        else
        {
            columnNumber = 1;
            lineNumber += 1; 
        }
    }
}

void EditorModel::moveCursorLeft()
{
    if (columnNumber == 1 and lineNumber == 1)
    {
        //setErrorMessage("Already at beginning");
        throw EditorException ("Already at beginning");
    }
    else if (lineNumber != 1 and columnNumber == 1)
    {
        unsigned int len = emVector.at(lineNumber-2).length();
        columnNumber = len + 1;
        lineNumber -= 1;
    }
    else
    {
        columnNumber -= 1;
    }
}

void EditorModel::moveCursorUp()
{
    if (lineNumber == 1)
    {
        throw EditorException ("Already at Top");
    }
    else
    {
        unsigned int prevLineLen = emVector.at(lineNumber-2).length();
        if ((columnNumber-1) > prevLineLen)
        {
            columnNumber = prevLineLen + 1;
        }
        lineNumber -= 1;
    }
}

void EditorModel::moveCursorDown()
{
    if (lineNumber == lineCount())
    {
        throw EditorException ("Already at Bottom");
    }
    else
    {
        unsigned int nextLineLen = emVector.at(lineNumber).length();
        if ((columnNumber-1) > nextLineLen)
        {
            columnNumber = nextLineLen + 1;
        }
        lineNumber += 1;
    }
}

void EditorModel::beginningOfLine()
{
    columnNumber = 1;
} 

void EditorModel::endOfLine()
{
    unsigned int end = emVector.at(lineNumber-1).length();
    columnNumber = end+1;
} 

void EditorModel::insertChar(char& character)
{
    setErrorMessage("");
    emVector.at(lineNumber-1).insert((columnNumber-1), 1, character);
    columnNumber += 1;
}

void EditorModel::createNewline()
{
    unsigned int len = emVector.at(lineNumber-1).length();
    if (columnNumber-1 == len)
    {

        emVector.push_back("");
    }
    else
    {
        std::string line = emVector.at(lineNumber-1);
        std::string nextLine = line.substr(columnNumber-1, 
                                (len-(columnNumber-1)));
        
        emVector.at(lineNumber-1).erase(columnNumber-1, nextLine.length());
        emVector.insert(emVector.begin() + (lineNumber), 1, nextLine);
    
    }
    columnNumber = 1;
    lineNumber += 1;
    numOfLines += 1;
}

void EditorModel::previousSpot(unsigned int& ln, unsigned int& cn)
{
    lineNumber = ln;
    columnNumber = cn;
}

void EditorModel::deleteLine()
{
    if (lineNumber == 1 and numOfLines == 1)
    {
        emVector.at(0).clear();
        columnNumber = 1;
    }
    else
    {
        if (lineNumber == numOfLines)
        {
            unsigned int prevLength = emVector.at(lineNumber-2).length();
            emVector.erase(emVector.begin() + lineNumber-1);
            
            if (columnNumber <= prevLength)
            {
            }
            else
            {
                columnNumber = prevLength+1;
            }
            lineNumber -= 1;
        }
        else
        {
            unsigned int nextLength = emVector.at(lineNumber).length();
            if (columnNumber <= nextLength)
            {
            }
            else
            {
                columnNumber = nextLength+1;
            }
            emVector.erase(emVector.begin() + lineNumber-1);
             
        }
        numOfLines -= 1;
    }
}

std::string EditorModel::tempHolder()
{
    tempStr = emVector.at(lineNumber-1);
    return tempStr;
}

void EditorModel::addBackIn(unsigned int& lnum, std::string& str)
{
    emVector.insert(emVector.begin() + (lnum-1), 1, str);
    numOfLines += 1;
}

void EditorModel::backspace()
{
    if (columnNumber == 1)
    {
        if (lineNumber == 1)
        {
            throw EditorException ("Already at Beginning");
        }
        else
        {
            std::string tempStr = emVector.at(lineNumber-2);
            emVector.at(lineNumber-2).append(emVector.at(lineNumber-1));
            emVector.erase(emVector.begin() + (lineNumber-1));
            columnNumber = tempStr.length() + 1;
            lineNumber -= 1;
            numOfLines -= 1;
        }
    }
    else
    {
        emVector.at(lineNumber-1).erase(emVector.at(lineNumber-1).begin() 
                                    + (columnNumber-2));
        columnNumber -= 1;
    }
}


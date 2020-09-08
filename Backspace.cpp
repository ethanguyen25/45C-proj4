//Backspace.cpp


#include "Backspace.hpp"


void Backspace::execute(EditorModel& model)
{
    prevColumnNum = model.cursorColumn();
    prevLineNum = model.cursorLine();
    if (prevColumnNum != 1)
    {
        std::string s = model.tempHolder();
        tempChar = s.at(prevColumnNum-2);
    }
    model.backspace();
}

void Backspace::undo(EditorModel& model)
{
    if (model.cursorLine() == prevLineNum)
    {
        model.insertChar(tempChar);
    }
    else
    {
        model.createNewline();
    }
    model.previousSpot(prevLineNum, prevColumnNum);
}

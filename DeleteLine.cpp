//DeleteLine.cpp


#include "DeleteLine.hpp"

void DeleteLine::execute(EditorModel& model)
{
    prevColumnNum = model.cursorColumn();
    prevLineNum = model.cursorLine();
    prevStr = model.tempHolder();
    model.deleteLine();
}

void DeleteLine::undo(EditorModel& model)
{
    model.addBackIn(prevLineNum, prevStr);
    model.previousSpot(prevLineNum, prevColumnNum);
}

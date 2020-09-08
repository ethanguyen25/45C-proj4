//CursorDown.cpp

#include "CursorDown.hpp"


void CursorDown::execute(EditorModel& model)
{
    prevColumnNum = model.cursorColumn();
    prevLineNum = model.cursorLine();
    model.moveCursorDown();
}

void CursorDown::undo(EditorModel& model)
{
    model.previousSpot(prevLineNum, prevColumnNum);
}

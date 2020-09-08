//CursorHome.cpp


#include "CursorHome.hpp"


void CursorHome::execute(EditorModel& model)
{
    prevColumnNum = model.cursorColumn();
    prevLineNum = model.cursorLine();
    model.beginningOfLine();
}

void CursorHome::undo(EditorModel& model)
{
    model.previousSpot(prevLineNum, prevColumnNum);
}

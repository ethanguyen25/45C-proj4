//CursorUp.cpp


#include "CursorUp.hpp"

void CursorUp::execute(EditorModel& model)
{
    prevColumnNum = model.cursorColumn();
    prevLineNum = model.cursorLine();
    model.moveCursorUp();
}

void CursorUp::undo(EditorModel& model)
{
    model.previousSpot(prevLineNum, prevColumnNum);
}

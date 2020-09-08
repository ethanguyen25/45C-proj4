//CursorEnd.cpp


#include "CursorEnd.hpp"

void CursorEnd::execute(EditorModel& model)
{
    prevColumnNum = model.cursorColumn();
    prevLineNum = model.cursorLine();
    model.endOfLine();    
}

void CursorEnd::undo(EditorModel& model)
{
    model.previousSpot(prevLineNum, prevColumnNum);
}   

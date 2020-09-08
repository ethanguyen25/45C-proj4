//Newline.cpp



#include "Newline.hpp"


void Newline::execute(EditorModel& model)
{
    prevColumnNum = model.cursorColumn();
    prevLineNum = model.cursorLine();
    model.createNewline();
}

void Newline::undo(EditorModel& model)
{
    model.backspace();
    model.previousSpot(prevLineNum, prevColumnNum);
}

//CursorEnd.hpp

#ifndef CURSOREND_HPP
#define CURSOREND_HPP

#include "Command.hpp"


class CursorEnd : public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);

private:
    unsigned int prevColumnNum;
    unsigned int prevLineNum;

};

#endif

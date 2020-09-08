//CursorRight.hpp


#ifndef CURSORRIGHT_HPP
#define CURSORRIGHT_HPP

#include "Command.hpp"

class CursorRight : public Command
{
public: 
    virtual void execute(EditorModel& model)
    {
        model.moveCursorRight();
    }

    virtual void undo(EditorModel& model)
    {
        model.moveCursorLeft();
    }

};

#endif

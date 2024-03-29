//CursorLeft.hpp


#ifndef CURSORLEFT_HPP
#define CURSORLEFT_HPP

#include "Command.hpp"

class CursorLeft : public Command
{
public:
    virtual void execute(EditorModel& model)
    {
        model.moveCursorLeft();
    }

    virtual void undo(EditorModel& model)
    {
        model.moveCursorRight();
    }

};

#endif
       

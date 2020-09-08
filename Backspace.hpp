//Backspace.hpp


#ifndef BACKSPACE_HPP
#define BACKSPACE_HPP


#include "Command.hpp"

class Backspace : public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);

private:
    unsigned int prevColumnNum;
    unsigned int prevLineNum;

    char tempChar;

};


#endif

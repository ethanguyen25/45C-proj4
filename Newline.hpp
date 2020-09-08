//Newline.hpp


#ifndef NEWLINE_HPP
#define NEWLINE_HPP


#include "Command.hpp"

class Newline : public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);

private:
    unsigned int prevColumnNum;
    unsigned int prevLineNum;

};


#endif

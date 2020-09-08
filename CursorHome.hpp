//CursorHome.hpp


#ifndef CURSORHOME_HPP
#define CURSORHOME_HPP

#include "Command.hpp"


class CursorHome : public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);

private:
    unsigned int prevColumnNum;
    unsigned int prevLineNum;

};



#endif

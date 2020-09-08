//DeleteLine.hpp

#ifndef DELETELINE_HPP
#define DELETELINE_HPP


#include "Command.hpp"

class DeleteLine : public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);

private:
    unsigned int prevColumnNum;
    unsigned int prevLineNum;
    std::string prevStr;
};

#endif

//InsertCharacter.hpp


#ifndef INSERTCHARACTER_HPP
#define INSERTCHARACTER_HPP

#include "Command.hpp"
#include <string>
#include "EditorException.hpp"

class InsertCharacter : public Command
{
public:
    InsertCharacter(char character)
        :character{character}
    {
    }
    
    virtual void execute(EditorModel& model)
    {
        model.insertChar(character);
    }

    virtual void undo(EditorModel& model)
    {
        model.backspace();
    }

private:
    char character;

};


#endif

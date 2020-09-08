// InteractionProcessor.cpp
//
// ICS 45C Spring 2020
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"

#include <vector>

// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    view.refresh();

    //REMEMBER TO DELETE!!!!!
    std::vector<Command*> undoVector;
    std::vector<Command*> redoVector;
    
    Command* command = nullptr;
    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if (!undoVector.empty())
            {
                Command* prevCommand = undoVector.back();
                prevCommand->undo(model);
                view.refresh();
                redoVector.push_back(prevCommand);
                undoVector.pop_back();
            }
        }
        else if (interaction.type() == InteractionType::redo)
        {
            //can only redo after undo
            if (!redoVector.empty())
            {
                Command* prevCommand = redoVector.back();
                prevCommand->execute(model);
                view.refresh();
                undoVector.push_back(prevCommand);
                redoVector.pop_back();
            }
        }
        else if (interaction.type() == InteractionType::command)
        {
            //Command* command = interaction.command();
            command = interaction.command();
            undoVector.push_back(command);
            try
            {
                command->execute(model);
                model.clearErrorMessage();
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
            
            //delete command;
        }
    }
    if (!undoVector.empty())
    {
        for (int u = 0; u < undoVector.size(); ++u)
        {
            delete undoVector.at(u);
        }
        undoVector.clear();
    }
    if (!redoVector.empty())
    {
        for (int r = 0; r < redoVector.size(); ++r)
        {
            delete redoVector.at(r);
        }
        redoVector.clear();
    }
}


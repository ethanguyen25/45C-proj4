// KeypressInteractionReader.cpp
//
// ICS 45C Spring 2020
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"


// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

#include "Command.hpp"
#include "CursorRight.hpp"
#include "CursorLeft.hpp"
#include "CursorUp.hpp"
#include "CursorDown.hpp"
#include "CursorHome.hpp"
#include "CursorEnd.hpp"
#include "InsertCharacter.hpp"
#include "Newline.hpp"
#include "DeleteLine.hpp"
#include "Backspace.hpp"


Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
                case 'X':
                {
                    return Interaction::quit();
                }
                case 'Z':
                {
                    return Interaction::undo();
                }
                case 'A':
                { 
                    return Interaction::redo();
                }
                case 'O':
                {
                    Command* crptr = new CursorRight;
                    return Interaction::command(crptr);
                }
                case 'U':
                { 
                    Command* clptr = new CursorLeft;
                    return Interaction::command(clptr);
                }
                case 'I':
                { 
                    Command* cuptr = new CursorUp;
                    return Interaction::command(cuptr);
                }
                case 'K':
                { 
                    Command* cdptr = new CursorDown;
                    return Interaction::command(cdptr);
                }
                case 'Y':
                { 
                    Command* chptr = new CursorHome;
                    return Interaction::command(chptr);
                }
                case 'P':
                { 
                    Command* ceptr = new CursorEnd;
                    return Interaction::command(ceptr);
                }
                case 'J':
                case 'M':
                { 
                    Command* nlptr = new Newline;
                    return Interaction::command(nlptr);
                }
                case 'D':
                { 
                    Command* dlptr = new DeleteLine;
                    return Interaction::command(dlptr);
                }
                case 'H':
                { 
                    Command* bsptr = new Backspace;
                    return Interaction::command(bsptr);
                }
            }

        }
        else
        {
            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly
            
            Command* icptr = new InsertCharacter(keypress.code());
            return Interaction::command(icptr);
        }
    }
}


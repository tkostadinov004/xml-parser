#include "Core/Controller/Commands/HelpCommand.h"

HelpCommand::HelpCommand(XMLController& controller, const MyVector<MyString>& arguments) : ControllerCommand(controller, "help", arguments, 0)
{
}

void HelpCommand::execute() const
{
	_controller.help();
}

ControllerCommand* HelpCommand::clone() const
{
	return new HelpCommand(*this);
}
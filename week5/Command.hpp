#ifndef _COMMAND_HPP
#define _COMMAND_HPP

class Command {
  public:
    virtual ~Command() {};
    virtual void execute() = 0;
};

#endif

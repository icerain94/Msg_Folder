#include "Message.h"
#include "Folder.h"

Message::Message(const Message &m):folders(m.folders),contents(m.contents)
{
    std::cout<<"Message"<<std::endl;

    add_to_Folders(m);
}


Message::~Message()
{
    std::cout<<"~Message"<<std::endl;
    remove_from_Folders();
}

Message& Message::operator=(const Message &m)
{
    std::cout<<"Message operator="<<std::endl;
    remove_from_Folders();
    add_to_Folders(m);
    contents=m.contents;
    folders=m.folders;
    return *this;
}

void Message::save(Folder &f)
{
    std::cout<<"Message save"<<std::endl;
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    std::cout<<"Message remove"<<std::endl;
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    std::cout<<"Message add_to_Folders"<<std::endl;
    for(auto f:m.folders)
    {
        f->addMsg(this);
    }
}
void Message::remove_from_Folders()
{
    std::cout<<"remove_from_Folders"<<std::endl;
    for(auto f:folders)
    {
        f->remMsg(this);
    }
}

void swap(Message &lhs,Message &rhs)
{

    using std::swap;

    for(auto f:lhs.folders)
    {
        f->remMsg(&lhs);
    }
    for(auto f:rhs.folders)
    {
        f->remMsg(&rhs);
    }
    swap(lhs.folders,rhs.folders);
    swap(lhs.contents,rhs.contents);
    for(auto f:lhs.folders)
    {
        f->addMsg(&lhs);
    }
    for(auto f:rhs.folders)
    {
        f->addMsg(&rhs);
    }
}

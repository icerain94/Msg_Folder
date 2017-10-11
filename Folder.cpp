#include "Folder.h"

Folder::Folder()
{
    std::cout<<"Folder"<<std::endl;
    //ctor
}

Folder::~Folder()
{
    std::cout<<"~Folder "<<messages.size()<<std::endl;
    //dtor
}

void Folder::test()
{
    for(auto msg:messages)
    {
        std::cout<<msg->contents<<std::endl;
    }
    std::cout<<std::endl;
}

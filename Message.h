#ifndef MESSAGE_H
#define MESSAGE_H
#include<set>
#include<string>
#include <iostream>
#include "Folder.h"

class Folder;
class Message
{
    friend class Folder;
    friend void swap(Message &lhs,Message &rhs);
    public:
        explicit Message(const std::string &str=""):contents(str){std::cout<<"Message"<<std::endl;}
        Message(const Message &rhs);

        Message& operator= (const Message &rhs);


        virtual ~Message();

        void save(Folder&);
        void remove(Folder&);

    private:
        std::set<Folder*>folders;
        std::string contents;

        void add_to_Folders(const Message&);
        void remove_from_Folders();
};

#endif // MESSAGE_H

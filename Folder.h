#ifndef FOLDER_H
#define FOLDER_H

#include<set>
#include "Message.h"
#include <iostream>

class Message;
class Folder
{
    friend class Message;
    friend void swap(Message &lhs,Message &rhs);
    public:
        Folder();
        Folder(const Folder &f)=delete;
        Folder& operator=(const Folder &f)=delete;
        void test();
        virtual ~Folder();

    private:
        std::set<Message*>messages;
        void addMsg(Message *msg)
        {
            std::cout<<"Folder addMsg"<<std::endl;
            messages.insert(msg);
        }
        void remMsg(Message *msg)
        {
            std::cout<<"Folder remMsg"<<std::endl;
            messages.erase(msg);
        }


};

#endif // FOLDER_H

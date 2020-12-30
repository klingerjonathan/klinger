/*
auth: Jonathan Klinger 
file: work_packet.h 
date: 12.2020
desc: Exercise 04
*/

#pragma once

class WorkPacket {
    private: 
        int work_id;
    
    public: 
        WorkPacket(int work_id) {this->work_id = work_id;}
        
        int get_work_id() const {return this->work_id;}
};
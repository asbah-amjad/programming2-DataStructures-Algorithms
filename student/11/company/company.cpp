/*
#############################################################################
# COMP.CS.110 Programming 2, Autumn 2020                                    #
# Project3: Company                                                         #
# File: company.cpp                                                         #
# Description: Program first reads company information from the input file, #
# and then allow the user to make searches concerning the relationships in  #
# the company.                                                              #
#       *                                                                   #
# Program Author:                                                           #
#       * Name: Asbah Amjad Usmani                                          #
#       * Student Number: H292962                                           #
#       * User Id: khasus                                                   #
#       * Email: asbahamjad.usmani@tuni.fi                                  #
#       *                                                                   #
#############################################################################
*/
#include "company.hh"
#include <algorithm>

Company::Company(): empStruct_()
{

}

Company::~Company()
{

}

Employee *Company::getPointer(const std::string &id) const
{
    Employee* ptr = nullptr;
    for(auto* p: empStruct_){
        if(p->id_ == id){
            ptr = p;
        }
    }
    return ptr;
}

void Company::printNotFound(const std::string &id, std::ostream &output) const
{
    Employee* ptr = getPointer(id);
    if(ptr == nullptr){
        output << "Error. " << id << " not found." << std::endl;
    }
}

IdSet Company::VectorToIdSet(const std::vector<Employee *> &container) const
{
    IdSet s;
    for(const auto* p : container){
        s.insert(p->id_);
    }
    return s;
}


void Company::addNewEmployee(const std::string &id, const std::string &dep, const double &time, std::ostream &output)
{
    Employee* newEmployee = new Employee;
    Employee* ptr = getPointer(id);

    if(ptr == nullptr){
        newEmployee->id_ = id;
        newEmployee->department_ = dep;
        newEmployee->time_in_service_ = time;

        empStruct_.push_back(newEmployee);
    }
    else{
        output << "Error. Employee already added." << std::endl;
    }
}

void Company::printEmployees(std::ostream &output) const
{
    IdSet set = VectorToIdSet(empStruct_);
    for(auto it = set.begin(); it != set.end(); ++it){
        Employee* ptr = getPointer(*it);
        output << *it << ", " << ptr->department_ << ", " << ptr->time_in_service_ << std::endl;
    }
}

void Company::addRelation(const std::string &subordinate, const std::string &boss, std::ostream &output)
{
    Employee* subPtr = getPointer(subordinate);
    Employee* bossPtr = getPointer(boss);

    printNotFound(subordinate, output);

    if(bossPtr!=nullptr && subPtr != nullptr){
        subPtr->boss_ = bossPtr;
        bossPtr->subordinates_.push_back(subPtr);
    }
}

void Company::printBoss(const std::string &id, std::ostream &output) const
{
    printNotFound(id, output);
    Employee* ptr = getPointer(id);
    Employee* bossPtr = ptr->boss_;

    if(bossPtr == nullptr){
        output << id << " has no bosses" << std::endl;
    }
    else{
        output << id << " has 1 bosses:" << std::endl;
        output << bossPtr->id_ << std::endl;
    }
}

void Company::printSubordinates(const std::string &id, std::ostream &output) const
{
    printNotFound(id, output);
    Employee* ptr = getPointer(id);

    if(ptr->subordinates_.size() == 0){
        output << id << " has no subordinates." << std::endl;
    }
    else{
        output << id << " has " << ptr->subordinates_.size() << " subordinates:" << std::endl;
        for(auto *p : ptr->subordinates_){
            output << p->id_ << std::endl;
        }
    }
}

void Company::printColleagues(const std::string &id, std::ostream &output) const
{
    printNotFound(id, output);
    Employee* ptr = getPointer(id);
    Employee* bossPtr = ptr->boss_;
    if(bossPtr->subordinates_.size() <= 1){
        output << id << " has no colleagues." << std::endl;
    }
    else{
        output << id << " has " << bossPtr->subordinates_.size()-1 << " colleagues:" << std::endl;
        for(auto *p : bossPtr->subordinates_){
            if(p->id_ != id){
                output << p->id_ << std::endl;
            }
        }
    }
}

void Company::printDepartment(const std::string &id, std::ostream &output) const
{
    printNotFound(id, output);
    IdSet set;
    Employee* ptr = getPointer(id);
    std::string department = ptr->department_;
    for(auto* p: empStruct_){
        if(p->department_ == department && p->id_ != id){
            set.insert(p->id_);
        }
    }
    if(set.size() != 0){
        output << id << " has " << set.size() << " department colleagues:" << std::endl;
        for(auto it = set.begin(); it != set.end(); ++it){
            output << *it << std::endl;
        }
    }
    else{
        output << id << " has no department colleagues." << std::endl;
    }
}

void Company::printLongestTimeInLineManagement(const std::string &id, std::ostream &output) const
{
    printNotFound(id, output);
    Employee* ptr = getPointer(id);
    std::string department = ptr->department_;
    double time = ptr->time_in_service_;
    std::string name = id;

    for(auto* p: empStruct_){
        if(p->department_ == department && p->time_in_service_ > time){
            time = p->time_in_service_;
            name = p->id_;
        }
    }
    output << "With the time of " << time << ", " << name << " is the longest-served employee in their line management." << std::endl;
}

void Company::printShortestTimeInLineManagement(const std::string &id, std::ostream &output) const
{
    printNotFound(id, output);
}

void Company::printBossesN(const std::string &id, const int n, std::ostream &output) const
{
    printNotFound(id, output);
    output << n;
}

void Company::printSubordinatesN(const std::string &id, const int n, std::ostream &output) const
{
    printNotFound(id, output);
    output << n;
}

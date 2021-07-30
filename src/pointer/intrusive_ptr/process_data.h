#include "reference_counter.h"
#include<string>
#include<iostream>

class ProcessData : public ReferenceCounter {
public:
    ProcessData(int id, std::string info) :m_id(id), m_info(info) {
        std::cout << "Process Data Constructor" << std::endl;
    }

    ProcessData(const ProcessData &other) {
        std::cout << "Process Data Copy Constructor" << std::endl;
        m_id = other.m_id;
        m_info = other.m_info;
    }

    const ProcessData operator=(const ProcessData &other) {
        std::cout << "Process Data Assignment Operator" << std::endl;
        m_id = other.m_id;
        m_info = other.m_info;
    }

    ~ProcessData() {
        std::cout << "Process Data Destructor" << std::endl;
    }

private:
    int m_id;
    std::string m_info;
};

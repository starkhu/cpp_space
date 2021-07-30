#include <iostream>
#include <boost/intrusive_ptr.hpp>


#include <assert.h>
#include <atomic>
#include <iostream>

class ReferenceCounter{
public:
    friend void intrusive_ptr_add_ref(ReferenceCounter *p) {
        std::cout << "Call intrusive_ptr_add_ref" << std::endl;
        assert(p);
        assert(p->ref_count >= 0);
        ++p->ref_count;
    }

    friend void intrusive_ptr_release(ReferenceCounter *p) {
        std::cout << "Call intrusive_ptr_release" << std::endl;
        assert(p);
        assert(p->ref_count > 0);
        if (--p->ref_count == 0) {
            delete p;
        }
    }

    ReferenceCounter() :ref_count(0) {
        std::cout << "Reference Counter Constructor" << std::endl;
    }

    ReferenceCounter(const ReferenceCounter  &other) {
        std::cout << "Reference Counter Copy Constructor" << std::endl;
    }

    ReferenceCounter& operator=(const ReferenceCounter &other) {
        std::cout << "Reference Counter Assignment Operator" << std::endl;
    }

    ~ReferenceCounter() {
        std::cout << "Reference Counter Destructor" << std::endl;
    };

    int RefCount() {
        return ref_count;
    }

private:
    std::atomic_int ref_count;
};

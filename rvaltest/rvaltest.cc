#include <iostream>
#include <string>

#include "dbg.h"
#include "log.h"
#include "perf.h"

using std::string;

class Task {
public:
    string value_{};
    Task(string value) : value_{value} {
        PLOGD << "Created Task " << value;
    }

    Task( Task & t ) : value_{t.value_} {
        PLOGE << "Copied Task from Task " << t.value_;
    }

    Task( string & s) : value_ { s } {
        PLOGE << "Copied Task (from string)" << s;
    }

    operator std::string() const { 
        PLOGE << "Converted task to string " << this << "  " << value_;
        return this->value_; 
    }

    friend std::ostream & operator<<(std::ostream &out, const Task & t) {
        out << t.value_;
        return out;
    }
};

template <class Task>
class Queue {
public:
    string name_{};

    Queue(string name) : name_{name} {
        PLOGD << "Created queue " << name;
    }

    void Enqueue(const Task & t) {
        PLOGD << "Enqueued Address t\n" << dbg::memdump(&t);
        PLOGD << "Enqueued Data t\n" << dbg::memdump(t);
        PLOGN << "Enqueued " << &t;
    }
};

template< class Queue, class Task >
void Enqueue(Queue &q, Task const & t) {
    PLOGI << "using const ref Enqueue";
    q.Enqueue (t);
}

template< class Queue, class Task >
void Enqueue(Queue &q, Task && t) {
    PLOGW << "using rval Enqueue";
    PLOGD << "In Enqueue t\n" << dbg::memdump(t);

    q.Enqueue( std::move(t) );
    // q.Enqueue( t );
}

Task * MakeTask() {
    Task *t = new Task("Made by MakeTask()");
    PLOGD << "In MakeTask t\n" << dbg::memdump(*t);
    return t;
}

int main(int argc, char** argv) {
    perf::Timer clock;

    setup_console_logging(plog::debug);
    PLOGD << "Welcome to rvaltest!";
    
    auto q = Queue<Task>("muhqueue");
    Enqueue(q, string("Skittles!"));
    Task *t = MakeTask();
    PLOGD << "In main t\n" << dbg::memdump(t);
    Enqueue(q, *t);

    clock.tock();
    PLOGD << "# rvaltest Runtime: " << clock.duration().count() << "ms";
}

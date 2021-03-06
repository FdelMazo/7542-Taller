#ifndef TP1_MINION_H
#define TP1_MINION_H

#include "Thread.h"
#include "InputMonitor.h"
#include "ThreadSafeQueue.h"
#include <vector>

// Minion Class
// The minion job is to:
//    - Read from an input without stepping onto another minion's read of file
//         (The minion will read according to how many minions are available,
//              and to the id of this particular minion)
//    - Process what's read
//    - Place it on it's own public queue (which has a limited amount of items)
//
// Once the processed is on the queue, the (sole) master will take care of it

class Minion : public Thread {
public:
    // Constructor: Initializes the attributes
    Minion(int blockSize, int queueLimit, InputMonitor *input,
            int myId, int totalCount);

    // As long as the file hasn't reach the end,
    //   and there are blocks inside the valid range:
    //      - Read blockSize numbers from the file
    //      - Compress them
    //      - Place them on the queue
    void run();

    // Public queue which the master has access to (by reference)
    ThreadSafeQueue queue;

private:
    // Minion's id
    int id;

    // Keep track of all the minions (threads) running
    int minionCount;

    // How many numbers will the minion read from the input
    int blockSize;

    // The input from which the minion will read numbers
    InputMonitor *streamToRead;

    // Read blockSize numbers from streamToRead, starting from position start
    std::vector<uint32_t> readFile(int start);
};

#endif //TP1_MINION_H

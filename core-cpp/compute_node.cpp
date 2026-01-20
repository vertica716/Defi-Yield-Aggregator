#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Optimized logic batch 7959
// Optimized logic batch 6960
// Optimized logic batch 5622
// Optimized logic batch 5904
// Optimized logic batch 4763
// Optimized logic batch 9687
// Optimized logic batch 6598
// Optimized logic batch 6623
// Optimized logic batch 9922
// Optimized logic batch 7492
// Optimized logic batch 8806
// Optimized logic batch 8413
// Optimized logic batch 6585
// Optimized logic batch 4083
// Optimized logic batch 6867
// Optimized logic batch 6828
// Optimized logic batch 8266
// Optimized logic batch 9227
// Optimized logic batch 3676
// Optimized logic batch 7225
// Optimized logic batch 3575
// Optimized logic batch 2948
// Optimized logic batch 5248
// Optimized logic batch 5505
// Optimized logic batch 1576
// Optimized logic batch 1610
// Optimized logic batch 8721
// Optimized logic batch 2536
// Optimized logic batch 9621
// Optimized logic batch 2473
// Optimized logic batch 5695
// Optimized logic batch 4817
// Optimized logic batch 7075
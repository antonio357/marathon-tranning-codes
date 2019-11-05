#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void clearStack(stack<int>* stack) {
    while (not stack->empty()) {
        stack->pop();
    }
}

void clearQueue(queue<int>* queue) {
    while (not queue->empty()) {
        queue->pop();
    }
}

void clearPriorityQueue(priority_queue<int>* priority_queue) {
    while (not priority_queue->empty()) {
        priority_queue->pop();
    }
}

int main() {
    int nCases;
    int opcode, data;
    stack<int> stack;
    queue<int> queue;
    priority_queue<int> priorityQueue;
    bool  its_stack, its_queue, its_priority_queue;

    while (cin >> nCases) {
        its_stack = true;
        its_queue = true;
        its_priority_queue = true;
        clearStack(&stack);
        clearQueue(&queue);
        clearPriorityQueue(&priorityQueue);

        for (int i = 0; i < nCases; ++i) {
            cin >> opcode >> data;

            if (opcode == 1) {
                stack.push(data);
                queue.push(data);
                priorityQueue.push(data);
            }

            else if (opcode == 2) {
                if (not stack.empty()) {
                    if (stack.top() != data) its_stack = false;
                    stack.pop();
                } else its_stack = false;

                if (not queue.empty()) {
                    if (queue.front() != data) its_queue = false;
                    queue.pop();
                } else its_queue = false;

                if (not priorityQueue.empty()) {
                    if (priorityQueue.top() != data) its_priority_queue = false;
                    priorityQueue.pop();
                } else its_priority_queue = false;
            }
        }

        if (its_stack == false and its_queue == false and its_priority_queue == false) cout << "impossible";
        else if (its_stack == true and its_queue == false and its_priority_queue == false) cout << "stack";
        else if (its_stack == false and its_queue == true and its_priority_queue == false) cout << "queue";
        else if (its_stack == false and its_queue == false and its_priority_queue == true) cout << "priority queue";
        else cout << "not sure";
        cout << endl;
    }
    return 0;
}
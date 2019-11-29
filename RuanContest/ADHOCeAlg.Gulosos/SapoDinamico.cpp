#include <iostream>
#include <list>

using namespace std;

struct rock {
    string type;
    int dist_from_left_edge;
    bool can_jump_on;
};

void printRocks(const list <rock>* rocks) {
    for (auto i = rocks->begin(); i != rocks->end(); ++i) {
        cout << "type = " << i->type << endl;
        cout << "dist_from_left_edge = " << i->dist_from_left_edge << endl;
        cout << "can_jump_on = " << i->can_jump_on << endl << endl;
    }
}

void jump(list <rock>* rocks, list <rock>::iterator* actual_rock, list <rock>::iterator* next_rock, string operation) {
    if (operation == "sum") {
        while (*next_rock != rocks->end()) {

            if ((*next_rock)->type == "small") {
                if ((*actual_rock)->type == "big") {
                    break;
                } else if ((*actual_rock)->type == "small") {
                    (*next_rock)++;
                    break;
                }

            } else if ((*next_rock)->type == "big") {
                break;
            }
        }
    } else if (operation == "subtraction") {

    }
}

int getBiggestJump(list <rock>* rocks) {
    int biggest_jump = 0, jump_size;
    auto actual_rock = rocks->begin();
    auto next_rock = actual_rock;
    next_rock++;

    // going further
    while (true) {
        jump(rocks, &actual_rock, &next_rock, "sum");
        jump_size = next_rock->dist_from_left_edge - actual_rock->dist_from_left_edge;
        if (jump_size > biggest_jump) biggest_jump = jump_size;

        actual_rock = next_rock;
        if (actual_rock == rocks->end()) break;
        else next_rock++;
    }

    // getting back
    while (true) {
        jump(rocks, &actual_rock, &next_rock, "subtraction");
        jump_size = actual_rock->dist_from_left_edge - next_rock->dist_from_left_edge;
        if (jump_size > biggest_jump) biggest_jump = jump_size;
        if (next_rock == rocks->begin()) break;
    }
    return biggest_jump;
}

int main() {
    int nCases;
    int nRocks;
    int right_edge_dist;
    string rock_info, rock_type, int_from_rock_info;
    list <rock> rocks;

    cin >> nCases;
    for (int i = 1; i <= nCases; ++i) {
        cin >> nRocks >> right_edge_dist;
        rocks.clear();

        rock lr = {"left_edge", 0, true};
        rocks.push_back(lr);
        for (int j = 0; j < nRocks; ++j) {
            cin >> rock_info;

            if (rock_info[0] == 'S') rock_type = "small";
            else if (rock_info[0] == 'B') rock_type = "big";

            int_from_rock_info.clear();
            for (int k = 2; k < rock_info.length(); ++k) {
                int_from_rock_info.push_back(rock_info[k]);
            }

            rock r = {rock_type, stoi(int_from_rock_info), true};
            rocks.push_back(r);
        }
        rock rr = {"right_edge", right_edge_dist, true};
        rocks.push_back(rr);

        cout << "Case " << i << ": " << getBiggestJump(&rocks) << endl;
    }
    return 0;
}
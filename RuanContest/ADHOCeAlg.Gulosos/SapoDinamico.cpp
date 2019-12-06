#include <iostream>
#include <vector>

using namespace std;

struct rock {
    string type;
    int dist_from_left_edge;
    bool can_jump_on;
};

void printRocks(const vector <rock>* rocks) {
    for (auto i = rocks->begin(); i != rocks->end(); ++i) {
        cout << "type = " << i->type << endl;
        cout << "dist_from_left_edge = " << i->dist_from_left_edge << endl;
        cout << "can_jump_on = " << i->can_jump_on << endl << endl;
    }
}

int getBiggestJump(vector <rock>* rocks) {
    int biggest_jump = 0, jump_size;
    auto actual_rock = rocks->begin();
    auto next_rock = rocks->begin();

    // going further
    while (true) {
        if (actual_rock->type == "small") actual_rock->can_jump_on = false;
        else if (actual_rock->type == "right_edge") break;
        ++next_rock;

        if (actual_rock->type == "small") {
            if (next_rock->type == "small") {
                ++next_rock;
                jump_size = next_rock->dist_from_left_edge - actual_rock->dist_from_left_edge;
                if (jump_size > biggest_jump) biggest_jump = jump_size;
                actual_rock = next_rock;
            } else {
                jump_size = next_rock->dist_from_left_edge - actual_rock->dist_from_left_edge;
                if (jump_size > biggest_jump) biggest_jump = jump_size;
                actual_rock = next_rock;
            }
        } else {
            jump_size = next_rock->dist_from_left_edge - actual_rock->dist_from_left_edge;
            if (jump_size > biggest_jump) biggest_jump = jump_size;
            actual_rock = next_rock;
        }
    }

    // getting back
    while (true) {
        if (actual_rock->type == "left_edge") break;
        --next_rock;

        if (next_rock->can_jump_on) {
            jump_size = actual_rock->dist_from_left_edge - next_rock->dist_from_left_edge;
            if (jump_size > biggest_jump) biggest_jump = jump_size;
            actual_rock = next_rock;
        }
    }

    return biggest_jump;
}

int main() {
    int nCases;
    int nRocks;
    int right_edge_dist;
    string rock_info, rock_type, int_from_rock_info;
    vector <rock> rocks;

    cin >> nCases;
    for (int i = 0; i < nCases; ++i) {
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

        cout << "Case " << (i + 1) << ": " << getBiggestJump(&rocks) << endl;
    }
    return 0;
}
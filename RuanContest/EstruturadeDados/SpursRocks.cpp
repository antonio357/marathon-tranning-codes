#include <iostream>
#include <queue>
#include <list>
#include <map>

using namespace std;

struct match_score {
    int points_made;
    int win_lose_points;
    int points_received;
};

struct team {
    int team_id;
    int win_lose_score, total_score, subs_num;
    double average_score;
    list <match_score> scores;
};

bool operator<(const team& t1, const team& t2) {
    if (t1.win_lose_score > t2.win_lose_score) return false;
    else if (t1.win_lose_score < t2.win_lose_score) return true;
    else {
        if (t1.average_score > t2.average_score) return false;
        else if (t1.average_score < t2.average_score) return true;
        else {
            if (t1.total_score > t2.total_score) return false;
            else if (t1.total_score < t2.total_score) return true;
            else {
                if (t1.subs_num < t2.subs_num) return false;
                else if (t1.subs_num > t2.subs_num) return true;
            }
        }
    }
    return true;
}

void validateMatchInput(map <int, team>* teams, int team_id, match_score score) {
    auto t_p = teams->find(team_id);

    if (t_p != teams->end()) { // team exits
        t_p->second.scores.push_back(score);
    }
    else { // team does not exist
        team new_team;
        new_team.team_id = team_id;
        new_team.scores.push_back(score);
        teams->insert(pair <int, team> (team_id, new_team));
    }
}

int TeamWinLosePoints(team* t) {
    int total = 0;

    for (auto it = t->scores.begin(); it != t->scores.end() ; ++it) {
        total += it->win_lose_points;
    }
    return total;
}

double teamAverageScore(team* t) {
    double total = 0;

    for (auto it = t->scores.begin(); it != t->scores.end() ; ++it) {
        total += it->points_received;
    }

    if (total == 0) return (double) t->total_score;
    else return ((double) t->total_score) / total;
}

int TeamTotalPoints(team* t) {
    int total = 0;

    for (auto it = t->scores.begin(); it != t->scores.end() ; ++it) {
        total += it->points_made;
    }
    return total;
}

void print(priority_queue <team>* sorted_teams, int* instance_counter) {
    if (*instance_counter > 0) cout << endl;
    (*instance_counter)++;
    cout << "Instancia " << *instance_counter << endl;

    while (not sorted_teams->empty()) {
        cout << sorted_teams->top().team_id;
        if (sorted_teams->size() > 1) cout << ' ';
        sorted_teams->pop();
    } cout << endl;
}

void sort(map <int, team>* teams, priority_queue <team>* sorted_teams) {
    for (auto it = teams->begin(); it != teams->end() ; ++it) {
        it->second.total_score = TeamTotalPoints(&(it->second));
        it->second.win_lose_score = TeamWinLosePoints(&(it->second));
        it->second.average_score = teamAverageScore(&(it->second));
        it->second.subs_num = it->second.scores.size();
        sorted_teams->push(it->second);
    } teams->clear();
}

int main() {
    int n, x, y, z, w, instance_counter = 0;
    map<int, team> teams;
    priority_queue<team> sorted_teams;

    while (true) {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n * (n - 1) / 2; ++i) {
            cin >> x >> y >> z >> w;

            match_score x_score = {y, 1, w};
            match_score z_score = {w, 1, y};

            // deciding how wins
            if (y > w) { // x wins
               x_score.win_lose_points++;
            }
            else if (w > y) { // z wins
                z_score.win_lose_points++;
            }

            validateMatchInput(&teams, x, x_score);
            validateMatchInput(&teams, z, z_score);
        }

        sort(&teams, &sorted_teams);
        print(&sorted_teams, &instance_counter);
    }
    return 0;
}

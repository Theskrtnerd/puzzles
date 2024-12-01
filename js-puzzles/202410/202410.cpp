#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

const int N = 6;
char table[N][N] = {
    {'A', 'A', 'A', 'A', 'A', 'A'},
    {'A', 'A', 'A', 'A', 'B', 'B'},
    {'A', 'A', 'B', 'B', 'B', 'B'},
    {'B', 'B', 'B', 'B', 'C', 'C'},
    {'B', 'B', 'C', 'C', 'C', 'C'},
    {'C', 'C', 'C', 'C', 'C', 'C'}
};

unordered_map<char, int> char_to_int = {
    {'A', 1}, {'B', 3}, {'C', 2}
};

vector<pair<int, int>> get_knight_moves(int x, int y) {
    vector<pair<int, int>> moves = {
        {x + 2, y + 1}, {x + 2, y - 1}, {x - 2, y + 1}, {x - 2, y - 1},
        {x + 1, y + 2}, {x + 1, y - 2}, {x - 1, y + 2}, {x - 1, y - 2}
    };
    vector<pair<int, int>> valid_moves;
    for (auto move : moves) {
        int nx = move.first, ny = move.second;
        if (nx >= 0 && nx < 6 && ny >= 0 && ny < 6) {
            valid_moves.push_back(move);
        }
    }
    return valid_moves;
}

void find_paths(int x, int y, int end_x, int end_y, vector<pair<int, int>> path, vector<vector<pair<int, int>>>& paths, int current_score, vector<int>& scores, unordered_set<string>& solutions) {
    if (x == end_x && y == end_y) {
        if(current_score == 2024){
            string solution = "";
            for(auto move: path){
                solution += table[move.first][move.second];
            }
            if (solutions.find(solution) != solutions.end() || solution.length() > 15) {
                return;
            }
            else{
                cout << solution << endl;
                solutions.insert(solution);
            }
        }
        paths.push_back(path);
        scores.push_back(current_score);
        return;
    }
    for (auto move : get_knight_moves(x, y)) {
        int nx = move.first, ny = move.second;
        std::pair<int, int> move1 = make_pair(nx, ny);
        if (find(path.begin(), path.end(), move1) == path.end()) {
            path.push_back(move1);
            if (table[nx][ny] == table[path[path.size()-2].first][path[path.size()-2].second]) {
                current_score += char_to_int[table[nx][ny]];
            }
            else{
                current_score *= char_to_int[table[nx][ny]];
            }
            if (current_score > 2024) {
                return;
            }
            find_paths(nx, ny, end_x, end_y, path, paths, current_score, scores, solutions);
            if (table[nx][ny] == table[path[path.size()-2].first][path[path.size()-2].second]) {
                current_score -= char_to_int[table[nx][ny]];
            }
            else{
                current_score /= char_to_int[table[nx][ny]];
            }
            path.pop_back();
        }
    }
}

vector<vector<pair<int, int>>> get_path(int x, int y, vector<int>& scores, unordered_set<string>& solutions) {
    vector<vector<pair<int, int>>> paths;
    vector<pair<int, int>> path = {{x, y}};
    find_paths(x, y, 5, 0, path, paths, char_to_int[table[x][y]], scores, solutions);
    return paths;
}

int main() {
    vector<int> scores;
    unordered_set<string> solutions;
    vector<vector<pair<int, int>>> paths = get_path(0, 5, scores, solutions);
    /*
    for(int i=0; i<scores.size(); i++){
        cout << scores[i] << endl;
        if(scores[i] == 2024){
            for(auto move: paths[i]){
                cout << "(" << move.first << "," << move.second << ")" << ", ";
            }
            cout << endl;
        }
    }
    */
    return 0;
}
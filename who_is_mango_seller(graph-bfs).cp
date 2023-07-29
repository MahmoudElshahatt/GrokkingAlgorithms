#include <iostream>
#include <queue>
#include <map>
#include <unordered_set>
using namespace std;

map<string, vector<string>> graph;

bool person_is_seller(string name) {
    return name[name.length() - 1] == 'm';
}

void search(const string& start_person)  {
   queue<string> search_queue;
   unordered_set<string> searched;
   
    for (const string& neighbor : graph[start_person]) {
        search_queue.push(neighbor);
    }
    
    while (!search_queue.empty()) {
        string person = search_queue.front();
        search_queue.pop();

        cout << person << endl;
       if(searched.find(person)!=searched.end()){
        if (person_is_seller(person)) {
            cout << person << " is the seller" << endl;
             return;
        } }else {
            for (const auto& neighbor : graph[person]) {
                    search_queue.push(neighbor);
                    searched.insert(neighbor);
                
            }
        }
    }

    cout << "No seller found" << endl;
}

int main() {
    // Write C++ code here

    graph["you"] = { "alice", "bob", "claire" };
    graph["bob"] = { "anuj", "peggy" };
    graph["alice"] = { "peggy" };
    graph["claire"] = { "thom", "jonny" };
    graph["anuj"] = {};
    graph["peggy"] = {};
    graph["thom"] = {};
    graph["jonny"] = {};

     search("you");
    return 0;
}

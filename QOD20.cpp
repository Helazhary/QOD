#include <bits/stdc++.h>
using namespace std;


struct Table {
    int number;
    int capacity;
};

struct Request {
    int number;
    int groupSize;
    int totalMoney;
};

bool compareRequests(const Request& r1, const Request& r2) {
    return r1.totalMoney > r2.totalMoney;
}

bool compareTables(const Table& t1, const Table& t2) {
    return t1.capacity < t2.capacity;
}

// Binary search to find a suitable table for the group size
int findTable(const vector<Table>& tables, int groupSize) {
    int low = 0;
    int high = tables.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (tables[mid].capacity >= groupSize) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n; //# of requests
    int k; // # of tables
    int acceptedRequests = 0; 
    int totalMoney = 0; 

    cin >> n;

    vector<Request> requests(n);
    for (int i = 0; i < n; i++) {
        cin >> requests[i].groupSize >> requests[i].totalMoney;
        requests[i].number = i + 1;
    }

  
    sort(requests.begin(), requests.end(), compareRequests);

    cin >> k;


    vector<Table> tables(k);
    for (int i = 0; i < k; i++) {
        cin >> tables[i].capacity;
        tables[i].number = i + 1;
    }

  
    sort(tables.begin(), tables.end(), compareTables);

    
    vector<pair<int, int>> assignments;

    for (int i = 0; i < n && acceptedRequests < k; i++) {
        int tableIndex = findTable(tables, requests[i].groupSize);

        if (tableIndex != -1) {
            totalMoney += requests[i].totalMoney; 
            acceptedRequests++;
            assignments.push_back({ requests[i].number, tables[tableIndex].number });
            tables.erase(tables.begin() + tableIndex); 
        }
    }

    cout << acceptedRequests << " " << totalMoney << endl;

    for (const auto& assignment : assignments) {
        cout << assignment.first << " " << assignment.second << endl;
    }

    return 0;
}

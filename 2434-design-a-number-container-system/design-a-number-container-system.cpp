class NumberContainers {
public:
    unordered_map<int, int> p; 
    unordered_map<int, set<int>> nI; 

    void change(int index, int number) {
        if (p.find(index) != p.end()) { 
            int prevNum = p[index]; 
            nI[prevNum].erase(index);  
            
            if (nI[prevNum].empty()) { 
                nI.erase(prevNum);
            }
        }

        p[index] = number; 
        nI[number].insert(index); 
    }

    int find(int number) {
        if (nI.find(number) == nI.end() || nI[number].empty()) {
            return -1; 
        }
        return *nI[number].begin(); 
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index, number);
 * int param_2 = obj->find(number);
 */

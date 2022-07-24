class NumberContainers {
public:
    unordered_map<int,int>ind;
    unordered_map<int,set<int>>num;
    //num map -> number -> index link
    //ind map -> index -> number link
    
    NumberContainers() {  }
    
    void change(int index, int number) {
        auto it=ind.find(index);
        if(it!=ind.end())
            num[it->second].erase(index);
        ind[index]=number;
        num[number].insert(index);     
    }    
    int find(int number) {
        auto it=num.find(number);
        return it==num.end() || it->second.empty() ? -1 : *num[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
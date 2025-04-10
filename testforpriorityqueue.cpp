    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        priority_queue<pair<int,string> , vector<pair<int,string>> , greater<pair<int,string>>> pq;
        pq.push(make_pair(1,"abhiyan"));    
        pq.push(make_pair(3,"mummy"));    
        pq.push(make_pair(2,"baba"));
        while(!pq.empty())
        {
            cout<<pq.top().first<<"  " << pq.top().second <<endl;
            pq.pop();
        }   
        return 0;
    }
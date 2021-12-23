#include<bits/stdc++.h>
#include<string>
#include<climits>
using namespace std;
const int MAX_CHARS = 256;

string smallestWindow(string str){
    //Complete this method
    int n = str.length();
    
    if(n==0){
        return "";
    }
    bool visited[MAX_CHARS] = {false};
    int dist_count=0;
    for(int i=0;i<n;i++){
        if(visited[str[i]]==false){
            visited[str[i]]=true;
            dist_count++;
        }
    }
    
    int start=0,start_index=-1,min_length = INT_MAX;
    int count = 0;
    int curr_count[MAX_CHARS] = {0};
    
    for(int j=0;j<n;j++){
        curr_count[str[j]]++;
        
            if(curr_count[str[j]]==1){
                count++;
            }
            
            if(count==dist_count){
                while(curr_count[str[start]]>1){
                    if(curr_count[str[start]]>1){
                       curr_count[str[start]]--;
                    }
                     start++;
                }
                
                int len_window = j - start +1;
                if(min_length> len_window){
                    min_length = len_window;
                    start_index = start;
                }
            }
            
    }
    
    return str.substr(start_index,min_length);
}
